#include <nwg_pch.hpp>
#include <nwg_drawable.h>
#if (defined NWG_GAPI)
#include <nwg_engine.h>
#include <nwg_loader.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	ADrawable::ADrawable(GfxEngine& rGfx) :
		TEntity(), AGfxRes(rGfx),
		m_unOrder(0) { }
	ADrawable::~ADrawable() { }
	// --setters
	void ADrawable::SetOrder(UInt8 unOrder) { m_unOrder = unOrder; }
	void ADrawable::SetMaterial(RefKeeper<GfxMaterial>& rgMtl) { m_gMtl = rgMtl; }
	void ADrawable::AddVtxBuf(RefKeeper<VertexBuf>& rBuf) { m_vtxBufs.push_back(rBuf); }
	void ADrawable::RmvVtxBuf(UInt8 nIdx) { m_vtxBufs.erase(m_vtxBufs.begin() + nIdx); }
	// --core_methods
	//void ADrawable::Bind() { }
}
namespace NWG
{
	VertexedDrawable::VertexedDrawable(GfxEngine& rGfx) : ADrawable(rGfx) { }
	// --core_methods
	void VertexedDrawable::Bind() {
		m_gMtl->Bind();
		Size szData = 0;
		Size unCount = 0;
		for (auto& itBuf : m_vtxBufs) {
			itBuf->Bind();
			szData += itBuf->GetDataSize();
			unCount += itBuf->GetDataCount();
		}
		m_pGfx->GetContext()->Draw(static_cast<UINT>(unCount), 0u);
	}
}
namespace NWG
{
	IndexedDrawable::IndexedDrawable(GfxEngine& rGfx) : ADrawable(rGfx) { }
	// --core_methods
	void IndexedDrawable::Bind() {
		m_gMtl->Bind();
		for (auto& itBuf : m_vtxBufs) { itBuf->Bind(); }
		m_idxBuf->Bind();
		m_pGfx->GetContext()->DrawIndexed(m_idxBuf->GetDataCount(), NULL, NULL);
	}
}
#endif
#endif	// NWG_GAPI