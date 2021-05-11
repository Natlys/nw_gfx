#ifndef NC_GFX_MESH_H
#define NC_GFX_MESH_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "../mtl/nc_gfx_mtl.h"
#	include "../layt/nc_gfx_layt.h"
#	include "../nc_gfx_cmp.h"
namespace NC
{
	class NC_API gfx_mesh : public nc_cmp_tt<gfx_mesh>, public gfx_cmp_t, public nc_iop_cmp_t, public nc_name_owner_t
	{
	public:
		using layt_t = mem_ref_t<gfx_layt_t>;
		using layt_tc = const layt_t;
		using gmtl_t = mem_ref_t<gfx_mtl_t>;
		using gmtl_tc = const gmtl_t;
	public:
		gfx_mesh();
		virtual ~gfx_mesh();
	public:
		// getters //
		inline gmtl_t& get_gmtl()        { return m_gmtl; }
		inline gmtl_tc& get_gmtl() const { return m_gmtl; }
		inline layt_t& get_layt()        { return m_layt; }
		inline layt_tc& get_layt() const { return m_layt; }
		// setters //
		// operators //
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// commands //
		virtual v1nil_t on_draw() override;
	protected:
		layt_t m_layt;
		gmtl_t m_gmtl;
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_MESH_H