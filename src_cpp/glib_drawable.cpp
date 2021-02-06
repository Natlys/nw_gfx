#include <glib_pch.hpp>
#include <glib_drawable.h>

#include <glib_material.h>
#include <glib_buffer.h>
#include <glib_engine.h>

namespace GLIB
{
	Drawable::Drawable() :
		vtxArr(RefKeeper<VertexArr>()),
		gMtl(nullptr) { }
	Drawable::Drawable(Size szVtxData, Size szIdxData) :
		vtxArr(RefKeeper<VertexArr>()),
		gMtl(nullptr)
	{
		VertexArr::Create(vtxArr);

		RefKeeper<VertexBuf> vtxBuf;
		VertexBuf::Create(vtxBuf);
		vtxBuf->SetData(szVtxData, nullptr);
		vtxArr->AddVtxBuffer(vtxBuf);

		RefKeeper<IndexBuf> idxBuf;
		IndexBuf::Create(idxBuf);
		idxBuf->SetData(szIdxData, nullptr);
		vtxArr->SetIdxBuffer(idxBuf);
	}

	Drawable::~Drawable() {
		vtxArr.Reset();
	}
	// --core_methods
	void Drawable::UploadVtxData(const BufferData* pData, UInt32 unCount, UInt32 unFirstBuf)
	{
		for (UInt32 di = 0; di < unCount; di++) {
			if (VertexBuf* pvtxBuf = vtxArr->GetVtxBuffer(unFirstBuf + di)) {
				pvtxBuf->SetSubData(pData[di].szData, pData[di].pData, pData[di].szOffset);
			}
			else { return; }
		}
	}
	void Drawable::UploadIdxData(const BufferData* pData)
	{
		if (IndexBuf* pidxBuf = vtxArr->GetIdxBuffer()) {
			pidxBuf->SetSubData(pData->szData, pData->pData, pData->szOffset);
		}
	}
}