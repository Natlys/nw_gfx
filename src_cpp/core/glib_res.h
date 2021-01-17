#ifndef GLIB_RES_H
#define GLIB_RES_H

#include <glib_core.hpp>

namespace GLIB
{
	/// IdStack class
	class IdStack : protected DStack<UInt32>
	{
	public:
		IdStack() : DStack<UInt32>() { push(1); }
		// -- getters
		inline UInt32 GetFreeId() { UInt32 unFreeId = top(); if (size() == 1) { top()++; } else { pop(); } return unFreeId; }
		// -- setters
		inline void SetFreeId(UInt32 unFreeId) { if (unFreeId != top()) { push(unFreeId); } }
	};
	/// Abstract GraphicsRes class
	class GLIB_API AGRes
	{
	public:
		AGRes(const char* strName);
		AGRes(AGRes& rCpy);
		virtual ~AGRes();

		// --getters
		inline const char* GetName() { return &m_strName[0]; }
		inline UInt32 GetId() { return m_unId; }
		// --data_methods
		virtual bool SaveF(const char* strFPath) = 0;
		virtual bool LoadF(const char* strFPath) = 0;
	protected:
		String m_strName;
		UInt32 m_unId;
	private:
		static IdStack s_IdStack;
	};
}

#endif	// GLIB_RES_H