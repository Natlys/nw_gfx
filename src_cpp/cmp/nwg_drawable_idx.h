#ifndef NWG_DRAWABLE_IDX_H
#define NWG_DRAWABLE_IDX_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <cmp/nwg_drawable.h>
namespace NWG
{
	/// indexed drawable class
	class NWG_API idx_drawable : public a_drawable, public t_gfx_res<idx_drawable>
	{
		using buffer = mem_ref<idx_buf>;
	public:
		idx_drawable(gfx_engine& graphics);
		virtual ~idx_drawable();
		// --getters
		buffer& get_buf() { return m_ibuf; }
		// --setters
		// --core_methods
		virtual void on_draw() override;
	private:
		buffer m_ibuf;
	};
}

#endif	// NWG_GAPI
#endif	// NWG_DRAWABLE_IDX_H