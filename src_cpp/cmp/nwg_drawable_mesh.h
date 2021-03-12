#ifndef NW_DRAWABLE_MESH_H
#define NW_DRAWABLE_MESH_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <cmp/nwg_drawable_idx.h>
#include <lib/nwg_data.h>
namespace NW
{
	class NW_API drawable_mesh : public a_drawable, public a_data_rsc, public t_gfx_res<drawable_mesh>
	{
	public:
		drawable_mesh();
		~drawable_mesh();
		// --getters
		// --setters
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const override;
		virtual in_stream& operator>>(in_stream& stm) override;
		// --core_methods
	private:
		mem_ref<buf_idx> m_ibuf;
	};
}
#endif	// NW_GAPI
#endif	// NW_DRAWABLE_MESH_H