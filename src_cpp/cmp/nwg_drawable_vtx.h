#ifndef NW_DRAWABLE_VTX_H
#define NW_DRAWABLE_VTX_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <cmp/nwg_drawable.h>
#include <core/nwg_buf_vtx.h>
namespace NW
{
	/// drawable_vertex class
	class NW_API drawable_vtx : public drawable
	{
		using buffers = darray<mem_ref<buf_vtx>>;
	public:
		drawable_vtx(gfx_engine& graphics);
		virtual ~drawable_vtx();
		// --getters
		buffers& get_bufs()		{ return m_vbufs; }
		// --setters
		// --core_methods
		virtual void on_draw() override;
	private:
		buffers m_vbufs;
	};
}

#endif	// NW_GAPI
#endif	// NW_DRAWABLE_VTX_H