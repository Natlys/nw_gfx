#include <nwg_pch.hpp>
#include "nwg_shd_buf.h"
#if (defined NWG_GAPI)
#include <nwg_engine.h>
#include <nwg_loader.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	ShaderBuf::ShaderBuf() : TEntity(), AGfxRes(), m_szData(0), m_sdType(DT_FLOAT32) { }
	ShaderBuf::~ShaderBuf() { SetData(0, nullptr); }
	// --setters
	void ShaderBuf::SetSubData(Size szData, const Ptr pVtxData, Size szOffset) {
		glBufferSubData(GL_UNIFORM_BUFFER, szOffset, szData, pVtxData);
	}
	void ShaderBuf::SetData(Size szData, const Ptr pVtxData) {
		m_szData = szData;
		if (m_unRId != 0) { glDeleteBuffers(1, &m_unRId); m_unRId = 0; }
		if (szData == 0) { return; }
		glGenBuffers(1, &m_unRId);
		glBindBuffer(GL_UNIFORM_BUFFER, m_unRId);
		glBufferData(GL_UNIFORM_BUFFER, szData, pVtxData, pVtxData == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
	}
	// --core_methods
	void ShaderBuf::Bind() { glBindBuffer(GL_UNIFORM_BUFFER, m_unRId); }
	void ShaderBuf::Bind(UInt32 unPoint) const { glBindBufferBase(GL_UNIFORM_BUFFER, unPoint, m_unRId); }
	void ShaderBuf::Bind(UInt32 unPoint, Size szData, Size szOffset) const { glBindBufferRange(GL_UNIFORM_BUFFER, unPoint, m_unRId, szOffset, szData); }
	void ShaderBuf::Remake(const ShaderLayout& rBufLayout) {
		if (m_szData < rBufLayout.GetSize()) { SetData(rBufLayout.GetSize()); }
		for (auto& rBlock : rBufLayout.GetBlocks()) { Bind(rBlock.unBindPoint, rBlock.szAll, rBlock.szOffset); }
	}
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	ShaderBuf::ShaderBuf(GfxEngine& rGfx) :
		TEntity(), AGfxRes(rGfx),
		m_gdInfo(GfxDataInfo()), m_pNative(nullptr) { }
	ShaderBuf::~ShaderBuf() { if (m_pNative != nullptr) { m_pNative->Release(); m_pNative = nullptr; } }
	// --setters
	void ShaderBuf::SetSubData(Size szData, const Ptr pData, Size szOffset) {
		D3D11_MAPPED_SUBRESOURCE msubRes{ 0 };
		m_pGfx->GetContext()->Map(m_pNative, 0u, D3D11_MAP_WRITE_DISCARD, 0u, &msubRes);
		memcpy(msubRes.pData, pData, szData);
		m_pGfx->GetContext()->Unmap(m_pNative, 0u);
	}
	void ShaderBuf::SetLayout(const ShaderLayout& rBufLayout) {
		for (auto& rBlock : rBufLayout.GetBlocks()) { Bind(rBlock.unBindPoint, rBlock.szAll, rBlock.szOffset); }
	}
	// --core_methods
	void ShaderBuf::Bind() {
		m_pGfx->GetContext()->VSSetConstantBuffers(0, 1, &m_pNative);
		m_pGfx->GetContext()->PSSetConstantBuffers(0, 1, &m_pNative);
	}
	void ShaderBuf::Bind(UInt32 unPoint) {
	}
	void ShaderBuf::Bind(UInt32 unPoint, Size szData, Size szOffset) { }
	void ShaderBuf::Remake(const GfxDataInfo& rInfo) {
		m_gdInfo = rInfo;
		if (m_pNative != nullptr) { m_pNative->Release(); m_pNative = nullptr; }
		if (m_gdInfo.szData == 0) { return; }

		D3D11_BUFFER_DESC bufDesc{ 0 };
		bufDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
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