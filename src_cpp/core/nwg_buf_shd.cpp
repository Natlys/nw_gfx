#include <nwg_pch.hpp>
#include "nwg_buf_shd.h"
#if (defined NW_GAPI)
#include <core/nwg_engine.h>
#if (NW_GAPI & NW_GAPI_OGL)
#include <lib/nwg_load_buf.h>
namespace NW
{
	shd_elem::shd_elem(cstring element_name, data_types data_type, si32 idx, si32 count) :
		name(""), type(data_type),
		idx(idx), count(count), offset_size(0)
	{
		strcpy(name, element_name);
	}
}
namespace NW
{
	buf_shd::buf_shd(gfx_engine& graphics) :
		a_gfx_buf(), t_gfx_rsc(graphics),
		m_elems(elements()),
		m_slot(0),
		m_offset_size(0)
	{
	}
	buf_shd::~buf_shd() { }
	// --setters
	void buf_shd::set_slot(ui8 bind_slot) { m_slot = bind_slot; }
	void buf_shd::set_offset(size offset_size) { m_offset_size = offset_size; }
	void buf_shd::set_data(size data_size, const ptr data_ptr, size offset_size) {
		glBufferSubData(GL_UNIFORM_BUFFER, offset_size, data_size, data_ptr);
	}
	void buf_shd::add_elem(const shd_elem& element, si8 count) {
		while (count-- > 0) {
			m_elems.push_back(element);
			m_elems.back().idx = m_elems.size() - 1;
		}
	}
	void buf_shd::rmv_elem(ui8 idx) {
		m_elems.erase(m_elems.begin() + idx % m_elems.size());
	}
	// --core_methods
	void buf_shd::on_draw()
	{
		glBindBuffer(GL_UNIFORM_BUFFER, m_ogl_id);
		//glBindBufferBase(GL_UNIFORM_BUFFER, m_slot, m_ogl_id);
		glBindBufferRange(GL_UNIFORM_BUFFER, m_slot, m_ogl_id, m_offset_size, m_data_size);
	}
	bit buf_shd::remake()
	{
		if (m_ogl_id != 0) { glDeleteBuffers(1, &m_ogl_id); m_ogl_id = 0; }
		if (m_elems.empty()) { return false; }
		
		m_data_size = 0;
		for (auto& elem : m_elems) {
			elem.offset_size += m_data_size;
			m_data_size += dt_get_aligned_size(elem.type, elem.count);
		}
		
		glGenBuffers(1, &m_ogl_id);
		glBindBuffer(GL_UNIFORM_BUFFER, m_ogl_id);
		glBufferData(GL_UNIFORM_BUFFER, m_data_size, nullptr, GL_DYNAMIC_DRAW);
		
		return true;
	}
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NW
{
	buf_shd::buf_shd(gfx_engine& graphics) :
		a_gfx_buf(graphics), t_cmp()
	{
	}
	buf_shd::~buf_shd() { }
	// --setters
	void buf_shd::SetSubData(Size szData, const Ptr pData, Size szOffset) {
		D3D11_MAPPED_SUBRESOURCE msubRes{ 0 };
		m_gfx->GetContext()->Map(m_native, 0u, D3D11_MAP_WRITE_DISCARD, 0u, &msubRes);
		memcpy(msubRes.pData, pData, szData);
		m_gfx->GetContext()->Unmap(m_native, 0u);
	}
	void buf_shd::SetLayout(ShaderLayout& refLayout) {
		for (auto& rBlock : refLayout.GetBlocks()) { Bind(rBlock.unBindPoint, rBlock.szAll, rBlock.szOffset); }
	}
	// --core_methods
	void buf_shd::Bind() {
		m_gfx->GetContext()->VSSetConstantBuffers(0, 1, &m_native);
		m_gfx->GetContext()->PSSetConstantBuffers(0, 1, &m_native);
	}
	void buf_shd::Bind(si32 unPoint) {
	}
	void buf_shd::Bind(si32 unPoint, Size szData, Size szOffset) { }
	bool buf_shd::Remake(const gfx_buf_info& info) {
		m_info = info;
		if (m_native != nullptr) { m_native->Release(); m_native = nullptr; }
		if (m_info.szData == 0) { return true; }

		D3D11_BUFFER_DESC bufDesc{ 0 };
		bufDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
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