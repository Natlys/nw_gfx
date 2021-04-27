#ifndef NW_GFX_TEXTURE_H
#define NW_GFX_TEXTURE_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../nw_gfx_cmp.h"
#	include "../img/nw_gfx_img.h"
namespace NW
{
	/// graphics_texture class
	/// description:
	class NW_API gfx_txr : public t_cmp<gfx_txr>, public a_gfx_cmp, public gfx_img
	{
	public:
		// --texture
		using txr_t = gfx_txr;
		using txr_tc = const txr_t;
		// --gfx_api
#	if (NW_GAPI & NW_GAPI_OGL)
		using handle_t = GLuint;
		using format_t = GLenum;
		using pxtype_t = GLenum;
#	endif
#	if (NW_GAPI & NW_GAPI_D3D)
		using handle_t = ID3D11ShaderResourceView*;
		using format_t = DXGI_FORMAT;
		using pxtype_t = DXGI_FORMAT;
#	endif
		using handle_tc = const handle_t;
		using format_tc = const format_t;
		using pxtype_tc = const pxtype_t;
	public:
		gfx_txr();
		gfx_txr(txr_tc& copy);
		gfx_txr(txr_t&& copy);
		virtual ~gfx_txr();
		// --getters
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline format_tc get_format() const { return m_format; }
		inline pxtype_tc get_pxtype() const { return m_pxtype; }
		inline cv1u get_slot() const { return m_slot; }
		// --setters
		txr_t& set_slot(cv1u slot);
		// --predicates
		inline v1bit has_slot(cv1u slot = NW_NULL) const { return m_slot == slot; }
		// --operators
		inline txr_t& operator=(txr_tc& copy) { gfx_img::operator=(copy); return *this; }
		inline txr_t& operator=(txr_t&& copy) { gfx_img::operator=(copy); return *this; }
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		virtual v1bit remake();
		virtual v1nil clear(ptr_tc data);
		virtual v1nil on_draw() override;
	protected:
		handle_t m_handle;
		format_t m_format;
		pxtype_t m_pxtype;
		v1u m_slot;
	};
}
#endif	// NW_GAPI
#endif // NW_GFX_TEXTURE_H
