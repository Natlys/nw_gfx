#ifndef NWG_TEXTURE_2D_H
#define NWG_TEXTURE_2D_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include "nwg_txr.h"
namespace NW
{
	/// txr_2d class
	/// description:
	class NW_API txr_2d : public a_txr
	{
	public:
		txr_2d(gfx_engine& graphics);
		virtual ~txr_2d();
		// --setters
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
		// --core_methods
		virtual bit remake(const img_cmp& img) override;
		virtual void clear(ptr value) override;
		virtual void on_draw() override;
	private:
#if (NW_GAPI & NW_GAPI_DX)
		ID3D11Texture2D* m_native;
#endif
	};
	// txr_2d_multisample class
	class NW_API txr_2d_mulsmp : public txr_2d
	{
	public:
		txr_2d_mulsmp(gfx_engine& graphics);
		~txr_2d_mulsmp();
		// --getters
		inline ui8 get_samples() const		{ return m_samples; }
		// --setters
		void set_samples(ui8 samples);
		// --operators
		virtual stm_out& operator<<(stm_out& stm) const override;
		virtual stm_in& operator>>(stm_in& stm) override;
		// --core_methods
		virtual bit remake(const img_cmp& img) override;
		virtual void on_draw() override;
	private:
		ui8 m_samples;
#if (NW_GAPI & NW_GAPI_DX)
		ID3D11Texture2D* m_native;
#endif
	};
}
#endif	// NW_GAPI
#endif // NWG_TEXTURE_2D_H