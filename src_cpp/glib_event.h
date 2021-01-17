#ifndef GLIB_AEVENT_H
#define GLIB_AEVENT_H

#include <glib_decl.hpp>

namespace GLIB
{
	/// Abstract Event struct
	struct GLIB_API AEvent
	{
	public:
		bool bIsHandled = false;
		EventTypes EvtType = ET_NONE;
	public:
		AEvent(EventTypes evtType) : EvtType(evtType) {};
		virtual ~AEvent() = default;
	};
	/// MouseMoveEvent struct
	/// --Has x and y coordinates of mouse
	struct GLIB_API MouseEvent : public AEvent
	{
	public:
		double nX = 0.0, nY = 0.0;
		UInt32 nButton = 0;
	public:
		// MouseMove/Scroll-Event
		MouseEvent(EventTypes mmevtType, double nCoordOrScrollX, double nCoordOrScrollY) :
			AEvent(mmevtType), nX(nCoordOrScrollX), nY(nCoordOrScrollY) {}
		// MouseButtonEvent
		MouseEvent(EventTypes mbevtType, UInt32 nButtonIndex) :
			AEvent(mbevtType), nButton(nButtonIndex) {}
	};
	/// KeyboardEvent struct
	struct GLIB_API KeyboardEvent : public AEvent
	{
	public:
		// ReleaseEvent
		KeyboardEvent(EventTypes kevtType, UInt32 unKeyCode) :
			AEvent(kevtType), unKeyCode(unKeyCode), cChar(' ') {}
		// PressEvent
		KeyboardEvent(EventTypes kevtType, UInt32 unKeyCode, UInt32 unRepeatCount) :
			AEvent(kevtType), unKeyCode(unKeyCode), unRepeatCount(unRepeatCount), cChar(' ') {}
		// TypeEvent
		KeyboardEvent(Char Char) :
			AEvent(ET_KEY_TYPE), unKeyCode(0), unRepeatCount(0), cChar(Char) {}
		UInt32 unKeyCode = 0;
		UInt32 unRepeatCount = 0;
		Char cChar = ' ';
	};
	/// WindowEvent struct
	/// --Has width and height of the window
	struct GLIB_API WindowEvent : public AEvent
	{
	public:
		Int32 nX = 0, nY = 0;
		bool bIsFocused = false;
	public:
		// WindowCloseEvent
		WindowEvent(EventTypes wevType) :
			AEvent(wevType) {}
		// WindowFocusEvent
		WindowEvent(EventTypes wevType, bool bIsFocused) :
			AEvent(wevType), bIsFocused(bIsFocused) {}
		// WindowResizeEvent
		WindowEvent(EventTypes wevType, UInt32 nWidthOrX, UInt32 nHeightOrY) :
			AEvent(wevType), nX(nWidthOrX), nY(nHeightOrY) {}
	};
}

#endif	//NW_AEVENT_H