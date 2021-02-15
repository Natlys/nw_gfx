#ifndef NWG_TEXTURE_H
#define NWG_TEXTURE_H
#include <nwg_core.hpp>
#include <nwg_entity.h>
#if (defined NWG_GAPI)
#include <nwg_tools.h>
namespace NWG
{
	/// TextureInfo struct
	struct NWG_API TextureInfo
	{
	public:
		TextureWraps WrapTypeS = TXW_REPEAT, WrapTypeT = TXW_REPEAT, WrapTypeR = TXW_REPEAT;
		TextureFilters FilterMin = TXF_NEAREST, FilterMag = TXF_NEAREST;
		TextureFormats texFormat = TXF_RGBA;
		TextureInterFormats texInterFormat = TXFI_RGBA8;
		PixelFormats pxFormat = PXF_UINT8;
		Bit bGenMipmap = true;
		Bit bGenSubImage = true;
		UInt32 unSamples = 1;
	};
}
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	/// Texture class
	/// Description:
	/// -> Set props and data -> LoadData -> MakeTexture -> Bind drawing stuff
	/// -> Enable -> Draw -> Disable
	/// --It's a wrapping image which has to wrap a mesh
	class NWG_API Texture : public GfxEntity, public TDataRes<Texture>
	{
	public:
		Texture(const char* strName, TextureTypes texTypes);
		~Texture();
		// --getters
		inline UInt32 GetTexSlot() const { return m_unTexSlot; }
		inline TextureTypes GetType() const { return m_texType; }
		inline const TextureInfo& GetTexInfo() const { return m_texInfo; }
		inline const ImageInfo& GetImgInfo() const { return m_imgInfo; }
		// --setters
		void SetSlot(UInt32 unSlot) { m_unTexSlot = unSlot; }
		void SetInfo(const TextureInfo& rTexInfo);
		void SetInfo(const ImageInfo& rImgInfo);
		// --core_methods
		virtual void Bind() const override;
		virtual void Remake();
		virtual void Clear(Ptr pValue);
		// --data_methods
		virtual bool SaveF(const char* strFPath);
		virtual bool LoadF(const char* strFPath);
	private:
		TextureTypes m_texType;
		UInt32 m_unTexSlot;
		TextureInfo m_texInfo;
		ImageInfo m_imgInfo;
	};
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	/// Texture class
	/// Description:
	/// -> Set props and data -> LoadData -> MakeTexture -> Bind drawing stuff
	/// -> Enable -> Draw -> Disable
	/// --It's a wrapping image which has to wrap a mesh
	class NWG_API Texture : public TDataRes<Texture>, public GfxEntity
	{
	public:
		Texture(const char* strName, TextureTypes texTypes);
		virtual ~Texture();
		// --core_methods
		virtual void Bind() const override;
		void Unbind();
		void Remake();
		void Clear(Ptr pValue);
		// --data_methods
		virtual bool SaveF(const char* strFPath);
		virtual bool LoadF(const char* strFPath);
	private:
		TextureTypes m_texType;
		UInt32 m_unTexSlot;
		TextureInfo m_texInfo;
		ImageInfo m_imgInfo;
	};
}
#endif
#endif	// NWG_GAPI
#endif // GFX_TEXTURE_H