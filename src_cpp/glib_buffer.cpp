#include <glib_pch.hpp>
#include "glib_buffer.h"

#pragma warning(disable : 4312)

#if (defined GLIB_GAPI)
#include <glib_engine.h>
#include <glib_api.h>
// Buffers
namespace GLIB
{
	// --==<AVertexBuf>==--
	AVertexBuf::AVertexBuf() :
		m_bIsBound(false), m_szData(0), m_bufLayout(VertexBufLayout()) {}
	// --core_methods
	AVertexBuf* AVertexBuf::Create()
	{
		AVertexBuf* pVB = nullptr;
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: pVB = GEngine::Get().NewT<VertexBufOgl>(); break;
	#endif	// GLIB_GAPI
		default: NWL_ERR("There is no accessible API"); break;
		}
		return pVB;
	}
	void AVertexBuf::Create(RefOwner<AVertexBuf>& rVtxBuf)
	{
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: rVtxBuf.MakeRef<VertexBufOgl>(); break;
	#endif // GLIB_GAPI
		default: NWL_ERR("Graphics API is not defined"); break;
		}
	}
	void AVertexBuf::Create(RefKeeper<AVertexBuf>& rVtxBuf)
	{
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: rVtxBuf.MakeRef<VertexBufOgl>(); break;
	#endif // GLIB_GAPI
		default: NWL_ERR("Graphics API is not defined"); break;
		}
	}
	// --==</AVertexBuf>==--
	// --==<AIndexBuf>==--
	AIndexBuf::AIndexBuf() :
		m_bIsBound(false), m_szData(0) {}
	// --core_methods
	AIndexBuf* AIndexBuf::Create()
	{
		AIndexBuf* pIB = nullptr;
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: pIB = GEngine::Get().NewT<IndexBufOgl>(); break;
	#endif // GLIB_GAPI
		default: NWL_ERR("Graphics API is not defined"); break;
		}
		return pIB;
	}
	void AIndexBuf::Create(RefOwner<AIndexBuf>& rIdxBuf)
	{
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: rIdxBuf.MakeRef<IndexBufOgl>(); break;
	#endif // GLIB_GAPI
		default: NWL_ERR("Graphics API is not defined"); break;
		}
	}
	void AIndexBuf::Create(RefKeeper<AIndexBuf>& rIdxBuf)
	{
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: rIdxBuf.MakeRef<IndexBufOgl>(); break;
	#endif // GLIB_GAPI
		default: NWL_ERR("Graphics API is not defined"); break;
		}
	}
	// --==</AIndexBuf>==--
	// --==<AShaderBuf>==--
	AShaderBuf::AShaderBuf() :
		m_bIsBound(false), m_szData(0), m_bufLayout(ShaderBufLayout()) {}
	// --core_methods
	AShaderBuf* AShaderBuf::Create() {
		AShaderBuf* pSB = nullptr;
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: pSB = GEngine::Get().NewT<ShaderBufOgl>(); break;
	#endif // GLIB_GAPI
		default: NWL_ERR("Graphics API is not defined"); break;
		}
		return pSB;
	}
	void AShaderBuf::Create(RefOwner<AShaderBuf>& rShdBuf)
	{
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: rShdBuf.MakeRef<ShaderBufOgl>(); break;
	#endif // GLIB_GAPI
		default: NWL_ERR("Graphics API is not defined"); break;
		}
	}
	void AShaderBuf::Create(RefKeeper<AShaderBuf>& rShdBuf)
	{
		switch (GEngine::Get().GetGApiType()) {
	#if (GLIB_GAPI & GLIB_GAPI_OGL)
		case GApiTypes::GAPI_OPENGL: rShdBuf.MakeRef<ShaderBufOgl>(); break;
	#endif // GLIB_GAPI
		default: NWL_ERR("Graphics API is not defined"); break;
		}
	}
	// --==</AShaderBuf>==--
}
#endif	// GLIB_GAPI
#if (GLIB_GAPI & GLIB_GAPI_OGL)
#include <glad/glad.h>
// VertexBufferOgl
namespace GLIB
	// VertexBufferOgl
{
	VertexBufOgl::VertexBufOgl() :
		AVertexBuf(),
		m_unRIdVB(0), m_unRIdVA(0)
	{
		glGenVertexArrays(1, &m_unRIdVA);
	}
	VertexBufOgl::~VertexBufOgl()
	{
		SetData(0, nullptr);
		glDeleteVertexArrays(1, &m_unRIdVA);
	}

	// --setters
	void VertexBufOgl::SetData(Size szData, const Ptr pVtxData) {
		m_szData = szData;
		if (m_unRIdVB != 0) { glDeleteBuffers(1, &m_unRIdVB); m_unRIdVB = 0; }
		if (szData == 0) { return; }
		glGenBuffers(1, &m_unRIdVB);

		glBindBuffer(GL_ARRAY_BUFFER, m_unRIdVB);
		glBufferData(GL_ARRAY_BUFFER, szData, pVtxData,
			pVtxData == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	void VertexBufOgl::SetSubData(Size szData, const Ptr pVtxData, Size szOffset) {
		glBindBuffer(GL_ARRAY_BUFFER, m_unRIdVB);
		glBufferSubData(GL_ARRAY_BUFFER, szOffset, szData, pVtxData);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	void VertexBufOgl::SetLayout(const VertexBufLayout& rBufLayout) {
		glBindVertexArray(m_unRIdVA); glBindBuffer(GL_ARRAY_BUFFER, m_unRIdVB);
		for (UInt32 ati = 0; ati < m_bufLayout.GetElems().size(); ati++) { glDisableVertexAttribArray(ati); }
		m_bufLayout = rBufLayout;
		for (UInt32 ati = 0; ati < rBufLayout.GetElems().size(); ati++) {
			const BufferElement& rBufElem = m_bufLayout.GetElem(ati);
			glVertexAttribPointer(ati, rBufElem.unCount,
				rBufElem.sdType, rBufElem.bNormalized ? GL_TRUE : GL_FALSE,
				m_bufLayout.GetStride(), reinterpret_cast<void*>(rBufElem.unOffset));
			glEnableVertexAttribArray(ati);
		}
		glBindVertexArray(0); glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	// --core_methods
	void VertexBufOgl::Bind() const {
		if (m_bIsBound) { return; }
		glBindVertexArray(m_unRIdVA); glBindBuffer(GL_ARRAY_BUFFER, m_unRIdVB);
		m_bIsBound = true;
	}
	void VertexBufOgl::Unbind() const {
		if (!m_bIsBound) { return; }
		glBindVertexArray(0); glBindBuffer(GL_ARRAY_BUFFER, 0);
		m_bIsBound = false;
	}
}
// IndexBufferOgl
namespace GLIB
{
	IndexBufOgl::IndexBufOgl() :
		AIndexBuf(),
		m_unRId(0) { }
	IndexBufOgl::~IndexBufOgl() { SetData(0, nullptr); }

	// --setters
	void IndexBufOgl::SetData(Size szAlloc, const Ptr pIdxData) {
		m_szData = szAlloc;
		if (m_unRId != 0) { glDeleteBuffers(1, &m_unRId); m_unRId = 0; }
		if (szAlloc == 0) { return; }
		glGenBuffers(1, &m_unRId);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_unRId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, szAlloc, pIdxData,
			pIdxData == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	void IndexBufOgl::SetSubData(Size szData, const Ptr pIdxData, Size szOffset)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_unRId);
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, szOffset, szData, pIdxData);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	// --core_methods
	void IndexBufOgl::Bind() const {
		if (m_bIsBound) { return; }
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_unRId);
		m_bIsBound = true;
	}
	void IndexBufOgl::Unbind() const {
		if (!m_bIsBound) { return; }
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		m_bIsBound = false;
	}
}
// ShaderBufferOgl
namespace GLIB
{
	ShaderBufOgl::ShaderBufOgl() :
		AShaderBuf(),
		m_unRId(0) { }
	ShaderBufOgl::~ShaderBufOgl() { SetData(0, nullptr); }

	// --setters
	void ShaderBufOgl::SetData(Size szAlloc, const Ptr pShdData) {
		m_szData = szAlloc;
		if (m_unRId != 0) { glDeleteBuffers(1, &m_unRId); m_unRId = 0; }
		if (szAlloc == 0) { return; }
		glGenBuffers(1, &m_unRId);

		glBindBuffer(GL_UNIFORM_BUFFER, m_unRId);
		glBufferData(GL_UNIFORM_BUFFER, szAlloc, pShdData,
			pShdData == nullptr ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}
	void ShaderBufOgl::SetSubData(Size szData, const Ptr pShdData, Size szOffset) {
		glBindBuffer(GL_UNIFORM_BUFFER, m_unRId);
		glBufferSubData(GL_UNIFORM_BUFFER, szOffset, szData, pShdData);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}

	void ShaderBufOgl::SetLayout(const ShaderBufLayout& rBufLayout) {
		m_bufLayout = rBufLayout;
		if (m_szData < rBufLayout.GetSize()) { SetData(rBufLayout.GetSize()); }
		for (auto& rBlock : rBufLayout.GetBlocks()) { Bind(rBlock.unBindPoint, rBlock.szAll, rBlock.szOffset); }
	}

	// --core_methods
	void ShaderBufOgl::Bind() const
	{
		if (m_bIsBound) { return; }
		for (auto& rBlock : m_bufLayout.GetBlocks()) { Bind(rBlock.unBindPoint, rBlock.szAll, rBlock.szOffset); }
		m_bIsBound = true;
	}
	void ShaderBufOgl::Bind(UInt32 unPoint) const {
		glBindBuffer(GL_UNIFORM_BUFFER, m_unRId);
		glBindBufferBase(GL_UNIFORM_BUFFER, unPoint, m_unRId);
	}
	void ShaderBufOgl::Bind(UInt32 unPoint, Size szData, Size szOffset) const {
		glBindBuffer(GL_UNIFORM_BUFFER, m_unRId);
		glBindBufferRange(GL_UNIFORM_BUFFER, unPoint, m_unRId, szOffset, szData);
	}
	void ShaderBufOgl::Unbind() const {
		if (!m_bIsBound) { return; }
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
		m_bIsBound = false;
	}
}
#endif	// GLIB_GAPI