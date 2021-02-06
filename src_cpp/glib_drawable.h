#ifndef GLIB_DRAWABLE_H
#define GLIB_DRAWABLE_H

#include <glib_core.hpp>

namespace GLIB
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
namespace GLIB
{
	/// Drawable struct
	struct Drawable
	{
	public:
		RefKeeper<VertexArr> vtxArr;
		GMaterial* gMtl;
	public:
		Drawable();
		Drawable(Size szVtxData, Size szIdxData);
		~Drawable();
	
		// --core_methods
		void UploadVtxData(const BufferData* pData, UInt32 unCount = 1, UInt32 unFirstBuf = 0);
		void UploadIdxData(const BufferData* pData);
	};
}

#endif	// GLIB_DRAWABLE_H