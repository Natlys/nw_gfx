#ifndef NW_DRAWABLE_IDX_H
#define NW_DRAWABLE_IDX_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <cmp/nwg_drawable.h>
#include <core/nwg_buf_idx.h>
namespace NW
{
	/// indexed drawable class
	class NW_API drawable_idx : public drawable
	{
		using buffer = mem_ref<buf_idx>;
	public:
		drawable_idx(gfx_engine& graphics);
		virtual ~drawable_idx();
		// --getters
		buffer& get_buf() { return m_ibuf; }
		// --setters
		// --core_methods
		virtual void on_draw() override;
	private:
		buffer m_ibuf;
	};
}

#endif	// NW_GAPI
#endif	// NW_DRAWABLE_IDX_H