#include <nwg_pch.hpp>
#include "nwg_layout.h"
#if(defined NW_GAPI)
#include <core/nwg_engine.h>
#include <core/nwg_shader.h>
#if(NW_GAPI & NW_GAPI_OGL)
#include <lib/nwg_load_base.h>
#include <lib/nwg_load_layt.h>
namespace NW
{
	input_layout::input_layout(gfx_engine& graphics) :
		t_gfx_rsc(graphics),
		m_ogl_id(0)
	{
	}
	input_layout::~input_layout() { if (m_ogl_id != 0) { glDeleteVertexArrays(1, &m_ogl_id); m_ogl_id = 0; } }
	// --setters
	void input_layout::add_elem(const shd_elem& element, si8 count) {
		while (count-- > 0) {
			m_elems.push_back(element);
			m_elems.back().idx = m_elems.size() - 1;
		}
	}
	void input_layout::rmv_elem(ui8 idx) {
		m_elems.erase(m_elems.begin() + idx % m_elems.size());
	}
	// --core_methods
	void input_layout::on_draw()
	{
		glBindVertexArray(m_ogl_id);
	}
	bool input_layout::remake(a_shader& shader)
	{
		if (m_ogl_id != 0) { glDeleteVertexArrays(1, &m_ogl_id); m_ogl_id = 0; }
		if (m_elems.size() == 0) { return false; }
		glGenVertexArrays(1, &m_ogl_id);
		glBindVertexArray(m_ogl_id);
		
		m_strides.clear();
		m_strides.push_back(0);
		for (ui8 bei = 0; bei < m_elems.size(); bei++) {
			auto& elem = m_elems[bei];
			elem.offset_size = m_strides.back();
			m_strides.back() += dt_get_size(elem.type, elem.count);
		}
		for (ui8 bei = 0; bei < m_elems.size(); bei++) {
			auto& elem = m_elems[bei];
			glEnableVertexAttribArray(elem.idx);
			glVertexAttribPointer(elem.idx, elem.count * dt_get_count(elem.type), convert_enum<data_types, GLenum>(elem.type),
				GL_FALSE, m_strides.back(), reinterpret_cast<ptr>(elem.offset_size));
		}
		return true;
	}
}

#endif
#if(NW_GAPI & NW_GAPI_DX)
#include <lib/nwg_dx_loader.h>
namespace NW {
	input_layout::input_layout(gfx_engine& graphics) :
		a_gfx_rsc(graphics), t_cmp(),
		m_shader(nullptr), m_native(nullptr) { }
	input_layout::~input_layout() { if (m_native != nullptr) { m_native->Release(); m_native = nullptr; } }
	// --setters
	void input_layout::SetShader(VertexShader* pShader) { m_pShader = pShader; }
	// --core_methods
	void input_layout::on_draw() { m_gfx->GetContext()->IASetInputLayout(m_native); }
	bool input_layout::Remake() {
		if (m_native != nullptr) { m_native->Release(); m_native = nullptr; }
		if (m_pShader == nullptr) { return false; }
		
		auto& rLayout = m_pShader->GetVtxLayout();
		darray<D3D11_INPUT_ELEMENT_DESC> dxElems(rLayout.GetElems().size());
		for (si32 bei = 0; bei < dxElems.size(); bei++) {
			auto& itElem = rLayout.GetElem(bei);
			auto& dxElem = dxElems[bei];
			dxElem.Format = convert_enum<data_types, DXGI_FORMAT>(itElem.sdType);
			dxElem.SemanticName = itElem.name;
			dxElem.SemanticIndex = 0;
			dxElem.InputSlot = itElem.unNum;
			dxElem.AlignedByteOffset = itElem.szOffset;
			dxElem.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
			dxElem.InstanceDataStepRate = 0;
		}
		m_gfx->GetDevice()->CreateInputLayout(&dxElems[0], dxElems.size(),
			m_pShader->GetBlob()->GetBufferPointer(), m_pShader->GetBlob()->GetBufferSize(), &m_native);
		if (m_native == nullptr) { throw error("input layout is null!"); }
		m_gfx->GetContext()->IASetInputLayout(m_native);
		return true;
	}
}

#endif
#endif	// NW_GAPI