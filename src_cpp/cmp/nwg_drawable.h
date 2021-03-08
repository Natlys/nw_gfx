#ifndef NWG_DRAWABLE_H
#define NWG_DRAWABLE_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <core/nwg_res.h>
#include <core/nwg_vtx_buf.h>
#include <core/nwg_idx_buf.h>
namespace NWG
{
	/// abstract drawable class
	class NWG_API a_drawable
	{
		/// storable component reference
		using res_ref = mem_ref<a_gfx_res>;
		/// component refs
		using resources = darray<mem_ref<a_gfx_res>>;
	public:
		a_drawable();
		virtual ~a_drawable();
		// --getters
		inline resources& get_resources()		{ return m_rscs; }
		inline res_ref& get_res(ui8 idx)		{ return m_rscs[idx % m_rscs.size()]; }
		// --setters
		// --core_methods
		void add_res(res_ref& ref);
		template<class gtype> void add_res(mem_ref<gtype>& ref) { mem_ref<a_gfx_res> a_ref(ref); add_res(a_ref); }
		void rmv_res(ui8 idx);
	protected:
		resources m_rscs;
	};
}
#endif
#endif	// NWG_DRAWABLE_H