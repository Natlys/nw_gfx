#ifndef NWG_SHADER_H
#define NWG_SHADER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_cmp.h>
#include "nwg_shd_rsc.h"
#include "nwg_shd_layt.h"
#include <cmp/buf/nwg_buf_shd.h>
namespace NW
{
	class NW_API a_shd : public t_cmp<a_shd>, public a_gfx_cmp, public a_data_cmp
	{
	public:
		using rsc = mem_ref<buf_shd>;
		using rscs = darray<rsc>;
#if (NW_GAPI & NW_GAPI_OGL)
		using handle = GLuint;
#endif
#if (NW_GAPI & NW_GAPI_DX)
		using handle = ID3DBlob*;
#endif
	public:
		a_shd(gfx_engine& graphics);
		virtual ~a_shd();
		// --getters
		inline cstr get_src_code() const	{ return &m_src_code[0]; }
		inline rsc& get_rsc(ui8 idx)		{ return m_rscs[idx % m_rscs.size()]; }
		inline handle get_handle()			{ return m_handle; }
		// --setters
		void add_rsc(rsc& ref);
		void rmv_rsc(ui8 idx);
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const = 0;
		virtual stm_in& operator>>(stm_in& stm) = 0;
		// --core_methods
		virtual bit remake(cstr source_code) = 0;
		virtual void on_draw() = 0;
	protected:
		handle m_handle;
		dstr m_src_code;
		rscs m_rscs;
	};
	extern NW_API bit gfx_get_err_log(shd_types shd_type, si32 shd_id);
}
#endif	// NW_GAPI
#endif // NWG_SHADER_H