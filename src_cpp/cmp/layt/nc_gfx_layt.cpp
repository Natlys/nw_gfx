#include "nc_gfx_pch.hpp"
#include "nc_gfx_layt.hxx"
#if(defined NC_GAPI)
#	include "../../lib/nc_gfx_lib_info.hxx"
#	include "../../lib/nc_gfx_lib_core.hxx"
#	include "../../core/nc_nc_gfx_eng.hxx"
#	if(NC_GAPI & NC_GAPI_OGL)
namespace NC
{
	gfx_layt_t::gfx_layt_t() :
		nc_cmp_tt(), gfx_cmp_t(),
		m_handle(NC_NULL),
		m_layt(layt_t())
	{
	}
	gfx_layt_t::gfx_layt_t(buf_layt_tc& copy) : gfx_layt_t() { operator=(copy); }
	gfx_layt_t::gfx_layt_t(buf_layt_t&& copy) : gfx_layt_t() { operator=(copy); }
	gfx_layt_t::~gfx_layt_t() { if (m_handle != NC_NULL) { get_context()->layt_del(1u, &m_handle); m_handle = NC_NULL; } }
	/* setters */
	gfx_layt_t::buf_layt_t& gfx_layt_t::set_layt(layt_tc& layout) {
		m_layt = layout;
		return *this;
	}
	/* commands */
	v1bit_t gfx_layt_t::remake()
	{
		if (m_handle != NC_NULL) { get_context()->layt_del(1u, &m_handle); m_handle = NC_NULL; }
		gfx_context_state_t last_state;
		v1s_t last_vbuf(NC_NULL); get_context()->get_int(GL_ARRAY_BUFFER_BINDING, &last_vbuf);
		NC_CHECK(m_layt.remake(), "remake error!", return NC_FALSE);
		NC_CHECK(last_vbuf != NC_NULL, "there has to be bound a vertex buffer!", return NC_FALSE);

		get_context()->layt_new(1u, &m_handle);
		get_context()->layt_bind(get_handle());
		
		size_t ei = 0u;
		for (auto ielem : m_layt) {
			get_context()->layt_set_enabled(ei);
			const GLint count = gfx_info_t::get_count(ielem.get_type());
			const GLenum type = gfx_info_t::get_type(ielem.get_type());
			const GLvoid* offset = reinterpret_cast<const GLvoid*>(ielem.get_offset());
			const GLsizei stride = m_layt.get_space();
			get_context()->layt_set_atb(ei, count, type, GL_FALSE, stride, offset);
			ei += 1u;
		}

		return NC_TRUTH;
	}
	v1nil_t gfx_layt_t::on_draw()
	{
		get_context()->layt_bind(get_handle());
	}
	// --==</core_methods>==--
}

#	endif	// GAPI_OGL
#	if(NC_GAPI & NC_GAPI_D3D)
namespace NC
{
	gfx_layt_t::gfx_layt_t(nc_gfx_eng& graphics) :
		gfx_cmp_t(graphics), nc_cmp_tt(), mem_layt_t(),
		m_handle(NC_NULL)
	{
	}
	gfx_layt_t::~gfx_layt_t() { if (m_handle != NC_NULL) { m_handle->Release(); m_handle = NC_NULL; } }
	/* setters */
	/* commands */
	v1bit_t gfx_layt_t::remake(nc_ref_t<gfx_shd_t>& shader, celems& elements) {
		m_elems = elements;
		if (m_handle != NC_NULL) { m_handle->Release(); m_handle = NC_NULL; }
		if (shader.is_valid() == NC_FALSE) { return NC_FALSE; }
		if (m_elems.size() == 0) { return NC_FALSE; }

		m_stride = 0;
		for (v1u_t bei = 0; bei < m_elems.size(); bei++) {
			auto& elem = m_elems[bei];
			elem.offset = m_stride;
			m_stride += elem.get_size();
		}

		darray<D3D11_INPUT_ELEMENT_DESC> dx_elems(m_elems.size());
		for (v1u_t bei = 0u; bei < dx_elems.size(); bei++) {
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
		if (m_handle == NC_NULL) { throw init_error(__FILE__, __LINE__); return NC_FALSE; }
		return NC_TRUTH;
	}
<<<<<<< HEAD
	v1nil_t gfx_layt_t::on_draw()
=======
	void gfx_layt_t::on_draw()
>>>>>>> 5ec48b78bf51cdaf84eb36840c5ed9ec4bcddd88
	{
		m_gfx->get_ctxh()->IASetInputLayout(m_handle);
	}
	// --==</core_methods>==--
}
#endif	// GAPI_D3D
#endif	// NC_GAPI