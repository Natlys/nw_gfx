#include "nw_gfx_pch.hpp"
#include "nw_gfx_buf_vtx.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
#	include "../../lib/nw_gfx_lib_buf.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_buf_vtx::gfx_buf_vtx() : gfx_buf() { }
	gfx_buf_vtx::gfx_buf_vtx(layt_tc& layout, cv1u count, ptr_tc data) : gfx_buf(layout, count, data) {}
	gfx_buf_vtx::~gfx_buf_vtx() { }
	// --setters
	gfx_buf_vtx::buf_t& gfx_buf_vtx::set_data(cv1u key, ptr_tc data, cv1u count) {
		gfx_buf::set_data(key, data, count);
		glBufferSubData(GL_ARRAY_BUFFER, get_stride() * key, get_stride() * count, get_data(get_stride() * key));
		return *this;
	}
	// --==<core_methods>==--
	v1bit gfx_buf_vtx::remake()
	{
		NW_CHECK(gfx_buf::remake(), "remake error!", return NW_FALSE);

		glBindBuffer(GL_ARRAY_BUFFER, get_handle());
		//glBufferData(GL_ARRAY_BUFFER, get_space(), get_data(), has_data() ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW);
		glBufferData(GL_ARRAY_BUFFER, get_space(), get_data(), GL_DYNAMIC_DRAW);

		return NW_TRUE;
	}
	v1nil gfx_buf_vtx::on_draw()
	{
		glBindBuffer(GL_ARRAY_BUFFER, get_handle());
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_buf_vtx::gfx_buf_vtx(gfx_engine& graphics) :
		gfx_buf(graphics)
	{
	}
	gfx_buf_vtx::gfx_buf_vtx(gfx_engine& graphics, size nof_bytes, cptr buffer, size stride, size offset) :
		gfx_buf_vtx(graphics)
	{
		if (!remake_bytes(nof_bytes, buffer, stride, offset)) { throw init_error(__FILE__, __LINE__); return; }
	}
	gfx_buf_vtx::~gfx_buf_vtx()
	{
	}
	// --setters
	void gfx_buf_vtx::set_data_bytes(size nof_bytes, cptr buffer, size offset) {
		D3D11_MAPPED_SUBRESOURCE msub_rsc{ 0 };
		m_gfx->get_ctxh()->Map(m_handle, 0u, D3D11_MAP_WRITE_NO_OVERWRITE, 0u, &msub_rsc);
		memcpy(static_cast<ubyte*>(msub_rsc.pData) + m_offset + offset, buffer, nof_bytes);
		m_gfx->get_ctxh()->Unmap(m_handle, 0u);
	}
	// --==<core_methods>==--
	v1bit gfx_buf_vtx::remake_bytes(size nof_bytes, cptr buffer, size stride, size offset) {
		m_size = nof_bytes;
		m_stride = stride;
		m_offset = offset;
		if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; }
		if (m_size <= 0 || m_stride <= 0) { return NW_FALSE; }
		if (m_stride > m_size || m_offset >= m_size) { return NW_FALSE; }
		
		D3D11_BUFFER_DESC buf_desc{ 0 };
		buf_desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		buf_desc.MiscFlags = 0u;
		buf_desc.StructureByteStride = m_stride;
		buf_desc.ByteWidth = m_size;

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
	void gfx_buf_vtx::on_draw()
	{
		m_gfx->get_ctxh()->IASetVertexBuffers(0, 1, &m_handle, reinterpret_cast<UINT*>(&m_stride), reinterpret_cast<UINT*>(&m_offset));
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_D3D
#endif	// NW_GAPI