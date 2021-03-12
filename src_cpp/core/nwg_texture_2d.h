#ifndef NW_TEXTURE_2D_H
#define NW_TEXTURE_2D_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_texture.h>
namespace NW
{
	/// texture_2d class
	/// description:
	class NW_API texture_2d : public a_texture, public t_gfx_res<texture_2d>
	{
	public:
		texture_2d(gfx_engine& graphics, cstring name);
		virtual ~texture_2d();
		// --setters
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
		// --core_methods
		virtual bit remake(const a_image& img) override;
		virtual void clear(ptr value) override;
		virtual void on_draw() override;
	};
}
#endif	// NW_GAPI
#endif // GFX_TEXTURE_H