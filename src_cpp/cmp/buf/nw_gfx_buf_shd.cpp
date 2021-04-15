#include "nw_gfx_pch.hpp"
#include "nw_gfx_buf_shd.h"
#if (defined NW_GAPI)
#	include "../../core/nw_gfx_engine.h"
#	include "../../lib/nw_gfx_lib_buf.h"
#	if (NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_buf_shd::gfx_buf_shd(gfx_engine& graphics) :
		a_gfx_buf(graphics),
		m_slot(NW_NULL)
	{
	}
	gfx_buf_shd::~gfx_buf_shd()
	{
	}
	// --setters
	v1nil gfx_buf_shd::set_slot(cv1u slot) {
		m_slot = slot;
	}
	v1nil gfx_buf_shd::set_data(cv1u count, ptr_tc data, cv1u offset) {
		a_gfx_buf::set_data(count, data, offset);
		glBufferSubData(GL_UNIFORM_BUFFER, get_stride() * offset, get_stride() * count, get_byte(get_stride() * offset));
	}
	// --==<core_methods>==--
	v1bit gfx_buf_shd::remake(cv1u stride, cv1u count, ptr_tc data)
	{
		NW_CHECK(mem_layt::remake(NW_NULL, NW_NULL), "failed remake!", return NW_FALSE);
		NW_CHECK(mem_layt::get_size() == stride, "stride has to be equal to the layout size!", return NW_FALSE);
		NW_CHECK(a_gfx_buf::remake(stride, count, data), "failed remake!", return NW_FALSE);
		NW_CHECK(mem_layt::remake(mem_buf::get_bytes(), NW_NULL), "failed remake!", return NW_FALSE);

		glBindBuffer(GL_UNIFORM_BUFFER, get_handle());
		glBufferData(GL_UNIFORM_BUFFER, get_space(), data, data ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW);
		
		return NW_TRUE;
	}
	v1nil gfx_buf_shd::on_draw()
	{
		glBindBuffer(GL_UNIFORM_BUFFER, get_handle());
		glBindBufferRange(GL_UNIFORM_BUFFER, get_slot(), get_handle(), get_offset(), get_space());
	}
	// --==</core_methods>==--
}
#	endif	// GAPI_OGL
#	if (NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_buf_shd::gfx_buf_shd(gfx_engine& graphics) :
		t_cmp(), a_gfx_buf(graphics),
		m_slot(NW_NULL)
	{
	}
	gfx_buf_shd::gfx_buf_shd(gfx_engine& graphics, size nof_bytes, cptr buffer, size offset) :
		gfx_buf_shd(graphics)
	{
		if (!remake_bytes(nof_bytes, buffer, offset)) { throw init_error(__FILE__, __LINE__); }
	}
	gfx_buf_shd::~gfx_buf_shd()
	{
	}
	// --setters
	void gfx_buf_shd::set_slot(v1u bind_slot) {
		m_slot = bind_slot;
	}
	void gfx_buf_shd::set_offset(size offset) {
		m_offset = offset;
	}
	void gfx_buf_shd::set_data_bytes(size nof_bytes, cptr buffer, size offset) {
		D3D11_MAPPED_SUBRESOURCE msub_res{ 0 };
		m_gfx->get_ctxh()->Map(m_handle, 0u, D3D11_MAP_WRITE_NO_OVERWRITE, 0u, &msub_res);
		memcpy(static_cast<ubyte*>(msub_res.pData) + m_offset + offset, buffer, nof_bytes);
		m_gfx->get_ctxh()->Unmap(m_handle, 0u);
	}
	// --==<core_methods>==--
	v1bit gfx_buf_shd::remake_bytes(size nof_bytes, cptr buffer, size offset)
	{
		m_size = nof_bytes;
		m_offset = offset;
		m_stride = nof_bytes;
		if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; }
		if (m_size <= 0) { return NW_FALSE; }
		if (m_offset >= m_size || m_elems.size() == 0) { return NW_FALSE; }

		D3D11_BUFFER_DESC buf_desc{ 0 };
		buf_desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		buf_desc.MiscFlags = 0u;
		buf_desc.StructureByteStride = m_size;
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
	void gfx_buf_shd::on_draw()
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
#endif	// NW_GAPI