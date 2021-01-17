#ifndef GLIB_ATEXTURE_H
#define GLIB_ATEXTURE_H
#include <core/glib_res.h>

#include <glib_tools.h>

#if (defined GLIB_GAPI)
namespace GLIB
{
	/// SubTexture1d struct
	struct GLIB_API SubTexture1d
	{
		friend class ATexture1d;
	public:
		Int32 nTexCrd = 0;
		Int32 nTexSize = 1;
		ATexture1d* pOverTex = nullptr;
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
		friend class ATexture2d;
	public:
		V2i xyTexCrd = { 0, 0 };
		V2i whTexSize = { 1, 1 };
		ATexture2d* pOverTex = nullptr;
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
		friend class ATexture3d;
	public:
		V3i xyzTexCrd = { 0, 0, 0 };
		V3i whdTexSize = { 1, 1, 1 };
		ATexture3d* pOverTex = nullptr;
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
	};
	/// TextureInfo struct
	struct GLIB_API TextureInfo
	{
	public:
		TextureConfigs WrapTypeS = TC_WRAP_REPEAT, WrapTypeT = TC_WRAP_REPEAT, WrapTypeR = TC_WRAP_REPEAT;
		TextureConfigs FilterMin = TC_FILTER_NEAREST, FilterMag = TC_FILTER_NEAREST;
		TextureConfigs Format = TC_FORMAT_RGBA, InterFormat = TC_FORMAT_RGBA;
	};
	/// Abstract Texture class
	/// Description:
	/// -> Set props and data -> LoadData -> MakeTexture -> Bind drawing stuff
	/// -> Enable -> Draw -> Disable
	/// --It's a wrapping image which has to wrap a mesh
	class GLIB_API ATexture : public AGRes
	{
	public:
		ATexture(const char* strName);
		ATexture(ATexture& rCpy);
		virtual ~ATexture();

		// --getters
		inline UInt32 GetRenderId() const { return m_unRId; }
		inline UInt32 GetTexSlot() const { return m_unTexSlot; }
		inline const TextureInfo& GetTexInfo() const { return m_TexInfo; }
		inline const ImageInfo& GetImgInfo() const { return m_ImgInfo; }
		// --setters
		virtual void SetInfo(const TextureInfo& rTexInfo) = 0;
		virtual void SetInfo(const ImageInfo& rImgInfo) = 0;

		// --core_methods
		virtual void Bind(UInt32 unTexSlot) = 0;
		virtual void Unbind() = 0;
		virtual void Remake() = 0;
		// --data_methods
		virtual bool SaveF(const char* strFPath) override { return true; }
		virtual bool LoadF(const char* strFPath) override { return true; }
	protected:
		UInt32 m_unRId;
		UInt32 m_unTexSlot;
		TextureInfo m_TexInfo;
		ImageInfo m_ImgInfo;
		static UByte s_ClearColorData[4];
	};
	/// Abstract Texture1d class
	class GLIB_API ATexture1d : public ATexture
	{
	public:
		ATexture1d(const char* strName);
		ATexture1d(ATexture1d& rCpy);
		virtual ~ATexture1d();

		// --getters
		inline UInt32 GetWidth() const { return m_ImgInfo.nWidth; }
		// --setters
		virtual void SetInfo(const TextureInfo& rTexInfo) = 0;
		virtual void SetInfo(const ImageInfo& rImgInfo) = 0;

		// --core_methods
		virtual void Bind(UInt32 unTexSlot) = 0;
		virtual void Unbind() = 0;
		virtual void Remake() = 0;
		// --data_methods
		virtual bool SaveF(const char* strFPath) override;
		virtual bool LoadF(const char* strFPath) override;

		static ATexture1d* Create(const char* strName);
	};
	/// Abstract Texture2d class
	class GLIB_API ATexture2d : public ATexture
	{
	public:
		ATexture2d(const char* strName);
		ATexture2d(ATexture2d& rCpy);
		virtual ~ATexture2d();

		// --getters
		inline UInt32 GetWidth() const { return m_ImgInfo.nWidth; }
		inline UInt32 GetHeight() const { return m_ImgInfo.nHeight; }
		inline const DArray<SubTexture2d>& GetSubTexs() const { return m_SubTexs; }
		// --setters
		virtual void SetInfo(const TextureInfo& rTexInfo) = 0;
		virtual void SetInfo(const ImageInfo& rImgInfo) = 0;
		void SetSubTexs(const DArray<SubTexture2d>& rSubTexs);
		// --core_methods
		virtual void Bind(UInt32 unTexSlot) = 0;
		virtual void Unbind() = 0;
		virtual void Remake() = 0;
		// --data_methods
		virtual bool SaveF(const char* strFPath) override;
		virtual bool LoadF(const char* strFPath) override;

		static ATexture2d* Create(const char* strName);
	private:
		DArray<SubTexture2d> m_SubTexs;
	};
	/// Abstract Texture3d class
	class GLIB_API ATexture3d : public ATexture
	{
	public:
		ATexture3d(const char* strName);
		ATexture3d(ATexture3d& rCpy);
		virtual ~ATexture3d();

		// --getters
		inline UInt32 GetWidth() const { return m_ImgInfo.nWidth; }
		inline UInt32 GetHeight() const { return m_ImgInfo.nHeight; }
		inline UInt32 GetDepth() const { return m_ImgInfo.nDepth; }
		// --setters
		virtual void SetInfo(const TextureInfo& rTexInfo) = 0;
		virtual void SetInfo(const ImageInfo& rImgInfo) = 0;

		// --core_methods
		virtual void Bind(UInt32 unTexSlot) = 0;
		virtual void Unbind() = 0;
		virtual void Remake() = 0;
		// --data_methods
		virtual bool SaveF(const char* strFPath) override;
		virtual bool LoadF(const char* strFPath) override;

		static ATexture3d* Create(const char* strName);
	};
}
#endif	// GLIB_GAPI
#if (GLIB_GAPI & GLIB_GAPI_OGL)
namespace GLIB
{
	/// Texture1dOgl Class
	class GLIB_API Texture1dOgl : public ATexture1d
	{
	public:
		Texture1dOgl(const char* strName);
		~Texture1dOgl();

		// --setters
		virtual void SetInfo(const TextureInfo& rTexImfo) override;
		virtual void SetInfo(const ImageInfo& rImgInfo) override;

		// --core_methods
		virtual void Bind(UInt32 unTexSlot) override;
		virtual void Unbind() override;
		virtual void Remake() override;
	};
	/// Texture2dOgl Class
	class GLIB_API Texture2dOgl : public ATexture2d
	{
	public:
		Texture2dOgl(const char* strName);
		~Texture2dOgl();

		// --setters
		virtual void SetInfo(const TextureInfo& rTexImfo) override;
		virtual void SetInfo(const ImageInfo& rImgInfo) override;

		// --core_methods
		virtual void Bind(UInt32 unTexSlot) override;
		virtual void Unbind() override;
		virtual void Remake() override;
	};
	/// Texture3dOgl Class
	class GLIB_API Texture3dOgl : public ATexture3d
	{
	public:
		Texture3dOgl(const char* strName);
		~Texture3dOgl();

		// --setters
		virtual void SetInfo(const TextureInfo& rTexImfo) override;
		virtual void SetInfo(const ImageInfo& rImgInfo) override;

		// --core_methods
		virtual void Bind(UInt32 unTexSlot) override;
		virtual void Unbind() override;
		virtual void Remake() override;
	};
}
#endif // GLIB_GAPI

#endif // GLIB_ATEXTURE_H