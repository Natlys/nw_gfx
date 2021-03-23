#ifndef NWG_SHADER_LAYOUT_H
#define NWG_SHADER_LAYOUT_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_cmp.h>
#include <cmp/buf/nwg_buf_shd.h>
namespace NW
{
	/// shader_layout class
	/// description:
	/// --default input assembler tool for vertex shaders;
	/// --equivalent of the vertex array in opengl;
	class NW_API shd_layt : public t_cmp<shd_layt>, public a_gfx_cmp, public data_layt
	{
#if (NW_GAPI & NW_GAPI_DX)
		using handle = ID3D11InputLayout*;
#endif
#if (NW_GAPI & NW_GAPI_OGL)
		using handle = GLuint;
#endif
	public:
		shd_layt(gfx_engine& graphics);
		virtual ~shd_layt();
		// --getters
		inline handle get_handle() const	{ return m_handle; }
		// --core_methods
		bit remake(mem_ref<a_shd>& shader);
		virtual void on_draw() override;
	private:
		handle m_handle;
		size m_stride;
	};
}
#endif	// NW_GAPI
#endif	// NW_SHADER_LAYOUT_H