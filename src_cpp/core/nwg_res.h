#ifndef NWG_RESOURCE_H
#define NWG_RESOURCE_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
namespace NWG
{
	/// abstract graphics_resource class
	class NWG_API a_gfx_res : public a_type_owner
	{
	protected:
		a_gfx_res();
	public:
		virtual ~a_gfx_res();
		// --getters
		virtual inline ui32 get_type_id() const = 0;
		virtual inline ui32 get_res_id() const = 0;
		// --core_methods
		virtual void on_draw() = 0;
	};
	/// templated graphics_resource class
	template <class ctype>
	class NWL_API t_gfx_res : public a_gfx_res
	{
	protected:
		t_gfx_res(gfx_engine& graphics) : m_gfx(&graphics), m_res_id(id_indexator::get_id<ctype>()) { }
	public:
		virtual ~t_gfx_res() { id_indexator::set_id<ctype>(m_res_id); };
		// --getters
		static inline ui32 get_type_id_static()				{ return type_indexator::get_id<ctype>(); }
		virtual inline ui32 get_type_id() const override	{ return type_indexator::get_id<ctype>(); }
		virtual inline ui32 get_res_id() const override		{ return m_res_id; }
		// --core_methods
		virtual void on_draw() override { }
	protected:
		gfx_engine* m_gfx;
		const ui32 m_res_id;
	};
}
#endif	// NWG_GAPI
#endif	// NWG_RESOURCE_H