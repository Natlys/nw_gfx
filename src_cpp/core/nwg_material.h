#ifndef NW_MATERIAL_H
#define NW_MATERIAL_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_rsc.h>
#include <core/nwg_shader.h>
namespace NW
{
	/// gfx_material class
	class NW_API gfx_material : public t_gfx_res<gfx_material>, public a_data_rsc
	{
	public:
		using shader = mem_ref<a_shader>;
		using shaders = darray<shader>;
		using texture = mem_ref<a_texture>;
		using textures = darray<mem_ref<a_texture>>;
	public:
		gfx_material(gfx_engine& graphics, cstring name);
		virtual ~gfx_material();
		// --getters
		inline shader& get_shader(ui8 idx)		{ return m_shds[idx % m_shds.size()]; }
		inline texture& get_texture(ui8 idx)	{ return m_txrs[idx % m_txrs.size()]; }
#if (NW_GAPI & NW_GAPI_OGL)
		inline GLuint get_ogl_id() const		{ return m_ogl_id; }
#endif
#if (NW_GAPI & NW_GAPI_DX)
#endif
		// --setters
		template<typename vtype> void set_value(si32 idx, const vtype& data, ui32 count = 1);
		void add_shader(shader& ref);
		void rmv_shader(ui8 idx);
		void add_texture(texture& ref);
		void rmv_texture(ui8 idx);
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
		// --core_methods
		bit remake();
		virtual void on_draw() override;
	private:
		shaders m_shds;
		textures m_txrs;
#if (NW_GAPI & NW_GAPI_OGL)
		GLuint m_ogl_id;
#endif
#if (NW_GAPI & NW_GAPI_DX)
#endif
	};
}

#endif	// NW_GAPI
#endif	// NW_MATERIAL_H