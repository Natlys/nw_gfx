#ifndef GLIB_ENGINE_H
#define GLIB_ENGINE_H

#include <glib_tools.h>
#include <glib_core.hpp>

namespace GLIB
{
	/// GEngine singleton class
	class GLIB_API GEngine : public ASingleton<GEngine>
	{
	public:
		friend class ASingleton<GEngine>;
	private:
		GEngine();
	public:
		~GEngine();
		
		// --getters
		inline AMemAllocator& GetMemory() { return m_Memory; }
		inline Thread& GetRunThread() { return m_thrRun; }
		
		inline AGApi* GetGApi() { return m_pGApi.GetRef(); }
		inline GApiTypes GetGApiType() { return m_gapiType; }
		const DrawerInfo& GetInfo() { return m_DInfo; }

		// --setters
		// --predicates
		Bit IsRunning() { return m_bIsRunning; }

		// --core_methods
		void Run();
		bool Init();
		void Quit();
		void Update();
		// --data_methods
		bool SaveFImage(const char* strFPath, ImageInfo* pImgInfo);
		bool LoadFImage(const char* strFPath, ImageInfo* pImgInfo);
		bool SaveFShaderCode(const char* strFPath, AShader* pShader);
		bool LoadFShaderCode(const char* strFPath, AShader* pShader);
		// --memory_methods
		template <typename MType, typename...Args>
		inline MType* NewT(Args...Arguments) { return NWL::NewT<MType>(GetMemory(), Arguments...); }
		template <typename MType>
		inline MType* NewTArr(UInt64 unAlloc) { return NWL::NewTArr<MType>(GetMemory(), unAlloc); }
		template <typename MType>
		inline void DelT(MType* pBlock) { NWL::DelT<MType>(GetMemory(), pBlock); }
		template <typename MType>
		inline void DelTArr(MType* pBlock, UInt64 unDealloc) { NWL::DelTArr<MType>(GetMemory(), pBlock, unDealloc); }
	private:
		Bit m_bIsRunning;
		Thread m_thrRun;
		MemArena m_Memory;

		RefOwner<AGApi> m_pGApi;
		GMaterial* m_pGMtlScreen;

		DrawerInfo m_DInfo;
		GApiTypes m_gapiType;
	};
}

#endif // GLIB_ENGINE_H