#include <glib_pch.hpp>
#include "glib_buffer.h"

#pragma warning(disable : 4312)

#if (defined GLIB_GAPI)
#include <glib_engine.h>
#endif	// GLIB_API

#if (GLIB_GAPI & GLIB_GAPI_OGL)
#include <glad/glad.h>
namespace GLIB
{
	// --==<AGBuf>==--
	AGBuffer::AGBuffer(GBufferTypes gbType) : m_unRId(0), m_gbType(gbType), m_bIsBound(false), m_szData(0) { }
	AGBuffer::~AGBuffer() { Unbind(); if (m_unRId != 0) { glDeleteBuffers(1, &m_unRId); } }
	// --setters
	void AGBuffer::SetSubData(Size szData, const Ptr pVtxData, Size szOffset) {
		Bind();
		glBufferSubData(m_gbType, szOffset, szData, pVtxData);
		Unbind();
	}
	void AGBuffer::SetData(Size szData, const Ptr pVtxData) {
		Unbind();
		m_szData = szData;
		if (m_unRId != 0) { glDeleteBuffers(1, &m_unRId); m_unRId = 0; }
		if (szData == 0) { return; }
		glGenBuffers(1, &m_unRId);
		Bind();
		glBufferData(m_gbType, szData, pVtxData, pVtxData == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
		Unbind();
	}
	void AGBuffer::Bind() const {
		if (m_bIsBound) { return; }
		glBindBuffer(m_gbType, m_unRId);
		m_bIsBound = true;
	}
	void AGBuffer::Unbind() const {
		if (!m_bIsBound) { return; }
		glBindBuffer(m_gbType, 0);
		m_bIsBound = false;
	}
	// --==</AGBuf>==--
}
namespace GLIB
{
	// --==<VertexBuf>==--
	VertexBuf::VertexBuf() : AGBuffer(GBT_VERTEX) { }
	VertexBuf::~VertexBuf() { }

	// --core_methods
	void VertexBuf::Create(RefKeeper<VertexBuf>& rVtxBuf) { rVtxBuf.MakeRef<VertexBuf>(); }
	// --==</VertexBuf>==--
}
namespace GLIB
{
	// --==<IndexBuf>==--
	IndexBuf::IndexBuf() : AGBuffer(GBT_INDEX) { }
	IndexBuf::~IndexBuf() { }

	// --core_methods
	void IndexBuf::Create(RefKeeper<IndexBuf>& rIdxBuf) { rIdxBuf.MakeRef<IndexBuf>(); }
	// --==</IndexBuf>==--
}
namespace GLIB
{
	// --==<ShaderBuf>==--
	ShaderBuf::ShaderBuf() : AGBuffer(GBT_SHADER), m_bufLayout(ShaderBufLayout()) { }
	ShaderBuf::~ShaderBuf() { }
	// --setters
	void ShaderBuf::SetLayout(const ShaderBufLayout& rBufLayout) {
		m_bufLayout = rBufLayout;
		if (m_szData < rBufLayout.GetSize()) { SetData(rBufLayout.GetSize()); }
		for (auto& rBlock : rBufLayout.GetBlocks()) { Bind(rBlock.unBindPoint, rBlock.szAll, rBlock.szOffset); }
	}
	// --core_methods
	void ShaderBuf::Bind() const
	{
		AGBuffer::Bind();
		for (auto& rBlock : m_bufLayout.GetBlocks()) { Bind(rBlock.unBindPoint, rBlock.szAll, rBlock.szOffset); }
	}
	void ShaderBuf::Bind(UInt32 unPoint) const {
		glBindBuffer(GL_UNIFORM_BUFFER, m_unRId);
		glBindBufferBase(GL_UNIFORM_BUFFER, unPoint, m_unRId);
	}
	void ShaderBuf::Bind(UInt32 unPoint, Size szData, Size szOffset) const {
		glBindBuffer(GL_UNIFORM_BUFFER, m_unRId);
		glBindBufferRange(GL_UNIFORM_BUFFER, unPoint, m_unRId, szOffset, szData);
	}
	void ShaderBuf::Create(RefKeeper<ShaderBuf>& rShdBuf) { rShdBuf.MakeRef<ShaderBuf>(); }
	// --==</AShaderBuf>==--
}
#endif	// GLIB_GAPI
namespace GLIB
{
	VertexArr::VertexArr() :
		m_unRId(0), m_bIsBound(false),
		m_idxBuf(nullptr),
		m_gpType(PT_TRIANGLES) { glCreateVertexArrays(1, &m_unRId); }
	VertexArr::~VertexArr() { glDeleteVertexArrays(1, &m_unRId); }
	
	// --setters
	// --==<core_methods>==--
	void VertexArr::Bind() const {
		if (m_bIsBound) { return; }
		glBindVertexArray(m_unRId);
		m_bIsBound = true;
	}
	void VertexArr::Unbind() const {
		if (!m_bIsBound) { return; }
		glBindVertexArray(0);
		m_bIsBound = false;
	}

	void VertexArr::Remake(const VertexBufLayout& rvtxLayout) {
		Bind();
		if (m_idxBuf != nullptr) { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_idxBuf->GetRenderId()); }
		else { glBindBuffer(GBT_INDEX, 0); }
		for (auto& itBuf : m_vtxBufs) { glBindBuffer(GL_ARRAY_BUFFER, itBuf->GetRenderId()); }
		for (UInt32 ati = 0; ati < m_vtxLayout.GetElems().size(); ati++) { glDisableVertexAttribArray(ati); }
		m_vtxLayout = rvtxLayout;
		for (UInt32 ati = 0; ati < m_vtxLayout.GetElems().size(); ati++) {
			const BufferElement& rBufElem = m_vtxLayout.GetElem(ati);
			glEnableVertexAttribArray(ati);
			glVertexAttribPointer(ati, rBufElem.unCount, rBufElem.sdType,
				rBufElem.bNormalized ? GL_TRUE : GL_FALSE, m_vtxLayout.GetStride(), reinterpret_cast<Ptr>(rBufElem.unOffset));
		}
		Unbind();
	}

	void VertexArr::Create(RefKeeper<VertexArr>& rVtxArr) { rVtxArr.MakeRef<VertexArr>(); }
	// --==</core_methods>==--
}