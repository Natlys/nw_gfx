#ifndef GLIB_PCH_HPP

// --<standard>--
// --stl
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <algorithm>
// --data_proc
#include <iostream>
#include <sstream>
#include <fstream>
// --strings
#include <string>
// --support
#include <exception>
#include <typeinfo>
#include <typeindex>
// --memory
#include <new>
#include <memory>
// --parallel computation
#include <thread>
#include <future>
#include <mutex>
// --</standard>--

// --<native>--
#include <cstddef>
#include <cstdarg>
#include <cstdio>
#include <ctime>
// --</native>--

// --<platform>--
#ifdef GLIB_PLATFORM_WINDOWS
#include <windows.h>
#endif
// --</platform>--

#if (GLIB_MATH & GLIB_MATH_GLM)
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/matrix.hpp>
#endif	// GLIB_MATH

#endif	// GLIB_PCH_HPP