#ifndef NW_GFX_TEXTURE_2D_H
#define NW_GFX_TEXTURE_2D_H
#include "nw_gfx_core.hpp"
#if (defined NW_GAPI)
#	include "nw_gfx_txr.h"
namespace NW
{
	/// gfx_txr_2d class
	/// description:
	class NW_API gfx_txr_2d : public gfx_txr
	{
	public:
		gfx_txr_2d();
		virtual ~gfx_txr_2d();
		// --getters
		// --setters
		// --predicates
		// --operators
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		virtual v1bit remake() override;
		virtual v1nil clear(ptr_tc data) override;
		virtual v1nil on_draw() override;
	public:
#	if (NW_GAPI & NW_GAPI_D3D)
		ID3D11Texture2D* m_native;
#	endif
	};
	// gfx_txr_2d_multisample class
	class NW_API gfx_txr_2d_mulsmp : public gfx_txr_2d
	{
	public:
		gfx_txr_2d_mulsmp();
		~gfx_txr_2d_mulsmp();
		// --getters
		inline v1u get_samples() const { return m_samples; }
		// --setters
		v1nil set_samples(v1u samples);
		// --operators
		virtual op_stream_t& operator<<(op_stream_t& stm) const override;
		virtual ip_stream_t& operator>>(ip_stream_t& stm) override;
		// --core_methods
		virtual v1bit remake();
		virtual v1nil on_draw() override;
	private:
		v1u m_samples;
#	if (NW_GAPI & NW_GAPI_D3D)
		ID3D11Texture2D* m_native;
#	endif
	};
}
#endif	// NW_GAPI
#endif // NW_GFX_TEXTURE_2D_H
