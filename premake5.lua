--==<graphics_library_project>==--
project "nw_gfx"
	kind "staticlib" --.lib
	staticruntime "on"
	language "c++"
	cppdialect "c++17"
	targetdir (dir_out_res)
	objdir (dir_out_int)
	pchheader "nwg_pch.hpp"
	pchsource "src_cpp/nwg_pch.cpp"
	files
	{
		"%{dir_cpp.own}**.c**",
		"%{dir_cpp.own}**.h**",
		dir_data,
		dir_lua.."**.**",
		dir_glsl.."**.**",
		dir_hlsl.."**.**",
		dir_data.."**.h", dir_data.."**.rc",  dir_data.."**.aps",
	}
	includedirs
	{
		"%{dir_cpp.own}",
		"%{dir_cpp.ext}",
		"%{dir_cpp.nw_lib}",
		dir_data,
	}
	libdirs
	{
		"%{dir_lib.nw_lib}",
	}
	links
	{
		"nw_lib",
		"opengl32.lib",
		"d3d11.lib",
	}
	filter "system:windows"
		systemversion "latest"
		defines { "NWG_PLATFORM_WINDOWS" }
	filter "configurations:debug"
		defines "NWG_DEBUG"
		symbols "on"
	filter "configurations:release"
		defines "NWG_RELEASE"
		optimize "on"
--==</graphics_project>==--