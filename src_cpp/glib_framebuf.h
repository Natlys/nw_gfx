#ifndef GLIB_AFRAME_BUFFER_H
#define GLIB_AFRAME_BUFFER_H

#include <glib_core.hpp>

#if (defined GLIB_GAPI)
namespace GLIB
{
	/// FrameBufInfo struct
	struct GLIB_API FrameBufInfo
	{
	public:
		V4i xywhViewport = { 0, 0, 1, 1 };
		UInt32 unSamples = 1;
		Bit bSwapChain = false;
		Bit bResizable = true;
		UInt32 unColorCount = 0;
		Bit bHasDepth = false;
		Bit bHasStencil = false;

	public:
		inline Int32 GetWidth() const { return { xywhViewport.z - xywhViewport.x }; }
		inline Int32 GetHeight() const { return { xywhViewport.w - xywhViewport.y }; }
	};
	/// FrameBuffer class
	class GLIB_API FrameBuf : public ADataRes
	{
	public:
		FrameBuf(const char* strName, const FrameBufInfo& rFbInfo);
		virtual ~FrameBuf();

		// --getters
		inline UInt32 GetRenderId() const { return m_unRId; }
		inline Int32 GetWidth() const { return m_Info.GetWidth(); }
		inline Int32 GetHeight() const { return m_Info.GetHeight(); }
		inline Texture* GetAttachment(UInt32 unIdx = 0);
		inline const FrameBufInfo& GetInfo() const { return m_Info; }
		inline V4f GetClearColor() const { return m_rgbaClear; }
		// --setters
		void SetViewport(V4i xywhViewport);
		void SetClearColor(V4f rgbaClear);
		void AttachTexture(RefKeeper<Texture>& rTex);
		void DetachTexture(UInt32 unIdx);
		// --core_methods
		void Bind() const;
		void Unbind() const;
		void Remake();
		void Clear(UInt32 bitMask = FB_COLOR | FB_DEPTH | FB_STENCIL);
		void ReadPixels(Ptr pData, UInt32 unAttachIdx, Int32 nX, Int32 nY, Int32 nWidth = 1, Int32 nHeight = 1);
		void WritePixels(Ptr pData, UInt32 unAttachIdx, Int32 nWidth, Int32 nHeight);
		static void Create(const char* strName, const FrameBufInfo& rFbInfo, RefKeeper<FrameBuf>& rFrameBuf);
		// --data_methods
		virtual bool SaveF(const char* strFPath) override { return true; }
		virtual bool LoadF(const char* strFPath) override { return true; }
	protected:
		mutable Bit m_bIsBound;
		UInt32 m_unRId;
		FrameBufInfo m_Info;
		V4f m_rgbaClear;
		DArray<RefKeeper<Texture>> m_Attachments;
	};
	inline Texture* FrameBuf::GetAttachment(UInt32 unIdx) {
		NWL_ASSERT(unIdx <= m_Attachments.size(), "Overflow");
		return m_Attachments[unIdx].GetRef();
	}
}
#endif	// GLIB_GAPI
#endif // GLIB_AFRAME_BUFFER_H