#ifndef NWG_CORE_HPP
#define NWG_CORE_HPP

// --==<linking>==--
#if (defined NWG_PLATFORM_WINDOWS)
	#if (defined NWG_BUILD_DLL)
		#define NWG_API __declspec(dllexport)
	#elif (defined NWG_BUILD_EXE)
		#define NWG_API __declspec(dllimport)
	#elif (defined NWG_BUILD_LIB)
		#define NWG_API
	#endif
#endif	// NWG_PLATFORM
// --==</linking>==--

// --==<configurations>==--
// --graphics api choice
#define NWG_GAPI_OGL	1 << 1
#define NWG_GAPI_DX		1 << 2
#define NWG_GAPI		NWG_GAPI_OGL
// --==</configurations>==--

#if (NWG_GAPI & NWG_GAPI_OGL)
// --==<data_types_ogl>==--
#define GL_BOOL					0x8B56
#define GL_BYTE					0x1400
#define GL_UNSIGNED_BYTE		0x1401
#define GL_SHORT				0x1402
#define GL_UNSIGNED_SHORT		0x1403
#define GL_INT					0x1404
#define GL_UNSIGNED_INT			0x1405
#define GL_FLOAT				0x1406
#define GL_DOUBLE				0x140A
#define GL_SAMPLER_1D			0x8B5D
#define GL_UNSIGNED_INT_24_8	0x84FA
// --==</data_types_ogl>==--

// --==<data_types_nw>==--
#define NWG_ZERO			0
#define NWG_ONE				1
#define NWG_BOOL			GL_BOOL
#define NWG_INT16			GL_SHORT
#define NWG_UINT16			GL_UNSIGNED_SHORT
#define NWG_INT8			GL_BYTE
#define NWG_UINT8			GL_UNSIGNED_BYTE
#define NWG_INT32			GL_INT
#define NWG_UINT32			GL_UNSIGNED_INT
#define NWG_FLOAT32			GL_FLOAT
#define NWG_FLOAT64			GL_DOUBLE
#define NWG_FLOAT32_VEC2	(NWG_FLOAT32 + 0x0020)
#define NWG_FLOAT32_VEC3	(NWG_FLOAT32 + 0x0030)
#define NWG_FLOAT32_VEC4	(NWG_FLOAT32 + 0x0040)
#define NWG_FLOAT32_MAT2	(NWG_FLOAT32 + 0x0100)
#define NWG_FLOAT32_MAT3	(NWG_FLOAT32 + 0x0200)
#define NWG_FLOAT32_MAT4	(NWG_FLOAT32 + 0x0300)
#define NWG_SAMPLER_1D		GL_SAMPLER_1D
#define NWG_UINT24_8		GL_UNSIGNED_INT_24_8
// --==</data_types_nw>==--

// --==<draw_modes_ogl>==--
#define GL_POINT			0x1B00
#define GL_LINE				0x1B01
#define GL_FILL				0x1B02
// --primitives
#define GL_POINTS			0x0000
#define GL_LINES			0x0001
#define GL_LINE_STRIP		0x0003
#define GL_LINE_LOOP		0x0002
#define GL_TRIANGLES		0x0004
#define GL_TRIANGLE_STRIP	0x0005
#define GL_TRIANGLE_FAN		0x0006
// --==</draw_modes_ogl>==--

// --==<draw_modes_nw>==--
#define NWG_POINT			0x1B00
#define NWG_LINE			0x1B01
#define NWG_FILL			0x1B02
// --primitives
#define NWG_POINTS			0x0000
#define NWG_LINES			0x0001
#define NWG_LINE_STRIP		0x0003
#define NWG_LINE_LOOP		0x0002
#define NWG_TRIANGLES		0x0004
#define NWG_TRIANGLE_STRIP	0x0005
#define NWG_TRIANGLE_FAN	0x0006
// --==</draw_modes_GFX>==--

// --==<planes_ogl>==--
#define GL_FRONT			0x0404
#define GL_BACK				0x0405
#define GL_LEFT				0x0406
#define GL_RIGHT			0x0407
#define GL_FRONT_AND_BACK	0x0408
// --==</planes_ogl>==--
// --==<planes_nw>==--
#define NWG_FRONT			GL_FRONT
#define NWG_BACK			GL_BACK
#define NWG_LEFT			GL_LEFT
#define NWG_RIGHT			GL_RIGHT
#define NWG_FRONT_AND_BACK	GL_FRONT_AND_BACK
// --==</planes_nw>==--

// --==<shaders_ogl>==--
#define GL_SHADER				0x82E1
#define GL_PROGRAM				0x82E2
#define GL_FRAGMENT_SHADER		0x8B30
#define GL_GEOMETRY_SHADER		0x8DD9
#define GL_VERTEX_SHADER		0x8B31
// --==<shaders_ogl>==--

// --==<shaders_nw>==--
#define NWG_SHADER				GL_PROGRAM
#define NWG_SHADER_VERTEX		GL_VERTEX_SHADER
#define NWG_SHADER_GEOMETRY		GL_GEOMETRY_SHADER
#define NWG_SHADER_PIXEL		GL_FRAGMENT_SHADER
// --==</shaders_nw>==--

// --==<configurations_ogl>==--
#define GL_POINT_SIZE			0x0B11
#define GL_LINE_SMOOTH			0x0B20
#define GL_LINE_WIDTH			0x0B21

#define GL_CULL_FACE			0x0B44
#define GL_CULL_FACE_MODE		0x0B45
#define GL_FRONT_FACE			0x0B46
#define GL_CW					0x0900
#define GL_CCW					0x0901

#define GL_DEPTH_TEST			0x0B71
#define GL_DEPTH_FUNC			0x0B74

#define GL_STENCIL_TEST			0x0B90
#define GL_STENCIL_FUNC			0x0B92

#define GL_BLEND				0x0BE2
#define GL_BLEND_DST			0x0BE0
#define GL_BLEND_SRC			0x0BE1
#define GL_SRC_COLOR			0x0300
#define GL_ONE_MINUS_SRC_COLOR	0x0301
#define GL_SRC_ALPHA			0x0302
#define GL_ONE_MINUS_SRC_ALPHA	0x0303
#define GL_DST_ALPHA			0x0304
#define GL_ONE_MINUS_DST_ALPHA	0x0305
#define GL_DST_COLOR			0x0306
#define GL_ONE_MINUS_DST_COLOR	0x0307
#define GL_SRC_ALPHA_SATURATE	0x0308

#define GL_MULTISAMPLE			0x809D

#define GL_KEEP					0x1E00
#define GL_REPLACE				0x1E01
#define GL_INCR					0x1E02
#define GL_DECR					0x1E03
// --==</configurations_ogl>==--

// --==<configurations_nw>==--
#define NWG_POINT_SIZE				GL_POINT_SIZE
#define NWG_LINE_SMOOTH				GL_LINE_SMOOTH
#define NWG_LINE_WIDTH				GL_LINE_WIDTH

#define NWG_CULL_FACE				GL_CULL_FACE
#define NWG_CULL_FACE_MODE			GL_CULL_FACE_MODE
#define NWG_FRONT_FACE				GL_FRONT_FACE
#define NWG_CW						GL_CW
#define NWG_CCW						GL_CCW

#define NWG_DEPTH_TEST				GL_DEPTH_TEST
#define NWG_DEPTH_FUNC				GL_DEPTH_FUNC

#define NWG_STENCIL_TEST			GL_STENCIL_TEST
#define NWG_STENCIL_FUNC			GL_STENCIL_FUNC

#define NWG_BLEND					GL_BLEND
#define NWG_BLEND_DST				GL_BLEND_DST
#define NWG_BLEND_SRC				GL_BLEND_SRC
#define NWG_SRC_COLOR				GL_SRC_COLOR
#define NWG_ONE_MINUS_SRC_COLOR		GL_ONE_MINUS_SRC_COLOR
#define NWG_SRC_ALPHA				GL_SRC_ALPHA
#define NWG_ONE_MINUS_SRC_ALPHA		GL_ONE_MINUS_SRC_ALPHA
#define NWG_DST_ALPHA				GL_DST_ALPHA
#define NWG_ONE_MINUS_DST_ALPHA		GL_ONE_MINUS_DST_ALPHA
#define NWG_DST_COLOR				GL_DST_COLOR
#define NWG_ONE_MINUS_DST_COLOR		GL_ONE_MINUS_DST_COLOR
#define NWG_SRC_ALPHA_SATURATE		GL_SRC_ALPHA_SATURATE

#define NWG_MULTISAMPLE			GL_MULTISAMPLE

#define NWG_KEEP		GL_KEEP
#define NWG_REPLACE		GL_REPLACE
#define NWG_INCR		GL_INCR
#define NWG_DECR		GL_DECR
// --==</configurations_nw>==--

// --==<expressions_ogl>==--
// --constants
#define GL_NONE		0
#define GL_FALSE	0
#define GL_TRUE		1
#define GL_ZERO		0
#define GL_ONE		1
// --conditions
#define GL_NEVER		0x0200
#define GL_LESS			0x0201
#define GL_EQUAL		0x0202
#define GL_LEQUAL		0x0203
#define GL_GREATER		0x0204
#define GL_NOTEQUAL		0x0205
#define GL_GEQUAL		0x0206
#define GL_ALWAYS		0x0207
// --logic
#define GL_AND				0x1501
#define GL_AND_REVERSE		0x1502
#define GL_COPY				0x1503
#define GL_AND_INVERTED		0x1504
#define GL_NOOP				0x1505
#define GL_XOR				0x1506
#define GL_OR				0x1507
#define GL_NOR				0x1508
#define GL_EQUIV			0x1509
#define GL_INVERT			0x150A
#define GL_OR_REVERSE		0x150B
#define GL_COPY_INVERTED	0x150C
#define GL_OR_INVERTED		0x150D
#define GL_NAND				0x150E
// --==</expressions_ogl>==--

// --==<expressions_nw>==--
// --constants
#define NWG_NONE		0
#define NWG_FALSE		0
#define NWG_TRUE		1
// --conditions
#define NWG_NEVER		0x0200
#define NWG_LESS		0x0201
#define NWG_EQUAL		0x0202
#define NWG_LEQUAL		0x0203
#define NWG_GREATER		0x0204
#define NWG_NOTEQUAL	0x0205
#define NWG_GEQUAL		0x0206
#define NWG_ALWAYS		0x0207
// --logic
#define NWG_AND				0x1501
#define NWG_AND_REVERSE		0x1502
#define NWG_COPY			0x1503
#define NWG_AND_INVERTED	0x1504
#define NWG_NOOP			0x1505
#define NWG_XOR				0x1506
#define NWG_OR				0x1507
#define NWG_NOR				0x1508
#define NWG_EQUIV			0x1509
#define NWG_INVERT			0x150A
#define NWG_OR_REVERSE		0x150B
#define NWG_COPY_INVERTED	0x150C
#define NWG_OR_INVERTED		0x150D
#define NWG_NAND			0x150E
// --==</expressions_nw>==--

// --==<pixel_formats_ogl>==--
#define GL_RED				0x1903
#define GL_GREEN			0x1904
#define GL_BLUE				0x1905
#define GL_ALPHA			0x1906
#define GL_RGB				0x1907
#define GL_RGBA				0x1908
#define GL_RED_INTEGER		0x8D94
#define GL_GREEN_INTEGER	0x8D95
#define GL_BLUE_INTEGER		0x8D96
#define GL_RGB_INTEGER		0x8D98
#define GL_RGBA_INTEGER		0x8D99
#define GL_R8UI				0x8232
#define GL_R16I				0x8233
#define GL_R16UI			0x8234
#define GL_R32I				0x8235
#define GL_R32UI			0x8236
#define GL_RG8I				0x8237
#define GL_RGBA8			0x8058
#define GL_DEPTH			0x1801
#define GL_STENCIL			0x1802
#define GL_DEPTH24_STENCIL8	0x88F0
// --==</pixel_formats_ogl>==--

// --==<pixel_formats_nw>==--
#define NWG_RED				GL_RED
#define NWG_GREEN			GL_GREEN
#define NWG_BLUE			GL_BLUE
#define NWG_ALPHA			GL_ALPHA
#define NWG_RGB				GL_RGB
#define NWG_RGBA			GL_RGBA
#define NWG_RED_INT			GL_RED_INTEGER
#define NWG_GREEN_INT		GL_GREEN_INTEGER
#define NWG_BLUE_INT		GL_BLUE_INTEGER
#define NWG_RGB_INT			GL_RGB_INTEGER
#define NWG_RGBA_INT		GL_RGBA_INTEGER
#define NWG_DEPTH			GL_DEPTH
#define NWG_STENCIL			GL_STENCIL
#define NWG_RED_INT32		GL_R32I
#define NWG_RED_UINT32		GL_R32UI
#define NWG_RGBA8			GL_RGBA8
#define NWG_DEPTH24			GL_DEPTH
#define NWG_STENCIL8			GL_STENCIL
#define NWG_DEPTH24_STENCIL8	GL_DEPTH24_STENCIL8
// --==</pixel_formats_nw>==--

// --==<textures_ogl>==--
#define GL_TEXTURE_1D					0x0DE0
#define GL_TEXTURE_2D					0x0DE1
#define GL_TEXTURE_3D					0x0DE2
#define GL_TEXTURE_2D_MULTISAMPLE		0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE	0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY	0x9102
#define GL_DEPTH_STENCIL				0x84F9
#define GL_DEPTH_STENCIL_ATTACHMENT		0x821A
#define GL_TEXTURE_MAG_FILTER			0x2800
#define GL_TEXTURE_MIN_FILTER			0x2801
#define GL_NEAREST						0x2600
#define GL_LINEAR						0x2601
#define GL_TEXTURE_WRAP_S				0x2802
#define GL_TEXTURE_WRAP_T				0x2803
#define GL_TEXTURE_WRAP_R				0x8072
#define GL_CLAMP						0x2900
#define GL_REPEAT						0x2901
// --==</textures_ogl>==--

// --==<textures_nw>==--
// --types
#define NWG_TEXTURE_1D					GL_TEXTURE_1D
#define NWG_TEXTURE_2D					GL_TEXTURE_2D
#define NWG_TEXTURE_3D					GL_TEXTURE_3D
#define NWG_TEXTURE_2D_MULTISAMPLE		GL_TEXTURE_2D_MULTISAMPLE
#define NWG_TEXTURE_3D_MULTISAMPLE		GL_TEXTURE_2D_MULTISAMPLE_ARRAY
#define NWG_DEPTH_STENCIL				GL_DEPTH_STENCIL
#define NWG_DEPTH_STENCIL_ATTACHMENT		GL_DEPTH_STENCIL_ATTACHMENT
// --filters
#define NWG_TEXTURE_MAG_FILTER			GL_TEXTURE_MAG_FILTER
#define NWG_TEXTURE_MIN_FILTER			GL_TEXTURE_MIN_FILTER
#define NWG_TEXTURE_FILTER_NEAREST		GL_NEAREST
#define NWG_TEXTURE_FILTER_LINEAR		GL_LINEAR
// --wrappers
#define NWG_TEXTURE_WRAP_S				GL_TEXTURE_WRAP_S
#define NWG_TEXTURE_WRAP_T				GL_TEXTURE_WRAP_T
#define NWG_TEXTURE_WRAP_R				GL_TEXTURE_WRAP_R
#define NWG_TEXTURE_WRAP_CLAMP			GL_CLAMP
#define NWG_TEXTURE_WRAP_REPEAT			GL_REPEAT
// --==</textures_nw>==--

// --==<gbuffers_ogl>==--
#define GL_ARRAY_BUFFER				0x8892
#define GL_ELEMENT_ARRAY_BUFFER		0x8893
#define GL_UNIFORM_BUFFER			0x8A11
// --==</gbuffers_ogl>==--


// --==<gbuffers_nw>==--
#define NWG_BUFFER_VERTEX		GL_ARRAY_BUFFER
#define NWG_BUFFER_INDEX			GL_ELEMENT_ARRAY_BUFFER
#define NWG_BUFFER_SHADER		GL_UNIFORM_BUFFER
// --==</gbuffers_nw>==--

// --==<framebuffers_ogl>==--
#define GL_DRAW_BUFFER			0x0C01
#define GL_READ_BUFFER			0x0C02
#define GL_FRAMEBUFFER			0x8D40
#define GL_COLOR_BUFFER_BIT		0x00004000
#define GL_DEPTH_BUFFER_BIT		0x00000100
#define GL_ACCUM_BUFFER_BIT		0x00000200
#define GL_STENCIL_BUFFER_BIT	0x00000400
#define GL_DEPTH_ATTACHMENT		0x8D00
#define GL_STENCIL_ATTACHMENT	0x8D20
// --==</buffers_ogl>==--

// --==<framebuffers_nw>==--
#define NWG_FRAMEBUF_IN			GL_DRAW_BUFFER
#define NWG_FRAMEBUF_OUT			GL_READ_BUFFER
#define NWG_FRAMEBUF_IN_OUT		GL_FRAMEBUFFER
#define NWG_BUFFER_COLOR_BIT		GL_COLOR_BUFFER_BIT
#define NWG_BUFFER_DEPTH_BIT		GL_DEPTH_BUFFER_BIT
#define NWG_BUFFER_STENCIL_BIT	GL_STENCIL_BUFFER_BIT
// --==</framebuffers_nw>==--

// --==<data_load_types_ogl>==--
#define GL_STATIC_DRAW			0x88E4
#define GL_STREAM_DRAW			0x88E0
#define GL_DYNAMIC_DRAW			0x88E8
// --==</data_load_types_ogl>==--

// --==<data_load_types_nw>==--
#define NWG_STATIC_DRAW		GL_STATIC_DRAW 
#define NWG_STREAM_DRAW		GL_STREAM_DRAW 
#define NWG_DYNAMIC_DRAW		GL_DYNAMIC_DRAW
// --==</data_load_types_nw>==--

// --==<error_codes_ogl>==--
#define GL_NO_ERROR				0
#define GL_INVALID_ENUM			0x0500
#define GL_INVALID_VALUE		0x0501
#define GL_INVALID_OPERATION	0x0502
#define GL_STACK_OVERFLOW		0x0503
#define GL_STACK_UNDERFLOW		0x0504
#define GL_OUT_OF_MEMORY		0x0505
// --==</error_codes_ogl>==--

// --==<error_codes_nw>==--
#define NWG_OK					GL_NO_ERROR         
#define NWG_INVALID_ENUM			GL_INVALID_ENUM     
#define NWG_INVALID_VALUE		GL_INVALID_VALUE    
#define NWG_INVALID_OPERATION	GL_INVALID_OPERATION
#define NWG_STACK_OVERFLOW		GL_STACK_OVERFLOW   
#define NWG_STACK_UNDERFLOW		GL_STACK_UNDERFLOW  
#define NWG_OUT_OF_MEMORY		GL_OUT_OF_MEMORY  
// --==</error_codes_nw>==--

// --==<info_ogl>==--
#define GL_VENDOR				0x1F00
#define GL_RENDERER				0x1F01
#define GL_VERSION				0x1F02
#define GL_EXTENSIONS			0x1F03

#define GL_COMPILE_STATUS		0x8B81
#define GL_LINK_STATUS			0x8B82
#define GL_INFO_LOG_LENGTH		0x8B84
#define GL_ATTACHED_SHADERS		0x8B85
// --==</info_ogl>==--

// --==<info_nw>==--
#define NWG_COMPILE_STATUS		GL_COMPILE_STATUS
#define NWG_LINK_STATUS			GL_LINK_STATUS
// --==</info_nw>==--
#endif // NWG_GAPI
#if (NWG_GAPI & NWG_GAPI_DX)
// --==<data_types_dx11>==--
// --==</data_types_dx11>==--

// --==<data_types_nw>==--
#define NWG_ZERO			0
#define NWG_ONE			1
#define NWG_BOOL			2
#define NWG_INT16		3
#define NWG_UINT16		4
#define NWG_INT8			5
#define NWG_UINT8		6
#define NWG_INT32		7
#define NWG_UINT32		8
#define NWG_FLOAT32		9
#define NWG_FLOAT64		10
#define NWG_FLOAT32_VEC2	11
#define NWG_FLOAT32_VEC3	12
#define NWG_FLOAT32_VEC4	13
#define NWG_FLOAT32_MAT2	14
#define NWG_FLOAT32_MAT3	15
#define NWG_FLOAT32_MAT4	16
#define NWG_SAMPLER_1D	17
#define NWG_UINT24_8		18
// --==</data_types_nw>==--

// --==<draw_modes_dx11>==--
// --primitives
#define	D3D_PT_UNDEFINED			0
#define	D3D_PT_POINTLIST			1
#define	D3D_PT_LINELIST				2
#define	D3D_PT_LINESTRIP			3
#define	D3D_PT_TRIANGLELIST			4
#define	D3D_PT_TRIANGLESTRIP		5
#define	D3D_PT_LINELIST_ADJ			10
#define	D3D_PT_LINESTRIP_ADJ		11
#define	D3D_PT_TRIANGLELIST_ADJ		12
#define	D3D_PT_TRIANGLESTRIP_ADJ	13
// --==</draw_modes_dx11>==--

// --==<draw_modes_nw>==--
#define NWG_POINT		3
#define NWG_LINE			2
#define NWG_FILL			1
// --primitives
#define NWG_POINTS			D3D_PT_POINTLIST
#define NWG_LINES			D3D_PT_LINELIST
#define NWG_LINE_STRIP		D3D_PT_LINESTRIP
#define NWG_LINE_LOOP		D3D_PT_LINESTRIP_ADJ
#define NWG_TRIANGLES		D3D_PT_TRIANGLELIST
#define NWG_TRIANGLE_STRIP	D3D_PT_TRIANGLESTRIP
#define NWG_TRIANGLE_FAN		D3D_PT_TRIANGLESTRIP_ADJ
// --==</draw_modes_nw>==--

// --==<planes_dx11>==--
// --==</planes_dx11>==--

// --==<planes_nw>==--
#define NWG_FRONT			5
#define NWG_BACK				4
#define NWG_LEFT				3
#define NWG_RIGHT			2
#define NWG_FRONT_AND_BACK	1
// --==</planes_nw>==--

// --==<shaders_dx11>==--
// --==<shaders_dx11>==--

// --==<shaders_nw>==--
#define NWG_SHADER				4
#define NWG_SHADER_VERTEX		3
#define NWG_SHADER_GEOMETRY		2
#define NWG_SHADER_PIXEL			1
// --==</shaders_nw>==--

// --==<configurations_dx11>==--
// --==</configurations_dx11>==--

// --==<configurations_nw>==--
#define NWG_POINT_SIZE			8
#define NWG_LINE_SMOOTH			7
#define NWG_LINE_WIDTH			6

#define NWG_CULL_FACE			5
#define NWG_CULL_FACE_MODE		4
#define NWG_FRONT_FACE			3
#define NWG_CW					2
#define NWG_CCW					1

#define NWG_DEPTH_TEST			51
#define NWG_DEPTH_FUNC			52
#define NWG_STENCIL_TEST			53
#define NWG_STENCIL_FUNC			54

#define NWG_BLEND				1
#define NWG_BLEND_DST			2
#define NWG_BLEND_SRC			3
#define NWG_SRC_COLOR			4
#define NWG_ONE_MINUS_SRC_COLOR	5
#define NWG_SRC_ALPHA			6
#define NWG_ONE_MINUS_SRC_ALPHA	7
#define NWG_DST_ALPHA			8
#define NWG_ONE_MINUS_DST_ALPHA	9
#define NWG_DST_COLOR			10
#define NWG_ONE_MINUS_DST_COLOR	11
#define NWG_SRC_ALPHA_SATURATE	12

#define NWG_MULTISAMPLE			0

#define NWG_KEEP					0
#define NWG_REPLACE				0
#define NWG_INCR					0
#define NWG_DECR					0
// --==</configurations_nw>==--

// --==<expressions_dx11>==--
// --constants
// --conditions
// --logic
// --==</expressions_dx11>==--

// --==<expressions_nw>==--
// --constants
#define NWG_NONE		0
#define NWG_FALSE	0
#define NWG_TRUE		1
// --conditions
#define NWG_NEVER		0x0200
#define NWG_LESS			0x0201
#define NWG_EQUAL		0x0202
#define NWG_LEQUAL		0x0203
#define NWG_GREATER		0x0204
#define NWG_NOTEQUAL		0x0205
#define NWG_GEQUAL		0x0206
#define NWG_ALWAYS		0x0207
// --logic
#define NWG_AND				0x1501
#define NWG_AND_REVERSE		0x1502
#define NWG_COPY				0x1503
#define NWG_AND_INVERTED		0x1504
#define NWG_NOOP				0x1505
#define NWG_XOR				0x1506
#define NWG_OR				0x1507
#define NWG_NOR				0x1508
#define NWG_EQUIV			0x1509
#define NWG_INVERT			0x150A
#define NWG_OR_REVERSE		0x150B
#define NWG_COPY_INVERTED	0x150C
#define NWG_OR_INVERTED		0x150D
#define NWG_NAND				0x150E
// --==</expressions_nw>==--

// --==<pixel_formats_dx11>==--
// --==</pixel_formats_dx11>==--

// --==<pixel_formats_nw>==--
#define NWG_RED				1
#define NWG_GREEN			2
#define NWG_BLUE				3
#define NWG_ALPHA			4
#define NWG_RGB				5
#define NWG_RGBA				6
#define NWG_RED_INT			7
#define NWG_GREEN_INT		8
#define NWG_BLUE_INT			9
#define NWG_RGB_INT			10
#define NWG_RGBA_INT			11
#define NWG_DEPTH			12
#define NWG_STENCIL			13
#define NWG_RED_INT32		14
#define NWG_RED_UINT32		15
#define NWG_RGBA8			16
#define NWG_DEPTH24			17
#define NWG_STENCIL8			18
#define NWG_DEPTH24_STENCIL8	19
// --==</pixel_formats_nw>==--

// --==<textures_dx11>==--
// --==</textures_dx11>==--

// --==<textures_nw>==--
// --types
#define NWG_TEXTURE_1D					1
#define NWG_TEXTURE_2D					2
#define NWG_TEXTURE_3D					3
#define NWG_TEXTURE_2D_MULTISAMPLE		4
#define NWG_TEXTURE_3D_MULTISAMPLE		5
#define NWG_DEPTH_STENCIL				6
#define NWG_DEPTH_STENCIL_ATTACHMENT		7
// --filters
#define NWG_TEXTURE_MAG_FILTER			1
#define NWG_TEXTURE_MIN_FILTER			2
#define NWG_TEXTURE_FILTER_NEAREST		3
#define NWG_TEXTURE_FILTER_LINEAR		4
// --wrappers
#define NWG_TEXTURE_WRAP_S				5
#define NWG_TEXTURE_WRAP_T				6
#define NWG_TEXTURE_WRAP_R				7
#define NWG_TEXTURE_WRAP_CLAMP			8
#define NWG_TEXTURE_WRAP_REPEAT			9
// --==</textures_nw>==--

// --==<gbuffers_dx11>==--
// --==</gbuffers_dx11>==--


// --==<gbuffers_nw>==--
#define NWG_BUFFER_VERTEX	1
#define NWG_BUFFER_INDEX	2
#define NWG_BUFFER_SHADER	3
// --==</gbuffers_nw>==--

// --==<framebuffers_dx11>==--
// --==</framebuffers_dx11>==--

// --==<framebuffers_nw>==--
#define NWG_FRAMEBUF_IN			1
#define NWG_FRAMEBUF_OUT			2
#define NWG_FRAMEBUF_IN_OUT		3
#define NWG_BUFFER_COLOR_BIT		4
#define NWG_BUFFER_DEPTH_BIT		5
#define NWG_BUFFER_STENCIL_BIT	6
// --==</framebuffers_nw>==--

// --==<data_load_types_dx11>==--
// --==</data_load_types_dx11>==--

// --==<data_load_types_nw>==--
#define NWG_STATIC_DRAW		1
#define NWG_STREAM_DRAW		2
#define NWG_DYNAMIC_DRAW		3
// --==</data_load_types_nw>==--

// --==<error_codes_dx11>==--
// --==</error_codes_dx11>==--

// --==<error_codes_nw>==--
#define NWG_OK					0
#define NWG_INVALID_ENUM			1
#define NWG_INVALID_VALUE		2
#define NWG_INVALID_OPERATION	3
#define NWG_STACK_OVERFLOW		4
#define NWG_STACK_UNDERFLOW		5
#define NWG_OUT_OF_MEMORY		6
// --==</error_codes_nw>==--

// --==<info_dx11>==--
// --==</info_dx11>==--

// --==<info_nw>==--
#define NWG_COMPILE_STATUS		7
#define NWG_LINK_STATUS			8
// --==</info_nw>==--

// --==<types_dx>==--
struct IDXGISwapChain;
struct ID3D11Device;
struct ID3D11DeviceContext;
struct ID3D11RenderTargetView;
struct ID3D11Buffer;
struct ID3D11InputLayout;
struct ID3D11VertexShader;
struct ID3D11PixelShader;
// --==</types_dx>==--
#endif	// NWG_GAPI

#include <nwg_pch.hpp>

namespace NWG
{
	class NWG_API GfxEngine;

	class NWG_API Shader;
	class NWG_API Texture;
	class NWG_API GfxMaterial;

	class NWG_API FrameBuf;

	class NWG_API VertexBufLayout;
	class NWG_API ShaderBufLayout;

	class NWG_API VertexBuf;
	class NWG_API IndexBuf;
	class NWG_API ShaderBuf;
	class NWG_API VertexArr;
}
namespace NWG
{
	struct NWG_API Drawable;

	struct NWG_API GfxCamera;

	struct NWG_API FrameBufInfo;
	struct NWG_API TextureInfo;

	struct NWG_API BufferElement;

	struct NWG_API SubTexture1d;
	struct NWG_API SubTexture2d;
	struct NWG_API SubTexture3d;
}
namespace NWG
{
	enum GfxApiTypes : UInt32 {
		GAPI_DEFAULT = NWG_GAPI,
		GAPI_OPENGL = NWG_GAPI_OGL,
		GAPI_DIRECTX = NWG_GAPI_DX,
	};
	enum GfxBufferTypes : UInt32 {
		GBT_DEFAULT = NWG_BUFFER_VERTEX,
		GBT_VERTEX = NWG_BUFFER_VERTEX,
		GBT_INDEX = NWG_BUFFER_INDEX,
		GBT_SHADER = NWG_BUFFER_SHADER,
	};
	enum FrameBufTypes : UInt32 {
		FBT_DEFAULT = NWG_FRAMEBUF_IN_OUT,
		FBT_IN = NWG_FRAMEBUF_IN, FBT_OUT = NWG_FRAMEBUF_OUT, FBT_IN_OUT = NWG_FRAMEBUF_IN_OUT,
	};
	enum ShaderTypes : UInt32 {
		ST_DEFAULT = NWG_SHADER,
		ST_SHADER = NWG_SHADER,
		ST_VERTEX = NWG_SHADER_VERTEX,
		ST_GEOMETRY = NWG_SHADER_GEOMETRY,
		ST_PIXEL = NWG_SHADER_PIXEL
	};
	enum FrameBufs : UInt32 {
		FB_DEFAULT = NWG_BUFFER_COLOR_BIT | NWG_BUFFER_DEPTH_BIT | NWG_BUFFER_STENCIL_BIT,
		FB_COLOR = NWG_BUFFER_COLOR_BIT,
		FB_DEPTH = NWG_BUFFER_DEPTH_BIT,
		FB_STENCIL = NWG_BUFFER_STENCIL_BIT
	};
	enum TextureTypes : UInt32 {
		TXT_NONE = 0,
		TXT_1D = NWG_TEXTURE_1D, TXT_2D = NWG_TEXTURE_2D, TXT_3D = NWG_TEXTURE_3D,
		TXT_2D_MULTISAMPLE = NWG_TEXTURE_2D_MULTISAMPLE, TXT_3D_MULTISAMPLE = NWG_TEXTURE_3D_MULTISAMPLE
	};
	enum ShaderDataTypes : UInt32 {
		SDT_DEFAULT = NWG_FLOAT32,
		SDT_BOOL = NWG_BOOL, SDT_INT8 = NWG_INT8, SDT_UINT8 = NWG_UINT8,
		SDT_INT16 = NWG_INT16, SDT_UINT16 = NWG_UINT16,
		SDT_INT32 = NWG_INT32, SDT_UINT32 = NWG_UINT32,
		SDT_FLOAT32 = NWG_FLOAT32, SDT_FLOAT64 = NWG_FLOAT64,

		SDT_SAMPLER = NWG_SAMPLER_1D
	};
}
namespace NWG
{
	enum GfxPrimitives : UInt32 {
		GPT_DEFAULT = NWG_TRIANGLES,
		GPT_POINTS = NWG_POINTS,
		GPT_LINES = NWG_LINES,
		GPT_LINE_LOOP = NWG_LINE_LOOP,
		GPT_LINE_STRIP = NWG_LINE_STRIP,
		GPT_TRIANGLES = NWG_TRIANGLES,
		GPT_TRIANGLE_STRIP = NWG_TRIANGLE_STRIP,
		GPT_TRIANGLE_FAN = NWG_TRIANGLE_FAN,
	};
	enum DrawModes : UInt32 {
		DM_DEFAULT = NWG_FILL,
		DM_LINE = NWG_LINE, DM_FILL = NWG_FILL
	};
	enum FacePlanes : UInt32 {
		FACE_DEFAULT = NWG_FRONT_AND_BACK,
		FACE_FRONT_AND_BACK = NWG_FRONT_AND_BACK,
		FACE_BACK = NWG_BACK, FACE_FRONT = NWG_FRONT,
		FACE_LEFT = NWG_LEFT, FACE_RIGTH = NWG_RIGHT,
	};
	enum GfxVariables : UInt32 {
		GV_DEFAULT = NWG_LINE_WIDTH,
		GV_LINE_WIDTH = NWG_LINE_WIDTH, GV_POINT_SIZE = NWG_POINT_SIZE,
	};
	enum ProcessingModes : UInt32 {
		PM_BLEND = NWG_BLEND,
		PM_MULTISAMPLE = NWG_MULTISAMPLE,
		PM_CULL_FACE = NWG_CULL_FACE,
		PM_DEPTH_TEST = NWG_DEPTH_TEST,
		PM_STENCIL_TEST = NWG_STENCIL_TEST
	};
	enum BlendConfigs : UInt32 {
		BC_SRC_DEFAULT = 0, BC_DEST_DEFAULT = 0,
		BC_SRC_ALPHA = NWG_SRC_ALPHA, BC_SRC_COLOR = NWG_SRC_COLOR,
		BC_ONE_MINUS_SRC_ALPHA = NWG_ONE_MINUS_SRC_ALPHA,
		BC_ONE_MINUS_SRC_COLOR = NWG_ONE_MINUS_SRC_COLOR,
		BC_DST_ALPHA = NWG_DST_ALPHA, BC_DST_COLOR = NWG_DST_COLOR,
		BC_ONE_MUNUS_DST_ALPHA = NWG_ONE_MINUS_DST_ALPHA,
		BC_ONE_MINUS_DST_COLOR = NWG_ONE_MINUS_DST_COLOR,
	};
	enum CullFaceConfigs : UInt32 {
		CFC_DEFAULT = 0
	};
	enum DepthConfigs : UInt32 {
		DTC_DEFAULT = NWG_GREATER,
		DTC_EQUAL = NWG_EQUAL,
		DTC_LESS = NWG_LESS, DTC_LEQUAL = NWG_LEQUAL,
		DTC_GREATER = NWG_GREATER, DTC_GEQUAL = NWG_GEQUAL,
		DTC_NEVER = NWG_NEVER, DTC_ALWAYS = NWG_ALWAYS
	};
	enum StencilConfigs : UInt32 {
		STC_DEFAULT = 0,
		STC_KEEP = NWG_KEEP, STC_ZERO = NWG_ZERO, STC_REPLACE = NWG_REPLACE, STC_INVERT = NWG_INVERT,
		STC_INCR = NWG_INCR, STC_DECR = NWG_DECR
	};
}
namespace NWG
{
	enum TextureWraps : UInt32 {
		TXW_NONE = 0, TXW_REPEAT = NWG_TEXTURE_WRAP_REPEAT, TXW_CLAMP = NWG_TEXTURE_WRAP_CLAMP,
	};
	enum TextureFilters : UInt32 {
		TXF_LINEAR = NWG_TEXTURE_FILTER_LINEAR, TXF_NEAREST = NWG_TEXTURE_FILTER_NEAREST,
	};
	enum TextureFormats : UInt32 {
		TXF_NONE = 0,
		TXF_RED = NWG_RED, TXF_GREEN = NWG_GREEN, TXF_BLUE = NWG_BLUE,
		TXF_RGB = NWG_RGB, TXF_RGBA = NWG_RGBA,
		TXF_RED_INT = NWG_RED_INT, TXF_GREEN_INT = NWG_GREEN_INT, TXF_BLUE_INT = NWG_BLUE_INT,
		TXF_RGB_INT = NWG_RGB_INT, TXF_RGBA_INT = NWG_RGBA_INT,
		TXF_DEPTH = NWG_DEPTH, TXF_STENCIL = NWG_STENCIL,
		TXF_DEPTH_STENCIL = NWG_DEPTH_STENCIL,
	};
	enum TextureInterFormats : UInt32 {
		TXFI_RED_UINT32 = NWG_RED_UINT32, TXFI_RED_INT32 = NWG_RED_INT32,
		TXFI_RGB = NWG_RGB, TXFI_RGBA8 = NWG_RGBA8,
		TXFI_DEPTH24 = NWG_DEPTH24, TXFI_STENCIL8 = NWG_STENCIL8,
		TXFI_DEPTH24_STENCIL8 = NWG_DEPTH24_STENCIL8,
	};
	enum PixelFormats : UInt32 {
		FBAT_DEFAULT = 0,
		PXF_INT8 = NWG_INT8, PXF_UINT8 = NWG_UINT8,
		PXF_INT32 = NWG_INT32, PXF_UINT32 = NWG_UINT32,
		PXF_UINT24_8 = NWG_UINT24_8
	};
	//	--==</enums>==--
}

#endif	// NWG_CORE_HPP

/*
* The project created in 16.01.2021
* Graphics library as a tool for game engines and applications
*/