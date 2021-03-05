#include <nwg_pch.hpp>
#include "nwg_frame_buf.h"
#if (defined NWG_GAPI)
#include <cmp/nwg_texture.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
#include <lib/nwg_ogl_v1.h>
#include <lib/nwg_ogl_v2.h>
#include <lib/nwg_ogl_arb.h>
namespace NWG
{
	frame_buf::frame_buf(gfx_engine& graphics, cstring name) :
		t_gfx_cmp(graphics), a_data_res(name),
		m_info(frame_buf_info()),
		m_ogl_id(0) { }
	frame_buf::~frame_buf() { if (m_ogl_id != 0) { glDeleteFramebuffers(1, &m_ogl_id); m_ogl_id = 0; } }
	// --setters
	void frame_buf::set_viewport(const v4si32& viewport_rect) { m_info.viewport = viewport_rect; }
	void frame_buf::set_clear_color(const v4f32& clear_color) { m_info.clear_color = clear_color; }
	void frame_buf::attach(mem_ref<a_texture>& ref) { m_atchs.push_back(ref); }
	void frame_buf::detach(ui8 idx) { m_atchs.erase(m_atchs.begin() + idx); }
	// --==<core_methods>==--
	void frame_buf::on_draw() {
		glBindFramebuffer(GL_FRAMEBUFFER, m_ogl_id);
		glViewport(0, 0, get_size_x(), get_size_y());
	}
	void frame_buf::remake(const frame_buf_info& info)
	{
		if (m_ogl_id != 0) { glDeleteFramebuffers(1, &m_ogl_id); m_ogl_id = 0; }
		if (get_size_x() < 1 || get_size_y() < 1) { return; }

		glGenFramebuffers(1, &m_ogl_id);
		glBindFramebuffer(GL_FRAMEBUFFER, m_ogl_id);

		m_info.color_ids.clear();
		m_info.has_depth = false;
		m_info.has_stencil = false;

		for (si32 txi = 0; txi < m_atchs.size(); txi++) {
			if (!m_atchs[txi].is_valid()) { throw error("null attachment!"); detach(txi); }
			auto& atch = *m_atchs[txi];
			texture_info txr_info = atch.get_info();
			txr_info.size_x = get_size_x();
			txr_info.size_y = get_size_y();
			atch.remake(txr_info);
			glBindTexture(GL_TEXTURE_2D, atch.get_ogl_id());
			si32 unAttachType = 0;
			if (txr_info.pxl_format== PXF_R32_SINT32 || txr_info.pxl_format == PXF_R32_UINT32 ||
				txr_info.pxl_format== PXF_R8G8B8_SINT32 || txr_info.pxl_format == PXF_R8G8B8_UINT32 ||
				txr_info.pxl_format== PXF_R8G8B8A8_SINT32 || txr_info.pxl_format== PXF_R8G8B8A8_UINT32)
			{
				unAttachType = GL_COLOR_ATTACHMENT0 + m_info.color_ids.size();
				m_info.color_ids.push_back(atch.get_ogl_id());
			}
			else if (txr_info.pxl_format== PXF_D32_SINT32 || txr_info.pxl_format== PXF_D32_UINT32) {
				m_info.has_depth = true;
				unAttachType = GL_DEPTH_ATTACHMENT;
			}
			else if (txr_info.pxl_format== PXF_S8_SINT8 || txr_info.pxl_format== PXF_S8_UINT8) {
				m_info.has_stencil = true;
				unAttachType = GL_STENCIL_ATTACHMENT;
			}
			else if (txr_info.pxl_format== PXF_D24S8_SINT32 || txr_info.pxl_format== PXF_D24S8_UINT32) {
				m_info.has_depth = m_info.has_stencil = true;
				unAttachType = GL_DEPTH_STENCIL_ATTACHMENT;
			}
			glFramebufferTexture2D(GL_FRAMEBUFFER, unAttachType, convert_enum<texture_types, si32>(atch.get_txr_type()), atch.get_ogl_id(), 0);
		}
		if (m_info.color_ids.size() > 0) { glDrawBuffers(m_info.color_ids.size(), &m_info.color_ids[0]); }
		else { glDrawBuffer(GL_NONE); }

		bool bIsCompleted = glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
		NWL_ASSERT(bIsCompleted, "framebufOgl is not created!");
	}
	void frame_buf::clear() {
		ui32 mask = 0;
		mask |= m_info.color_ids.size() > 0 ? GL_COLOR_BUFFER_BIT : 0u;
		mask |= m_info.has_depth ? GL_DEPTH_BUFFER_BIT : 0u;
		mask |= m_info.has_stencil ? GL_STENCIL_BUFFER_BIT : 0u;
		glClearColor(m_info.clear_color[0], m_info.clear_color[1], m_info.clear_color[2], m_info.clear_color[3]);
		glClear(mask);
	}

	void frame_buf::read_pixels(ptr data_ptr, ui8 attach_idx, const v4si32& read_rect)
	{
		const texture_info& txr_info = get_attachment(attach_idx)->get_info();
		glReadBuffer(GL_COLOR_ATTACHMENT0 + attach_idx);
		// --error is guaranteed, internal and usual formats are different
		glReadPixels(read_rect[0], read_rect[1], read_rect[2], read_rect[3],
			convert_enum<pixel_formats, ui32>(txr_info.pxl_format),
			convert_enum<pixel_formats, si32>(txr_info.pxl_format), data_ptr);
	}
	void frame_buf::draw_pixels(ptr data_ptr, ui8 attach_idx, const v4si32& draw_rect)
	{
		const texture_info& txr_info = get_attachment()->get_info();
		glDrawBuffer(GL_COLOR_ATTACHMENT0 + attach_idx);
		glDrawPixels(draw_rect[2], draw_rect[3],
			convert_enum<pixel_formats, ui32>(txr_info.pxl_format),
			convert_enum<pixel_formats, ui32>(txr_info.pxl_format), data_ptr);
	}
	// --==</core_methods>==--
	// --==<data_methods>==--
	bit frame_buf::save_file(cstring file_path) { return true; }
	bit frame_buf::load_file(cstring file_path) { return true; }
	// --==</data_methods>==--
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NWG
{
	framebuf::framebuf(gfx_engine& graphics, const char* name, const framebufInfo& info) :
		a_gfx_cmp(graphics), a_data_res(name),
		m_info(info),
		m_rgbaClear{ 0.5f, 0.5f, 0.5f, 1.0f } { }
	framebuf::~framebuf() { }
	// --setters
	void framebuf::SetViewport(V4i rectViewport) { m_info.rectViewport = rectViewport; }
	void framebuf::SetClearColor(V4f rgbaClear) { m_rgbaClear = rgbaClear; }
	void framebuf::AttachTexture(a_texture& rTex) { m_Attachments.push_back(mem_ref<a_texture>{ *ent_sys::GetEnt<a_texture>(rTex.GetEntId()) }); }
	void framebuf::DetachTexture(si32 idx) { m_Attachments.erase(m_Attachments.begin() + idx); }
	// --==<core_methods>==--
	void framebuf::Bind() {
	}
	void framebuf::Remake()
	{
	}
	void framebuf::Clear() {
	}

	void framebuf::ReadPixels(Ptr pData, si32 unAttachIdx, si32 nX, si32 nY, si32 nW, si32 nH)
	{
	}
	void framebuf::WritePixels(Ptr pData, si32 unAttachIdx, si32 nX, si32 nY, si32 nW, si32 nH)
	{
	}
	// --==</core_methods>==--
	// --==<data_methods>==--
	bool framebuf::SaveF(const char* file_path) { return true; }
	bool framebuf::LoadF(const char* file_path) { return true; }
	// --==</data_methods>==--
}
#endif
#endif // NWG_GAPI