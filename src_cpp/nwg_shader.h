#ifndef NWG_SHADER_H
#define NWG_SHADER_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <nwg_entity.h>
#include <nwg_core.hpp>
#include <nwg_buffer.h>
namespace NWG
{
	/// SubShaderOpenGL Class
	class NWG_API SubShader : public GfxEntity, public ACodeRes
	{
	public:
		friend class Shader;
	public:
		SubShader(const char* strName, ShaderTypes sdType);
		~SubShader();
		// --getters
		inline ShaderTypes GetType() const { return m_shdType; }
		inline Shader* GetOverShader() { return m_pOverShader; }
		// --core_methods
		virtual void Bind() const override {}
		void Attach(Shader* pOverShader);
		void Detach();
		void Remake();
		bool Compile();
		// --data_methods
		bool SaveF(const char* strFPath) override;
		bool LoadF(const char* strFPath) override;
	private:
		inline bool CodeProc();
	private:
		ShaderTypes m_shdType;
		Shader* m_pOverShader;
	};
	/// ShaderOpenGL Class
	class NWG_API Shader : public GfxEntity, public ACodeRes
	{
	public:
		using Globals = HashMap<String, Int32>;
		using Blocks = HashMap<String, Int32>;
		friend class SubShader;
	public:
		Shader(const char* strName);
		 ~Shader();
		// --getters
		inline const VertexBufLayout& GetVtxLayout() const { return m_vtxLayout; }
		inline const ShaderBufLayout& GetShdLayout() const { return m_shdLayout; }
		inline const Globals& GetGlobals() const { return m_Globals; }
		inline const Blocks& GetBlocks() const { return m_Blocks; }
		inline const SubShader* GetSubShader(ShaderTypes sdType);
		// --setters
		void SetBool(const char* strName, bool value) const;
		void SetInt(const char* strName, int value) const;
		void SetIntArray(const char* strName, Int32* pIntArr, UInt32 unCount) const;
		void SetUIntArray(const char* strName, UInt32* pUIntArr, UInt32 unCount) const;
		void SetFloat(const char* strName, float value) const;
		void SetFloatArray(const char* strName, float* pFloatArr, UInt32 unCount) const;
		void SetV2f(const char* strName, const V2f& value) const;
		void SetV3f(const char* strName, const V3f& value) const;
		void SetV4f(const char* strName, const V4f& value) const;
		void SetM4f(const char* strName, const Mat4f& value) const;
		// --core_methods
		virtual void Bind() const override;
		void Remake();
		bool Compile();
		// --data_methods
		bool SaveF(const char* strFPath) override;
		bool LoadF(const char* strFPath) override;
	private:
		inline bool CodeProc();
		inline Int32 GetUniformLoc(const char* strName) const;
		inline Int32 GetBlockIdx(const char* strName) const;
	private:
		VertexBufLayout m_vtxLayout;
		ShaderBufLayout m_shdLayout;
		mutable Globals m_Globals;
		mutable Blocks m_Blocks;
		DArray<RefKeeper<SubShader>> m_SubShaders;
	};
	inline const SubShader* Shader::GetSubShader(ShaderTypes sdType) {
			auto itSub = std::find_if(m_SubShaders.begin(), m_SubShaders.end(),
				[=](RefKeeper<SubShader>& rSub)->bool {return rSub->GetType() == sdType; });
			return itSub == m_SubShaders.end() ? nullptr : itSub->GetRef();
		}
}
#endif	// NWG_GAPI
#endif // NWG_SHADER_H