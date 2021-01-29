#ifndef GLIB_GBUFFER_H
#define GLIB_GBUFFER_H

#include <glib_tools.h>

#if (defined GLIB_GAPI)
// VertexBufLayout
namespace GLIB
{
	/// BufferElement structure
	/// --Contains all relevant data for shader usage of vertex buffer data
	struct GLIB_API BufferElement
	{
	public:
		Char strName[128];
		ShaderDataTypes sdType;
		UInt32 unCount;
		bool bNormalized;
		UInt32 unOffset;
	public:
		BufferElement() : strName(""), sdType(SDT_NONE), unCount(0), bNormalized(false), unOffset(0) { }
		BufferElement(const char* sName, ShaderDataTypes shaderDataType, UInt32 Count, bool Normalized) :
			strName(""), sdType(shaderDataType), unCount(Count),
			bNormalized(Normalized), unOffset(0) {
			strcpy(strName, sName);
		}
	};
	struct GLIB_API ShaderBlock
	{
	public:
		Char strName[128];
		UInt8 unBindPoint;
		DArray<BufferElement> BufElems;
		Size szOffset;
		Size szAll;
	public:
		ShaderBlock() : strName(""), unBindPoint(0), szOffset(0), szAll(0) {};
		ShaderBlock(const char* sName, UInt8 BindPoint) :
			strName(""),
			unBindPoint(BindPoint), szAll(0), szOffset(0) {
			strcpy(strName, sName);
		}
	};
	/// VertexBufLayout class
	class GLIB_API VertexBufLayout
	{
	public:
		VertexBufLayout() : m_unStride(1) { }
		VertexBufLayout(const DArray<BufferElement>& rBufElems) :
			m_unStride(1) { SetElements(rBufElems); }

		// --getters
		inline const BufferElement& GetElem(UInt8 unIdx) const { return m_BufElems.at(unIdx); }
		inline const DArray<BufferElement>& GetElems() const { return m_BufElems; }
		inline const UInt32 GetStride() const { return m_unStride; }
		// --setters
		inline void SetElements(const DArray<BufferElement>& rBufElems) { m_BufElems = rBufElems; Update(); }
		inline void AddElement(const BufferElement& rBufElem, Int8 nElems = 1) { while (nElems-- > 0) { m_BufElems.push_back(rBufElem); } Update(); }
		inline void AddElement(const char* strName, ShaderDataTypes sdType, UInt8 unCount, Int8 nElems = 1) {
			AddElement(BufferElement(strName, sdType, unCount, false), nElems);
		}
		inline void Reset() { m_unStride = 0; m_BufElems.clear(); }
	private:
		UInt32 m_unStride;
		DArray<BufferElement> m_BufElems;
	private:
		inline void Update() {
			m_unStride = 0;
			for (auto& rBufElem : m_BufElems) {
				rBufElem.unOffset = m_unStride;
				m_unStride += SdTypeGetSize(rBufElem.sdType, rBufElem.unCount);
			}
		}
	};
	/// ShaderBufLayout class
	class GLIB_API ShaderBufLayout
	{
	public:
		ShaderBufLayout() : m_szData(0) { }
		ShaderBufLayout(const DArray<ShaderBlock>& rBlocks) :
			m_szData(0) {
			SetBlocks(rBlocks);
		}
		// --getters
		inline Size GetSize() const { return m_szData; }
		inline const DArray<BufferElement>& GetGlobals() const { return m_Globals; }
		inline const ShaderBlock& GetBlock(UInt8 unIdx) const { return m_Blocks.at(unIdx); }
		inline const DArray<ShaderBlock>& GetBlocks() const { return m_Blocks; }
		// --setters
		inline void AddGlobalElem(const BufferElement& rBufElem) { m_Globals.push_back(rBufElem); }
		inline void SetBlocks(const DArray<ShaderBlock>& rBlocks) { m_Blocks = rBlocks; Update(); }
		inline void AddBlock(const ShaderBlock& rBlock, Int8 nElems = 1) { while (nElems-- > 0) { m_Blocks.push_back(rBlock); } Update(); }
		inline void Reset() { m_szData = 0; m_Blocks.clear(); m_Globals.clear(); }
	private:
		DArray<BufferElement> m_Globals;
		DArray<ShaderBlock> m_Blocks;
		Size m_szData;
	private:
		inline void Update() {
			m_szData = 0;
			for (UInt8 bi = 0; bi < m_Blocks.size(); bi++) {
				auto& rBlock = m_Blocks[bi];
				rBlock.unBindPoint = bi;
				rBlock.szOffset = m_szData;
				for (auto& rElem : rBlock.BufElems) {
					rElem.unOffset += rBlock.szAll;
					rBlock.szAll += SdTypeGetAllignedSize(rElem.sdType, rElem.unCount);
				}
				m_szData += rBlock.szAll;
			}
		}
	};
}
// Graphics Objetcs
namespace GLIB
{
	/// Abstract VertexBuffer Class
	/// Interface:
	/// -> Create -> If created with data in OpenGL, load dynamically,
	/// else - load statically and don't change the buffer size;
	/// -> Load Data (if it isn't)
	/// -> Give it's pointer to VertexArray EITHER
	/// Bind -> Draw -> Unbind
	class GLIB_API AVertexBuf
	{
	protected:
		AVertexBuf();
		AVertexBuf(const AVertexBuf& rCpy) = delete;
	public:
		virtual ~AVertexBuf() = default;

		// --getters
		inline Size GetDataSize() const { return m_szData; }
		inline const VertexBufLayout& GetLayout() { return m_bufLayout; }
		// --setters
		virtual void SetData(Size szData, const Ptr pVtxData = nullptr) = 0;
		virtual void SetSubData(Size szData, const Ptr pVtxData, Size szOffset = 0) = 0;
		virtual void SetLayout(const VertexBufLayout& rBufLayout) = 0;
		// --predicates
		inline Bit IsBound() const { return m_bIsBound; }
		// --core_methods
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static AVertexBuf* Create();
		static void Create(Size szAlloc, const Ptr pVtxData, RefOwner<AVertexBuf>& rVtxBuf);
		static void Create(Size szAlloc, const Ptr pVtxData, RefKeeper<AVertexBuf>& rVtxBuf);
		// --operators
		Ptr operator new[](Size szMem) = delete;
		void operator delete(Ptr pBlock) = delete;
		void operator delete[](Ptr pBlock) = delete;
	protected:
		mutable Bit m_bIsBound;
		Size m_szData;
		VertexBufLayout m_bufLayout;
	};
	/// Abstract IndexBuffer Class
	/// Interface:
	/// -> Create -> If created with data in OpenGL, load dynamically,
	/// else - load statically and don't change the buffer size;
	/// -> Load Data (if it isn't)
	/// -> Give it's pointer to VertexArray EITHER
	/// Bind -> Bind VertexBuffer -> Draw -> Unbind both Buffers
	class GLIB_API AIndexBuf
	{
	protected:
		AIndexBuf();
		AIndexBuf(const AIndexBuf& rCpy) = delete;
	public:
		virtual ~AIndexBuf() = default;

		// --getters
		inline Size GetDataSize() const { return m_szData; }
		// --setters
		virtual void SetData(Size szAlloc, const Ptr pIdxData = nullptr) = 0;
		virtual void SetSubData(Size szData, const Ptr pIdxData, Size szOffset = 0) = 0;
		// --predicates
		inline Bit IsBound() const { return m_bIsBound; }
		// --core_methods
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static AIndexBuf* Create();
		static void Create(Size szAlloc, const Ptr pIdxData, RefOwner<AIndexBuf>& rIdxBuf);
		static void Create(Size szAlloc, const Ptr pIdxData, RefKeeper<AIndexBuf>& rIdxBuf);
		// --operators
		void operator delete(Ptr pBlock) = delete;
		void operator delete[](Ptr pBlock) = delete;
	protected:
		mutable Bit m_bIsBound;
		Size m_szData;
	};
	/// Abstract ShaderBuffer class
	/// Description:
	/// -- Is used by shaders as opengl uniform setter, or as directx constant buffer
	class GLIB_API AShaderBuf
	{
	protected:
		AShaderBuf();
		AShaderBuf(const AShaderBuf& rCpy) = delete;
	public:
		virtual ~AShaderBuf() = default;

		// --getters
		inline Size GetDataSize() const { return m_szData; }
		virtual inline const ShaderBufLayout& GetLayout() { return m_bufLayout; }
		// --setters
		virtual void SetData(Size szData, const Ptr pShdData = nullptr) = 0;
		virtual void SetSubData(Size szData, const Ptr pShdData, Size szOffset = 0) = 0;
		virtual void SetLayout(const ShaderBufLayout& rShdLayout) = 0;
		// --predicates
		inline Bit IsBound() const { return m_bIsBound; }
		// --core_methods
		virtual void Bind() const = 0;
		virtual void Bind(UInt32 unPoint) const = 0;
		virtual void Bind(UInt32 unPoint, Size szData, Size szOffset = 0) const = 0;
		virtual void Unbind() const = 0;

		static AShaderBuf* Create();
		static void Create(Size szAlloc, const Ptr pShaderData, RefOwner<AShaderBuf>& rShdBuf);
		static void Create(Size szAlloc, const Ptr pShaderData, RefKeeper<AShaderBuf>& rShdBuf);
		// --operators
		void operator delete(Ptr pBlock) = delete;
		void operator delete[](Ptr pBlock) = delete;
	protected:
		mutable Bit m_bIsBound;
		Size m_szData;
		ShaderBufLayout m_bufLayout;
	};
}
#endif	// GLIB_GAPI
#if (GLIB_GAPI & GLIB_GAPI_OGL)
namespace GLIB
{
	/// VertexBufOgl
	class GLIB_API VertexBufOgl : public AVertexBuf
	{
	public:
		VertexBufOgl();
		~VertexBufOgl();

		// --setters
		virtual void SetData(Size szAlloc, const Ptr pVtxData = nullptr) override;
		virtual void SetSubData(Size szAlloc, const Ptr pVtxData, Size szOffset = 0) override;
		virtual void SetLayout(const VertexBufLayout& rBufLayout) override;

		// --core_methods
		virtual void Bind() const override;
		virtual void Unbind() const override;
	private:
		UInt32 m_unRIdVB;
		UInt32 m_unRIdVA;
	};
	/// IndexBufOgl class
	class GLIB_API IndexBufOgl : public AIndexBuf
	{
	public:
		IndexBufOgl();
		~IndexBufOgl();

		// --setters
		virtual void SetData(Size szData, const Ptr pIdxData = nullptr) override;
		virtual void SetSubData(Size szData, const Ptr pIdxData, Size szOffset = 0) override;
		// --core_methods
		virtual void Bind() const override;
		virtual void Unbind() const override;
	private:
		UInt32 m_unRId;
	};
	/// ShaderBufOgl class
	class GLIB_API ShaderBufOgl : public AShaderBuf
	{
	public:
		ShaderBufOgl();
		~ShaderBufOgl();

		// --getters
		// --setters
		virtual void SetData(Size szAlloc, const Ptr pVtxData = nullptr) override;
		virtual void SetSubData(Size szAlloc, const Ptr pVtxData, Size szOffset = 0) override;
		virtual void SetLayout(const ShaderBufLayout& rBufLayout) override;
		// --core_methods
		virtual void Bind() const override;
		virtual void Bind(UInt32 unPoint) const override;
		virtual void Bind(UInt32 unPoint, Size szData, Size szOffset = 0) const override;
		virtual void Unbind() const override;
	private:
		UInt32 m_unRId;
	};
}
#endif // GLIB_GAPI
#endif	// GLIB_GBUFFER_H