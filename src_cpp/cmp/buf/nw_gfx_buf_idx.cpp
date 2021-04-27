#include "nw_gfx_pch.hpp"
#include "nw_gfx_buf_idx.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
#	include "../../lib/nw_gfx_lib_buf.h"
#	include "../../lib/nw_gfx_lib_info.h"
#if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_buf_idx::gfx_buf_idx() : gfx_buf() { }
	gfx_buf_idx::gfx_buf_idx(layt_tc& layout, cv1u count, ptr_tc data) : gfx_buf(layout, count, data) { }
	gfx_buf_idx::~gfx_buf_idx() { }
	// --setters
	gfx_buf_idx::buf_t& gfx_buf_idx::set_data(cv1u key, ptr_tc data, cv1u count) {
		gfx_buf::set_data(key, data, count);
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, get_stride() * key, get_stride() * count, get_data(get_stride() * key));
		return *this;
	}
	// --==<core_methods>==--
	v1bit gfx_buf_idx::remake() {
		NW_CHECK(gfx_buf::remake(), "remake error!", return NW_FALSE);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, get_handle());
		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, get_space(), get_data(), has_data() ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, get_space(), get_data(), GL_DYNAMIC_DRAW);
		
		return NW_TRUE;
	}
	v1nil gfx_buf_idx::on_draw()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, get_handle());
	}
	// --==</core_methods>==--
}
#endif
#if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_buf_idx::gfx_buf_idx(gfx_engine& graphics) :
		t_cmp(), gfx_buf(graphics),
		m_data_type(convert<value_types, data_type>(VTYPE_V1_U32))
	{
	}
	gfx_buf_idx::gfx_buf_idx(gfx_engine& graphics, size nof_bytes, cptr buffer, ctype tid) :
		gfx_buf_idx(graphics)
	{
		if (!remake_bytes(nof_bytes, buffer, type)) { throw init_error(__FILE__, __LINE__); return; }
	}
	gfx_buf_idx::~gfx_buf_idx()
	{
	}
	// --setters
	v1nil gfx_buf_idx::set_data_bytes(size nof_bytes, cptr buffer, size offset) {
		D3D11_MAPPED_SUBRESOURCE msub_rsc{ 0 };
		m_gfx->get_ctxh()->Map(m_handle, 0u, D3D11_MAP_WRITE_NO_OVERWRITE, 0u, &msub_rsc);
		memcpy(msub_rsc.pData, buffer, nof_bytes);
		m_gfx->get_ctxh()->Unmap(m_handle, 0u);
	}
	// --==<core_methods>==--
	v1bit gfx_buf_idx::remake_bytes(size nof_bytes, cptr buffer, ctype tid)
	{
		m_size = nof_bytes;
		m_stride = NW_GET_VTYPE_SIZE_D(type);
		m_data_type = convert<value_types, data_type>(type);
		if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; }
		if (m_size <= 0) { return NW_FALSE; }

		D3D11_BUFFER_DESC buf_desc{ 0 };
		buf_desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		buf_desc.MiscFlags = 0u;
		buf_desc.StructureByteStride = m_stride;
		buf_desc.ByteWidth = nof_bytes;

		if (buffer == NW_NULL) {
			buf_desc.Usage = D3D11_USAGE_DYNAMIC;
			buf_desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
			m_gfx->get_dvch()->CreateBuffer(&buf_desc, NW_NULL, &m_handle);
		}
		else {
			buf_desc.Usage = D3D11_USAGE_DEFAULT;
			buf_desc.CPUAccessFlags = 0u;
			D3D11_SUBRESOURCE_DATA sub_data{ 0 };
			sub_data.pSysMem = buffer;
			m_gfx->get_dvch()->CreateBuffer(&buf_desc, &sub_data, &m_handle);
		}

		if (m_handle == NW_NULL) { throw init_error(__FILE__, __LINE__); return NW_FALSE; }
		return NW_TRUE;
	}
	v1nil gfx_buf_idx::on_draw()
	{
		m_gfx->get_ctxh()->IASetIndexBuffer(m_handle, m_data_type, 0);
	}
	// --==</core_methods>==--
}
#endif
#endif	// NW_GAPI