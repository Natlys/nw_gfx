#ifndef NW_GFX_SHADER_H
#define NW_GFX_SHADER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../txr/nw_gfx_txr.h"
#	include "../buf/nw_gfx_buf_shd.h"
#	include "../nw_gfx_cmp.h"
namespace NW
{
	class NW_API a_gfx_shd : public t_cmp<a_gfx_shd>, public a_gfx_cmp, public a_iop_cmp
	{
	public:
		using txr_t = mem_ref<a_gfx_txr>;
		using txr_tc = const txr_t;
		using buf_t = mem_ref<gfx_buf_shd>;
		using buf_tc = const buf_t;
		using txrs_t = t_darray<txr_t>;
		using txrs_tc = const txrs_t;
		using bufs_t = t_darray<buf_t>;
		using bufs_tc = const bufs_t;
		using source_t = dstr_t;
		using source_tc = const source_t;
#	if (NW_GAPI & NW_GAPI_OGL)
		using handle_t = GLuint;
#	endif
#		if (NW_GAPI & NW_GAPI_D3D)
		using handle_t = ID3DBlob*;
#	endif
		using handle_tc = const handle_t;
	public:
		a_gfx_shd();
		a_gfx_shd(source_tc& source_code);
		virtual ~a_gfx_shd();
		// --getters
		inline handle_t& get_handle()        { return m_handle; }
		inline handle_tc& get_handle() const { return m_handle; }
		inline source_t& get_source()        { return m_source; }
		inline source_tc& get_source() const { return m_source; }
		inline bufs_t& get_bufs(cv1u idx) { return m_bufs; }
		inline buf_t& get_buf(cv1u idx)   { return m_bufs[idx % m_bufs.size()]; }
		// --setters
		v1nil set_source(source_tc& source_code);
		v1nil set_buf(buf_t& ref, cv1u idx = 0);
		v1nil set_txr(txr_t& ref, cv1u idx = 0);
		// --operators
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		virtual v1bit remake();
		inline v1bit remake(source_tc source_code) { set_source(source_code); return remake(); }
		virtual v1nil on_draw() override;
	protected:
		handle_t m_handle;
		source_t m_source;
		bufs_t m_bufs;
		txrs_t m_txrs;
	};
}
#endif	// NW_GAPI
#endif // NW_GFX_SHADER_H
