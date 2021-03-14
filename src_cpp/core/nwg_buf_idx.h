#ifndef NW_INDEX_BUFFER_H
#define NW_INDEX_BUFFER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_buf.h>
namespace NW
{
	/// buf_idx class
	class NW_API buf_idx : public a_gfx_buf, public t_gfx_rsc<buf_idx>
	{
	public:
		buf_idx(gfx_engine& graphics);
		virtual ~buf_idx();
		// --getters
		inline data_types get_data_type() const	{ return m_data_type; }
		inline size get_data_count() const		{ return m_data_size / dt_get_size(m_data_type); }
		// --setters
		virtual void set_data(size data_size, const ptr data_ptr, size offset_size = 0) override;
		// --core_methods
		virtual void on_draw() override;
		bit remake(size data_size, const ptr data_ptr = nullptr, data_types data_type = DT_UINT32);
		template<typename itype>
		bit remake(ui32 data_count, itype* data_ptr = nullptr);
	private:
		data_types m_data_type = DT_DEFAULT;
	};
	template<typename itype>
	bit buf_idx::remake(ui32 data_count, itype* data_ptr) {
		return remake(data_count * sizeof(itype), data_ptr, convert_enum<itype, data_types>());
	}
}
#endif	// NW_GAPI
#endif	// NW_INDEX_BUFFER_H