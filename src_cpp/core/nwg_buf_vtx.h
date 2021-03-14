#ifndef NW_VERTEX_BUFFER_H
#define NW_VERTEX_BUFFER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_buf.h>
namespace NW
{
	/// buf_vtx class
	class NW_API buf_vtx : public a_gfx_buf, public t_gfx_rsc<buf_vtx>
	{
	public:
		buf_vtx(gfx_engine& graphics);
		virtual ~buf_vtx();
		// --getters
		inline size get_stride() const		{ return m_stride_size; }
		inline size get_data_count() const	{ return m_data_size / m_stride_size; }
		// --setters
		virtual void set_data(size data_size, const ptr data_ptr, size offset_size = 0) override;
		// --core_methods
		virtual void on_draw() override;
		bit remake(size data_size, const ptr data_ptr = nullptr, size stride_size = sizeof(v2f));
		template<typename vtype>
		bit remake(si32 data_count, vtype* data_ptr = nullptr);
	private:
		ui32 m_stride_size = 0;
	};
	template<typename vtype>
	bit buf_vtx::remake(si32 data_count, vtype* data_ptr) {
		return remake(data_count * sizeof(vtype), data_ptr, sizeof(vtype));
	}
}
#endif	// NW_GAPI
#endif	// NW_VERTEX_BUFFER_H