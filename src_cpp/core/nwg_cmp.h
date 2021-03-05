#ifndef NWG_COMPONENT_H
#define NWG_COMPONENT_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
namespace NWG
{
	/// abstract graphics_component class
	class NWG_API a_gfx_cmp : public a_cmp
	{
	protected:
		a_gfx_cmp(gfx_engine& graphics);
	public:
		virtual ~a_gfx_cmp();
		// --getters
		// --core_methods
		virtual void on_draw() = 0;
	protected:
		gfx_engine* m_gfx;
	};
	/// templated graphics_component class
	template <class gtype>
	class NWL_API t_gfx_cmp : public a_gfx_cmp, public t_cmp<gtype>
	{
	protected:
		t_gfx_cmp(gfx_engine& graphics) : a_gfx_cmp(graphics) { }
	public:
		virtual ~t_gfx_cmp() { }
		// --getters
		virtual inline ui32 get_type_id() const override { return type_indexator::get_id<gtype>(); }
		virtual inline ui32 get_cmp_id() const override { return m_cmp_id; }
		// --core_methods
		virtual void on_draw() = 0;
	};
}
#endif	// NWG_GAPI
#endif	// NWG_COMPONENT_H