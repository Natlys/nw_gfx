#ifndef NWG_SHADER_BUFFER_H
#define NWG_SHADER_BUFFER_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <cmp/nwg_buf.h>
namespace NWG
{
	/// shader_input_element struct
	struct NWG_API shd_elem
	{
	public:
		char8 name[128] = "default";
		data_types type = DT_DEFAULT;
		si32 count = 0;
		si32 idx = 0;
		size offset_size = 0;
	public:
		shd_elem(cstring name = "default", data_types dataType = DT_DEFAULT, si32 count = 1);
	};
	struct NWG_API shd_block
	{
	public:
		darray<shd_elem> elems;
		char8 name[128] = "default";
		ui8 bind_point = 0u;
		size offset_size = 0ul;
		size data_size = 0ul;
	public:
		shd_block(cstring name = "default", ui8 where_to_bind = 0);
	};
}
namespace NWG
{
	/// shader_buffer class
	/// description:
	/// --it is used by shaders as opengl uniform buffer, or as directx constant buffer;
	class NWG_API shd_buf : public a_gfx_buf
	{
		using blocks = darray<shd_block>;
	public:
		shd_buf(gfx_engine& graphics);
		virtual ~shd_buf();
		// --getters
		inline blocks& get_blocks()					{ return m_blocks; }
		inline shd_block& get_block(ui8 idx = 0)	{ return m_blocks.at(idx); }
		// --setters
		virtual void set_data(size data_size, const ptr data_ptr, size offset_size = 0) override;
		void add_block(const shd_block& block, si8 nof_elements = 1);
		void rmv_block(ui8 idx);
		// --core_methods
		virtual void on_draw() override;
		void bind(ui32 where_to_bind);
		void bind(ui32 where_to_bind, size data_size, size offset_size = 0);
		bit remake(size data_size, ptr data_ptr = nullptr);
		template<typename stype>
		bit remake(const stype* data_ptr = nullptr) { return remake(sizeof(stype), data_ptr); }
	private:
		darray<shd_block> m_blocks;
	};
}
#endif	// NWG_GAPI
#endif	// NWG_BUFFER_H