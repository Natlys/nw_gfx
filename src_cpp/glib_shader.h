#ifndef GLIB_ASHADER_H
#define GLIB_ASHADER_H
#include <core/glib_res.h>
#include <glib_tools.h>
#include <glib_buffer.h>

#if (defined GLIB_GAPI)
namespace GLIB
{
	/// Abstract SubShader Class
	class GLIB_API ASubShader : public AGRes
	{
	public:
		using Attribs = HashMap<String, Int32>;
		using Blocks = HashMap<String, Int32>;
	public:
		ASubShader(const char* strName, ShaderTypes sdType);
		virtual ~ASubShader();

		// --getters
		inline UInt32 GetRenderId() const { return m_unRId; }
		inline const char* GetCode() const { return &m_strCode[0]; }
		inline ShaderTypes GetType() const { return m_shdType; }
		virtual inline const AShader* GetOverShader() const = 0;
		// --setters
		inline void SetCode(const char* strCode) { m_strCode = strCode; }

		// --core_methods
		virtual void Attach(AShader* pOverShader) = 0;
		virtual void Detach() = 0;
		virtual bool Compile() = 0;
		virtual void Reset() = 0;
		// --data_methods
		virtual bool SaveF(const char* strFPath) override;
		virtual bool LoadF(const char* strFPath) override;
		
		static ASubShader* Create(const char* strName, ShaderTypes sdType);
	protected:
		UInt32 m_unRId;
		String m_strCode;
		ShaderTypes m_shdType;
	};
	/// Abstract Shader Class
	/// --Interface:
	/// -> Create -> AddSource Code with defined type -> Compile/Link
	/// -> Enable -> {Render} -> Disable
	/// --It is abstraction of current graphical API for GPU programms
	/// --So GPU can do any work without implicit API specification in the engine
	///	Shader Source Code loading rules:
	/// --> Load string as a source code(can be loaded a from file throught loadMaster)
	/// --> Load the source code with the beginning "#shader type" on the top of the particular shader
	/// --> SetSource of entire file with the appropriate type which is written there
	/// --> It is allowed to write shader code in separate and in the whole file.
	/// --> The code string has to be finished as "#shader type" or just "\0"(end of string)
	/// Future:
	/// -> Shader code preprocessing detects specific uniforms (lights/transform_matricies/...)
	/// And uses them for setting without giving a particular sstrName
	class GLIB_API AShader : public AGRes
	{
	public:
		using Globals = HashMap<String, Int32>;
		using Blocks = HashMap<String, Int32>;
	public:
		AShader(const char* strName);
		virtual ~AShader();

		// --getters
		inline UInt32 GetRenderId() const { return m_unRId; }
		inline const char* GetCode() const { return &m_strCode[0]; }
		inline const VertexBufLayout& GetVtxLayout() const { return m_vtxLayout; }
		inline const ShaderBufLayout& GetShdLayout() const { return m_shdLayout; }
		inline const Globals& GetGlobals() const { return m_Globals; }
		inline const Blocks& GetBlocks() const { return m_Blocks; }
		virtual inline const ASubShader* GetSubShader(ShaderTypes sdType) = 0;
		// --setters
		inline void SetCode(const char* strCode) { m_strCode = strCode; }
		// --core_methods
		virtual void Enable() = 0;
		virtual void Disable() = 0;
		virtual bool Compile() = 0;
		virtual void Reset() = 0;
		// --data_methods
		virtual bool SaveF(const char* strFPath) override;
		virtual bool LoadF(const char* strFPath) override;

		static AShader* Create(const char* strName);

		// --code_setters
		virtual void SetBool(const char* strName, bool value) const = 0;
		virtual void SetInt(const char* strName, int value) const = 0;
		virtual void SetIntArray(const char *strName, Int32 *pIntArr, UInt32 unCount) const = 0;
		virtual void SetUIntArray(const char *strName, UInt32 *pUIntArr, UInt32 unCount) const = 0;
		virtual void SetFloat(const char* strName, float value) const = 0;
		virtual void SetFloatArray(const char *strName, float *pFloatArr, UInt32 unCount) const = 0;
		virtual void SetV2f(const char* strName, const V2f& value) const = 0;
		virtual void SetV3f(const char* strName, const V3f& value) const = 0;
		virtual void SetV4f(const char* strName, const V4f& value) const = 0;
		virtual void SetM4f(const char* strName, const Mat4f& value) const = 0;
	protected:
		UInt32 m_unRId;
		String m_strCode;
		VertexBufLayout m_vtxLayout;
		ShaderBufLayout m_shdLayout;
		mutable Globals m_Globals;
		mutable Blocks m_Blocks;
	};
}
#endif	// GLIB_GAPI
#if (GLIB_GAPI & GLIB_GAPI_OGL)
// SubShader
namespace GLIB
{
	/// SubShader class OpenGL abstraction
	/// Interface:
	/// -> Create the shader
	/// -> Set the entire shader source code with written comment "#shader type" on the top
	/// -> Compile(Load) -> Set the ShaderOglram -> link that ShaderOglram
	class GLIB_API SubShaderOgl : public ASubShader
	{
		friend class ShaderOgl;
	public:
		SubShaderOgl(const char* strName, ShaderTypes sType);
		~SubShaderOgl();

		// --getters
		virtual const AShader* GetOverShader() const override;
		// --core_methods
		virtual void Attach(AShader* pOverShader) override;
		virtual void Detach() override;
		virtual bool Compile() override;
		virtual void Reset() override;
	private:
		inline bool CodeProc();
	private:
		ShaderOgl* m_pOverShader;
	};
}
// Shader
namespace GLIB
{
	/// Shader class - handler for shader program OpenGL
	/// Interface:
	/// -> Create ->
	/// -> Set the source code for both shader types: vertex and fragment shader
	/// -> Load the program
	/// Description
	/// -- Instead of own source code, shader programm has shader objects with that code
	class GLIB_API ShaderOgl : public AShader
	{
		friend class SubShaderOgl;
	public: // Interface Methods
		ShaderOgl(const char* strName);
		~ShaderOgl();

		// --getters
		virtual inline const ASubShader* GetSubShader(ShaderTypes sdType) {
			auto itSub = FIND_BY_FUNC(m_SubShaders, ASubShader&, sdType, .GetType);
			return itSub == m_SubShaders.end() ? nullptr : &*itSub;
		}
		// --core_methods
		virtual void Enable() override;
		virtual void Disable() override;
		virtual bool Compile() override;
		virtual void Reset() override;
		// --code_setters
		virtual void SetBool(const char* strName, bool value) const override;
		virtual void SetInt(const char* strName, int value) const override;
		virtual void SetIntArray(const char* strName, Int32* pIntArr, UInt32 unCount) const override;
		virtual void SetUIntArray(const char* strName, UInt32* pIntArr, UInt32 unCount) const override;
		virtual void SetFloat(const char* strName, float value) const override;
		virtual void SetFloatArray(const char* strName, float* pFloatArr, UInt32 unCount) const override;
		virtual void SetV2f(const char* strName, const V2f& value) const override;
		virtual void SetV3f(const char* strName, const V3f& value) const override;
		virtual void SetV4f(const char* strName, const V4f& value) const override;
		virtual void SetM4f(const char* strName, const Mat4f& value) const override;
	private:
		DArray<SubShaderOgl> m_SubShaders;
	private:
		/// We have gotten a whole source code file
		/// Iterate throught all the lines in that code
		/// If it suits the format:
		/// Create new SubShaderOgl of appropriate type in the own vector, set it's source
		inline bool CodeProc();
		// Optimization
		/// Gets uniforms from the program, or from the uniforms cashe if they are there
		inline Int32 GetUniformLoc(const char* strName) const;
		inline Int32 GetBlockIdx(const char* strName) const;
	};
}
#endif // GLIB_GAPI
#endif // GLIB_ASHADER_H