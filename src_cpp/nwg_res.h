#ifndef NWG_RESOURCE_H
#define NWG_RESOURCE_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	/// Abstract GraphicsResource class
	class NWG_API AGfxRes : public AMemSysUser
	{
		friend class GfxEngine;
	protected:
		AGfxRes(GfxEngine& rGfx);
	public:
		virtual ~AGfxRes();
		// --getters
#if (NWG_GAPI & NWG_GAPI_OGL)
		inline UInt32 const GetRenderId() const { return m_unRId; }
#endif
		// --core_methods
		virtual void Bind() = 0;
	protected:
		GfxEngine* m_pGfx;
#if (NWG_GAPI & NWG_GAPI_OGL)
		UInt32 m_unRId;
#endif
	};
}
#endif
#endif	// NWG_GAPI
#endif	// NWG_RESOURCE_H