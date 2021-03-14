#ifndef NW_TEXTURE_3D_H
#define NW_TEXTURE_3D_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_texture.h>
namespace NW
{
	/// texture_cube class
	/// description:
	class NW_API texture_cube : public a_texture, public t_gfx_rsc<texture_cube>
	{
	public:
		texture_cube(gfx_engine& graphics, cstring name);
		~texture_cube();
		// --getters
		// --setters
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
		// --core_methods
		virtual bit remake(const a_image& img) override;
		virtual void clear(ptr value) override;
		virtual void on_draw() override;
	private:
	};
}
#endif	// NW_GAPI
#endif	// NW_TEXTURE_3D_H