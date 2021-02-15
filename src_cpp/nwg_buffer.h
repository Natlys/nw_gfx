#ifndef NWG_BUFFER_H
#define NWG_BUFFER_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <nwg_entity.h>
#include <nwg_tools.h>
namespace NWG
{
	/// VertexBuffer Class
	class NWG_API VertexBuf : public GfxEntity
	{
		friend class VertexArr;
	public:
		VertexBuf();
		virtual ~VertexBuf();
		// --setters
		void SetData(Size szData, const Ptr pVtxData = nullptr);
		void SetSubData(Size szData, const Ptr pVtxData, Size szOffset = 0);
		// --core_methods
		virtual void Bind() const override;
	private:
		Size m_szData;
	};
	/// IndexBuffer Class
	class NWG_API IndexBuf : public GfxEntity
	{
		friend class GfxEngine;
	public:
		IndexBuf();
		virtual ~IndexBuf();
		// --setters
		void SetData(Size szData, const Ptr pVtxData = nullptr);
		void SetSubData(Size szData, const Ptr pVtxData, Size szOffset = 0);
		// --core_methods
		virtual void Bind() const override;
	private:
		Size m_szData;
	};
	/// ShaderBuffer class
	/// Description:
	/// -- Is used by shaders as opengl uniform setter, or as directx constant buffer
	class NWG_API ShaderBuf : public GfxEntity
	{
	public:
		ShaderBuf();
		virtual ~ShaderBuf();
		// --setters
		void SetData(Size szData, const Ptr pVtxData = nullptr);
		void SetSubData(Size szData, const Ptr pVtxData, Size szOffset = 0);
		// --core_methods
		virtual void Bind() const override;
		void Bind(UInt32 unPoint) const;
		void Bind(UInt32 unPoint, Size szData, Size szOffset = 0) const;
		void Remake(const ShaderBufLayout& rShdLayout);
	private:
		Size m_szData;
	};
}
#endif	// NWG_GAPI
#endif	// NWG_BUFFER_H