#ifndef GLIB_ATEXTURE_H
#define GLIB_ATEXTURE_H

#include <glib_core.hpp>

#if (defined GLIB_GAPI)
#include <glib_tools.h>
namespace GLIB
{
	/// SubTexture1d struct
	struct GLIB_API SubTexture1d
	{
	public:
		Int32 nTexCrd = 0;
		Int32 nTexSize = 1;
		Texture* pOverTex = nullptr;
	public:
		// --getters
		inline float GetTexCoord_0_1() const {
			return static_cast<float>(nTexCrd) / static_cast<float>(nOverTexSize);
		}
		inline float GetTexSize_0_1() const {
			return static_cast<float>(nTexSize) / static_cast<float>(nOverTexSize);
		}
	private:
		Int32 nOverTexSize = 0;
	};
	/// SubTexture2d struct
	struct GLIB_API SubTexture2d
	{
	public:
		V2i xyTexCrd = { 0, 0 };
		V2i whTexSize = { 1, 1 };
		Texture* pOverTex = nullptr;
		V2i whOverTexSize = { 0, 0 };
	public:
		// --getters
		inline V2f GetTexCoord_0_1() const {
			return V2f{ static_cast<float>(xyTexCrd.x) / static_cast<float>(whOverTexSize.x),
				static_cast<float>(xyTexCrd.y) / static_cast<float>(whOverTexSize.y) };
		}
		inline V2f GetTexSize_0_1() const {
			return V2f{ static_cast<float>(whTexSize.x) / static_cast<float>(whOverTexSize.x),
				static_cast<float>(whTexSize.y) / static_cast<float>(whOverTexSize.y) };
		}
	private:
	};
	/// SubTexture3d struct
	struct GLIB_API SubTexture3d
	{
	public:
		V3i xyzTexCrd = { 0, 0, 0 };
		V3i whdTexSize = { 1, 1, 1 };
		Texture* pOverTex = nullptr;
	public:
		// --getters
		inline V3f GetTexCoord_0_1() const {
			return V3f{ static_cast<float>(xyzTexCrd.x) / static_cast<float>(whdOverTexSize.x),
				static_cast<float>(xyzTexCrd.y) / static_cast<float>(whdOverTexSize.y),
				static_cast<float>(xyzTexCrd.z) / static_cast<float>(whdOverTexSize.z) };
		}
		inline V3f GetTexSize_0_1() const {
			return V3f{ static_cast<float>(whdTexSize.x) / static_cast<float>(whdOverTexSize.x),
				static_cast<float>(whdTexSize.y) / static_cast<float>(whdOverTexSize.y),
				static_cast<float>(whdTexSize.z) / static_cast<float>(whdOverTexSize.z) };
		}
	private:
		V3i whdOverTexSize = { 1, 1, 1 };
	};
}
namespace GLIB
{
	/// ImageInfo struct
	struct GLIB_API ImageInfo
	{
	public:
		UByte* ClrData;
		Int32 nWidth = 1, nHeight = 1, nDepth = 1;
		Int32 nChannels = 1;
	public:
		inline Size GetDataSize() { return nChannels * nWidth * nHeight * nDepth; }
	};
	/// TextureInfo struct
	struct GLIB_API TextureInfo
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
namespace GLIB
{
	/// Texture class
	/// Description:
	/// -> Set props and data -> LoadData -> MakeTexture -> Bind drawing stuff
	/// -> Enable -> Draw -> Disable
	/// --It's a wrapping image which has to wrap a mesh
	class GLIB_API Texture : public ADataRes
	{
	public:
		Texture(const char* strName, TextureTypes texTypes);
		~Texture();

		// --getters
		inline UInt32 GetRenderId() const { return m_unRId; }
		inline UInt32 GetTexSlot() const { return m_unTexSlot; }
		inline const TextureInfo& GetTexInfo() const { return m_texInfo; }
		inline const ImageInfo& GetImgInfo() const { return m_imgInfo; }
		// --setters
		void SetInfo(const TextureInfo& rTexInfo);
		void SetInfo(const ImageInfo& rImgInfo);
		// --predicates
		inline Bit IsBound() const { return m_bIsBound; }

		// --core_methods
		void Bind(UInt32 unTexSlot = 0);
		void Unbind();
		void Remake();
		static Texture* Create(const char* strName, TextureTypes texType);
		static void Create(const char* strName, TextureTypes texType, RefKeeper<Texture>& rTex);
		// --data_methods
		virtual bool SaveF(const char* strFPath) override;
		virtual bool LoadF(const char* strFPath) override;
	private:
		TextureTypes m_texType;
		UInt32 m_unRId;
		mutable Bit m_bIsBound;
		UInt32 m_unTexSlot;
		TextureInfo m_texInfo;
		ImageInfo m_imgInfo;
	};
}
#endif	// GLIB_GAPI
#endif // GLIB_ATEXTURE_H