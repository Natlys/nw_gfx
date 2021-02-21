#ifndef NWG_INDEX_BUFFER_H
#define NWG_INDEX_BUFFER_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <nwg_tools.h>
#include <nwg_res.h>
namespace NWG
{
	/// IndexBuf class
	class NWG_API IndexBuf : public TEntity<IndexBuf>, public AGfxRes
	{
	public:
		IndexBuf(GfxEngine& rGfx);
		virtual ~IndexBuf();
		// --getters
		inline Size GetDataSize() const { return m_gdInfo.szData; }
		inline Size GetDataStride() const { return m_gdInfo.szStride; }
		inline Size GetDataCount() const { return m_gdInfo.szData / m_gdInfo.szStride; }
		inline DataTypes GetDataType() { return m_gdInfo.sdType; }
		// --setters
		template<typename IType> void SetData(UInt32 unCount, IType* pData = nullptr);
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
	template<typename IType>
	void IndexBuf::SetData(UInt32 unCount, IType* pData) {
		GfxDataInfo gInfo(unCount * sizeof(IType), sizeof(IType), 0, pData, DtGet<IType>());
		Remake(gInfo);
	}
}
#endif	// NWG_GAPI
#endif	// NWG_INDEX_BUFFER_H