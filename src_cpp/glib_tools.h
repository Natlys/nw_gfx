#ifndef GLIB_TOOLS_H
#define GLIB_TOOLS_H
#include <glib_decl.hpp>

#if (defined GLIB_GAPI)
// Functions
namespace GLIB
{
	inline Size SDTypeGetSize(ShaderDataTypes sDataType, UInt32 unCount = 1) {
		Size szData = 0;
		switch (sDataType) {
		case SDT_BOOL:	case SDT_INT8:		case SDT_UINT8:		szData = 1;	break;
		case SDT_INT16:	case SDT_UINT16:	case SDT_SAMPLER:	szData = 4;	break;
		case SDT_INT32:	case SDT_UINT32:	case SDT_FLOAT32:	szData = 4;	break;
		case SDT_FLOAT64:										szData = 8;	break;
		default:	GLIB_ERR("Invalid shader data type");			szData = 0;	break;
		}
		return szData * unCount;
	}
	inline Size SDTypeGetAllignedSize(ShaderDataTypes sDataType, UInt32 unCount = 1) {
		Size szAll = 0;
		switch (sDataType) {
		case SDT_BOOL:	case SDT_INT8:	case SDT_UINT8:			szAll = 4;	break;
		case SDT_INT16:	case SDT_UINT16:						szAll = 4;	break;
		case SDT_INT32:	case SDT_UINT32:	case SDT_SAMPLER:	szAll = 4;	break;
		case SDT_FLOAT32:										szAll = 4;	break;
		case SDT_FLOAT64:										szAll = 8;	break;
		default:	GLIB_ERR("Invalid shader data type");			szAll = 0;	break;
		}
		return szAll * ((unCount + (szAll - 1)) & ~(szAll - 1));
	}
	inline const char* SDTypeGetString(ShaderDataTypes sdType) {
		return sdType == SDT_BOOL ? "boolean" :
			sdType == SDT_INT8 ? "byte" : sdType == SDT_UINT8 ? "unsigned byte" :
			sdType == SDT_INT16 ? "short" : sdType == SDT_UINT16 ? "unsigned short" :
			sdType == SDT_INT32 ? "integer" : sdType == SDT_UINT32 ? "unsigned integer" :
			sdType == SDT_FLOAT32 ? "float" : sdType == SDT_FLOAT64 ? "double" :
			"unknown";
	}
}
// Vertex
namespace GLIB
{
	/// Vertex for 1D objects
	/// -- XYZ coordinates for vertices
	/// -- RGBA color for vertices
	/// -- X coordinate for texture sampling
	/// -- Index for the texture slot
	struct GLIB_API VertexBatch1d
	{
		V3f vtxCrd;
		V4f vtxClr;
		float texCrd;
		float nTexSlot;
	};
	/// Vertex for 2D objects
	/// -- XY coordinates for vertices
	/// -- RGBA color for vertices
	/// -- UV coordinates for texture coordinates
	/// -- Index for the texture slot
	struct GLIB_API VertexBatch2d
	{
		V2f vtxCrd;
		V4f vtxClr;
		V2f texCrd;
		float nTexSlot;
	};
	/// Vertex for 3D objects
	/// -- XYZ coordinates for vertices
	/// -- RGBA color for vertices
	/// -- XY coordinates for texture sampling
	/// -- Index for the texture slot
	struct GLIB_API VertexBatch3d
	{
		V3f vtxCrd;
		V4f vtxClr;
		V2f texCrd;
		float nTexSlot;
		Mat4f m4Transform;
	};
	/// Vertex for 3D world
	/// -- XYZ coordinates for vertex coordinates
	/// -- UV coordinates for texture coordinates
	/// -- XYZ coordinates for normals
	struct GLIB_API VertexShape3d
	{
		V3f vtxCrd;
		V2f texCrd;
		V3f normCrd;

		VertexShape3d() :
			vtxCrd{}, texCrd{}, normCrd{} {}
		VertexShape3d(const V3f& vCoord, const V2f& vUV, const V3f& vNorm) :
			vtxCrd(vCoord), texCrd(vUV), normCrd(vNorm) {}
	};
}
// Drawing data
namespace GLIB
{
	/// DrawObjectData struct
	struct GLIB_API DrawObjectData
	{
		DArray<UByte> vtxData = DArray<UByte>(1, 1);
		DArray<UInt32> idxData = DArray<UInt32>(1, 1);
		UInt8 unDrawOrder = 0;
		GMaterial* pGMtl = nullptr;
	public:
		// --getters
		inline const UByte* GetVtxData() const { return &vtxData[0]; }
		inline const UInt32* GetIdxData() const { return &idxData[0]; }
		inline Size GetVtxSize() const { return vtxData.size(); }
		inline Size GetIdxSize() const { return idxData.size() * sizeof(UInt32); }
		inline Size GetIdxCount() const { return idxData.size(); }
		// --operators
		inline bool operator>	(const DrawObjectData& rDOData)	const { return rDOData.unDrawOrder > unDrawOrder; }
		inline bool operator>=	(const DrawObjectData& rDOData)	const { return rDOData.unDrawOrder >= unDrawOrder; }
		inline bool operator==	(const DrawObjectData& rDOData)	const { return rDOData.unDrawOrder == unDrawOrder; }
		inline bool operator<=	(const DrawObjectData& rDOData)	const { return rDOData.unDrawOrder <= unDrawOrder; }
		inline bool operator<	(const DrawObjectData& rDOData)	const { return rDOData.unDrawOrder < unDrawOrder; }
	};
	/// DrawSceneData struct
	struct GLIB_API DrawSceneData
	{
		Mat4f m4Proj;
		Mat4f m4View;
	public:
		DrawSceneData() : pData(&m4Proj[0]), szData(sizeof(Mat4f) * 2) {}
		// --getters
		inline const UByte* GetData() const { return static_cast<UByte*>(pData); }
		inline Size GetDataSize() const { return szData; }
	private:
		void* pData;
		Size szData;
	};
	/// RenderAttributes struct
	/// Description:
	/// -- Check and change renderer attributes for more or less performance/resource usage
	struct GLIB_API GEngineInfo
	{
	public:
		// --counters
		Size szVtx = 0;
		Size unVtx = 0;
		Size szIdx = 0;
		Size unIdx = 0;
		Size szShd = 0;
		UInt32 unTex = 0;
		// --drawing
		UInt16 unDrawCalls = 0;
	public:
		// --setters
		inline void Reset() {
			szVtx = szIdx = szShd = 0;
			unVtx = unIdx = unTex = 0;
			unDrawCalls = 0;
		}
	};
	struct GLIB_API DrawTools {
	public:
		// --vertex_data
		UByte* pVtxData = nullptr;
		UByte* pVtxIter = nullptr;
		Size szVtxData = 0;
		// --index_data
		UInt32* pIdxIter = nullptr;
		UInt32* pIdxData = nullptr;
		Size szIdxData = 0;
		// --shader_data
		UByte* pShdData = nullptr;
		UByte* pShdIter = nullptr;
		Size szShdData = 0;
		// --texture_data
		ATexture* pTextures[GLIB_MAX_TEXTURES];
		UInt8 unTexCount = 0;
		// --objects
		AShader* pShader = nullptr;
		AVertexBuf* pVtxBuf = nullptr;
		AIndexBuf* pIdxBuf = nullptr;
		AShaderBuf* pShdBuf = nullptr;
	public:
		inline void ResetData() {
			pVtxIter = &pVtxData[0];
			szVtxData = 0;
			pIdxIter = &pIdxData[0];
			szIdxData = 0;
			pShdIter = &pShdData[0];
			szShdData = 0;
			for (UInt8 txi = 0; txi < unTexCount; txi++) { pTextures[txi] = nullptr; }
			unTexCount = 0;
		}
	};
	struct GLIB_API DrawConfig {
		struct {
			GPrimitiveTypes GPrimitive = PT_TRIANGLES;
			DrawModes DMode = DM_FILL;
			Float32 nLineWidth = 0.5f;
			Float32 nPixelSize = 0.5f;
		} General;
		struct {
			bool bEnable = false;
			BlendConfigs FactorSrc = BC_SRC_ALPHA;
			BlendConfigs FactorDest = BC_ONE_MINUS_SRC_ALPHA;
		} Blending;
		struct {
			bool bEnable = false;
			DepthConfigs Func = DC_GREATER;
		} DepthTest;
	public:
		inline void Reset() {
			General.GPrimitive = PT_TRIANGLES;
			General.DMode = DM_FILL;
			General.nLineWidth = 0.5f;
			General.nPixelSize = 0.5f;

			Blending.bEnable = false;
			Blending.FactorSrc = BC_SRC_ALPHA;
			Blending.FactorDest = BC_ONE_MINUS_SRC_ALPHA;

			DepthTest.bEnable = false;
			DepthTest.Func = DC_GREATER;
		}
	};
}
// Pixel
namespace GLIB
{
	/// Pixel structure
	/// Description:
	/// -- Represents color in rgba for float and unsigned integer formats
	struct GLIB_API Pixel
	{
	public:
		explicit Pixel(float red = 0, float green = 0, float blue = 0, float alpha = 0) :
			ur(static_cast<UInt8>(red * 255.0f)),
			ug(static_cast<UInt8>(green * 255.0f)),
			ub(static_cast<UInt8>(blue * 255.0f)),
			ua(static_cast<UInt8>(alpha * 255.0f)) {}
		explicit Pixel(Int32 red, Int32 green, Int32 blue, Int32 alpha = 0) :
			ur(static_cast<UInt8>(red)),
			ug(static_cast<UInt8>(green)),
			ub(static_cast<UInt8>(blue)),
			ua(static_cast<UInt8>(alpha)) {}
		explicit Pixel(Int8 rgbaColor) :
			ur(static_cast<UInt8>(rgbaColor)),
			ug(static_cast<UInt8>(rgbaColor)),
			ub(static_cast<UInt8>(rgbaColor)),
			ua(static_cast<UInt8>(rgbaColor)) {};
		explicit Pixel(V4f rgbaColor)
		{
			ur = static_cast<UInt8>(rgbaColor.r * 255.0f);
			ug = static_cast<UInt8>(rgbaColor.g * 255.0f);
			ub = static_cast<UInt8>(rgbaColor.b * 255.0f);
			ua = static_cast<UInt8>(rgbaColor.a * 255.0f);
		}
		Pixel(UInt32 unRgba) { this->unRgba = unRgba; }

		union { UInt32 unRgba; struct { UInt8 ur, ug, ub, ua; }; struct { Int8 r, g, b, a; }; };
	public:
		// -- Convertion to float
		inline const float fR() const { return static_cast<float>(ur) / 255.0f; }
		inline const float fG() const { return static_cast<float>(ug) / 255.0f; }
		inline const float fB() const { return static_cast<float>(ub) / 255.0f; }
		inline const float fA() const { return static_cast<float>(ua) / 255.0f; }
		inline operator V4f() { return V4f{ fR(), fG(), fB(), fA() }; }
		// -- Operations with other pixels
		inline Pixel operator+(const Pixel& rPixel) {
			return Pixel(static_cast<Int8>(r + rPixel.r), static_cast<Int8>(g + rPixel.g),
				static_cast<Int8>(b + rPixel.b), static_cast<Int8>(a + rPixel.a));
		}
		inline Pixel operator-(const Pixel& rPixel) {
			return Pixel(static_cast<Int8>(r - rPixel.r), static_cast<Int8>(g - rPixel.g),
				static_cast<Int8>(b - rPixel.b), static_cast<Int8>(a - rPixel.a));
		}
		inline Pixel operator*(const Pixel& rPixel) {
			return Pixel(static_cast<Int8>(r * rPixel.r), static_cast<Int8>(g * rPixel.g),
				static_cast<Int8>(b * rPixel.b), static_cast<Int8>(a * rPixel.a));
		}
		inline Pixel operator/(const Pixel& rPixel) {
			return Pixel(static_cast<Int8>(r / rPixel.r), static_cast<Int8>(g / rPixel.g),
				static_cast<Int8>(b / rPixel.b), static_cast<Int8>(a / rPixel.a));
		}
		inline Pixel operator+=(const Pixel& rPixel) { r + rPixel.r; g + rPixel.g; b + rPixel.b; a + rPixel.a; return *this; }
		inline Pixel operator-=(const Pixel& rPixel) { r - rPixel.r; g - rPixel.g; b - rPixel.b; a - rPixel.a; return *this; }
		inline Pixel operator*=(const Pixel& rPixel) { r* rPixel.r; g* rPixel.g; b* rPixel.b; a* rPixel.a; return *this; }
		inline Pixel operator/=(const Pixel& rPixel) { r / rPixel.r; g / rPixel.g; b / rPixel.b; a / rPixel.a; return *this; }
		// -- Operations with float vector
		inline Pixel operator+(const V4f& rColor) {
			Pixel rPixel(rColor);
			return Pixel(r + rPixel.r, g + rPixel.g, b + rPixel.b, a + rPixel.a);
		}
		inline Pixel operator-(const V4f& rColor)
		{
			Pixel rPixel(rColor);
			return Pixel(r - rPixel.r, g - rPixel.g, b - rPixel.b, a - rPixel.a);
		}
		inline Pixel operator*(const V4f& rColor)
		{
			Pixel rPixel(rColor);
			return Pixel(r * rPixel.r, g * rPixel.g, b * rPixel.b, a * rPixel.a);
		}
		inline Pixel operator/(const V4f& rColor)
		{
			Pixel rPixel(rColor);
			return Pixel(r / rPixel.r, g / rPixel.g, b / rPixel.b, a / rPixel.a);
		}
		inline Pixel& operator+=(const V4f& rColor)
		{
			r += static_cast<Int8>(rColor.r) * 255.0f;
			g += static_cast<Int8>(rColor.g) * 255.0f;
			b += static_cast<Int8>(rColor.b) * 255.0f;
			a += static_cast<Int8>(rColor.a) * 255.0f;
			return *this;
		}
		inline Pixel& operator-=(const V4f& rColor)
		{
			r -= static_cast<Int8>(rColor.r) * 255.0f;
			g -= static_cast<Int8>(rColor.g) * 255.0f;
			b -= static_cast<Int8>(rColor.b) * 255.0f;
			a -= static_cast<Int8>(rColor.a) * 255.0f;
			return *this;
		}
		inline Pixel& operator*=(const V4f& rColor)
		{
			r *= static_cast<Int8>(rColor.r) * 255.0f;
			g *= static_cast<Int8>(rColor.g) * 255.0f;
			b *= static_cast<Int8>(rColor.b) * 255.0f;
			a *= static_cast<Int8>(rColor.a) * 255.0f;
			return *this;
		}
		inline Pixel& operator/=(const V4f& rColor)
		{
			r /= static_cast<Int8>(rColor.r) * 255.0f;
			g /= static_cast<Int8>(rColor.g) * 255.0f;
			b /= static_cast<Int8>(rColor.b) * 255.0f;
			a /= static_cast<Int8>(rColor.a) * 255.0f;
			return *this;
		}
	};
}
#endif	// GLIB_GAPI
#if (GLIB_GAPI & GLIB_GAPI_OGL)
#define GL_DEBUG_ERR_LOG(errType, objectID) (OGL_ErrLog_Shader(errType, objectID))
// Functions
namespace GLIB
{
	// Debug
	/// Clear GL error buffer
	extern void OGL_ClearErr();
	/// Return suitable error message accordingly to glGetError()
	extern bool OGL_ErrLog(const char* funcName, const char* file, int line);
	/// Get compile and linking status return true if there are errors
	extern int OGL_ErrLog_Shader(ShaderTypes ShaderType, UInt32 unShaderId);
}
#endif // GLIB_GAPI
#endif // GLIB_TOOLS_H