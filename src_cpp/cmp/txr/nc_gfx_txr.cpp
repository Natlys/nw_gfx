#include "nc_gfx_pch.hpp"
#include "nc_gfx_txr.hxx"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.hxx"
#	include "../../lib/nc_gfx_lib_info.hxx"
#	include "../img/nc_gfx_img.hxx"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_txr_t::gfx_txr_t() : nc_cmp_tt(), gfx_cmp_t(), m_handle(NC_NULL), m_format(NC_NULL), m_pxtype(NC_NULL), m_slot(NC_NULL) { }
	gfx_txr_t::gfx_txr_t(txr_tc& copy) : gfx_txr_t() { operator=(copy); }
	gfx_txr_t::gfx_txr_t(txr_t&& copy) : gfx_txr_t() { operator=(copy); }
	gfx_txr_t::~gfx_txr_t() { if (m_handle != NC_NULL) { get_context()->txr_del(1u, &m_handle); m_handle = NC_NULL; } }
	/* setters */
	gfx_txr_t::txr_t& gfx_txr_t::set_slot(v1u_tc slot) { m_slot = slot; return *this; }
	/* operators */
	nc_ostream_t& gfx_txr_t::operator<<(nc_ostream_t& stm) const {
		gfx_img_t::operator<<(stm);
		return stm;
	}
	nc_istream_t& gfx_txr_t::operator>>(nc_istream_t& stm) {
		gfx_img_t::operator>>(stm);
		return stm;
	}
	/* commands */
	v1bit_t gfx_txr_t::remake()
	{
		NC_CHECK(gfx_img_t::remake(), "remake error!", return NC_FALSE);
		if (m_handle != NC_NULL) { get_context()->txr_del(1u, &m_handle); m_handle = NC_NULL; }
		
		m_format = gfx_info_t::get_img_fmt(gfx_img_t::get_layt().get_type());
		m_pxtype = gfx_info_t::get_type(gfx_img_t::get_layt().get_type());

		get_context()->txr_new(1u, &m_handle);

		return NC_TRUTH;
	}
	v1nil_t gfx_txr_t::clear(ptr_tc data)
	{
		get_context()->txr_clear(get_handle(), 0, get_format(), get_pxtype(), data);
	}
	v1nil_t gfx_txr_t::on_draw()
	{
		get_context()->txr_active(GL_TEXTURE0 + get_slot());
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	gfx_txr_t::gfx_txr_t(nc_gfx_eng& graphics) :
		gfx_cmp_t(graphics), nc_cmp_tt(), gfx_img_t(),
		m_handle(NC_NULL),
		m_slot(NC_NULL),
		m_txr_fmt(convert<texture_formats, txr_fmt>(TXF_RGBA)),
		m_pxl_fmt(convert<pixel_formats, pxl_fmt>(PXF_R8G8B8A8_U32))
	{
	}
	gfx_txr_t::~gfx_txr_t()
	{
		if (m_handle != NC_NULL) { m_handle->Release(); m_handle = NC_NULL; }
	}
	/* setters */
	v1nil_t gfx_txr_t::set_slot(v1u_t slot) {
		m_slot = slot;
		m_smp->set_slot(slot);
	}
	v1nil_t gfx_txr_t::set_txr_fmt(txr_fmt format) {
		m_txr_fmt = format;
	}
	v1nil_t gfx_txr_t::set_pxl_fmt(pxl_fmt format) {
		m_pxl_fmt = format;
	}
	v1nil_t gfx_txr_t::set_smp(smp& ref) {
		m_smp = ref;
	}
	/* operators */
	/* commands */
	v1bit_t gfx_txr_t::load_file(cstr file_path)
	{
		img_bmp img;
		if (!iop_sys::get().load_file(file_path, img)) { throw init_error(__FILE__, __LINE__); return NC_FALSE; }
		if (!this->remake(img)) { return NC_FALSE; }

		return NC_TRUTH;
	}
	v1bit_t gfx_txr_t::save_file(cstr file_path)
	{
		return NC_TRUTH;
	}
	v1bit_t gfx_txr_t::remake(const gfx_img_t& img)
	{
		set_data(img);
		m_pxl_fmt = convert<v1s_t, pxl_fmt>(img.get_channels());
		m_txr_fmt = convert<v1s_t, txr_fmt>(img.get_channels());
		if (m_handle != NC_NULL) { m_handle->Release(); m_handle = NC_NULL; }

		return NC_TRUTH;
	}
	v1nil_t gfx_txr_t::on_draw() {
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
#endif	// NC_GAPI