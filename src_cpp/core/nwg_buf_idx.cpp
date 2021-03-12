#include <nwg_pch.hpp>
#include "nwg_buf_idx.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#if (NW_GAPI & NW_GAPI_OGL)
#include <lib/nwg_load_buf.h>
namespace NW
{
	buf_idx::buf_idx(gfx_engine& graphics) :
		a_gfx_buf(), t_gfx_res(graphics),
		m_data_type(DT_DEFAULT)
	{
	}
	buf_idx::~buf_idx() { }
	// --setters
	void buf_idx::set_data(size data_size, const ptr data_ptr, size offset_size) {
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset_size, data_size, data_ptr);
	}
	// --core_methods
	void buf_idx::on_draw()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ogl_id);
	}
	bit buf_idx::remake(size data_size, const ptr data_ptr, data_types data_type)
	{
		m_data_size = data_size;
		m_data_type = data_type;
		if (m_ogl_id != 0) { glDeleteBuffers(1, &m_ogl_id); m_ogl_id = 0; }
		if (data_size == 0) { return false; }
		glGenBuffers(1, &m_ogl_id);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ogl_id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, data_size, data_ptr, data_ptr == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
		return true;
	}
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NW
{
	buf_idx::buf_idx(gfx_engine& graphics) :
		a_gfx_buf(graphics), t_cmp()
	{
	}
	buf_idx::~buf_idx() { }
	// --setters
	void buf_idx::SetSubData(Size szData, const Ptr pData, Size szOffset) {
		D3D11_MAPPED_SUBRESOURCE msubRes{ 0 };
		m_gfx->GetContext()->Map(m_native, 0u, D3D11_MAP_WRITE_DISCARD, 0u, &msubRes);
		memcpy(msubRes.pData, pData, szData);
		m_gfx->GetContext()->Unmap(m_native, 0u);
	}
	// --core_methods
	void buf_idx::on_draw() {
		m_gfx->GetContext()->IASetIndexBuffer(m_native, convert_enum<data_types, DXGI_FORMAT>(m_info.sdType), 0);
	}
	bool buf_idx::remake(const gfx_buf_info& info) {
		m_info = info;
		if (m_native != nullptr) { m_native->Release(); m_native = nullptr; }
		if (m_info.szData == 0) { return false; }

		D3D11_BUFFER_DESC bufDesc{ 0 };
		bufDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		bufDesc.MiscFlags = 0u;
		bufDesc.StructureByteStride = m_info.szStride;
		bufDesc.ByteWidth = m_info.szData;

		if (m_info.pData == nullptr) {
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
		if (m_native == nullptr) { throw error("failed to create buffer!"); }
		return true;
	}
}
#endif
#endif	// NW_GAPI