#ifndef NW_DRAWABLE_H
#define NW_DRAWABLE_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_rsc.h>
namespace NW
{
	/// abstract drawable class
	class NW_API a_drawable
	{
		/// storable component reference
		using rsc_ref = mem_ref<a_gfx_rsc>;
		/// component refs
		using rscources = darray<mem_ref<a_gfx_rsc>>;
	public:
		a_drawable();
		virtual ~a_drawable();
		// --getters
		inline rscources& get_rscources()		{ return m_rscs; }
		inline rsc_ref& get_rsc(ui8 idx)		{ return m_rscs[idx % m_rscs.size()]; }
		// --setters
		// --core_methods
		void add_rsc(rsc_ref& ref);
		template<class gtype> void add_rsc(mem_ref<gtype>& ref) { mem_ref<a_gfx_rsc> a_ref(ref); add_rsc(a_ref); }
		void rmv_rsc(ui8 idx);
	protected:
		rscources m_rscs;
	};
}
#endif
#endif	// NW_DRAWABLE_H