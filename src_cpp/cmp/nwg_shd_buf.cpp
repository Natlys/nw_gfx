#include <nwg_pch.hpp>
#include "nwg_shd_buf.h"
#if (defined NWG_GAPI)
#include <core/nwg_engine.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
#include <lib/nwg_ogl_v1.h>
#include <lib/nwg_ogl_v3.h>
namespace NWG
{
	shd_elem::shd_elem(cstring element_name, data_types data_type, si32 count) :
		name(""), type(data_type),
		idx(0),
		count(count), offset_size(0) { strcpy(name, element_name); }
	
	shd_block::shd_block(cstring block_name, ui8 where_to_bind) :
		name(""),
		bind_point(where_to_bind), data_size(0), offset_size(0) {
		strcpy(name, block_name);
	}
}
namespace NWG
{
	shd_buf::shd_buf(gfx_engine& graphics) :
		a_gfx_buf(graphics) { }
	shd_buf::~shd_buf() { }
	// --setters
	void shd_buf::set_data(size data_size, const ptr data_ptr, size offset_size) {
		glBufferSubData(GL_UNIFORM_BUFFER, offset_size, data_size, data_ptr);
	}
	void shd_buf::add_block(const shd_block& block, si8 count) {
		while (count-- > 0) { m_blocks.push_back(block); }
	}
	void shd_buf::rmv_block(ui8 idx) {
		m_blocks.erase(m_blocks.begin() + idx % m_blocks.size());
	}
	// --core_methods
	void shd_buf::on_draw()
	{
		glBindBuffer(GL_UNIFORM_BUFFER, m_ogl_id);
		for (auto& iblock : m_blocks) { bind(iblock.bind_point, iblock.data_size, iblock.offset_size); }
	}
	void shd_buf::bind(ui32 where_to_bind)
	{
		glBindBuffer(GL_UNIFORM_BUFFER, m_ogl_id);
		glBindBufferBase(GL_UNIFORM_BUFFER, where_to_bind, m_ogl_id);
	}
	void shd_buf::bind(ui32 where_to_bind, size data_size, size offset_size)
	{
		glBindBuffer(GL_UNIFORM_BUFFER, m_ogl_id);
		glBindBufferRange(GL_UNIFORM_BUFFER, where_to_bind, m_ogl_id, offset_size, data_size);
	}
	bit shd_buf::remake(size data_size, const ptr data_ptr)
	{
		m_data_size = data_size;
		m_data_ptr = data_ptr;
		if (m_ogl_id != 0) { glDeleteBuffers(1, &m_ogl_id); m_ogl_id = 0; }
		if (data_size == 0) { return false; }
		glGenBuffers(1, &m_ogl_id);
		glBindBuffer(GL_UNIFORM_BUFFER, m_ogl_id);
		glBufferData(GL_UNIFORM_BUFFER, data_size, data_ptr, data_ptr == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
		
		for (ui8 bi = 0; bi < m_blocks.size(); bi++) {
			data_size = 0;
			auto& iblock = m_blocks[bi];
			iblock.bind_point = bi;
			iblock.offset_size = m_data_size;
			for (auto& elem : iblock.elems) {
				elem.offset_size += iblock.data_size;
				iblock.data_size += dt_get_aligned_size(elem.type, elem.count);
			}
			m_data_size += iblock.data_size;
		}

		return true;
	}
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NWG
{
	shd_buf::shd_buf(gfx_engine& graphics) : a_gfx_buf(graphics) { }
	shd_buf::~shd_buf() { }
	// --setters
	void shd_buf::SetSubData(Size szData, const Ptr pData, Size szOffset) {
		D3D11_MAPPED_SUBRESOURCE msubRes{ 0 };
		m_gfx->GetContext()->Map(m_native, 0u, D3D11_MAP_WRITE_DISCARD, 0u, &msubRes);
		memcpy(msubRes.pData, pData, szData);
		m_gfx->GetContext()->Unmap(m_native, 0u);
	}
	void shd_buf::SetLayout(ShaderLayout& refLayout) {
		for (auto& rBlock : refLayout.GetBlocks()) { Bind(rBlock.unBindPoint, rBlock.szAll, rBlock.szOffset); }
	}
	// --core_methods
	void shd_buf::Bind() {
		m_gfx->GetContext()->VSSetConstantBuffers(0, 1, &m_native);
		m_gfx->GetContext()->PSSetConstantBuffers(0, 1, &m_native);
	}
	void shd_buf::Bind(si32 unPoint) {
	}
	void shd_buf::Bind(si32 unPoint, Size szData, Size szOffset) { }
	bool shd_buf::Remake(const gfx_buf_info& info) {
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
#endif	// NWG_GAPI