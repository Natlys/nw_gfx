#ifndef NWG_ARRAY_H
#define NWG_ARRAY_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <nwg_buffer.h>
namespace NWG
{
	/// VertexArray class
	class VertexArr : public GfxEntity
	{
	public:
		VertexArr();
		virtual ~VertexArr();
		// --getters
		inline VertexBufLayout& GetLayout() { return m_vtxLayout; }
		inline GfxPrimitives GetDrawPrimitive() const { return m_gpType; }
		inline VertexBuf* GetVtxBuffer(UInt32 unIdx = 0) { return m_vtxBufs[unIdx].GetRef(); }
		inline IndexBuf* GetIdxBuffer() { return m_idxBuf.GetRef(); }
		// --setters
		inline void SetDrawPrimitive(GfxPrimitives gpType) { m_gpType = gpType; }
		// --core_methods
		void Bind() const;
		void Remake(const VertexBufLayout& rVtxLayout);
		void CreateVtxBuffer();
		void CreateIdxBuffer();
	private:
		VertexBufLayout m_vtxLayout;
		GfxPrimitives m_gpType;
		DArray<RefKeeper<VertexBuf>> m_vtxBufs;
		RefKeeper<IndexBuf> m_idxBuf;
	};
}
#endif	// NWG_GAPI
#endif	// NWG_ARRAY_H