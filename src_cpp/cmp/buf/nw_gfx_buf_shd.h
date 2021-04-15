#ifndef NW_GFX_SHADER_BUFFER_H
#define NW_GFX_SHADER_BUFFER_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_buf.h"
#	include "mem/nw_mem_buf.h"
namespace NW
{
	/// shader_buffer class
	/// description:
	/// --it is used by shaders as opengl uniform buffer, or as directx constant buffer;
	class NW_API gfx_buf_shd : public a_gfx_buf, public mem_layt
	{
	public:
		gfx_buf_shd(gfx_engine& graphics);
		virtual ~gfx_buf_shd();
		// --getters
		inline cv1u get_slot() const { return m_slot; }
		// --setters
		v1nil set_slot(cv1u slot);
		virtual v1nil set_data(cv1u count, ptr_tc data, cv1u offset = NW_NULL) override;
		// --core_methods
		virtual v1bit remake(cv1u stride, cv1u count, ptr_tc data = NW_NULL) override;
		virtual v1nil on_draw() override;
	private:
		v1u m_slot;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_SHADER_BUFFER_H
