#ifndef NWG_VERTEX_BUFFER_H
#define NWG_VERTEX_BUFFER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include "nwg_buf.h"
namespace NW
{
	/// vertex_buffer class
	class NW_API buf_vtx : public t_cmp<buf_vtx>, public a_gfx_buf
	{
	public:
		buf_vtx(gfx_engine& graphics);
		virtual ~buf_vtx();
		// --getters
		inline size get_stride_size() const	{ return m_stride_size; }
		inline size get_offset_size() const	{ return m_offset_size; }
		inline size get_data_count() const	{ return (m_data_size - m_offset_size) / m_stride_size; }
		// --setters
		virtual void set_data(size data_size, const ptr data_ptr, size offset_size = 0) override;
		// --core_methods
		virtual void on_draw() override;
		bit remake(size data_size, const ptr data_ptr, size offset_size, size stride_size);
		template<typename vtype>
		bit remake(si32 data_count, vtype* data_ptr = nullptr, size offset_size = 0u);
	private:
		ui32 m_stride_size;
		ui32 m_offset_size;
	};
	template<typename vtype>
	bit buf_vtx::remake(si32 data_count, vtype* data_ptr, size offset_size) {
		return remake(data_count * sizeof(vtype), data_ptr, offset_size, sizeof(vtype));
	}
}
#endif	// NW_GAPI
#endif	// NWG_VERTEX_BUFFER_H