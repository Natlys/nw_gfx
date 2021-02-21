#ifndef NWG_SHADER_BUFFER_H
#define NWG_SHADER_BUFFER_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <nwg_tools.h>
#include <nwg_res.h>
#include <nwg_layout.h>
namespace NWG
{
	struct SBuf1Mat4f {
		Mat4f m4Model = Mat4f(1.0f);
	};
	struct SBuf2Mat4f {
		Mat4f m4View = Mat4f(1.0f);
		Mat4f m4Proj = Mat4f(1.0f);
	};
	struct SBuf3Mat4f {
		Mat4f m4Model = Mat4f(1.0f);
		Mat4f m4View = Mat4f(1.0f);
		Mat4f m4Proj = Mat4f(1.0f);
	};
}
namespace NWG
{
	/// ShaderBuffer class
	/// Description:
	/// -- Is used by shaders as opengl uniform buffer, or as directx constant buffer
	class NWG_API ShaderBuf : public TEntity<ShaderBuf>, public AGfxRes
	{
	public:
		ShaderBuf(GfxEngine& rGfx);
		virtual ~ShaderBuf();
		// --getters
		inline Size GetDataSize() const { return m_gdInfo.szData; }
		inline Size GetDataStride() const { return m_gdInfo.szStride; }
		inline Size GetDataCount() const { return m_gdInfo.szData / m_gdInfo.szStride; }
		inline DataTypes GetDataType() { return m_gdInfo.sdType; }
		// --setters
		template<typename CType> void SetData(CType* pData = nullptr);
		void SetSubData(Size szData, const Ptr pData, Size szOffset = 0);
		void SetLayout(const ShaderLayout& rShdLayout);
		// --core_methods
		virtual void Bind() override;
		void Bind(UInt32 unPoint);
		void Bind(UInt32 unPoint, Size szData, Size szOffset = 0);
	private:
		void Remake(const GfxDataInfo& rInfo);
	private:
		GfxDataInfo m_gdInfo;
#if (NWG_GAPI & NWG_GAPI_DX)
		ID3D11Buffer* m_pNative;
	};
	template<typename CType> void ShaderBuf::SetData(CType* pData) {
		GfxDataInfo gdInfo(sizeof(CType), sizeof(CType), 0, pData);
		Remake(gdInfo);
	}
#endif
}
#endif	// NWG_GAPI
#endif	// NWG_BUFFER_H