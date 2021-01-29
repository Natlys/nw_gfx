#ifndef GLIB_PCH_HPP

// --<standard>--
// --stl
#include <utility>
#include <functional>
#include <algorithm>
// --</standard>--

// --<native>--
// --</native>--

// --<platform>--
#ifdef GLIB_PLATFORM_WINDOWS
#include <windows.h>
#endif
// --</platform>--

#include <native_world_library.hpp>
using namespace NWL;

#endif	// GLIB_PCH_HPP