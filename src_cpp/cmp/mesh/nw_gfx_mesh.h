#ifndef NW_GFX_MESH_H
#define NW_GFX_MESH_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "../mtl/nw_gfx_mtl.h"
#	include "../buf/nw_gfx_buf_layt.h"
#	include "../nw_gfx_cmp.h"
namespace NW
{
	class NW_API gfx_mesh : public t_cmp<gfx_mesh>, public a_gfx_cmp, public a_iop_cmp, public a_name_owner
	{
	public:
		using layt_t = mem_ref<gfx_buf_layt>;
		using layt_tc = const layt_t;
		using gmtl_t = mem_ref<gfx_mtl>;
		using gmtl_tc = const gmtl_t;
	public:
		gfx_mesh();
		virtual ~gfx_mesh();
	public:
		// --getters
		inline gmtl_t& get_gmtl()        { return m_gmtl; }
		inline gmtl_tc& get_gmtl() const { return m_gmtl; }
		inline layt_t& get_layt()        { return m_layt; }
		inline layt_tc& get_layt() const { return m_layt; }
		// --setters
		// --operators
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		virtual v1nil on_draw() override;
	protected:
		layt_t m_layt;
		gmtl_t m_gmtl;
	};
}
#endif	// NW_GAPI
#endif	// NW_GFX_MESH_H