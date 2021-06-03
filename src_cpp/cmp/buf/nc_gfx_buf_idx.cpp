#include "nc_gfx_pch.hpp"
#include "nc_gfx_buf_idx.hxx"
#if (defined NC_GAPI)
#	include "../../core/nc_nc_gfx_eng.hxx"
#	include "../../lib/nc_gfx_lib_info.hxx"
#	if (NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_buf_idx_t::gfx_buf_idx_t() : gfx_buf_t() { }
	gfx_buf_idx_t::gfx_buf_idx_t(layt_tc& layout, size_t count) : gfx_buf_idx_t() { NC_CHECK(remake(layout, count), "remake error!", return); }
	gfx_buf_idx_t::gfx_buf_idx_t(layt_tc& layout, size_t count, ptr_tc data) : gfx_buf_idx_t() { NC_CHECK(remake(layout, count, data), "remake error!", return); }
	gfx_buf_idx_t::gfx_buf_idx_t(gibuf_tc& copy) : gfx_buf_idx_t() { operator=(copy); }
	gfx_buf_idx_t::gfx_buf_idx_t(gibuf_t&& copy) : gfx_buf_idx_t() { operator=(copy); }
	gfx_buf_idx_t::~gfx_buf_idx_t() { }
	/* setters */
	gfx_buf_idx_t::buf_t& gfx_buf_idx_t::set_data(size_t key, ptr_tc data, size_t count) {
		gfx_buf_t::set_data(key, data, count);
		get_context()->buf_bind(GL_ELEMENT_ARRAY_BUFFER, get_handle());
		get_context()->buf_set_sub_data(GL_ELEMENT_ARRAY_BUFFER, get_stride() * key, get_stride() * count, get_data(get_stride() * key));
		return *this;
	}
	/* operators */
	nc_ostream_t& gfx_buf_idx_t::operator<<(nc_ostream_t& stm) const { gfx_buf_t::operator<<(stm); return stm; }
	nc_istream_t& gfx_buf_idx_t::operator>>(nc_istream_t& stm) { gfx_buf_t::operator>>(stm); return stm; }
	/* commands */
	v1bit_t gfx_buf_idx_t::remake()
	{
		NC_CHECK(gfx_buf_t::remake(), "remake error!", return NC_FALSE);

		get_context()->buf_bind(GL_ELEMENT_ARRAY_BUFFER, get_handle());
		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, get_space(), get_data(), has_data() ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW);
		get_context()->buf_set_data(GL_ELEMENT_ARRAY_BUFFER, get_space(), get_data(), GL_DYNAMIC_DRAW);
		
		return NC_TRUTH;
	}
	v1nil_t gfx_buf_idx_t::on_draw()
	{
		gfx_buf_t::on_draw();
		get_context()->buf_bind(GL_ELEMENT_ARRAY_BUFFER, get_handle());
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	gfx_buf_idx_t::gfx_buf_idx_t(nc_gfx_eng& graphics) :
		nc_cmp_tt(), gfx_buf_t(graphics),
		m_data_type(convert<value_types, data_type>(VTYPE_V1_U32))
	{
	}
	gfx_buf_idx_t::gfx_buf_idx_t(nc_gfx_eng& graphics, size nof_bytes, cptr buffer, ctype tid) :
		gfx_buf_idx_t(graphics)
	{
		if (!remake_bytes(nof_bytes, buffer, type)) { throw init_error(__FILE__, __LINE__); return; }
	}
	gfx_buf_idx_t::~gfx_buf_idx_t()
	{
	}
	/* setters */
	v1nil_t gfx_buf_idx_t::set_data_bytes(size nof_bytes, cptr buffer, size offset) {
		D3D11_MAPPED_SUBRESOURCE msub_rsc{ 0 };
		m_gfx->get_ctxh()->Map(m_handle, 0u, D3D11_MAP_WRITE_NO_OVERWRITE, 0u, &msub_rsc);
		memcpy(msub_rsc.pData, buffer, nof_bytes);
		m_gfx->get_ctxh()->Unmap(m_handle, 0u);
	}
	/* commands */
	v1bit_t gfx_buf_idx_t::remake_bytes(size nof_bytes, cptr buffer, ctype tid)
	{
		m_size = nof_bytes;
		m_stride = NC_GET_VTYPE_SIZE_D(type);
		m_data_type = convert<value_types, data_type>(type);
		if (m_handle != NC_NULL) { m_handle->Release(); m_handle = NC_NULL; }
		if (m_size <= 0) { return NC_FALSE; }

		D3D11_BUFFER_DESC buf_desc{ 0 };
		buf_desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		buf_desc.MiscFlags = 0u;
		buf_desc.StructureByteStride = m_stride;
		buf_desc.ByteWidth = nof_bytes;

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
	v1nil_t gfx_buf_idx_t::on_draw()
	{
		m_gfx->get_ctxh()->IASetIndexBuffer(m_handle, m_data_type, 0);
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NC_GAPI