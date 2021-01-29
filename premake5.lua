--==<graphics_library_project>==--
project "nw_glib"
	kind "staticlib" --.lib
	staticruntime "on"
	language "c++"
	cppdialect "c++17"
	targetdir ("bin/"..dir_out.."%{prj.name}")
	objdir ("bin/int/"..dir_out.."%{prj.name}")
	pchheader "glib_pch.hpp"
	pchsource "src_cpp/glib_pch.cpp"
	files
	{
		"src_cpp/**.c**",
		"src_cpp/**.h**",
		"src_glsl/**.glsl",
	}
	includedirs
	{
		"src_cpp/",
		"%{dir_cpp.nw_lib}",
		"%{dir_cpp.glfw}",
		"%{dir_cpp.glad}",
		"%{dir_cpp.stbi}"
	}
	libdirs
	{
		"%{dir_lib.nw_lib}",
		"%{dir_lib.glfw}",
		"%{dir_lib.glad}"
	}
	links
	{
		"nw_lib",
		"glfw",
		"glad",
		"opengl32.lib"
	}
	defines
	{
		"GLIB_BUILD_LIB",
		"GLIB_LINK_STATIC"
		--"GLIB_LINK_DYNAMIC"
	}
	filter "system:windows"
		systemversion "latest"
		defines { "GLIB_PLATFORM_WINDOWS" }
	filter "configurations:debug"
		defines "GLIB_DEBUG"
		symbols "on"
	filter "configurations:release"
		defines "GLIB_RELEASE"
		optimize "on"
--==</graphics_library_project>==--