--==<native_wolrd_graphics/>==--
project("nc_gfx")
	--general--
	kind("staticlib")
	--language--
	language("c")
	--libraries--
	links{"nc_lib", "nc_cfg"}
	libdirs{"../nc_lib", "../nc_cfg"}
	--filters--
	----platform_filters----
	filter("platforms:win64")
		system("windows")
	----system_filters----
	filter("system:windows")
		systemversion("latest")
	----language_filters----
	filter("language:c++")
		--standard--
		cppdialect("c++17")
		clr("off")
		rtti("off")
		--source--
		files{"%(prj.name)/src_cpp/**.cpp","%(prj.name)/src_cpp/**.hpp"}
		includedirs {"%(prj.name)/src_cpp/"}
		--binary--
		targetdir ("bin_cpp")
		objdir ("bin_cpp")
	filter("language:c")
		--standard--
		cdialect("c99")
		clr("off")
		--source--
		files{"%(prj.name)/src_cxx/**.c","%(prj.name)/src_cxx/**.h"}
		includedirs {"%(prj.name)/src_cxx/"}
		--binary--
		targetdir ("bin_cxx")
		objdir ("bin_cxx")
	----file_filters----
--==</native_wolrd_graphics>==--