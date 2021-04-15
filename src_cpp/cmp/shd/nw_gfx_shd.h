#ifndef NW_GFX_SHADER_H
#define NW_GFX_SHADER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#include "../nw_gfx_cmp.h"
#include "..//txr/nw_gfx_txr.h"
#include "../buf/nw_gfx_buf_shd.h"
namespace NW
{
	class NW_API a_gfx_shd : public t_cmp<a_gfx_shd>, public a_gfx_cmp, public a_io_cmp
	{
	public:
		using txr = mem_ref<a_gfx_txr>;
		using buf = mem_ref<gfx_buf_shd>;
		using txrs = darray<txr>;
		using bufs = darray<buf>;
#if (NW_GAPI & NW_GAPI_OGL)
		using handle_t = GLuint;
#endif
#if (NW_GAPI & NW_GAPI_D3D)
		using handle_t = ID3DBlob*;
#endif
		using handle_tc = const handle_t;
	public:
		a_gfx_shd(gfx_engine& graphics);
		virtual ~a_gfx_shd();
		// --getters
		inline cstr get_src_code() const { return &m_src_code[0]; }
		inline bufs& get_bufs(v1u idx)   { return m_bufs; }
		inline buf& get_buf(v1u idx)     { return m_bufs[idx % m_bufs.size()]; }
		inline handle_t get_handle()        { return m_handle; }
		inline handle_tc get_handle() const { return m_handle; }
		// --setters
		void set_buf(buf& ref, v1u idx = 0);
		void set_txr(txr& ref, v1u idx = 0);
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const = 0;
		virtual stm_in& operator>>(stm_in& stm) = 0;
		// --core_methods
		virtual v1bit remake(cstr source_code);
		virtual v1nil on_draw() override;
	protected:
		handle_t m_handle;
		dstr m_src_code;
		bufs m_bufs;
		txrs m_txrs;
	};
}
#endif	// NW_GAPI
#endif // NW_GFX_SHADER_H
