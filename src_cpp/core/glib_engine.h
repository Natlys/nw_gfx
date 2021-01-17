#ifndef GLIB_ENGINE_H
#define GLIB_ENGINE_H

#include <core/glib_layer.h>
#include <core/glib_res.h>

namespace GLIB
{
	/// GEngine singleton class
	class GLIB_API GEngine
	{
	public:
		using Layers = DArray<GLayer>;
		using AGRs = HashMap<UInt32, AGRes*>;
		template <class GType> using GRs = HashMap<UInt32, GType*>;
	private:
		GEngine();
		GEngine(const GEngine& rCpy) = delete;
		void operator=(const GEngine& rCpy) = delete;
	public:
		~GEngine();
		
		// --getters
		static inline GEngine& Get() { static GEngine s_GEngine; return s_GEngine; }
		inline std::thread& GetRunThread() { return m_thrRun; }
		inline AWindow* GetWindow() { return m_pWindow; }
		inline AGApi* GetGApi() { return m_pGApi; }
		const GEngineInfo& GetInfo() { return m_DInfo; }
		inline Layers& GetLayers() { return m_GLayers; }
		inline GLayer* GetLayer() { return &*m_GLayer; }
		inline GLayer* GetLayer(const char* strName);
		static inline AGRs& GetAGResources() { static AGRs s_AGRs; return s_AGRs; }
		static inline AGRes* GetAGResource(UInt32 unId);
		static inline AGRes* GetAGResource(const char* strName);
		template <class GType> static inline GRs<GType>& GetGResources() { static GRs<GType> s_GRs; return s_GRs; }
		template <class GType> static inline GType* GetGResource(UInt32 unId);
		template <class GType> static inline GType* GetGResource(const char* strName);
		// --setters
		GLayer* AddLayer(const char* strName);
		void RmvLayer(const char* strName);
		static inline void AddAGRes(AGRes* pAGRes);
		static inline void RmvAGRes(UInt32 unId);
		template <class GType> static inline void AddGRes(GType* pGRes);
		template <class GType> static inline void RmvGRes(UInt32 unId);
		// --predicates
		bool IsRunning() { return m_bIsRunning; }

		// --core_methods
		bool Init(WApiTypes WindowApiType, GApiTypes GraphicsApiType);
		void Quit();
		void Run();
		void Update();
		// --data_methods
		bool SaveFImage(const char* strFPath, ImageInfo* pImgInfo);
		bool LoadFImage(const char* strFPath, ImageInfo* pImgInfo);
		bool SaveFShaderCode(const char* strFPath, AShader* pShader);
		bool LoadFShaderCode(const char* strFPath, AShader* pShader);
	private:
		bool m_bIsRunning;
		std::thread m_thrRun;

		AWindow* m_pWindow;
		AGApi* m_pGApi;

		Layers m_GLayers;
		Layers::iterator m_GLayer;

		GEngineInfo m_DInfo;
	};
	inline GLayer* GEngine::GetLayer(const char* strName) {
		Layers::iterator itLayer = std::find_if(m_GLayers.begin(), m_GLayers.end(),
			[=](GLayer& rObj)->bool { return rObj.strName == strName; });
		return itLayer == m_GLayers.end() ? nullptr : &*itLayer;
	}
	inline AGRes* GEngine::GetAGResource(UInt32 unId) {
		AGRs& rAGRs = GetAGResources();
		AGRs::iterator& itAGR = rAGRs.find(unId);
		return itAGR == rAGRs.end() ? nullptr : itAGR->second;
	}
	inline AGRes* GEngine::GetAGResource(const char* strName) {
		AGRs& rAGRs = GetAGResources();
		AGRs::iterator& itAGR = find_if(rAGRs.begin(), rAGRs.end(),
			[=](std::pair<const UInt32, AGRes*>& rAGR)->bool { return strcmp(strName, rAGR.second->GetName()) == 0; });
		return itAGR == rAGRs.end() ? nullptr : itAGR->second;
	}
	template <class GType> inline GType* GEngine::GetGResource(UInt32 unId) {
		GRs<GType>& rGRs = GetGResources<GType>();
		GRs<GType>::iterator& itGR = rGRs.find(unId);
		return itGR == rGRs.end() ? nullptr : itGR->second;
	}
	template <class GType> inline GType* GEngine::GetGResource(const char* strName) {
		GRs<GType>& rGRs = GetGResources<GType>();
		GRs<GType>::iterator& itGR = find_if(rGRs.begin(), rGRs.end(),
			[=](std::pair<const UInt32, GType*>& rGR)->bool { return strcmp(strName, rGR.second->GetName()) == 0; });
		return itGR == rGRs.end() ? nullptr : itGR->second;
	}
	inline void GEngine::AddAGRes(AGRes* pAGRes) {
		if (pAGRes == nullptr) { return; }
		GetAGResources()[pAGRes->GetId()] = pAGRes;
	}
	inline void GEngine::RmvAGRes(UInt32 unId) {
		AGRs& rAGRs = GetAGResources();
		AGRs::iterator& itAGRs = rAGRs.find(unId);
		if (itAGRs == rAGRs.end()) { return; }
		rAGRs.erase(itAGRs);
	}
	template <class GType> inline void GEngine::AddGRes(GType* pGRes) {
		if (pGRes == nullptr) { return; }
		GetGResources<GType>()[pGRes->GetId()] = pGRes;
	}
	template <class GType> inline void GEngine::RmvGRes(UInt32 unId) {
		GRs<GType>& rGRs = GetGResources<GType>();
		GRs<GType>::iterator& itGRs = rGRs.find(unId);
		if (itGRs == rGRs.end()) { return; }
		rGRs.erase(itGRs);
	}
}

#endif // GLIB_ENGINE_H