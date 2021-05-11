#ifndef NC_GFX_TFORM_H
#define NC_GFX_TFORM_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "../buf/nc_gfx_buf_shd.h"
#	include "../nc_gfx_cmp.h"
namespace NC
{
	/// graphics_transform class
	class NC_API gfx_tform : public gfx_buf_shd_t
	{
	public:
		using tform_t = gfx_tform;
		using tform_tc = const tform_t;
	public:
		gfx_tform();
		gfx_tform(tform_tc& copy);
		gfx_tform(tform_t&& copy);
		virtual ~gfx_tform();
		// getters //
		inline v3f_t get_crd() const { return m_crd; }
		inline v3f_t get_rtn() const { return m_rtn; }
		inline v3f_t get_scl() const { return m_scl; }
		inline cm4x4f get_modl() const { return get_elem("modl").get<m4x4f>(); }
		// setters //
		tform_t& set_crd(v3f_tc& coord);
		tform_t& set_rtn(v3f_tc& rotat);
		tform_t& set_scl(v3f_tc& scale);
		tform_t& set_modl(cm4x4f& modl);
		// predicates //
		inline v1bit_t has_crd_x(v1f_tc coord) const { return m_crd[0] == coord; }
		inline v1bit_t has_crd_y(v1f_tc coord) const { return m_crd[1] == coord; }
		inline v1bit_t has_crd_z(v1f_tc coord) const { return m_crd[2] == coord; }
		inline v1bit_t has_crd_xyz(v3f_tc& coord) const { return m_crd[0] == coord[0] && m_crd[1] == coord[1] && m_crd[2] == coord[2]; }
		// operators //
		inline tform_t& operator=(tform_tc& copy) { gfx_buf_shd_t::operator=(copy); return *this; }
		inline tform_t& operator=(tform_t&& copy) { gfx_buf_shd_t::operator=(copy); return *this; }
		// commands //
		virtual v1bit_t remake() override;
		virtual v1nil_t on_draw() override;
	protected:
		v3f_t m_crd;
		v3f_t m_rtn;
		v3f_t m_scl;
	};
}
#endif
#endif	// NC_GFX_TFORM_H