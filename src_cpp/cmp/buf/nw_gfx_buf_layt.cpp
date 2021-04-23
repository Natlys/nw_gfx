#include "nw_gfx_pch.hpp"
#include "nw_gfx_buf_layt.h"
#if(defined NW_GAPI)
#	include "../../lib/nw_gfx_lib_info.h"
#	include "../../lib/nw_gfx_lib_core.h"
#	include "../../lib/nw_gfx_lib_layt.h"
#	include "../../core/nw_gfx_engine.h"
#	include "../../core/nw_gfx_state.h"
#	include "../shd/nw_gfx_shd.h"
#	if(NW_GAPI & NW_GAPI_OGL)
namespace NW
{
	gfx_buf_layt::gfx_buf_layt() :
		t_cmp(), a_gfx_cmp(), mem_layt(),
		m_handle(NW_NULL)
	{
	}
	gfx_buf_layt::~gfx_buf_layt() { if (m_handle != NW_NULL) { glDeleteVertexArrays(1u, &m_handle); m_handle = NW_NULL; } }
	// --setters
	// --==<core_methods>==--
	v1bit gfx_buf_layt::remake()
	{
		if (m_handle != NW_NULL) { glDeleteVertexArrays(1u, &m_handle); m_handle = NW_NULL; }
		gfx_state last_state;
		NW_CHECK(mem_layt::remake(), "failed remake!", return NW_FALSE);
		NW_CHECK(last_state.last_vbuf != NW_NULL, "there has to be bound a vertex buffer!", return NW_FALSE);

		glGenVertexArrays(1u, &m_handle);
		glBindVertexArray(get_handle());
		
		for (v1u ei = 0; ei < get_count(); ei++) {
			auto& ielem = get_node(ei);
			glEnableVertexAttribArray(ei);
			const GLint vcount = gfx_info::get_count(ielem.get_vtype());
			const GLenum vtype = gfx_info::get_type(ielem.get_vtype());
			const GLvoid* voffset = reinterpret_cast<const GLvoid*>(ielem.get_offset());
			const GLsizei stride = mem_layt::get_space();
			glVertexAttribPointer(ei, vcount, vtype, GL_FALSE, stride, voffset);
		}

		return NW_TRUE;
	}
	v1nil gfx_buf_layt::on_draw()
	{
		glBindVertexArray(get_handle());
	}
	// --==</core_methods>==--
}

#	endif	// GAPI_OGL
#	if(NW_GAPI & NW_GAPI_D3D)
namespace NW
{
	gfx_buf_layt::gfx_buf_layt(gfx_engine& graphics) :
		a_gfx_cmp(graphics), t_cmp(), mem_layt(),
		m_handle(NW_NULL)
	{
	}
	gfx_buf_layt::~gfx_buf_layt() { if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; } }
	// --setters
	// --==<core_methods>==--
	v1bit gfx_buf_layt::remake(mem_ref<a_gfx_shd>& shader, celems& elements) {
		m_elems = elements;
		if (m_handle != NW_NULL) { m_handle->Release(); m_handle = NW_NULL; }
		if (shader.is_valid() == NW_FALSE) { return NW_FALSE; }
		if (m_elems.size() == 0) { return NW_FALSE; }

		m_stride = 0;
		for (v1u bei = 0; bei < m_elems.size(); bei++) {
			auto& elem = m_elems[bei];
			elem.offset = m_stride;
			m_stride += elem.get_size();
		}

		darray<D3D11_INPUT_ELEMENT_DESC> dx_elems(m_elems.size());
		for (v1u bei = 0u; bei < dx_elems.size(); bei++) {
			auto& ielem = m_elems[bei];
			auto& dx_elem = dx_elems[bei];
			dx_elem.Format = convert<value_types, DXGI_FORMAT>(ielem.get_type());
			dx_elem.SemanticName = ielem.name;
			dx_elem.SemanticIndex = 0u;
			dx_elem.InputSlot = 0u;		// dx_elem.InputSlot = ielem.idx; should not be set in this way;
			dx_elem.AlignedByteOffset = ielem.offset;
			dx_elem.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
			dx_elem.InstanceDataStepRate = 0;
		}
		m_gfx->get_dvch()->CreateInputLayout(&dx_elems[0], dx_elems.size(),
			shader->get_handle()->GetBufferPointer(), shader->get_handle()->GetBufferSize(), &m_handle);
		if (m_handle == NW_NULL) { throw init_error(__FILE__, __LINE__); return NW_FALSE; }
		return NW_TRUE;
	}
	v1nil gfx_buf_layt::on_draw()
	{
		m_gfx->get_ctxh()->IASetInputLayout(m_handle);
	}
	// --==</core_methods>==--
}
#endif	// GAPI_D3D
#endif	// NW_GAPI