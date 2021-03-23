#ifndef NWG_VERTEXED_ENTITY_H
#define NWG_VERTEXED_ENTITY_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_ent.h>
#include <cmp/buf/nwg_buf_vtx.h>
namespace NW
{
	/// ent_vertex class
	class NW_API ent_vtx : public a_gfx_ent
	{
		using vbuf = mem_ref<buf_vtx>;
		using vbufs = darray<vbuf>;
	public:
		ent_vtx(gfx_engine& graphics);
		virtual ~ent_vtx();
		// --getters
		inline vbufs& get_vbufs()			{ return m_vbufs; }
		inline vbuf& get_vbuf(ui8 idx = 0)	{ return m_vbufs[idx % m_vbufs.size()]; }
		// --setters
		void add_vbuf(vbuf& ref);
		void rmv_vbuf(ui8 idx);
		// --core_methods
		virtual void on_draw() override;
	private:
		vbufs m_vbufs;
	};
}
#endif	// NW_GAPI
#endif	// NWG_VERTEXED_ENTITY_H