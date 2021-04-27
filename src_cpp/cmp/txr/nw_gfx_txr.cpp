#include "nw_gfx_pch.hpp"
#include "nw_gfx_txr.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
#	include "../../lib/nw_gfx_lib_txr.h"
#	include "../../lib/nw_gfx_lib_info.h"
#	include "../img/nw_gfx_img.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_txr::gfx_txr() : t_cmp(), a_gfx_cmp(), m_handle(NW_NULL), m_format(NW_NULL), m_pxtype(NW_NULL), m_slot(NW_NULL) { }
	gfx_txr::gfx_txr(txr_tc& copy) : gfx_txr() { operator=(copy); }
	gfx_txr::gfx_txr(txr_t&& copy) : gfx_txr() { operator=(copy); }
	gfx_txr::~gfx_txr() { if (m_handle != NW_NULL) { glDeleteTextures(1u, &m_handle); m_handle = NW_NULL; } }
	// --setters
	gfx_txr::txr_t& gfx_txr::set_slot(cv1u slot) { m_slot = slot; return *this; }
	// --operators
	op_stream_t& gfx_txr::operator<<(op_stream_t& stm) const {
		gfx_img::operator<<(stm);
		return stm;
	}
	ip_stream_t& gfx_txr::operator>>(ip_stream_t& stm) {
		gfx_img::operator>>(stm);
		return stm;
	}
	// --==<core_methods>==--
	v1bit gfx_txr::remake()
	{
		NW_CHECK(gfx_img::remake(), "remake error!", return NW_FALSE);
		if (m_handle != NW_NULL) { glDeleteTextures(1u, &m_handle); m_handle = NW_NULL; }
		
		m_format = gfx_info::get_img_fmt(gfx_img::get_layt().get_type());
		m_pxtype = gfx_info::get_type(gfx_img::get_layt().get_type());

		glGenTextures(1u, &m_handle);

		return NW_TRUE;
	}
	v1nil gfx_txr::clear(ptr_tc data)
	{
		glClearTexImage(get_handle(), 0, get_format(), get_pxtype(), data);
	}
	v1nil gfx_txr::on_draw()
	{
		glActiveTexture(GL_TEXTURE0 + get_slot());
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_txr::gfx_txr(gfx_engine& graphics) :
		a_gfx_cmp(graphics), t_cmp(), gfx_img(),
		m_handle(NW_NULL),
		m_slot(NW_NULL),
		m_txr_fmt(convert<texture_formats, txr_fmt>(TXF_RGBA)),
		m_pxl_fmt(convert<pixel_formats, pxl_fmt>(PXF_R8G8B8A8_U32))
	{
	}
	gfx_txr::~gfx_txr()
	{
		if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; }
	}
	// --setters
	v1nil gfx_txr::set_slot(v1u slot) {
		m_slot = slot;
		m_smp->set_slot(slot);
	}
	v1nil gfx_txr::set_txr_fmt(txr_fmt format) {
		m_txr_fmt = format;
	}
	v1nil gfx_txr::set_pxl_fmt(pxl_fmt format) {
		m_pxl_fmt = format;
	}
	v1nil gfx_txr::set_smp(smp& ref) {
		m_smp = ref;
	}
	// --operators
	// --==<core_methods>==--
	v1bit gfx_txr::load_file(cstr file_path)
	{
		img_bmp img;
		if (!iop_sys::get().load_file(file_path, img)) { throw init_error(__FILE__, __LINE__); return NW_FALSE; }
		if (!this->remake(img)) { return NW_FALSE; }

		return NW_TRUE;
	}
	v1bit gfx_txr::save_file(cstr file_path)
	{
		return NW_TRUE;
	}
	v1bit gfx_txr::remake(const gfx_img& img)
	{
		set_data(img);
		m_pxl_fmt = convert<v1s, pxl_fmt>(img.get_channels());
		m_txr_fmt = convert<v1s, txr_fmt>(img.get_channels());
		if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; }

		return NW_TRUE;
	}
	v1nil gfx_txr::on_draw() {
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
#	endif	// GAPI_D3D
#endif	// NW_GAPI