#include "nw_gfx_pch.hpp"
#include "nw_gfx_txr.h"
#if (defined NW_GAPI)
#include "core/nw_gfx_engine.h"
#include "lib/nw_gfx_lib_txr.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	a_gfx_txr::a_gfx_txr(gfx_engine& graphics) :
		a_gfx_cmp(graphics), t_cmp(), gfx_img(),
		m_handle(NW_NULL),
		m_slot(NW_NULL),
		m_txr_fmt(NW_FMT_RGBA),
		m_pxl_fmt(NW_FMT_R8G8B8A8_U32)
	{
	}
	a_gfx_txr::~a_gfx_txr() { if (m_handle != 0) { glDeleteTextures(1, &m_handle); m_handle = 0; } }
	// --setters
	v1nil a_gfx_txr::set_slot(v1u slot) {
		m_slot = slot;
		m_smp->set_slot(slot);
	}
	v1nil a_gfx_txr::set_txr_fmt(txr_fmt format) {
		m_txr_fmt = format;
	}
	v1nil a_gfx_txr::set_pxl_fmt(txr_fmt format) {
		m_pxl_fmt = format;
	}
	v1nil a_gfx_txr::set_smp(smp_t& ref) {
		m_smp = ref;
	}
	// --operators
	// --==<core_methods>==--
	v1bit a_gfx_txr::load_file(cstr file_path)
	{
		img_bmp_info img;
		if (!io_sys::get().load_file(file_path, img)) { throw init_error(__FILE__, __LINE__); return NW_FALSE; }
		//if (!this->remake(img)) { return NW_FALSE; }

		return NW_TRUE;
	}
	v1bit a_gfx_txr::remake(img_tc& img)
	{
		//set_data(img);
		if (m_handle != NW_NULL) { glDeleteTextures(1u, &m_handle); m_handle = NW_NULL; }
		NW_CHECK(get_stride() >= 1 && get_stride() <= 4, "no format!", return NW_FALSE)

		return NW_TRUE;
	}
	v1nil a_gfx_txr::on_draw()
	{
		m_smp->set_slot(m_slot);
		m_smp->on_draw();
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	a_gfx_txr::a_gfx_txr(gfx_engine& graphics) :
		a_gfx_cmp(graphics), t_cmp(), gfx_img(),
		m_handle(NW_NULL),
		m_slot(NW_NULL),
		m_txr_fmt(convert<texture_formats, txr_fmt>(TXF_RGBA)),
		m_pxl_fmt(convert<pixel_formats, pxl_fmt>(PXF_R8G8B8A8_U32))
	{
	}
	a_gfx_txr::~a_gfx_txr()
	{
		if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; }
	}
	// --setters
	v1nil a_gfx_txr::set_slot(v1u slot) {
		m_slot = slot;
		m_smp->set_slot(slot);
	}
	v1nil a_gfx_txr::set_txr_fmt(txr_fmt format) {
		m_txr_fmt = format;
	}
	v1nil a_gfx_txr::set_pxl_fmt(pxl_fmt format) {
		m_pxl_fmt = format;
	}
	v1nil a_gfx_txr::set_smp(smp& ref) {
		m_smp = ref;
	}
	// --operators
	// --==<core_methods>==--
	v1bit a_gfx_txr::load_file(cstr file_path)
	{
		img_bmp img;
		if (!io_sys::get().load_file(file_path, img)) { throw init_error(__FILE__, __LINE__); return NW_FALSE; }
		if (!this->remake(img)) { return NW_FALSE; }

		return NW_TRUE;
	}
	v1bit a_gfx_txr::save_file(cstr file_path)
	{
		return NW_TRUE;
	}
	v1bit a_gfx_txr::remake(const gfx_img& img)
	{
		set_data(img);
		m_pxl_fmt = convert<v1s, pxl_fmt>(img.get_channels());
		m_txr_fmt = convert<v1s, txr_fmt>(img.get_channels());
		if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; }

		return NW_TRUE;
	}
	v1nil a_gfx_txr::on_draw() {
		m_smp->set_slot(m_slot);
		m_smp->on_draw();

		m_gfx->get_ctxh()->VSSetShaderResources(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->PSSetShaderResources(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->GSSetShaderResources(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->HSSetShaderResources(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->DSSetShaderResources(m_slot, 1u, &m_handle);
	}
	// --==</core_methods>==--
}
#endif
#endif	// NW_GAPI