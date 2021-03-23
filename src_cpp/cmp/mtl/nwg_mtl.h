#ifndef NWG_MATERIAL_H
#define NWG_MATERIAL_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_cmp.h>
#include <cmp/shd/nwg_shd.h>
#include <cmp/txr/nwg_txr.h>
namespace NW
{
	/// material class
	class NW_API gfx_mtl : public t_cmp<gfx_mtl>, public a_gfx_cmp, public a_data_cmp
	{
	public:
		using shd = mem_ref<a_shd>;
		using shds = darray<shd>;
		using txr = mem_ref<a_txr>;
		using txrs = darray<txr>;
#if (NW_GAPI & NW_GAPI_OGL)
		using handle = GLuint;
#endif
#if (NW_GAPI & NW_GAPI_DX)
		using handle = ptr;
#endif
	public:
		gfx_mtl(gfx_engine& graphics);
		virtual ~gfx_mtl();
		// --getters
		inline shd& get_shd(ui8 idx)	{ return m_shds[idx % m_shds.size()]; }
		inline txr& get_txr(ui8 idx)	{ return m_txrs[idx % m_txrs.size()]; }
		inline handle get_handle()		{ return m_handle; }
		// --setters
		template<typename vtype> void set_value(si32 idx, const vtype& data, ui32 count = 1);
		void add_shd(shd& ref);
		void rmv_shd(ui8 idx);
		void add_txr(txr& ref);
		void rmv_txr(ui8 idx);
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
		// --core_methods
		bit remake();
		virtual void on_draw() override;
	private:
		shds m_shds;
		txrs m_txrs;
		handle m_handle;
	};
}

#endif	// NW_GAPI
#endif	// NWG_MATERIAL_H