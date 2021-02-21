#ifndef NWG_VERTEX_BUFFER_H
#define NWG_VERTEX_BUFFER_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <nwg_tools.h>
#include <nwg_res.h>
namespace NWG
{
	struct Vtx2f
	{
		V2f vtxCrd = { 0.0f, 0.0f };
	};
	struct Vtx2f2f4u8
	{
		V2f vtxCrd = { 0.0f, 0.0f };
		V2f texCrd = { 0.0f, 0.0f };
		V4u8 vtxClr = { 0u, 0u, 0u, 0u };
	};
	struct Vtx3f
	{
		V3f vtxCrd = { 0.0f, 0.0f, 0.0f };
	};
	struct Vtx3f2f3f
	{
		V3f vtxCrd = { 0.0f, 0.0f, 0.0f };
		V2f texCrd = { 0.0f, 0.0f };
		V3f nrmCrd = { 0.0f, 0.0f, 0.0f };
	};
}
namespace NWG
{
	/// VertexBuf class
	class NWG_API VertexBuf : public TEntity<VertexBuf>, public AGfxRes
	{
	public:
		VertexBuf(GfxEngine& rGfx);
		virtual ~VertexBuf();
		// --getters
		inline Size GetDataSize() const { return m_gdInfo.szData; }
		inline Size GetDataStride() const { return m_gdInfo.szStride; }
		inline Size GetDataCount() const { return m_gdInfo.szData / m_gdInfo.szStride; }
		inline DataTypes GetDataType() { return m_gdInfo.sdType; }
		// --setters
		template<typename VType> void SetData(UInt32 unCount, VType* pData = nullptr);
		void SetSubData(Size szData, const Ptr pData, Size szOffset = 0);
		// --core_methods
		virtual void Bind() override;
	private:
		void Remake(const GfxDataInfo& rInfo);
	private:
		GfxDataInfo m_gdInfo;
#if (NWG_GAPI & NWG_GAPI_DX)
		ID3D11Buffer* m_pNative;
#endif
	};
	template<typename VType>
	void VertexBuf::SetData(UInt32 unCount, VType* pData) {
		GfxDataInfo gInfo(unCount * sizeof(VType), sizeof(VType), 0, pData, DT_DEFAULT);
		Remake(gInfo);
	}
}
#endif	// NWG_GAPI
#endif	// NWG_VERTEX_BUFFER_H