#include <glib_pch.hpp>
#include "glib_res.h"

#include <core/glib_engine.h>

GLIB::IdStack GLIB::AGRes::s_IdStack = GLIB::IdStack();

namespace GLIB
{
	AGRes::AGRes(const char* strName) : m_strName(strName), m_unId(s_IdStack.GetFreeId()) { GEngine::Get().AddAGRes(this); }
	AGRes::AGRes(AGRes& rCpy) : AGRes(&rCpy.m_strName[0]) { }
	AGRes::~AGRes() { GEngine::Get().RmvAGRes(GetId()); s_IdStack.SetFreeId(m_unId); }
}