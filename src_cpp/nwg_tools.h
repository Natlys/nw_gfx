#ifndef NWG_TOOLS_H
#define NWG_TOOLS_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
namespace NWG
{
	template<typename DType> DataTypes DtGet();
	template<typename NwEnum, typename ConvType> ConvType ConvertEnum(NwEnum nwEnum);
	
	const char* DtGetStr(DataTypes sdType);
	Size DtGetSize(DataTypes sDataType, UInt32 unCount = 1);
	Size DtGetAlignedSize(DataTypes sDataType, UInt32 unCount = 1);
}
namespace NWG
{
	struct NWG_API GfxContextInfo
	{
	public:
		Char strRenderer[256], strVersion[256], strVendor[256], strShdLang[256];
		Int32 nMaxVertexAttribs = 0;
		Int32 nActiveTextureId = 0;
		Int32 nMaxTextures = 0;
	public:
		OStream& operator<<(OStream& rStream);
	};
	struct NWG_API GfxDrawInfo
	{
	public:
		Size szVtx = 0;
		Size szIdx = 0;
		UInt32 unIdx = 0;
		UInt32 unVtx = 0;
		DataTypes sdIdx = DT_UINT32;
	public:
		void Reset() { szVtx = szIdx = 0; unIdx = unVtx = 0; }
	};
	struct NWG_API GfxDataInfo
	{
	public:
		Size szData = 0;
		UInt32 szStride = 0;
		UInt32 szOffset = 0;
		Ptr pData = nullptr;
		DataTypes sdType = DT_DEFAULT;
	public:
		GfxDataInfo() = default;
		GfxDataInfo(Size sizeOfData, Size sizeOfStride, Size sizeOfOffset,
			Ptr ptrToData, DataTypes dataType);
		GfxDataInfo(Size sizeOfData, Size sizeOfStride, Size sizeOfOffset, Ptr ptrToData);
		// --operators
		OStream& operator<<(OStream& rStream);
	};
}
namespace NWG
{
	struct NWG_API GfxConfig {
		struct {
			struct {
				DrawModes dMode = DM_FILL;
				FacePlanes facePlane = FACE_DEFAULT;
			} PolyMode;
			Float32 nLineWidth = 0.5f;
			Float32 nPixelSize = 0.5f;
			UInt32 unSwapInterval = 1u;
		} General;
		struct {
			Bit bEnable = false;
			BlendConfigs FactorSrc = BC_SRC_ALPHA;
			BlendConfigs FactorDest = BC_ONE_MINUS_SRC_ALPHA;
		} Blending;
		struct {
			Bit bEnable = false;
			CullFaceConfigs CullFactor = CFC_DEFAULT;
		} Culling;
		struct {
			Bit bEnable = false;
			DepthConfigs Func = DTC_DEFAULT;
		} DepthTest;
		struct {
			Bit bEnable = false;
			StencilConfigs Func = STC_DEFAULT;
			UInt8 nBitMask = 0x0;
			UInt32 nRefValue = 0x0;
		} StencilTest;
	public:
		void Reset();
	};
}

#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	void OglClearErr();
	bool OglErrLog(const char* strInfo, const char* strFile, int nLine);
	int OglErrLogShader(ShaderTypes ShaderType, UInt32 unShaderId);
}
	#if (defined NWG_DEBUG)
			#define NWG_DEBUG_CALL(code) ( OglClearErr(); (code) NWL_ASSERT(OglErrLog(#call, __FILE__, __LINE__, "GL_ERROR: "))
	#else
		#define NWG_DEBUG_CALL(code) (code)
	#endif
#endif

#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	void DxClearErr();
	bool DxErrLog(const char* strInfo, const char* strFile, int nLine);
}
	#if (defined NWG_DEBUG)
		#define NWG_DEBUG_CALL(call) ( DxClearErr(); (call) NWL_ASSERT(DxErrLog(#call, __FILE__, __LINE__, "GL_ERROR: "))
	#else
		#define NWG_DEBUG_CALL(code) (code)
	#endif
#endif

#endif	// NWG_GAPI
#endif	// NWG_TOOLS_H