#include "nw_gfx_pch.hpp"
#include "nw_gfx_cmd.h"
#if (defined NW_GAPI)
#	include "../cmp/buf/nw_gfx_buf_vtx.h"
#	include "../cmp/buf/nw_gfx_buf_idx.h"
#	include "../lib/nw_gfx_lib_info.h"
#	include "nw_gfx_engine.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_cmd_buf::gfx_cmd_buf(gfx_engine& graphics) :
		a_gfx_rsc(graphics),
		m_list(NW_NULL)
	{
	}
	gfx_cmd_buf::~gfx_cmd_buf()
	{
		while (m_list != NW_NULL) {
		}
	}
	// --setters
	v1nil gfx_cmd_buf::add_cmd(vcmd_tc& command) {
		list_t* next_head = mem_sys::get().new_one<list_t>();
		next_head->m_link = m_list;
		next_head->m_data = mem_sys::get().new_one<vcmd_t>(command);
		m_list = next_head;
	}
	v1nil gfx_cmd_buf::add_cmd(icmd_tc& command) {
		list_t* next_head = mem_sys::get().new_one<list_t>();
		next_head->m_link = m_list;
		next_head->m_data = mem_sys::get().new_one<icmd_t>(command);
		m_list = next_head;
	}
	v1nil gfx_cmd_buf::rmv_cmd(cv1u key) {
	}
	// --==<core_methods>==--
	v1nil gfx_cmd_buf::on_draw()
	{
		while (m_list != NW_NULL) {
			switch (m_list->m_data->m_type) {
			case NW_GFX_CMD_VTX: {
				vcmd_t* vcmd = *m_list;
				NW_CHECK(vcmd->m_vbuf_first && (vcmd->m_vbuf_first < vcmd->m_vbuf_last), "no vertices!", return);
				GLuint vcount = 0u;
				for (gfx_buf_vtx* ivbuf = vcmd->m_vbuf_first; ivbuf < vcmd->m_vbuf_last; ivbuf++) {
					ivbuf->on_draw();
					vcount += ivbuf->get_count();
				}
				glDrawArrays(vcmd->m_prim, NW_NULL, vcount);
				mem_sys::get().del_one<vcmd_t>(vcmd);
				break;
			}
			case NW_GFX_CMD_IDX: {
				icmd_t* icmd = *m_list;
				NW_CHECK(icmd->m_vbuf_first && (icmd->m_vbuf_first < icmd->m_vbuf_last), "no vertices!", return);
				NW_CHECK(icmd->m_ibuf, "no indicies!", return);
				for (gfx_buf_vtx* ivbuf = icmd->m_vbuf_first; ivbuf < icmd->m_vbuf_last; ivbuf++) {
					ivbuf->on_draw();
				}
				gfx_buf_idx* ibuf = icmd->m_ibuf;
				ibuf->on_draw();
				const GLuint icount = ibuf->get_count();
				const GLenum itype =
					ibuf->get_stride() == 1u ? GL_UNSIGNED_BYTE :
					ibuf->get_stride() == 2u ? GL_UNSIGNED_SHORT :
					GL_UNSIGNED_INT;
				glDrawElements(icmd->m_prim, icount, itype, NW_NULL);
				mem_sys::get().del_one<icmd_t>(icmd);
				break;
			}
			default: NW_ERROR("undefined command!", return); break;
			}
			list_t* next_head = m_list->m_link;
			mem_sys::get().del_one<list_t>(m_list);
			m_list = next_head;
		}
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	//
}
#	endif	// GAPI_OGL
#endif	// NW_GAPI