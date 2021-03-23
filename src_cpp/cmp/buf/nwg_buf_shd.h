#ifndef NWG_SHADER_BUFFER_H
#define NWG_SHADER_BUFFER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include "nwg_buf.h"
namespace NW
{
	/// shader_buffer class
	/// description:
	/// --it is used by shaders as opengl uniform buffer, or as directx constant buffer;
	class NW_API buf_shd : public t_cmp<buf_shd>, public a_gfx_buf, public data_layt
	{
		using elem = data_elem;
		using elems = darray<elem>;
	public:
		buf_shd(gfx_engine& graphics);
		virtual ~buf_shd();
		// --getters
		inline ui8 get_slot() const		{ return m_slot; }
		// --setters
		void set_slot(ui8 bind_slot);
		void set_offset(size offset_size);
		virtual void set_data(size data_size, const ptr data_ptr, size offset_size = 0) override;
		// --core_methods
		bit remake(size data_size, const ptr data_ptr, size offset_size);
		template<typename stype>
		bit remake(const ptr data_ptr = nullptr, size offset_size = 0);
		virtual void on_draw() override;
	private:
		ui8 m_slot;
		size m_offset_size;
	};
	template<typename stype>
	bit buf_shd::remake(const ptr data_ptr, size offset_size) {
		return remake(sizeof(stype), data_ptr, offset_size);
	}
}
#endif	// NW_GAPI
#endif	// NWG_SHADER_BUFFER_H