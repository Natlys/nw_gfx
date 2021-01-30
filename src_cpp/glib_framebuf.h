#ifndef GLIB_AFRAME_BUFFER_H
#define GLIB_AFRAME_BUFFER_H

#include <glib_core.hpp>

#if (defined GLIB_GAPI)
	namespace GLIB
{
	/// FrameBufInfo struct
	struct GLIB_API FrameBufInfo
	{
		UInt32 unWidth = 0, unHeight = 0;
		UInt32 unSamples = 1;

		bool bSwapChainTarget = false;
	};
	/// Abstract FrameBuf class
	class GLIB_API AFrameBuf : public ADataRes
	{
	public:
		AFrameBuf(const char* strName, const FrameBufInfo& rFbInfo);
		virtual ~AFrameBuf();

		// --getters
		inline UInt32 GetRenderId() const { return m_unRId; }
		inline Int16 GetWidth() const { return m_Info.unWidth; }
		inline Int16 GetHeight() const { return m_Info.unHeight; }
		inline ATexture2d* GetColorAttach() { return m_ColorAttach.GetRef(); }
		inline const UInt32 GetDepthAttach() const { return m_DepthAttach; }
		inline const FrameBufInfo& GetInfo() const { return m_Info; }
		inline V4f GetClearColor() const { return m_rgbaClear; }
		// --setters
		void SetSizeWH(UInt32 unWidth, UInt32 unHeight);
		void SetClearColor(V4f rgbaClear);
		// --core_methods
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual void Remake() = 0;
		virtual void Clear() = 0;
		virtual void ReadPixels(Ptr pData, UInt32 unAttachIdx, Int32 nX, Int32 nY, Int32 nW = 1, Int32 nH = 1) = 0;
		virtual void WritePixels(Ptr pData, Int32 nW, Int32 nH) = 0;
		// --data_methods
		virtual bool SaveF(const char* strFPath) override { return true; }
		virtual bool LoadF(const char* strFPath) override { return true; }

		static AFrameBuf* Create(const char* strName, const FrameBufInfo& rFbInfo);
		static void Create(const char* strName, const FrameBufInfo& rFbInfo, RefOwner<AFrameBuf>& rFrameBuf);
		static void Create(const char* strName, const FrameBufInfo& rFbInfo, RefKeeper<AFrameBuf>& rFrameBuf);
	protected:
		mutable Bit m_bIsBound;
		UInt32 m_unRId;
		UInt32 m_DepthAttach;
		RefKeeper<ATexture2d> m_ColorAttach;
		FrameBufInfo m_Info;
		V4f m_rgbaClear;
	};
}
#endif	// GLIB_GAPI
#if (GLIB_GAPI & GLIB_GAPI_OGL)
namespace GLIB
{
	/// FrameBufOpenGL
	class FrameBufOgl : public AFrameBuf
	{
	public:
		FrameBufOgl(const char* strName, const FrameBufInfo& rFbInfo);
		virtual ~FrameBufOgl();

		// --core_methods
		virtual void Bind() const override;
		virtual void Unbind() const override;
		virtual void Remake() override;
		virtual void Clear() override;
		virtual void ReadPixels(Ptr pData, UInt32 unAttachIdx, Int32 nX, Int32 nY, Int32 nW = 1, Int32 nH = 1) override;
		virtual void WritePixels(Ptr pData, Int32 nW, Int32 nH) override;
	};
}
#endif // GLIB_GAPI
#endif // GLIB_AFRAME_BUFFER_H