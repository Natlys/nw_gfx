#ifndef NW_SHADER_BUFFER_H
#define NW_SHADER_BUFFER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_buf.h>
namespace NW
{
	/// shader_input_element struct
	struct NW_API shd_elem
	{
	public:
		schar name[128] = "default";
		data_types type = DT_DEFAULT;
		si32 count = 0;
		si32 idx = 0;
		size offset_size = 0;
	public:
		shd_elem(cstring name = "default", data_types dataType = DT_DEFAULT, si32 count = 1);
	};
}
namespace NW
{
	/// shader_buffer class
	/// description:
	/// --it is used by shaders as opengl uniform buffer, or as directx constant buffer;
	class NW_API buf_shd : public a_gfx_buf, public t_gfx_res<buf_shd>
	{
		using elements = darray<shd_elem>;
	public:
		buf_shd(gfx_engine& graphics);
		virtual ~buf_shd();
		// --getters
		inline ui8 get_slot() const				{ return m_slot; }
		inline elements& get_elems()			{ return m_elems; }
		inline shd_elem& get_elem(ui8 idx = 0)	{ return m_elems[idx % m_elems.size()]; }
		// --setters
		void set_slot(ui8 bind_slot);
		void set_offset(size offset_size);
		virtual void set_data(size data_size, const ptr data_ptr, size offset_size = 0) override;
		// --core_methods
		virtual void on_draw() override;
		bit remake(const elements& elems);
	private:
		ui8 m_slot;
		size m_offset_size;
		elements m_elems;
	};
}
#endif	// NW_GAPI
#endif	// NW_SHADER_BUFFER_H