#include <nwg_pch.hpp>
#include "nwg_shd_layt.h"
#if(defined NW_GAPI)
#include <core/nwg_engine.h>
#include <cmp/shd/nwg_shd.h>
#include <lib/nwg_load_core.h>
#include <lib/nwg_load_layt.h>
#if(NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	shd_layt::shd_layt(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics), data_layt(),
		m_handle(0)
	{
	}
	shd_layt::~shd_layt() { if (m_handle != 0) { glDeleteVertexArrays(1, &m_handle); m_handle = 0; } }
	// --setters
	// --==<core_methods>==--
	bit shd_layt::remake(mem_ref<a_shd>& shader)
	{
		if (m_handle != 0) { glDeleteVertexArrays(1, &m_handle); m_handle = 0; }
		if (m_elems.size() == 0) { return false; }
		glGenVertexArrays(1, &m_handle);
		glBindVertexArray(m_handle);
		
		m_stride = 0;
		for (ui8 bei = 0; bei < m_elems.size(); bei++) {
			auto& elem = m_elems[bei];
			elem.offset = m_stride;
			m_stride += elem.get_size();
		}
		for (ui8 bei = 0; bei < m_elems.size(); bei++) {
			auto& elem = m_elems[bei];
			glEnableVertexAttribArray(elem.idx);
			glVertexAttribPointer(elem.idx, elem.get_prim_count(), convert_enum<data_types, GLenum>(elem.get_type()),
				GL_FALSE, m_stride, reinterpret_cast<ptr>(elem.offset));
		}
		return true;
	}
	void shd_layt::on_draw()
	{
		glBindVertexArray(m_handle);
	}
	// --==</core_methods>==--
}

#endif
#if(NW_GAPI & NW_GAPI_DX)
namespace NW {
	shd_layt::shd_layt(gfx_engine& graphics) :
		t_cmp(), a_gfx_cmp(graphics), data_layt(),
		m_handle(nullptr)
	{
	}
	shd_layt::~shd_layt() { if (m_handle != nullptr) { m_handle->Release(); m_handle = nullptr; } }
	// --setters
	// --==<core_methods>==--
	bit shd_layt::remake(mem_ref<a_shd>& shader) {
		if (m_handle != nullptr) { m_handle->Release(); m_handle = nullptr; }
		
		darray<D3D11_INPUT_ELEMENT_DESC> dx_elems(m_elems.size());
		for (si32 bei = 0; bei < dx_elems.size(); bei++) {
			auto& ielem = m_elems[bei];
			auto& dx_elem = dx_elems[bei];
			dx_elem.Format = convert_enum<data_types, DXGI_FORMAT>(ielem.get_type());
			dx_elem.SemanticName = ielem.name;
			dx_elem.SemanticIndex = 0;
			dx_elem.InputSlot = ielem.idx;
			dx_elem.AlignedByteOffset = ielem.offset;
			dx_elem.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
			dx_elem.InstanceDataStepRate = 0;
		}
		m_gfx->get_dvch()->CreateInputLayout(&dx_elems[0], dx_elems.size(),
			shader->get_handle()->GetBufferPointer(), shader->get_handle()->GetBufferSize(), &m_handle);
		if (m_handle == nullptr) { throw init_error(__FILE__, __LINE__); return false; }
		return true;
	}
	void shd_layt::on_draw()
	{
		m_gfx->get_ctxh()->IASetInputLayout(m_handle);
	}
	// --==</core_methods>==--
}
#endif
#endif	// NW_GAPI