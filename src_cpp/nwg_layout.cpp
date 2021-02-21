#include <nwg_pch.hpp>
#include <nwg_layout.h>
#if(defined NWG_GAPI)
#include <nwg_engine.h>
#include <nwg_loader.h>
#include <nwg_shader.h>
#pragma warning(disable : 4267)
namespace NWG
{
	// --setters
	void VertexLayout::SetElements(const DArray<BufElem>& rBufElems) { m_Elems = rBufElems; }
	void VertexLayout::AddElement(const BufElem& rBufElem, Int8 nElems) { while (nElems-- > 0) { m_Elems.push_back(rBufElem); } }
	void VertexLayout::AddElement(const char* strName, DataTypes sdType, UInt8 unCount, Int8 nElems) {
		AddElement(BufElem(strName, sdType, unCount, false), nElems);
	}
	void VertexLayout::Remake() {
		if (m_Elems.size() == 0) { return; }
		m_szStride = 0;
		for (auto& rBufElem : m_Elems) {
			rBufElem.szOffset = m_szStride;
			m_szStride += DtGetSize(rBufElem.sdType, rBufElem.unCount);
		}
	}
}
namespace NWG
{
	// --setters
	void ShaderLayout::SetBlocks(const DArray<ShaderBlock>& rBlocks) { m_Blocks = rBlocks; Remake(); }
	void ShaderLayout::AddBlock(const ShaderBlock& rBlock, Int8 nElems) { while (nElems-- > 0) { m_Blocks.push_back(rBlock); } Remake(); }
	void ShaderLayout::Remake() {
		Size szData = 0;
		for (UInt8 bi = 0; bi < m_Blocks.size(); bi++) {
			auto& rBlock = m_Blocks[bi];
			rBlock.unBindPoint = bi;
			rBlock.szOffset = szData;
			for (auto& rElem : rBlock.Elems) {
				rElem.szOffset += rBlock.szAll;
				rBlock.szAll += DtGetAlignedSize(rElem.sdType, rElem.unCount);
			}
			szData += rBlock.szAll;
		}
	}
}
#if(NWG_GAPI & NWG_GAPI_OGL)
#endif
#if(NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	InputLayout::InputLayout(GfxEngine& rGfx) :
		TEntity(), AGfxRes(rGfx),
		m_pShader(nullptr), m_pNative(nullptr) { }
	InputLayout::~InputLayout() { SetShader(nullptr); }
	// --setters
	void InputLayout::SetShader(VertexShader* pShader) { m_pShader = pShader; }
	// --core_methods
	void InputLayout::Bind() { m_pGfx->GetContext()->IASetInputLayout(m_pNative); }
	void InputLayout::Remake() {
		if (m_pNative != nullptr) { m_pNative->Release(); m_pNative = nullptr; }
		if (m_pShader == nullptr) { return; }
		
		auto& rLayout = m_pShader->GetVtxLayout();
		DArray<D3D11_INPUT_ELEMENT_DESC> dxElems(rLayout.GetElems().size());
		for (UInt32 bei = 0; bei < dxElems.size(); bei++) {
			auto& itElem = rLayout.GetElem(bei);
			auto& dxElem = dxElems[bei];
			dxElem.Format = ConvertEnum<DataTypes, DXGI_FORMAT>(itElem.sdType);
			dxElem.SemanticName = itElem.strName;
			dxElem.SemanticIndex = 0;
			dxElem.InputSlot = itElem.unNum;
			dxElem.AlignedByteOffset = itElem.szOffset;
			dxElem.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
			dxElem.InstanceDataStepRate = 0;
		}
		m_pGfx->GetDevice()->CreateInputLayout(&dxElems[0], dxElems.size(),
			m_pShader->GetBlob()->GetBufferPointer(), m_pShader->GetBlob()->GetBufferSize(), &m_pNative);
		if (m_pNative == nullptr) { throw Exception("input layout is null!"); }
		m_pGfx->GetContext()->IASetInputLayout(m_pNative);
	}
}

#endif
#endif	// NWG_GAPI