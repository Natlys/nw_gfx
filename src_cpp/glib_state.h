#ifndef GLIB_ASTATE_H
#define GLIB_ASTATE_H

#include <glib_core.hpp>

namespace GLIB
{
	/// GState class
	/// Description:
	/// -- This is the main interaction part for the engine.
	/// -- State handles Lua virtual machiene which allows to use Lua scripts
	class GLIB_API GState
	{
	public:
		virtual ~GState() = default;

		// --getters
		virtual inline const char* GetName() = 0;
		// --setters
		// --core_methods
		virtual bool Init() = 0;
		virtual void Update() = 0;
		virtual void OnEnable() = 0;
		virtual void OnDisable() = 0;
		// --on_event_methods
		virtual void OnEvent(MouseEvent& rmEvt) = 0;
		virtual void OnEvent(KeyboardEvent& rkEvt) = 0;
		virtual void OnEvent(WindowEvent& rwEvt) = 0;
	};
}
#endif	// GLIB_CORE_STATE_H