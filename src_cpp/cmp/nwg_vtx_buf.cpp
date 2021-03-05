#include <nwg_pch.hpp>
#include "nwg_vtx_buf.h"
#if (defined NWG_GAPI)
#include <core/nwg_engine.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
#include <lib/nwg_ogl_v1.h>
namespace NWG
{
	vtx_buf::vtx_buf(gfx_engine& graphics) :
		a_gfx_buf(graphics),
		m_stride_size(0) { }
	vtx_buf::~vtx_buf() { }
	// --setters
	void vtx_buf::set_data(size data_size, const ptr data_ptr, size offset_size)
	{
		glBufferSubData(GL_ARRAY_BUFFER, offset_size, data_size, data_ptr);
	}
	// --core_methods
	void vtx_buf::on_draw()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_ogl_id);
	}
	bit vtx_buf::remake(size data_size, const ptr data_ptr, size stride_size)
	{
		m_data_size = data_size;
		m_data_ptr = data_ptr;
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
#if (NWG_GAPI & NWG_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NWG
{
	vtx_buf::vtx_buf(gfx_engine& graphics) :
		a_gfx_buf(graphics) { }
	vtx_buf::~vtx_buf() { }
	// --setters
	void vtx_buf::SetSubData(Size szData, const Ptr pData, Size szOffset) {
		D3D11_MAPPED_SUBRESOURCE msubRes{ 0 };
		m_gfx->GetContext()->Map(m_native, 0u, D3D11_MAP_WRITE_DISCARD, 0u, &msubRes);
		memcpy(msubRes.pData, pData, szData);
		m_gfx->GetContext()->Unmap(m_native, 0u);
	}
	// --core_methods
	void vtx_buf::Bind() { m_gfx->GetContext()->IASetVertexBuffers(0, 1, &m_native, &m_info.szStride, &m_info.szOffset); }
	bool vtx_buf::Remake(const gfx_buf_info& info) {
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
#endif	// NWG_GAPI