#ifndef GFX_DRAWABLE_H
#define GFX_DRAWABLE_H

#include <nwg_core.hpp>

namespace NWG
{
	/// VertexData struct
	struct BufferData
	{
	public:
		mutable Ptr pData = nullptr;
		Size szData = 0;
		Size szOffset = 0;
	public:
		BufferData() : pData(nullptr), szData(0), szOffset(0) {}
		BufferData(Ptr pData, Size szData, Size szOffset) : pData(pData), szData(szData), szOffset(szOffset) {}
	};
}
namespace NWG
{
	/// Drawable struct
	struct Drawable
	{
	public:
		RefKeeper<VertexArr> vtxArr;
		GfxMaterial* gMtl;
	public:
		Drawable();
		Drawable(Size szVtxData, Size szIdxData);
		~Drawable();
	
		// --core_methods
		void UploadVtxData(const BufferData* pData, UInt32 unCount = 1, UInt32 unFirstBuf = 0);
		void UploadIdxData(const BufferData* pData);
	};
}

#endif	// GFX_DRAWABLE_H