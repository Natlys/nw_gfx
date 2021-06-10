#ifndef NC_GFX_VERTEX_SHADER_H
#define NC_GFX_VERTEX_SHADER_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "nc_gfx_shd.hxx"
namespace NC
{
	/// graphics_shader_vertex_type
	class gfx_shd_vtx_t : public gfx_shd_t
	{
	public:
		using vshd_t = gfx_shd_vtx_t;
		using vshd_tc = const vshd_t;
	public:
		gfx_shd_vtx_t();
		gfx_shd_vtx_t(source_tc& source);
		gfx_shd_vtx_t(vshd_tc& copy);
		gfx_shd_vtx_t(vshd_t&& copy);
		virtual ~gfx_shd_vtx_t();
		/* getters */
		/* setters */
		/* operators */
		inline vshd_t& operator=(vshd_tc& copy) { gfx_shd_t::operator=(copy); return *this; }
		inline vshd_t& operator=(vshd_t&& copy) { gfx_shd_t::operator=(copy); return *this; }
		virtual nc_ostream_t& operator<<(nc_ostream_t& stm) const override;
		virtual nc_istream_t& operator>>(nc_istream_t& stm) override;
		/* command */
		virtual v1bit_t remake() override;
		virtual v1nil_t on_bind(binder_t& ref) override;
		virtual v1nil_t on_draw() override;
	private:
#	if (NC_GAPI & NC_GAPI_D3D)
		ID3D11VertexShader* m_native;
#	endif
	};
}
#endif	// NC_GAPI
#endif // NC_GFX_VERTEX_SHADER_H
