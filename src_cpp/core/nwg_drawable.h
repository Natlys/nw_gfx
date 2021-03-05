#ifndef NWG_DRAWABLE_H
#define NWG_DRAWABLE_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <core/nwg_cmp.h>
#include <cmp/nwg_vtx_buf.h>
#include <cmp/nwg_idx_buf.h>
namespace NWG
{
	/// abstract drawable class
	class NWG_API a_drawable : public a_ent
	{
		/// basic component reference
		using cmp_ref = mem_ref<a_gfx_cmp>;
		/// component_id - ref association
		using cmps = dictionary<ui32, mem_ref<a_gfx_cmp>>;
	public:
		a_drawable(gfx_engine& graphics);
		virtual ~a_drawable();
		// --getters
		inline ui8 get_order() const { return m_order; }
		inline cmps& get_cmps();
		inline cmp_ref& get_cmp(ui32 type_id);
		// --setters
		void set_order(ui8 order);
		void add_cmp(cmp_ref& ref);
		void rmv_cmp(ui32 idx);
		template<class gtype>
		void add_cmp(mem_ref<gtype>& ref) { mem_ref<a_gfx_cmp> temp_ref(ref); add_cmp(temp_ref); }
	protected:
		gfx_engine* m_gfx;
		ui8 m_order;
	};
}
#endif
#endif	// NWG_DRAWABLE_H