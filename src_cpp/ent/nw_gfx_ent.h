#ifndef NW_GFX_ENTITY_H
#define NW_GFX_ENTITY_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "cmp/nw_gfx_cmp.h"
namespace NW
{
	/// abstract graphics_entity class
	class NW_API a_gfx_ent : public t_ent<a_gfx_ent, a_gfx_cmp>, public a_gfx_rsc
	{
	public:
#	if (NW_GAPI & NW_GAPI_OGL)
		using prim = GLenum;
#	endif
#	if (NW_GAPI & NW_GAPI_D3D)
		using prim = D3D11_PRIMITIVE_TOPOLOGY;
#	endif
	protected:
		a_gfx_ent(gfx_engine& graphics);
	public:
		virtual ~a_gfx_ent();
		// --getters
		inline prim get_prim() const { return m_prim; }
		// --setters
		void set_prim(prim primitive);
		// --core_methods
		virtual v1nil on_draw();
	protected:
		prim m_prim;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_ENTITY_H