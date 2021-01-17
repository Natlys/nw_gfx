#ifndef GLIB_CORE_HPP
#define GLIB_CORE_HPP

// --==<linking>==--
#if defined GLIB_LINK_DYNAMIC
#ifdef GLIB_BUILD_DLL
#define GLIB_API __declspec(dllexport)
#elif defined GLIB_BUILD_EXE
#define GLIB_API __declspec(dllimport)
#endif
#else
#define GLIB_API
#endif
// --==</linking>==--

// --==<configurations>==--
// --window_choice
#define GLIB_WINDOW_GLFW			1 << 1
#define GLIB_WINDOW				GLIB_WINDOW_GLFW
// --window_choice

// --mathematics_library_choice
#define GLIB_MATH_NATIVE			1 << 1
#define GLIB_MATH_GLM				1 << 2
#define GLIB_MATH					GLIB_MATH_GLM
// --mathematics_library_choice

// --graphics_api_choice
#define GLIB_GAPI_OGL		1 << 1

#define GLIB_GAPI GLIB_GAPI_OGL

#if (GLIB_WINDOW & GLIB_WINDOW_GLFW)
#define GLFW_INCLUDE_NONE
#endif	// GLIB_WINDOW
// --==</configurations>==--

// --==<support_macroses>==--
///Translate anything to the C string(char array)
#define GLIB_CSTR(anything) (#anything)
/// Translate anything to the string
#define GLIB_STR(anything) (std::string(anything))
/// Formating of text same as printf()
#define GLIB_STR_FORM(format, args);
/// Get directory of cpp file
#define GLIB_STR_PART_L(str, symb) ( ( str.substr(0, str.rfind(symb) + 1) ).c_str() )
/// Get name of cpp file
#define GLIB_STR_PART_R(str, symb) ( ( str.substr(str.rfind(symb) + 1, str.size()) ).c_str() )
/// Get file name from absolute path
#define GLIB_FNAME_APATH(path) ( GLIB_STR_PART_R(std::string(path), '\\') )
/// Get file directory from absolute path
#define GLIB_FDIR_APATH(path) ( GLIB_STR_PART_L(std::string(path), '\\') )

#define XY_TO_X(x, y, w) (y * w + x)

#define FIND_BY_FUNC(Container, Type, val, func) std::find_if(Container.begin(), Container.end(),	\
	[=](Type Obj)->bool {return Obj func() == val; });
#define FIND_BY_NAME(Container, Type, val, func) std::find_if(Container.begin(), Container.end(),	\
	[=](Type Obj)->bool {return (strcmp(&(Obj func())[0], val) == 0); });

// --debug_macro
// -->__VA_ARGS__ - variadic agruments = arguments given as ...
#if (defined GLIB_DEBUG)
#define GLIB_BREAK() __debugbreak();
/// Print the calling location and the message
/// --Writes LOG::[location]::LINE_{calling_line}:
///	====< msg >====\n
#define GLIB_LOG(msg) GLIB_LOG_LOC(GLIB_FNAME_APATH(__FILE__));			\
		std::cout << "====< " << msg << " >====\n";
	/// --Takes format string where [param] means next string
	/// --Example: NW_LOG_F("Format message [param] sometext", nextString)
	/// --Writes: LOG::[FILE_NAME]::LILE_[CURR_LINE]:
	///	====< Format message nextString sometext >====
#define GLIB_LOG_F(format, ...) {										\
		const char* msg = format; int i = 0;							\
		char ch = 'a';	std::stringstream sStr;							\
		while(ch != '\0') { ch = msg[i];								\
			if (ch == '{') while(true) { ch = msg[i + 1];				\
				if (ch == '\0') break;									\
				else if (ch == '}'){sStr << __VA_ARGS__; break;}		\
				i++; }													\
			else {sStr << msg[i];}										\
		i++; }															\
		GLIB_LOG(sStr.str());												\
	}
	/// --Writes LOG::[location]::LINE_{calling_line}:\n
#define GLIB_LOG_LOC(loc) std::cout << "LOG::[" << loc <<				\
			"]::LINE_" << __LINE__ << std::endl
#define GLIB_ASSERT(expr, comment) if (!(expr)) { std::cout <<		\
		"GLIB::ASSERT::[" << __FILE__ <<									\
		"]::LINE_" << __LINE__ << ":\n" << comment << ">>\n";			\
	GLIB_BREAK(); }
#define GLIB_ERR(comment) GLIB_ASSERT(false, comment);

#if (GLIB_GAPI & GLIB_GAPI_OGL)
// --opengl_debug
namespace NW
{
	extern inline void OGL_ClearErr();
	extern inline bool OGL_ErrLog(const char* funcName, const char* file, int line);
}
#define OGL_CALL(function) OGL_ClearErr();\
		function;\
		GLIB_ASSERT(OGL_ErrLog(#function, NW_FNAME_APATH((std::string)__FILE__), __LINE__), "GL_ERROR: ")
#endif // NW_GRAPHICS
#else
#define GLIB_LOG(loc, what);
#define GLIB_LOG_LC(loc, what);
#define GLIB_ASSERT(expr, comment);
#define GLIB_ERR(function);

#define OGL_CALL(function);
#endif // GLIB_DEBUG
// --==</support_macroses>==--

// --==<pragmas>==--
#pragma warning(disable : 4005)
#pragma warning(disable : 4081)
#pragma warning(disable : 4099)
#pragma warning(disable : 4102)
#pragma warning(disable : 4244)
#pragma warning(disable : 4267)
#pragma warning(disable : 4552)
#pragma warning(disable : 4996)
// --==</pragmas>==--

#endif	// GLIB_CORE_HPP

#include <glib_pch.hpp>
#include <glib_def.hpp>

/*
* The project created in 16.01.2021
* Graphics library as a tool for game engines and applications
*/