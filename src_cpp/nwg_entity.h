#ifndef NWG_ENTITY_H
#define NWG_ENTITY_H

#include <nwg_core.hpp>

#if (defined NWG_GAPI)
namespace NWG
{
	/// GraphicsEntityOpenGL class
	class NWG_API GfxEntity : public TEntity<GfxEntity>
	{
	public:
		GfxEntity() : TEntity(), m_pGfx(nullptr), m_unRId(0) {}
		virtual ~GfxEntity() {}
		// --getters
		inline UInt32 const GetRenderId() const { return m_unRId; }
		// --core_methods
		virtual void Bind() const = 0;
	protected:
		GfxEngine* m_pGfx;
#if (NWG_GAPI & NWG_GAPI_OGL)
		UInt32 m_unRId;
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#endif
	};
}
#endif	// NWG_GAPI
#endif	// NWG_ENTITY_H