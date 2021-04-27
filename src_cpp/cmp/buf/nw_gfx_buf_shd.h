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
	class NW_API gfx_buf_shd : public gfx_buf
	{
	public:
		using gsbuf_t = gfx_buf_shd;
		using gsbuf_tc = const gsbuf_t;
	public:
		gfx_buf_shd();
		gfx_buf_shd(layt_tc& layout, cv1u count, ptr_tc data = NW_NULL);
		virtual ~gfx_buf_shd();
		// --getters
		inline cv1u get_slot() const { return m_slot; }
		// --setters
		gsbuf_t& set_slot(cv1u slot);
		virtual buf_t& set_data(cv1u key, ptr_tc data, cv1u count) override;
		// --core_methods
		virtual v1bit remake() override;
		virtual v1nil on_draw() override;
	private:
		v1u m_slot;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_SHADER_BUFFER_H
