#include <nwg_pch.hpp>
#include "nwg_buffer.h"
#pragma warning(disable : 4312)
#if (defined NWG_GAPI)
#include <nwg_engine.h>
#include <nwg_loader.h>
#if (NWG_GAPI & NWG_GAPI_OGL)
namespace NWG
{
	VertexBuf::VertexBuf() : GfxEntity() { }
	VertexBuf::~VertexBuf() { SetData(0, nullptr); }
	// --setters
	void VertexBuf::SetSubData(Size szData, const Ptr pVtxData, Size szOffset) {
		glBufferSubData(GL_ARRAY_BUFFER, szOffset, szData, pVtxData);
	}
	void VertexBuf::SetData(Size szData, const Ptr pVtxData) {
		m_szData = szData;
		if (m_unRId != 0) { glDeleteBuffers(1, &m_unRId); m_unRId = 0; }
		if (szData == 0) { return; }
		glGenBuffers(1, &m_unRId);
		glBindBuffer(GL_ARRAY_BUFFER, m_unRId);
		glBufferData(GL_ARRAY_BUFFER, szData, pVtxData, pVtxData == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
	}
	void VertexBuf::Bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, m_unRId);
	}
}
namespace NWG
{
	IndexBuf::IndexBuf() : GfxEntity() { }
	IndexBuf::~IndexBuf() { SetData(0, nullptr); }
	// --setters
	void IndexBuf::SetSubData(Size szData, const Ptr pVtxData, Size szOffset) {
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, szOffset, szData, pVtxData);
	}
	void IndexBuf::SetData(Size szData, const Ptr pVtxData) {
		m_szData = szData;
		if (m_unRId != 0) { glDeleteBuffers(1, &m_unRId); m_unRId = 0; }
		if (szData == 0) { return; }
		glGenBuffers(1, &m_unRId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_unRId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, szData, pVtxData, pVtxData == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
	}
	void IndexBuf::Bind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_unRId);
	}
}
namespace NWG
{
	ShaderBuf::ShaderBuf() : GfxEntity() { }
	ShaderBuf::~ShaderBuf() { SetData(0, nullptr); }
	// --setters
	void ShaderBuf::SetSubData(Size szData, const Ptr pVtxData, Size szOffset) {
		glBufferSubData(GL_UNIFORM_BUFFER, szOffset, szData, pVtxData);
	}
	void ShaderBuf::SetData(Size szData, const Ptr pVtxData) {
		m_szData = szData;
		if (m_unRId != 0) { glDeleteBuffers(1, &m_unRId); m_unRId = 0; }
		if (szData == 0) { return; }
		glGenBuffers(1, &m_unRId);
		glBindBuffer(GL_UNIFORM_BUFFER, m_unRId);
		glBufferData(GL_UNIFORM_BUFFER, szData, pVtxData, pVtxData == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
	}
	// --core_methods
	void ShaderBuf::Bind() const {
		glBindBuffer(GL_UNIFORM_BUFFER, m_unRId);
	}
	void ShaderBuf::Bind(UInt32 unPoint) const {
		glBindBufferBase(GL_UNIFORM_BUFFER, unPoint, m_unRId);
	}
	void ShaderBuf::Bind(UInt32 unPoint, Size szData, Size szOffset) const {
		glBindBufferRange(GL_UNIFORM_BUFFER, unPoint, m_unRId, szOffset, szData);
	}
	void ShaderBuf::Remake(const ShaderBufLayout& rBufLayout) {
		if (m_szData < rBufLayout.GetSize()) { SetData(rBufLayout.GetSize()); }
		for (auto& rBlock : rBufLayout.GetBlocks()) { Bind(rBlock.unBindPoint, rBlock.szAll, rBlock.szOffset); }
	}
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
#endif
#endif	// NWG_GAPI