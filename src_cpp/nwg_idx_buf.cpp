#include <nwg_pch.hpp>
#include "nwg_idx_buf.h"
#if (defined NWG_GAPI)
#include <nwg_engine.h>
#include <nwg_loader.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	IndexBuf::IndexBuf() : TEntity(), AGfxRes(), m_szData(0), m_sdType(DT_UINT32) { }
	IndexBuf::~IndexBuf() { SetData(0, nullptr); }
	// --setters
	void IndexBuf::SetSubData(Size szData, const Ptr pVtxData, Size szOffset) {
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, szOffset, szData, pVtxData);
	}
	void IndexBuf::SetData(Size szData, const Ptr pVtxData) {
		m_szData = szData;
		if (m_unRId != 0) { glDeleteBuffers(1, &m_unRId); m_unRId = 0; }
		if (szData == 0) { return; }
		glGenBuffers(1, &m_unRId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_unRId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, szData, pVtxData, pVtxData == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
	}
	void IndexBuf::Bind() {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_unRId);
	}
}

#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	IndexBuf::IndexBuf(GfxEngine& rGfx) :
		TEntity(), AGfxRes(rGfx), m_gdInfo(GfxDataInfo()),
		m_pNative(nullptr) { }
	IndexBuf::~IndexBuf() {
		if (m_pNative != nullptr) { m_pNative->Release(); m_pNative = nullptr; }
	}
	// --setters
	void IndexBuf::SetSubData(Size szData, const Ptr pData, Size szOffset) {
		D3D11_MAPPED_SUBRESOURCE msubRes{ 0 };
		m_pGfx->GetContext()->Map(m_pNative, 0u, D3D11_MAP_WRITE_DISCARD, 0u, &msubRes);
		memcpy(msubRes.pData, pData, szData);
		m_pGfx->GetContext()->Unmap(m_pNative, 0u);
	}
	// --core_methods
	void IndexBuf::Bind() {
		m_pGfx->GetContext()->IASetIndexBuffer(m_pNative, ConvertEnum<DataTypes, DXGI_FORMAT>(m_gdInfo.sdType), 0);
	}
	void IndexBuf::Remake(const GfxDataInfo& rInfo) {
		m_gdInfo = rInfo;
		if (m_pNative != nullptr) { m_pNative->Release(); m_pNative = nullptr; }
		if (m_gdInfo.szData == 0) { return; }

		D3D11_BUFFER_DESC bufDesc{ 0 };
		bufDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		bufDesc.MiscFlags = 0u;
		bufDesc.StructureByteStride = m_gdInfo.szStride;
		bufDesc.ByteWidth = m_gdInfo.szData;

		if (m_gdInfo.pData == nullptr) {
			m_gdInfo.pData = MemSys::GetMemory().GetDataBeg();
			bufDesc.Usage = D3D11_USAGE_DYNAMIC;
			bufDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		}
		else {
			bufDesc.Usage = D3D11_USAGE_DEFAULT;
			bufDesc.CPUAccessFlags = 0u;
		}

		D3D11_SUBRESOURCE_DATA subData{ 0 };
		subData.pSysMem = m_gdInfo.pData;

		m_pGfx->GetDevice()->CreateBuffer(&bufDesc, &subData, &m_pNative);
		if (m_pNative == nullptr) { throw Exception("Failed to create buffer!"); }
	}
}
#endif
#endif	// NWG_GAPI