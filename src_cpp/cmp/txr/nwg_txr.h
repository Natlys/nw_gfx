#ifndef NWG_TEXTURE_H
#define NWG_TEXTURE_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_cmp.h>
#include <lib/nwg_img.h>
#include "nwg_txr_smp.h"
namespace NW
{
	/// abstarct texture class
	/// description:
	class NW_API a_txr : public img_cmp, public a_gfx_cmp
	{
	public:
		using txr_fmt = txr_formats;
		using smp = mem_ref<txr_smp>;
#if (NW_GAPI & NW_GAPI_OGL)
		using handle = GLuint;
#endif
#if (NW_GAPI & NW_GAPI_DX)
		using handle = ID3D11ShaderResourceView*;
#endif
	public:
		a_txr(gfx_engine& graphics);
		virtual ~a_txr();
		// --getters
		inline handle get_handle()			{ return m_handle; }
		inline ui8 get_slot() const			{ return m_slot; }
		inline txr_fmt get_txr_fmt() const	{ return m_txr_fmt; }
		inline smp& get_smp()				{ return m_smp; }
		// --setters
		void set_slot(ui8 txr_slot);
		void set_smp(smp& ref);
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const = 0;
		virtual stm_in& operator>>(stm_in& stm) = 0;
		// --core_methods
		virtual bit remake(const img_cmp& img) = 0;
		virtual void clear(ptr value) = 0;
		virtual void on_draw() override;
	protected:
		handle m_handle;
		ui8 m_slot;
		txr_fmt m_txr_fmt;
		smp m_smp;
	};
}
#endif	// NW_GAPI
#endif // NWG_TEXTURE_H