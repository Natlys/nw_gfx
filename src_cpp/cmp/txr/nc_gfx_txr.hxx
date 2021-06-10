#ifndef NC_GFX_TEXTURE_H
#define NC_GFX_TEXTURE_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "../nc_gfx_cmp.hxx"
#	include "../img/nc_gfx_img.hxx"
namespace NC
{
	/// graphics_texture_type
	/// description:
	class gfx_txr_t : public nc_cmp_tt<gfx_txr_t>, public gfx_cmp_t, public gfx_img_t
	{
	public:
		// --texture
		using txr_t = gfx_txr_t;
		using txr_tc = const txr_t;
		// --gfx_api
#	if (NC_GAPI & NC_GAPI_OGL)
		using handle_t = GLuint;
		using format_t = GLenum;
		using pxtype_t = GLenum;
#	endif
#	if (NC_GAPI & NC_GAPI_D3D)
		using handle_t = ID3D11ShaderResourceView*;
		using format_t = DXGI_FORMAT;
		using pxtype_t = DXGI_FORMAT;
#	endif
		using handle_tc = const handle_t;
		using format_tc = const format_t;
		using pxtype_tc = const pxtype_t;
	public:
		gfx_txr_t();
		gfx_txr_t(txr_tc& copy);
		gfx_txr_t(txr_t&& copy);
		virtual ~gfx_txr_t();
		/* getters */
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline format_tc get_format() const { return m_format; }
		inline pxtype_tc get_pxtype() const { return m_pxtype; }
		inline v1u_tc get_slot() const { return m_slot; }
		/* setters */
		txr_t& set_slot(v1u_tc slot);
		/* vetters */
		/* operators */
		inline txr_t& operator=(txr_tc& copy) { gfx_img_t::operator=(copy); return *this; }
		inline txr_t& operator=(txr_t&& copy) { gfx_img_t::operator=(copy); return *this; }
		virtual nc_ostream_t& operator<<(nc_ostream_t& stm) const override;
		virtual nc_istream_t& operator>>(nc_istream_t& stm) override;
		/* command */
		virtual v1bit_t remake();
		virtual v1nil_t clear(ptr_tc data);
		virtual v1nil_t on_draw() override;
	protected:
		handle_t m_handle;
		format_t m_format;
		pxtype_t m_pxtype;
		v1u_t m_slot;
	};
}
#endif	// NC_GAPI
#endif // NC_GFX_TEXTURE_H
