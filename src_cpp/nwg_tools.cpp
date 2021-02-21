#include <nwg_pch.hpp>
#include "nwg_tools.h"
#pragma warning (disable: 4312)
#if (defined NWG_GAPI)
#include <nwg_loader.h>
namespace NWG
{
	template<>DataTypes DtGet<Int8>()	{ return DT_SINT8; }
	template<>DataTypes DtGet<V2i8>()	{ return DT_VEC2_SINT8; }
	template<>DataTypes DtGet<V3i8>()	{ return DT_VEC3_SINT8; }
	template<>DataTypes DtGet<V4i8>()	{ return DT_VEC4_SINT8; }

	template<>DataTypes DtGet<UInt8>()	{ return DT_SINT8; }
	template<>DataTypes DtGet<V2u8>()	{ return DT_VEC2_UINT8; }
	template<>DataTypes DtGet<V3u8>()	{ return DT_VEC3_UINT8; }
	template<>DataTypes DtGet<V4u8>()	{ return DT_VEC4_UINT8; }

	template<>DataTypes DtGet<Int16>()	{ return DT_SINT16; }
	template<>DataTypes DtGet<V2i16>()	{ return DT_VEC2_SINT16; }
	template<>DataTypes DtGet<V3i16>()	{ return DT_VEC3_SINT16; }
	template<>DataTypes DtGet<V4i16>()	{ return DT_VEC4_SINT16; }

	template<>DataTypes DtGet<UInt16>()	{ return DT_UINT16; }
	template<>DataTypes DtGet<V2u16>()	{ return DT_VEC2_UINT16; }
	template<>DataTypes DtGet<V3u16>()	{ return DT_VEC3_UINT16; }
	template<>DataTypes DtGet<V4u16>()	{ return DT_VEC4_UINT16; }

	template<>DataTypes DtGet<Int32>()	{ return DT_SINT32; }
	template<>DataTypes DtGet<V2i>()	{ return DT_VEC2_SINT32; }
	template<>DataTypes DtGet<V3i>()	{ return DT_VEC3_SINT32; }
	template<>DataTypes DtGet<V4i>()	{ return DT_VEC4_SINT32; }

	template<>DataTypes DtGet<UInt32>()	{ return DT_UINT32; }
	template<>DataTypes DtGet<V2u>()	{ return DT_VEC2_UINT32; }
	template<>DataTypes DtGet<V3u>()	{ return DT_VEC3_UINT32; }
	template<>DataTypes DtGet<V4u>()	{ return DT_VEC4_UINT32; }

	template<>DataTypes DtGet<Float32>(){ return DT_FLOAT32; }
	template<>DataTypes DtGet<V2f>()	{ return DT_VEC2_FLOAT32; }
	template<>DataTypes DtGet<V3f>()	{ return DT_VEC3_FLOAT32; }
	template<>DataTypes DtGet<V4f>()	{ return DT_VEC4_FLOAT32; }

#if (NWG_GAPI & NWG_GAPI_OGL)
	template<> UInt32 ConvertEnum<DataTypes, UInt32>(DataTypes nwEnum) {
		switch (dType) {
		case DT_BOOL: return GL_BOOL;
		case DT_SINT8: return GL_BYTE;
		case DT_VEC2_SINT8: return GL_BYTE;
		case DT_VEC3_SINT8: case DT_VEC4_SINT8: return GL_BYTE;

		case DT_UINT8: return GL_UNSIGNED_BYTE;
		case DT_VEC2_UINT8: return GL_UNSIGNED_BYTE;
		case DT_VEC3_UINT8: return GL_UNSIGNED_BYTE;
		case DT_VEC4_UINT8: return GL_UNSIGNED_BYTE;

		case DT_SINT16: return GL_SHORT;
		case DT_VEC2_SINT16: return GL_SHORT;
		case DT_VEC3_SINT16: return GL_SHORT;
		case DT_VEC4_SINT16: return GL_SHORT;

		case DT_UINT16: return GL_UNSIGNED_SHORT;
		case DT_VEC2_UINT16: return GL_UNSIGNED_SHORT;
		case DT_VEC3_UINT16: return GL_UNSIGNED_SHORT;
		case DT_VEC4_UINT16: return GL_UNSIGNED_SHORT;

		case DT_SINT32: return GL_INT;
		case DT_VEC2_SINT32: return GL_INT;
		case DT_VEC3_SINT32: return GL_INT;
		case DT_VEC4_SINT32: return GL_INT;

		case DT_UINT32: return GL_UNSIGNED_INT;
		case DT_VEC2_UINT32: return GL_UNSIGNED_INT;
		case DT_VEC3_UINT32: return GL_UNSIGNED_INT;
		case DT_VEC4_UINT32: return GL_UNSIGNED_INT;

		case DT_FLOAT32: return GL_FLOAT;
		case DT_VEC2_FLOAT32: return GL_FLOAT16_VEC2_NV;
		case DT_VEC3_FLOAT32: return GL_FLOAT16_VEC3_NV;
		case DT_VEC4_FLOAT32: return GL_FLOAT16_VEC4_NV;

		default: throw Exception("unsupported format", ERC_NO_SUPPORT); break;
}
		return DT_DEFAULT;
	}
	template<> UInt32 ConvertEnum<GfxPrimitives, UInt32>(GfxPrimitives nwEnum) {
		switch (gpType) {
		case GPT_POINTS: return GL_POINTS; break;
		case GPT_TRIANGLES: return GL_TRIANGLES; break;
		case GPT_TRIANGLE_STRIP: return GL_TRIANGLE_STRIP; break;
		case GPT_TRIANGLE_FAN: return GL_TRIANGLE_FAN; break;
		case GPT_LINES: return GL_LINES; break;
		case GPT_LINE_LOOP: return GL_LINE_LOOP; break;
		case GPT_LINE_STRIP: return GL_LINE_STRIP; break;
		default: throw Exception("unavailable primitive topology", ERC_INVALID_ENUM); break;
		}
		return GL_TRIANGLES;
	}
	template<> UInt32 ConvertEnum<TextureTypes, UInt32>(TextureTypes nwEnum) {
		switch (texType) {
		default: throw Exception("unsupported texture type", ERC_NO_SUPPORT); break;
		}
		return GL_TEXTURE2D;
	}
	template<> UInt32 ConvertEnum<PixelFormats, UInt32>(PixelFormats pxlFormat) {
		switch (pxlFormat) {
		default: throw Exception("unsupported pixel format", ERC_NO_SUPPORT); break;
		}
		return GL_RGB;
	}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
	template<> DXGI_FORMAT ConvertEnum<DataTypes, DXGI_FORMAT>(DataTypes dType) {
		switch (dType) {
		case DT_BOOL: return DXGI_FORMAT_R8_UINT;
		case DT_SINT8: return DXGI_FORMAT_R8_SINT;
		case DT_VEC2_SINT8: return DXGI_FORMAT_R8_SINT;
		case DT_VEC3_SINT8: case DT_VEC4_SINT8: return DXGI_FORMAT_R8G8B8A8_SINT;

		case DT_UINT8: return DXGI_FORMAT_R8_UINT;
		case DT_VEC2_UINT8: return DXGI_FORMAT_R8_UINT;
		case DT_VEC3_UINT8: return DXGI_FORMAT_R8G8B8A8_UINT;
		case DT_VEC4_UINT8: return DXGI_FORMAT_R8G8B8A8_UINT;

		case DT_SINT16: return DXGI_FORMAT_R16_SINT;
		case DT_VEC2_SINT16: return DXGI_FORMAT_R16_SINT;
		case DT_VEC3_SINT16: return DXGI_FORMAT_R16G16B16A16_SINT;
		case DT_VEC4_SINT16: return DXGI_FORMAT_R16G16B16A16_SINT;

		case DT_UINT16: return DXGI_FORMAT_R16_UINT;
		case DT_VEC2_UINT16: return DXGI_FORMAT_R16_UINT;
		case DT_VEC3_UINT16: return DXGI_FORMAT_R16G16B16A16_UINT;
		case DT_VEC4_UINT16: return DXGI_FORMAT_R16G16B16A16_UINT;

		case DT_SINT32: return DXGI_FORMAT_R32_SINT;
		case DT_VEC2_SINT32: return DXGI_FORMAT_R32_SINT;
		case DT_VEC3_SINT32: return DXGI_FORMAT_R32G32B32_SINT;
		case DT_VEC4_SINT32: return DXGI_FORMAT_R32G32B32A32_SINT;

		case DT_UINT32: return DXGI_FORMAT_R32_UINT;
		case DT_VEC2_UINT32: return DXGI_FORMAT_R32_UINT;
		case DT_VEC3_UINT32: return DXGI_FORMAT_R32G32B32_UINT;
		case DT_VEC4_UINT32: return DXGI_FORMAT_R32G32B32A32_UINT;

		case DT_FLOAT32: return DXGI_FORMAT_R32_FLOAT;
		case DT_VEC2_FLOAT32: return DXGI_FORMAT_R32G32_FLOAT;
		case DT_VEC3_FLOAT32: return DXGI_FORMAT_R32G32B32_FLOAT;
		case DT_VEC4_FLOAT32: return DXGI_FORMAT_R32G32B32A32_FLOAT;

		default: throw Exception("unsupported format", ERC_NO_SUPPORT); break;
		}
		return DXGI_FORMAT_R32_FLOAT;
	}
	template<> D3D11_PRIMITIVE_TOPOLOGY ConvertEnum<GfxPrimitives, D3D11_PRIMITIVE_TOPOLOGY>(GfxPrimitives gpType) {
		switch (gpType) {
		case GPT_POINTS: return D3D11_PRIMITIVE_TOPOLOGY_POINTLIST; break;
		case GPT_TRIANGLES: return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST; break;
		case GPT_TRIANGLE_STRIP: return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP; break;
		case GPT_TRIANGLE_FAN: return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ; break;
		case GPT_LINES: return D3D11_PRIMITIVE_TOPOLOGY_LINELIST; break;
		case GPT_LINE_LOOP: return D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ; break;
		case GPT_LINE_STRIP: return D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP; break;
		default: throw Exception("unavailable primitive topology", ERC_INVALID_ENUM); break;
		}
		return D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	}
	template<> UInt32 ConvertEnum<TextureTypes, UInt32>(TextureTypes texType) {
		switch (texType) {
		case TXT_1D: return 0; break;
		case TXT_2D: return 0; break;
		case TXT_3D: return 0; break;
		default: throw Exception("unsupported texture type", ERC_NO_SUPPORT); break;
		}
		return 0;
	}
	template<> DXGI_FORMAT ConvertEnum <PixelFormats, DXGI_FORMAT>(PixelFormats pxlFormat) {
		switch (pxlFormat) {
		case PXF_R32_SINT32: return DXGI_FORMAT_R32_SINT; break;
		case PXF_R8G8B8A8_SINT32: return DXGI_FORMAT_R8G8B8A8_SNORM; break;
		case PXF_R8G8B8A8_UINT32: return DXGI_FORMAT_B8G8R8A8_UNORM; break;
		default: throw Exception("unsupported pixel format", ERC_NO_SUPPORT); break;
		}
		return DXGI_FORMAT_R8G8B8A8_UNORM;
	}
	template<> D3D11_FILTER ConvertEnum <TextureFilters, D3D11_FILTER>(TextureFilters texFilter) {
		switch (texFilter) {
		case TXF_LINEAR: return D3D11_FILTER_MIN_MAG_MIP_LINEAR; break;
		case TXF_NEAREST: return D3D11_FILTER_MIN_MAG_MIP_POINT; break;
		default: throw Exception("unsupported pixel filter", ERC_NO_SUPPORT); break;
		}
		return D3D11_FILTER_MIN_MAG_MIP_POINT;
	}
	template<> D3D11_TEXTURE_ADDRESS_MODE ConvertEnum<TextureWraps, D3D11_TEXTURE_ADDRESS_MODE>(TextureWraps texWrap) {
		switch (texWrap) {
		case TXW_REPEAT: return D3D11_TEXTURE_ADDRESS_WRAP; break;
		case TXW_CLAMP: return D3D11_TEXTURE_ADDRESS_CLAMP; break;
		case TXW_BORDER: return D3D11_TEXTURE_ADDRESS_CLAMP; break;
		default: throw Exception("unsupported pixel filter", ERC_NO_SUPPORT); break;
		}
		return D3D11_TEXTURE_ADDRESS_WRAP;
	}
#endif
	const char* DtGetStr(DataTypes dType) {
		switch (dType) {
		case DT_BOOL: return "boolean"; break;
		case DT_SINT8: return "signed byte"; break;
		case DT_UINT8: return "unsigned byte"; break;
		case DT_SINT16: return "signed short"; break;
		case DT_UINT16: return "unsigned short"; break;
		case DT_SINT32: return "signed integer"; break;
		case DT_UINT32: return "unsigned integer"; break;
		case DT_FLOAT32: return "float"; break;
		case DT_VEC2_FLOAT32: return "float vector 2d"; break;
		case DT_VEC3_FLOAT32: return "float vector 3d"; break;
		case DT_VEC4_FLOAT32: return "float vector 4d"; break;
		default: return "unknown_type"; break;
		}
	}

	Size DtGetSize(DataTypes sDataType, UInt32 unCount) {
		Size szData = 0;
		switch (sDataType) {
		case DT_BOOL:
		case DT_SINT8: case DT_UINT8:
			szData = 1; break;
		case DT_VEC2_SINT8: case DT_VEC2_UINT8:
		case DT_SINT16: case DT_UINT16:
			szData = 2; break;
		case DT_FLOAT32:
		case DT_SINT32: case DT_UINT32:
		case DT_VEC2_SINT16: case DT_VEC2_UINT16:
		case DT_VEC2_SINT32: case DT_VEC2_UINT32:
			szData = 4; break;
		
		case DT_VEC2_FLOAT32:
			szData = 8 * 2;	break;
		case DT_VEC3_FLOAT32:
			szData = 8 * 3;	break;
		case DT_VEC4_FLOAT32:
			szData = 8 * 4;	break;
		default: throw Exception("invalid data type", ERC_INVALID_ENUM); szData = 0; break;
		}
		return szData * unCount;
	}
	Size DtGetAlignedSize(DataTypes dType, UInt32 unCount) {
		Size szAll = 0;
		// Size szData = DtGetSize(dType);
		switch (dType) {
		case DT_BOOL: case DT_SINT8: case DT_UINT8: szAll = 4;	break;
		case DT_SINT16: case DT_UINT16: szAll = 4;	break;
		case DT_SINT32: case DT_UINT32: szAll = 4;	break;
		case DT_FLOAT32: szAll = 4;	break;
		default: throw Exception("invalid data type", ERC_INVALID_ENUM); szAll = 0; break;
		}
		return szAll * ((unCount + (szAll - 1)) & ~(szAll - 1));
	}
}
namespace NWG
{
	GfxDataInfo::GfxDataInfo(Size sizeOfData, Size sizeOfStride, Size sizeOfOffset,
		Ptr ptrToData, DataTypes dataType) :
		szData(sizeOfData), szStride(sizeOfStride), szOffset(sizeOfOffset),
		pData(ptrToData), sdType(dataType) { }
	GfxDataInfo::GfxDataInfo(Size sizeOfData, Size sizeOfStride, Size sizeOfOffset, Ptr ptrToData) :
		szData(sizeOfData), szStride(static_cast<UInt32>(sizeOfStride)), szOffset(static_cast<UInt32>(sizeOfOffset)),
		pData(ptrToData), sdType(DT_DEFAULT) { }
	
	OStream& GfxContextInfo::operator<<(OStream& rStream) {
		return rStream <<
			"--==<graphics_context_info>==--" << std::endl <<
			"graphics context: " << &strVersion[0] << std::endl <<
			"renderer: " << &strRenderer[0] << std::endl <<
			"version: " << &strVersion[0] << std::endl <<
			"vendor: " << &strVendor[0] << std::endl <<
			"shading language: " << &strShdLang[0] << std::endl <<
			"--==</graphics_info>==--" << std::endl;
	}
	OStream& operator<<(OStream& rStream, GfxContextInfo& rgInfo) { return rgInfo.operator<<(rStream); }
}
namespace NWG
{
	void GfxConfig::Reset() {
		General.PolyMode.dMode = DM_FILL;
		General.PolyMode.facePlane = FACE_DEFAULT;

		General.nLineWidth = 0.5f;
		General.nPixelSize = 0.5f;

		Blending.bEnable = false;
		Blending.FactorSrc = BC_SRC_ALPHA;
		Blending.FactorDest = BC_ONE_MINUS_SRC_ALPHA;

		DepthTest.bEnable = false;
		DepthTest.Func = DTC_GREATER;
	}
}
#if (NWG_GAPI & NWG_GAPI_OGL)
#include <nwg_loader.h>
// Functions
namespace NWG
{
	// glGetError gets last message and clears errorLog
	void OglClearErr() { while (glGetError() != GL_NO_ERROR); }

	bool OglErrLog(const char* funcName, const char* file, int line)
	{// Get error and match error message for it
		UInt32 errorCode;
		while ((errorCode = glGetError()) != GL_NO_ERROR)
		{
			String strErr;
			switch (errorCode) {
			case NWG_INVALID_ENUM:
				strErr = "INVALID_ENUM";
				break;
			case NWG_INVALID_VALUE:
				strErr = "INVALID_VALUE";
				break;
			case NWG_INVALID_OPERATION:
				strErr = "INVALID_OPERATION";
				break;
			case NWG_STACK_OVERFLOW:
				strErr = "STACK_OVERFLOW";
				break;
			case NWG_STACK_UNDERFLOW:
				strErr = "STACK_UNDERFLOW";
				break;
			case NWG_OUT_OF_MEMORY:
				strErr = "OUT_OF_MEMORY";
				break;
			}
			printf("GFX_ERR_LOG::FILE_%s::LINE_%d:\n%s\n", funcName, line, &strErr[0]);
			return false;
		}
		return true;
	}

	Int32 OglErrLogShader(ShaderTypes shaderType, UInt32 shaderID)
	{
		if (shaderID == 0) return NWL_ERR_UNKNOWN_ID;
		Int32 success = 0;
		Int32 errLogSize = 0;
		String errLog;
		std::string strType = shaderType == NWG_SHADER_VERTEX ?
			"SHADER_VERTEX" : shaderType == NWG_SHADER_PIXEL ?
			"SHADER_PIXEL" : "SHADER_PROG";
		if (shaderType != ST_SHADER)
		{
			glGetShaderiv(shaderID, NWG_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &errLogSize);
				errLog.resize(errLogSize);

				glGetShaderInfoLog(shaderID, errLogSize, NULL, &errLog[0]);
				NWL_ERR(errLog);
				return NWL_ERR_SHADER_COMPILE;
			}
		}
		else
		{
			glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramiv(shaderID, GL_INFO_LOG_LENGTH, &errLogSize);
				errLog.resize(errLogSize);

				glGetProgramInfoLog(shaderID, errLogSize, NULL, &errLog[0]);
				NWL_ERR(&errLog[0]);
				return NWL_ERR_SHADER_LINK;
			}
		}
		return NWG_OK;
	}
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	void DxClearErr() {
		//
	}
	bool DxErrLog(const char* strInfo, const char* strFile, int nLine) {
		return false;
	}
}
#endif
#endif	// NWG_GAPI