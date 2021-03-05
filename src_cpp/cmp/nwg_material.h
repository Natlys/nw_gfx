#ifndef NWG_MATERIAL_H
#define NWG_MATERIAL_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <core/nwg_cmp.h>
#include <cmp/nwg_shader.h>
namespace NWG
{
	struct NWG_API gfx_material_info : public a_info
	{
	public:
		gfx_api_types gapi_type = GAPI_DEFAULT;
		dstring name = "default";
		dstring source_vtx = "default";
		dstring source_pxl = "default";
		dstring source_gmt = "default";
	public:
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
	};
}
namespace NWG
{
	/// gfx_material class
	class NWG_API gfx_material : public t_gfx_cmp<gfx_material>, public a_data_res
	{
	public:
		using shaders = darray<mem_ref<shader>>;
	public:
		gfx_material(gfx_engine& graphics, cstring name);
		virtual ~gfx_material();
		// --getters
		inline const gfx_material_info& get_info() const	{ return m_info; }
		inline mem_ref<shader>& get_shader(shader_types shd_type);
#if (NWG_GAPI & NWG_GAPI_OGL)
		inline GLuint get_ogl_id() const { return m_ogl_id; }
#endif
		// --setters
		template<typename vtype> void set_value(si32 idx, const vtype& data, ui32 count = 1);
		// --core_methods
		virtual void on_draw() override;
		bit remake(const gfx_material_info& info);
		// --data_methods
		virtual bit save_file(cstring file_path) override;
		virtual bit load_file(cstring file_path) override;
	private:
		gfx_material_info m_info;
		shaders m_shds;
#if (NWG_GAPI & NWG_GAPI_OGL)
		GLuint m_ogl_id;
#endif
	};
	inline mem_ref<shader>& gfx_material::get_shader(shader_types shd_type) {
		for (auto& ishd : m_shds) {
			if (ishd->get_shd_type() == shd_type) { return ishd; }
		}
		return *m_shds.begin();
	}
}

#endif	// NWG_GAPI
#endif	// NWG_MATERIAL_H