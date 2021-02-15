#include <nwg_pch.hpp>
#include "nwg_array.h"
#if (defined NWG_GAPI)
#include <nwg_engine.h>
#include <nwg_loader.h>
namespace NWG
{
}
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	VertexArr::VertexArr() :
		GfxEntity(), m_gpType(GPT_TRIANGLES)
	{
		glCreateVertexArrays(1, &m_unRId);
	}
	VertexArr::~VertexArr() { glDeleteVertexArrays(1, &m_unRId); }
	// --setters
	// --==<core_methods>==--
	void VertexArr::Bind() const { glBindVertexArray(m_unRId); }
	void VertexArr::Remake(const VertexBufLayout& rvtxLayout) {
		if (m_idxBuf.GetRef() != nullptr) { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_idxBuf->GetRenderId()); }
		else { glBindBuffer(GBT_INDEX, 0); }
		for (auto& itBuf : m_vtxBufs) { glBindBuffer(GL_ARRAY_BUFFER, itBuf->GetRenderId()); }
		for (UInt32 ati = 0; ati < m_vtxLayout.GetElems().size(); ati++) { glDisableVertexAttribArray(ati); }
		m_vtxLayout = rvtxLayout;
		for (UInt32 ati = 0; ati < m_vtxLayout.GetElems().size(); ati++) {
			const BufferElement& rBufElem = m_vtxLayout.GetElem(ati);
			glEnableVertexAttribArray(ati);
			glVertexAttribPointer(ati, rBufElem.unCount, rBufElem.sdType,
				rBufElem.bNormalized ? GL_TRUE : GL_FALSE, m_vtxLayout.GetStride(), reinterpret_cast<Ptr>(rBufElem.szOffset));
		}
	}
	void VertexArr::CreateVtxBuffer()
	{
		RefKeeper<VertexBuf> vtxBuf;
		vtxBuf.MakeRef<VertexBuf>();
		m_vtxBufs.push_back(vtxBuf);
	}
	void VertexArr::CreateIdxBuffer()
	{
		m_idxBuf.MakeRef<IndexBuf>();
	}
	// --==</core_methods>==--
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	VertexArrDx::VertexArrDx(GfxEngineDx& rGfx) :
		VertexArr(), GfxEntityDx(rGfx) { }
	VertexArrDx::~VertexArrDx() { }

	// --==<core_methods>==--
	void VertexArrDx::Bind() const {
	}
	void VertexArrDx::Unbind() const {
	}

	void VertexArrDx::Remake(const VertexBufLayout& rvtxLayout) {
	}
	void VertexArrDx::CreateVtxBuffer()
	{
		RefKeeper<VertexBuf> vtxBuf;
		vtxBuf.MakeRef<VertexBufDx>();
		AddVtxBuffer(vtxBuf);
	}
	void VertexArrDx::CreateIdxBuffer()
	{
		RefKeeper<IndexBuf> idxBuf;
		idxBuf.MakeRef<IndexBufDx>();
		SetIdxBuffer(idxBuf);
	}
	// --==</core_methods>==--
}
#endif
#endif	// NWG_GAPI