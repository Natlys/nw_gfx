#ifndef NW_LAYOUT_H
#define NW_LAYOUT_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_rsc.h>
#include <core/nwg_buf_shd.h>
#include <lib/nwg_tools.h>
namespace NW
{
	/// input_layout class
	/// description:
	/// --default input assembler tool for vertex shaders;
	/// --equivalent of the vertex array in opengl;
	class NW_API input_layout : public t_gfx_res<input_layout>
	{
		using elems = darray<shd_elem>;
	public:
		input_layout(gfx_engine& graphics);
		virtual ~input_layout();
		// --getters
		inline shader_vtx* get_shader()			{ return m_shader; }
		inline elems& get_elems()				{ return m_elems; }
		inline shd_elem& get_elem(ui8 idx)		{ return m_elems[idx % m_elems.size()]; }
#if (NW_GAPI & NW_GAPI_OGL)
		inline GLuint get_ogl_id() const		{ return m_ogl_id; }
#endif
#if (NW_GAPI & NW_GAPI_DX)
		inline ID3D11InputLayout* get_dx_buf()	{ return m_dx_layt; }
#endif
		// --setters
		void set_shader(shader_vtx* shader);
		void add_elem(const shd_elem& elem, si8 nof_elements = 1);
		void rmv_elem(ui8 idx);
		// --core_methods
		virtual void on_draw() override;
		bit remake(shader_vtx& ref);
	private:
		shader_vtx* m_shader;
		elems m_elems;
		darray<size> m_strides;
#if (NW_GAPI & NW_GAPI_OGL)
		GLuint m_ogl_id;
#endif
#if (NW_GAPI & NW_GAPI_DX)
		ID3D11InputLayout* m_dx_layt;
#endif
	};
}
#endif	// NW_GAPI
#endif	// NW_LAYOUT_H