#ifndef GFX_DRAWABLE_H
#define GFX_DRAWABLE_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <nwg_res.h>
#include <nwg_tools.h>
#include <nwg_vtx_buf.h>
#include <nwg_idx_buf.h>
#include <nwg_material.h>
namespace NWG
{
	/// Abstract Drawable class
	class NWG_API ADrawable : public TEntity<ADrawable>, public AGfxRes
	{
		using VtxBufs = DArray<RefKeeper<VertexBuf>>;
	public:
		ADrawable(GfxEngine& rGfx);
		virtual ~ADrawable();
		// --getters
		inline UInt8 GetOrder() const { return m_unOrder; }
		inline RefKeeper<GfxMaterial>& GetMaterial() { return m_gMtl; }
		inline VtxBufs& GetVtxBufs() { return m_vtxBufs; }
		inline RefKeeper<VertexBuf>& GetVtxBuf(UInt8 nIdx) { return m_vtxBufs[nIdx % m_vtxBufs.size()]; }
		// --setters
		void SetOrder(UInt8 unOrder);
		void SetMaterial(RefKeeper<GfxMaterial>& rgMtl);
		void AddVtxBuf(RefKeeper<VertexBuf>& rBuf);
		void RmvVtxBuf(UInt8 nIdx);
		// --core_methods
		virtual void Bind() = 0;
	protected:
		UInt8 m_unOrder;
		RefKeeper<GfxMaterial> m_gMtl;
		VtxBufs m_vtxBufs;
	};
}
namespace NWG
{
	/// VertexedDrawable class
	class NWG_API VertexedDrawable : public ADrawable
	{
	public:
		VertexedDrawable(GfxEngine& rGfx);
		template<typename VType> VertexedDrawable(GfxEngine& rGfx, UInt32 unVtxCount, VType* pVtxData);
		// --core_methods
		virtual void Bind() override;
	};
	template<typename VType> VertexedDrawable::VertexedDrawable(GfxEngine& rGfx, UInt32 unVtxCount, VType* pVtxData = nullptr) :
		ADrawable(rGfx)
	{
		m_vtxBufs.push_back(RefKeeper<VertexBuf>());
		m_pGfx->CreateRes<VertexBuf>(m_vtxBufs.back());
		m_vtxBufs.back()->SetData<VType>(unVtxCount, pVtxData);
	}
	/// IndexedDrawable class
	class NWG_API IndexedDrawable : public ADrawable
	{
	public:
		IndexedDrawable(GfxEngine& rGfx);
		template<typename IType> IndexedDrawable(GfxEngine& rGfx, UInt32 unIdxCount, IType* pIdxData);
		// --getters
		inline IndexBuf* GetIdxBuf() { return m_idxBuf; }
		// --setters
		void SetIdxBuf(RefKeeper<IndexBuf>& rBuf);
		// --core_methods
		virtual void Bind() override;
	protected:
		RefKeeper<IndexBuf> m_idxBuf;
	};
	template<typename IType> IndexedDrawable::IndexedDrawable(GfxEngine& rGfx, UInt32 unIdxCount, IType* pIdxData = nullptr) :
		ADrawable(rGfx)
	{
		m_pGfx->CreateRes<IndexBuf>(m_idxBuf);
		m_idxBuf->SetData<IType>(unIdxCount, pIdxData);
	}
}
#endif
#endif	// GFX_DRAWABLE_H