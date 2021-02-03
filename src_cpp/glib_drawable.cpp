#include <glib_pch.hpp>
#include <glib_drawable.h>

#include <glib_material.h>
#include <glib_buffer.h>
#include <glib_engine.h>

namespace GLIB
{
	Drawable::Drawable() :
		vtxArr(RefKeeper<VertexArr>()),
		vtxBuf(RefKeeper<VertexBuf>()), idxBuf(RefKeeper<IndexBuf>()),
		gMtl(RefKeeper<GMaterial>())
	{
		vtxArr.SetRef(GraphEngine::Get().GetMemory(), VertexArr::Create());
		idxBuf.SetRef(GraphEngine::Get().GetMemory(), IndexBuf::Create());
		vtxBuf.SetRef(GraphEngine::Get().GetMemory(), VertexBuf::Create());
		vtxArr->SetIdxBuffer(idxBuf.GetRef());
		vtxArr->AddVtxBuffer(*vtxBuf);
	}
	Drawable::~Drawable() {
		vtxArr.Reset();
		idxBuf.Reset();
		vtxBuf.Reset();
		gMtl.Reset();
	}
}