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
		using smp_t = mem_ref<gfx_txr_smp>;
		using smp_tc = const smp_t;
#if (NW_GAPI & NW_GAPI_OGL)
		using handle_t = GLuint;
		using txr_fmt = GLenum;
		using pxl_fmt = GLenum;
		using vtype_t = GLenum;
#endif
#if (NW_GAPI & NW_GAPI_D3D)
		using handle_t = ID3D11ShaderResourceView*;
		using txr_fmt = DXGI_FORMAT;
		using pxl_fmt = DXGI_FORMAT;
		using vtype_t = DXGI_FORMAT;
#endif
		using handle_tc = const handle_t;
	public:
		a_gfx_txr(gfx_engine& graphics);
		virtual ~a_gfx_txr();
		// --getters
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		inline cv1u get_slot() const        { return m_slot; }
		inline txr_fmt get_txr_fmt() const  { return m_txr_fmt; }
		inline pxl_fmt get_pxl_fmt() const  { return m_pxl_fmt; }
		inline vtype_t get_vtype() const    { return m_vtype; }
		inline smp_t& get_smp()        { return m_smp; }
		inline smp_tc& get_smp() const { return m_smp; }
		// --setters
		v1nil set_slot(v1u slot);
		v1nil set_txr_fmt(txr_fmt format);
		v1nil set_pxl_fmt(pxl_fmt format);
		v1nil set_smp(smp_t& ref);
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const = 0;
		virtual stm_in& operator>>(stm_in& stm) = 0;
		// --core_methods
		v1bit load_file(cstr file_path);
		v1bit save_file(cstr file_path);
		virtual v1b remake(img_tc& img);
		virtual v1nil clear(ptr_tc buffer) = 0;
		virtual v1nil on_draw() override;
	protected:
		handle_t m_handle;
		v1u m_slot;
		txr_fmt m_txr_fmt;
		pxl_fmt m_pxl_fmt;
		vtype_t m_vtype;
		smp_t m_smp;
	};
}
#endif	// NW_GAPI
#endif // NW_GFX_TEXTURE_H
