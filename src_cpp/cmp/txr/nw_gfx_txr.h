#ifndef NW_GFX_TEXTURE_H
#define NW_GFX_TEXTURE_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../img/nw_gfx_img.h"
#	include "nw_gfx_txr_smp.h"
namespace NW
{
	/// abstarct texture_component class
	/// description:
	class NW_API a_gfx_txr : public t_cmp<a_gfx_txr>, public a_gfx_cmp, public gfx_img
	{
	public:
		using txr_t = a_gfx_txr;
		using txr_tc = const txr_t;
		using img_t = gfx_img;
		using img_tc = const img_t;
		using smp_t = mem_ref<gfx_txr_smp>;
		using smp_tc = const smp_t;
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
		a_gfx_txr();
		a_gfx_txr(txr_tc& copy);
		a_gfx_txr(txr_t&& copy);
		virtual ~a_gfx_txr();
		// --getters
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline format_tc get_format() const { return m_format; }
		inline pxtype_tc get_pxtype() const { return m_pxtype; }
		inline cv1u get_slot() const   { return m_slot; }
		inline smp_t& get_smp()        { return m_smp; }
		inline smp_tc& get_smp() const { return m_smp; }
		// --setters
		v1nil set_slot(cv1u slot);
		v1nil set_smp(smp_t& ref);
		// --predicates
		inline v1bit has_slot(cv1u slot = NW_NULL) const { return m_slot == slot; }
		inline v1bit has_smp() const { return m_smp.is_valid(); }
		// --operators
		inline v1nil operator=(txr_tc& copy);
		inline v1nil operator=(txr_t&& copy);
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
		smp_t m_smp;
	};
}
#endif	// NW_GAPI
#endif // NW_GFX_TEXTURE_H
