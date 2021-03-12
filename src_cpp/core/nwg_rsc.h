#ifndef NW_RESOURCE_H
#define NW_RESOURCE_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
namespace NW
{
	/// abstract graphics_resource class
	class NW_API a_gfx_rsc : public a_type_owner
	{
	protected:
		a_gfx_rsc();
	public:
		virtual ~a_gfx_rsc();
		// --getters
		virtual inline ui32 get_type_id() const = 0;
		virtual inline ui32 get_rsc_id() const = 0;
		// --core_methods
		virtual void on_draw() = 0;
	};
	/// templated graphics_resource class
	template <class ctype>
	class NW_API t_gfx_res : public a_gfx_rsc
	{
	protected:
		t_gfx_res(gfx_engine& graphics) : m_gfx(&graphics), m_rsc_id(id_indexator::get_id<ctype>()) { }
	public:
		virtual ~t_gfx_res() { id_indexator::set_id<ctype>(m_rsc_id); };
		// --getters
		static inline ui32 get_type_id_static()				{ return type_indexator::get_id<ctype>(); }
		virtual inline ui32 get_type_id() const override	{ return type_indexator::get_id<ctype>(); }
		virtual inline ui32 get_rsc_id() const override		{ return m_rsc_id; }
		// --core_methods
		virtual void on_draw() override { }
	protected:
		gfx_engine* m_gfx;
		const ui32 m_rsc_id;
	};
}
#endif	// NW_GAPI
#endif	// NW_RESOURCE_H