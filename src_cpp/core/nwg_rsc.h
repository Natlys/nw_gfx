#ifndef NWG_RESOURCE_H
#define NWG_RESOURCE_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
namespace NW
{
	/// abstract graphics_resource class
	class NW_API a_gfx_rsc
	{
	public:
		a_gfx_rsc(gfx_engine& graphics);
		virtual ~a_gfx_rsc();
		// --core_methods
		virtual void on_draw();
	protected:
		gfx_engine* m_gfx;
	};
}
#endif	// NW_GAPI
#endif	// NWG_RESOURCE_H