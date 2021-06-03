#include "nc_gfx_pch.hpp"
#include "nc_gfx_buf_shd.hxx"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.hxx"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_buf_shd_t::gfx_buf_shd_t() : gfx_buf_t(), m_slot(NC_NULL) { }
	gfx_buf_shd_t::gfx_buf_shd_t(layt_tc& layout, size_t count) : gfx_buf_shd_t() { NC_CHECK(remake(layout, count), "remake error!", return); }
	gfx_buf_shd_t::gfx_buf_shd_t(layt_tc& layout, size_t count, ptr_tc data) : gfx_buf_shd_t() { NC_CHECK(remake(layout, count, data), "remake error!", return); }
	gfx_buf_shd_t::gfx_buf_shd_t(gsbuf_tc& copy) : gfx_buf_shd_t() { operator=(copy); }
	gfx_buf_shd_t::gfx_buf_shd_t(gsbuf_t&& copy) : gfx_buf_shd_t() { operator=(copy); }
	gfx_buf_shd_t::~gfx_buf_shd_t() { }
	/* setters */
	gfx_buf_shd_t::gsbuf_t& gfx_buf_shd_t::set_slot(v1u_tc slot) { m_slot = slot; return *this; }
	gfx_buf_shd_t::buf_t& gfx_buf_shd_t::set_data(size_t key, ptr_tc data, size_t count) {
		gfx_buf_t::set_data(key, data, count);
		get_context()->buf_bind(GL_UNIFORM_BUFFER, get_handle());
		get_context()->buf_set_sub_data(GL_UNIFORM_BUFFER, get_stride() * key, get_stride() * count, get_data(get_stride() * key));
		return *this;
	}
	/* operators */
	nc_ostream_t& gfx_buf_shd_t::operator<<(nc_ostream_t& stm) const { gfx_buf_t::operator<<(stm); return stm; }
	nc_istream_t& gfx_buf_shd_t::operator>>(nc_istream_t& stm) { gfx_buf_t::operator>>(stm); return stm; }
	/* commands */
	v1bit_t gfx_buf_shd_t::remake()
	{
		NC_CHECK(gfx_buf_t::remake(), "remake error!", return NC_FALSE);
		
		get_context()->buf_bind(GL_UNIFORM_BUFFER, get_handle());
		//glBufferData(GL_UNIFORM_BUFFER, get_space(), get_data(), has_data() ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW);
		get_context()->buf_set_data(GL_UNIFORM_BUFFER, get_space(), get_data(), GL_DYNAMIC_DRAW);
		
		return NC_TRUTH;
	}
	v1nil_t gfx_buf_shd_t::on_draw()
	{
		gfx_buf_t::on_draw();
		get_context()->buf_bind(GL_UNIFORM_BUFFER, get_handle());
		get_context()->buf_bind_base(GL_UNIFORM_BUFFER, get_slot(), get_handle());
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	gfx_buf_shd_t::gfx_buf_shd_t(nc_gfx_eng& graphics) :
		nc_cmp_tt(), gfx_buf_t(graphics),
		m_slot(NC_NULL)
	{
	}
	gfx_buf_shd_t::gfx_buf_shd_t(nc_gfx_eng& graphics, size nof_bytes, cptr buffer, size offset) :
		gfx_buf_shd_t(graphics)
	{
		if (!remake_bytes(nof_bytes, buffer, offset)) { throw init_error(__FILE__, __LINE__); }
	}
	gfx_buf_shd_t::~gfx_buf_shd_t()
	{
	}
	/* setters */
	void gfx_buf_shd_t::set_slot(v1u_t bind_slot) {
		m_slot = bind_slot;
	}
	void gfx_buf_shd_t::set_offset(size offset) {
		m_offset = offset;
	}
	void gfx_buf_shd_t::set_data_bytes(size nof_bytes, cptr buffer, size offset) {
		D3D11_MAPPED_SUBRESOURCE msub_res{ 0 };
		m_gfx->get_ctxh()->Map(m_handle, 0u, D3D11_MAP_WRITE_NO_OVERWRITE, 0u, &msub_res);
		memcpy(static_cast<ubyte*>(msub_res.pData) + m_offset + offset, buffer, nof_bytes);
		m_gfx->get_ctxh()->Unmap(m_handle, 0u);
	}
	/* commands */
	v1bit_t gfx_buf_shd_t::remake_bytes(size nof_bytes, cptr buffer, size offset)
	{
		m_size = nof_bytes;
		m_offset = offset;
		m_stride = nof_bytes;
		if (m_handle != NC_NULL) { m_handle->Release(); m_handle = NC_NULL; }
		if (m_size <= 0) { return NC_FALSE; }
		if (m_offset >= m_size || m_elems.size() == 0) { return NC_FALSE; }

		D3D11_BUFFER_DESC buf_desc{ 0 };
		buf_desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		buf_desc.MiscFlags = 0u;
		buf_desc.StructureByteStride = m_size;
		buf_desc.ByteWidth = m_size;

		if (buffer == NC_NULL) {
			buf_desc.Usage = D3D11_USAGE_DYNAMIC;
			buf_desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
			m_gfx->get_dvch()->CreateBuffer(&buf_desc, NC_NULL, &m_handle);
		}
		else {
			buf_desc.Usage = D3D11_USAGE_DEFAULT;
			buf_desc.CPUAccessFlags = 0u;
			D3D11_SUBRESOURCE_DATA sub_data{ 0 };
			sub_data.pSysMem = buffer;
			m_gfx->get_dvch()->CreateBuffer(&buf_desc, &sub_data, &m_handle);
		}

		if (m_handle == NC_NULL) { throw init_error(__FILE__, __LINE__); return NC_FALSE; }
		return NC_TRUTH;
	}
	void gfx_buf_shd_t::on_draw()
	{
		m_gfx->get_ctxh()->VSSetConstantBuffers(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->PSSetConstantBuffers(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->GSSetConstantBuffers(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->HSSetConstantBuffers(m_slot, 1u, &m_handle);
		m_gfx->get_ctxh()->DSSetConstantBuffers(m_slot, 1u, &m_handle);
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NC_GAPI