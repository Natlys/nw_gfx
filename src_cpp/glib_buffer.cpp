#include <glib_pch.hpp>
#include "glib_buffer.h"

#pragma warning(disable : 4312)

#if (defined GLIB_GAPI)
#include <core/glib_engine.h>
#include <core/glib_api.h>
// Buffers
namespace GLIB
{
	AVertexBuf* AVertexBuf::Create(Size szAlloc, const void* pVtxData)
	{
		AVertexBuf* pVB = nullptr;
		switch (GEngine::Get().GetGApi()->GetType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: pVB = new VertexBufOgl(); break;
	#endif	// GLIB_GAPI
		default: GLIB_ERR("There is no accessible API"); break;
		}
		pVB->SetData(szAlloc, pVtxData);
		return pVB;
	}
	AIndexBuf* AIndexBuf::Create(Size szAlloc, const void* pIdxData)
	{
		AIndexBuf* pIB = nullptr;
		switch (GEngine::Get().GetGApi()->GetType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: pIB = new IndexBufOgl(); break;
	#endif // GLIB_GAPI
		default: GLIB_ERR("Graphics API is not defined"); break;
		}
		pIB->SetData(szAlloc, pIdxData);
		return pIB;
	}
	AShaderBuf* AShaderBuf::Create(Size szAlloc, const void* pIdxData) {
		AShaderBuf* pSB = nullptr;
		switch (GEngine::Get().GetGApi()->GetType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: pSB = new ShaderBufOgl(); break;
	#endif // GLIB_GAPI
		default: GLIB_ERR("Graphics API is not defined"); break;
		}
		pSB->SetData(szAlloc, pIdxData);
		return pSB;
	}
}
#endif	// GLIB_GAPI
#if (GLIB_GAPI & GLIB_GAPI_OGL)
#include <glad/glad.h>
namespace GLIB
	// VertexBufferOgl
{
	VertexBufOgl::VertexBufOgl() :
		m_unRIdVB(0), m_unRIdVA(0), m_szData(0)
	{
		glGenVertexArrays(1, &m_unRIdVA);
	}
	VertexBufOgl::~VertexBufOgl()
	{
		SetData(0, nullptr);
		glDeleteVertexArrays(1, &m_unRIdVA);
	}

	// --setters
	void VertexBufOgl::SetData(Size szData, const void* pVtxData) {
		m_szData = szData;
		if (m_unRIdVB != 0) { glDeleteBuffers(1, &m_unRIdVB); m_unRIdVB = 0; }
		if (szData == 0) { return; }
		glGenBuffers(1, &m_unRIdVB);

		glBindBuffer(GL_ARRAY_BUFFER, m_unRIdVB);
		glBufferData(GL_ARRAY_BUFFER, szData, pVtxData,
			pVtxData == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	void VertexBufOgl::SetSubData(Size szData, const void* pVtxData, Size szOffset) {
		glBindBuffer(GL_ARRAY_BUFFER, m_unRIdVB);
		glBufferSubData(GL_ARRAY_BUFFER, szOffset, szData, pVtxData);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	void VertexBufOgl::SetLayout(const VertexBufLayout& rBufLayout) {
		glBindVertexArray(m_unRIdVA); glBindBuffer(GL_ARRAY_BUFFER, m_unRIdVB);
		for (UInt32 ati = 0; ati < m_BufLayout.GetElems().size(); ati++) { glDisableVertexAttribArray(ati); }
		m_BufLayout = rBufLayout;
		for (UInt32 ati = 0; ati < rBufLayout.GetElems().size(); ati++) {
			const BufferElement& rBufElem = m_BufLayout.GetElem(ati);
			glVertexAttribPointer(ati, rBufElem.unCount,
				rBufElem.sdType, rBufElem.bNormalized ? GL_TRUE : GL_FALSE,
				m_BufLayout.GetStride(), reinterpret_cast<void*>(rBufElem.unOffset));
			glEnableVertexAttribArray(ati);
		}
		glBindVertexArray(0); glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	// --core_methods
	void VertexBufOgl::Bind() const { glBindVertexArray(m_unRIdVA); glBindBuffer(GL_ARRAY_BUFFER, m_unRIdVB); }
	void VertexBufOgl::Unbind() const { glBindVertexArray(0); glBindBuffer(GL_ARRAY_BUFFER, 0); }
}
// IndexBufferOgl
namespace GLIB
{
	IndexBufOgl::IndexBufOgl() :
		m_unRId(0), m_szData(0) { }
	IndexBufOgl::~IndexBufOgl() { SetData(0, nullptr); }

	// --setters
	void IndexBufOgl::SetData(Size szAlloc, const void* pIdxData) {
		m_szData = szAlloc;
		if (m_unRId != 0) { glDeleteBuffers(1, &m_unRId); m_unRId = 0; }
		if (szAlloc == 0) { return; }
		glGenBuffers(1, &m_unRId);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_unRId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, szAlloc, pIdxData,
			pIdxData == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	void IndexBufOgl::SetSubData(Size szData, const void* pIdxData, Size szOffset)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_unRId);
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, szOffset, szData, pIdxData);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	// --core_methods
	void IndexBufOgl::Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_unRId); }
	void IndexBufOgl::Unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
}
// ShaderBufferOgl
namespace GLIB
{
	ShaderBufOgl::ShaderBufOgl() :
		m_unRId(0), m_szData(0) { }
	ShaderBufOgl::~ShaderBufOgl() { SetData(0, nullptr); }

	// --setters
	void ShaderBufOgl::SetData(Size szAlloc, const void* pIdxData) {
		m_szData = szAlloc;
		if (m_unRId != 0) { glDeleteBuffers(1, &m_unRId); m_unRId = 0; }
		if (szAlloc == 0) { return; }
		glGenBuffers(1, &m_unRId);

		glBindBuffer(GL_UNIFORM_BUFFER, m_unRId);
		glBufferData(GL_UNIFORM_BUFFER, szAlloc, pIdxData,
			pIdxData == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}
	void ShaderBufOgl::SetSubData(Size szData, const void* pIdxData, Size szOffset) {
		glBindBuffer(GL_UNIFORM_BUFFER, m_unRId);
		glBufferSubData(GL_UNIFORM_BUFFER, szOffset, szData, pIdxData);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}

	void ShaderBufOgl::SetLayout(const ShaderBufLayout& rBufLayout) {
		m_BufLayout = rBufLayout;
		if (m_szData < rBufLayout.GetSize()) { SetData(rBufLayout.GetSize()); }
		for (auto& rBlock : rBufLayout.GetBlocks()) { Bind(rBlock.unBindPoint, rBlock.szAll, rBlock.szOffset); }
	}

	// --core_methods
	void ShaderBufOgl::Bind() const
	{
		for (auto& rBlock : m_BufLayout.GetBlocks()) { Bind(rBlock.unBindPoint, rBlock.szAll, rBlock.szOffset); }
	}
	void ShaderBufOgl::Bind(UInt32 unPoint) const {
		glBindBuffer(GL_UNIFORM_BUFFER, m_unRId);
		glBindBufferBase(GL_UNIFORM_BUFFER, unPoint, m_unRId);
	}
	void ShaderBufOgl::Bind(UInt32 unPoint, Size szData, Size szOffset) const {
		glBindBuffer(GL_UNIFORM_BUFFER, m_unRId);
		glBindBufferRange(GL_UNIFORM_BUFFER, unPoint, m_unRId, szOffset, szData);
	}
	void ShaderBufOgl::Unbind() const { glBindBuffer(GL_UNIFORM_BUFFER, 0); }
}
#endif	// GLIB_GAPI