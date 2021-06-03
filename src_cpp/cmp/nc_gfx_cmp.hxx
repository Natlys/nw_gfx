#ifndef NC_GFX_COMPONENT_H
#define NC_GFX_COMPONENT_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
namespace NC
{
	/// graphics_component_type
	class gfx_cmp_t
	{
	public:
		using context_t = gfx_context_t;
		using context_tc = const context_t;
	public:
		/* ctor_dtor */
		gfx_cmp_t();
		virtual ~gfx_cmp_t();
		/* getters */
		inline context_t* get_context()        { return m_context; }
		inline context_tc* get_context() const { return m_context; }
		/* setters */
		/* commands */
		virtual v1nil_t on_draw() = 0;
	private:
		context_t* m_context;
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_COMPONENT_H
