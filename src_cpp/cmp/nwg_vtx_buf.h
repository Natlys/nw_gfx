#ifndef NWG_VERTEX_BUFFER_H
#define NWG_VERTEX_BUFFER_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <cmp/nwg_buf.h>
namespace NWG
{
	/// vtx_buf class
	class NWG_API vtx_buf : public a_gfx_buf
	{
	public:
		vtx_buf(gfx_engine& graphics);
		virtual ~vtx_buf();
		// --getters
		inline size get_stride() const		{ return m_stride_size; }
		inline size get_data_count() const	{ return m_data_size / m_stride_size; }
		// --setters
		virtual void set_data(size data_size, const ptr data_ptr, size offset_size = 0) override;
		// --core_methods
		virtual void on_draw() override;
		bit remake(size data_size, const ptr data_ptr = nullptr, size stride_size = sizeof(v2f32));
		template<typename vtype>
		bit remake(si32 data_count, vtype* data_ptr = nullptr);
	private:
		ui32 m_stride_size = 0;
	};
	template<typename vtype>
	bit vtx_buf::remake(si32 data_count, vtype* data_ptr) {
		return remake(data_count * sizeof(vtype), data_ptr, sizeof(vtype));
	}
}
#endif	// NWG_GAPI
#endif	// NWG_VERTEX_BUFFER_H