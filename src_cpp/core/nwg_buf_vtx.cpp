#include <nwg_pch.hpp>
#include "nwg_buf_vtx.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#if (NW_GAPI & NW_GAPI_OGL)
#include <lib/nwg_load_buf.h>
namespace NW
{
	buf_vtx::buf_vtx(gfx_engine& graphics) :
		a_gfx_buf(), t_gfx_res(graphics),
		m_stride_size(0)
	{
	}
	buf_vtx::~buf_vtx() { }
	// --setters
	void buf_vtx::set_data(size data_size, const ptr data_ptr, size offset_size)
	{
		glBufferSubData(GL_ARRAY_BUFFER, offset_size, data_size, data_ptr);
	}
	// --core_methods
	void buf_vtx::on_draw()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_ogl_id);
	}
	bit buf_vtx::remake(size data_size, const ptr data_ptr, size stride_size)
	{
		m_data_size = data_size;
		m_stride_size = stride_size;
		if (m_ogl_id != 0) { glDeleteBuffers(1, &m_ogl_id); m_ogl_id = 0; }
		if (data_size == 0 || stride_size == 0) { return false; }
		glGenBuffers(1, &m_ogl_id);
		glBindBuffer(GL_ARRAY_BUFFER, m_ogl_id);
		glBufferData(GL_ARRAY_BUFFER, data_size, data_ptr, data_ptr == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
		return true;
	}
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NW
{
	buf_vtx::buf_vtx(gfx_engine& graphics) :
		a_gfx_buf(graphics), t_cmp()
		m_stride_size(0)
	{
	}
	buf_vtx::~buf_vtx() { }
	// --setters
	void buf_vtx::SetSubData(Size szData, const Ptr pData, Size szOffset) {
		D3D11_MAPPED_SUBRESOURCE msubRes{ 0 };
		m_gfx->GetContext()->Map(m_native, 0u, D3D11_MAP_WRITE_DISCARD, 0u, &msubRes);
		memcpy(msubRes.pData, pData, szData);
		m_gfx->GetContext()->Unmap(m_native, 0u);
	}
	// --core_methods
	void buf_vtx::Bind() { m_gfx->GetContext()->IASetVertexBuffers(0, 1, &m_native, &m_info.szStride, &m_info.szOffset); }
	bool buf_vtx::Remake(const gfx_buf_info& info) {
		m_info = info;
		if (m_native != nullptr) { m_native->Release(); m_native = nullptr; }
		if (m_info.szData == 0) { return false; }

		D3D11_BUFFER_DESC bufDesc{ 0 };
		bufDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bufDesc.MiscFlags = 0u;
		bufDesc.StructureByteStride = m_info.szStride;
		bufDesc.ByteWidth = m_info.szData;

		if (info.pData == nullptr) {
			m_info.pData = mem_sys::GetMemory().GetDataBeg();
			bufDesc.Usage = D3D11_USAGE_DYNAMIC;
			bufDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		}
		else {
			bufDesc.Usage = D3D11_USAGE_DEFAULT;
			bufDesc.CPUAccessFlags = 0u;
		}

		D3D11_SUBRESOURCE_DATA subData{ 0 };
		subData.pSysMem = m_info.pData;

		m_gfx->GetDevice()->CreateBuffer(&bufDesc, &subData, &m_native);
		if (m_native == nullptr) { throw error("Failed to create buffer!"); }
		return true;
	}
}
#endif
#endif	// NW_GAPI