#ifndef NW_DRAWABLE_H
#define NW_DRAWABLE_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_rsc.h>
#include <core/nwg_material.h>
namespace NW
{
	/// drawable class
	class NW_API drawable : public t_gfx_rsc<drawable>
	{
		/// storable component reference
		using rsc_ref = mem_ref<a_gfx_rsc>;
		/// component refs
		using rscs = darray<mem_ref<a_gfx_rsc>>;
		/// material reference
		using gmt = mem_ref<gfx_material>;
	public:
		drawable(gfx_engine& graphics);
		virtual ~drawable();
		// --getters
		inline rscs& get_rscs()				{ return m_rscs; }
		inline rsc_ref& get_rsc(ui8 idx)	{ return m_rscs[idx % m_rscs.size()]; }
		inline gmt& get_gmt()				{ return m_gmt; }
		// --setters
		// --core_methods
		void add_rsc(rsc_ref& ref);
		template<class gtype> void add_rsc(mem_ref<gtype>& ref) { mem_ref<a_gfx_rsc> a_ref(ref); add_rsc(a_ref); }
		void rmv_rsc(ui8 idx);
		virtual void on_draw();
	protected:
		gmt m_gmt;
		rscs m_rscs;
	};
}
#endif
#endif	// NW_DRAWABLE_H