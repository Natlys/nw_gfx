#ifndef NWG_TEXTURE_H
#define NWG_TEXTURE_H
#include <nwg_core.hpp>
#include <nwg_res.h>
#if (defined NWG_GAPI)
#include <nwg_tools.h>
namespace NWG
{
	/// Texture class
	/// Description:
	class NWG_API Texture : public TEntity<Texture>, public AGfxRes, public ADataRes
	{
	public:
		TextureWraps m_WrapS, m_WrapT, m_WrapR;
		TextureFilters m_Filter;
		V4f m_rgbaBorder;
	public:
		Texture(GfxEngine& rGfx, const char* strName, TextureTypes texTypes);
		virtual ~Texture();
		// --getters
		inline UInt8 GetTexSlot() const { return m_unSlot; }
		inline TextureTypes GetTexType() const { return m_texType; }
		inline const ImageInfo& GetImgInfo() const { return m_imgInfo; }
		// --setters
		void SetSlot(UInt8 unSlot);
		void SetInfo(const ImageInfo& rImgInfo);
		// --core_methods
		virtual void Bind() override;
		virtual void Remake();
		virtual void Clear(Ptr pValue);
		// --data_methods
		virtual bool SaveF(const char* strFPath);
		virtual bool LoadF(const char* strFPath);
	private:
		TextureTypes m_texType;
		UInt8 m_unSlot;
		ImageInfo m_imgInfo;
#if (NWG_GAPI & NWG_GAPI_DX)
		ID3D11ShaderResourceView* m_pNative;
		ID3D11SamplerState* m_pSampler;
#endif
	};
}
#endif	// NWG_GAPI
#endif // GFX_TEXTURE_H