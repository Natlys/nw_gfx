#ifndef NWG_LAYOUT_H
#define NWG_LAYOUT_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <core/nwg_tools.h>
#include <core/nwg_cmp.h>
#include <cmp/nwg_shd_buf.h>
namespace NWG
{
	/// input_layout class
	/// description:
	/// --default input assembler tool for vertex shaders;
	/// --equivalent to the vertex array in opengl;
	class NWG_API input_layout : public t_gfx_cmp<input_layout>
	{
		using elems = darray<shd_elem>;
	public:
		input_layout(gfx_engine& graphics);
		virtual ~input_layout();
		// --getters
		inline vtx_shader* get_shader()		{ return m_shader; }
		inline elems& get_elems()			{ return m_elems; }
		inline shd_elem& get_elem(ui8 idx)	{ return m_elems[idx % m_elems.size()]; }
#if (NWG_GAPI & NWG_GAPI_OGL)
		inline GLuint get_ogl_id() const { return m_ogl_id; }
#endif
		// --setters
		void set_shader(vtx_shader* shader);
		void add_elem(const shd_elem& elem, si8 nof_elements = 1);
		void rmv_elem(ui8 idx);
		// --core_methods
		virtual void on_draw() override;
		bit remake(vtx_shader& ref);
	private:
		vtx_shader* m_shader;
		elems m_elems;
		darray<size> m_strides;
#if (NWG_GAPI & NWG_GAPI_OGL)
		GLuint m_ogl_id;
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
		ID3D11InputLayout* m_native;
#endif
	};
}
#endif	// NWG_GAPI
#endif	// NWG_LAYOUT_H