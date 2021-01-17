#ifndef GLIB_DEF_HPP
#define GLIB_DEF_HPP

// --==<alias>==--
namespace GLIB
{
	// --number
	typedef __int8				Int8;
	typedef __int16				Int16;
	typedef __int32				Int32;
	typedef __int64				Int64;
	typedef unsigned __int8		UInt8;
	typedef unsigned __int16	UInt16;
	typedef unsigned __int32	UInt32;
	typedef unsigned __int64	UInt64;
	typedef float				Float32;
	typedef double				Float64;
	typedef long double			Float128;
	// --memory
	typedef size_t				Size;
	typedef char				Byte;
	typedef unsigned char		UByte;
	template <typename RefType>
	using RefOwner = std::unique_ptr<RefType>;
	template <typename RefType>
	using RefKeeper = std::shared_ptr<RefType>;
	// --string
	typedef char Char;
	typedef char Char8;
	typedef unsigned char UChar;
	typedef unsigned char UChar8;
	typedef wchar_t Char16;
	using CString = const char*;
	using String = std::string;
	using WString = std::wstring;
	// --stream
	using InStream = std::istream;
	using OutStream = std::ostream;
	using IOStream = std::iostream;
	using StrStream = std::stringstream;
	// --container
	template <typename ValType, Size szCapacity>
	using SArray = std::array<ValType, szCapacity>;
	template <typename ValType>
	using DArray = std::vector<ValType>;
	template <typename ValType>
	using DStack = std::stack<ValType>;
	template <typename ValType>
	using List2 = std::list<ValType>;
	template <typename KeyType, typename ValType>
	using HashMap = std::unordered_map<KeyType, ValType>;
	// --info
	using TypeInfo = std::type_index;
	// --math
#if (GLIB_MATH & GLIB_MATH_GLM)
	// --vector
	typedef glm::bvec2 V2b;
	typedef glm::bvec3 V3b;
	typedef glm::bvec4 V4b;
	typedef glm::i16vec2 V2si;
	typedef glm::i16vec3 V3si;
	typedef glm::i16vec4 V4si;
	typedef glm::i32vec2 V2i;
	typedef glm::i32vec3 V3i;
	typedef glm::i32vec4 V4i;
	typedef glm::i64vec2 V2li;
	typedef glm::i64vec3 V3li;
	typedef glm::i64vec4 V4li;
	typedef glm::u16vec2 V2usi;
	typedef glm::u16vec3 V3usi;
	typedef glm::u16vec4 V4usi;
	typedef glm::u32vec2 V2ui;
	typedef glm::u32vec3 V3ui;
	typedef glm::u32vec4 V4ui;
	typedef glm::u64vec2 V2uli;
	typedef glm::u64vec3 V3uli;
	typedef glm::u64vec4 V4uli;
	typedef glm::vec2 V2f;
	typedef glm::vec3 V3f;
	typedef glm::vec4 V4f;
	typedef glm::dvec2 V2d;
	typedef glm::dvec3 V3d;
	typedef glm::dvec4 V4d;
	// --matrix
	typedef glm::mat2 Mat2f;
	typedef glm::mat3 Mat3f;
	typedef glm::mat4 Mat4f;
	typedef glm::dmat2x2 mat2d;
	typedef glm::dmat3x3 mat3d;
	typedef glm::dmat4x4 mat4d;
#endif
}
#if (GLIB_GAPI & GLIB_GAPI_OGL)
typedef void GLvoid;
typedef char GLchar;
typedef signed char GLbyte;
typedef unsigned char GLubyte;
typedef unsigned char GLboolean;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned int GLuint;
typedef unsigned int GLbitfield;
typedef unsigned short GLushort;
typedef unsigned long GLulong;
typedef unsigned int GLenum;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
#endif // GLIB_GAPI
// --==</alias>==--
#if (GLIB_WINDOW & GLIB_WINDOW_GLFW)
// --==<keyboard_glfw>==--
#define GLFW_KEY_UNKNOWN            -1
// --keys_to_print
#define GLFW_KEY_SPACE              32
#define GLFW_KEY_APOSTROPHE         39
#define GLFW_KEY_COMMA              44
#define GLFW_KEY_MINUS              45
#define GLFW_KEY_PERIOD             46
#define GLFW_KEY_SLASH              47
#define GLFW_KEY_0                  48
#define GLFW_KEY_1                  49
#define GLFW_KEY_2                  50
#define GLFW_KEY_3                  51
#define GLFW_KEY_4                  52
#define GLFW_KEY_5                  53
#define GLFW_KEY_6                  54
#define GLFW_KEY_7                  55
#define GLFW_KEY_8                  56
#define GLFW_KEY_9                  57
#define GLFW_KEY_SEMICOLON          59
#define GLFW_KEY_EQUAL              61
#define GLFW_KEY_A                  65
#define GLFW_KEY_B                  66
#define GLFW_KEY_C                  67
#define GLFW_KEY_D                  68
#define GLFW_KEY_E                  69
#define GLFW_KEY_F                  70
#define GLFW_KEY_G                  71
#define GLFW_KEY_H                  72
#define GLFW_KEY_I                  73
#define GLFW_KEY_J                  74
#define GLFW_KEY_K                  75
#define GLFW_KEY_L                  76
#define GLFW_KEY_M                  77
#define GLFW_KEY_N                  78
#define GLFW_KEY_O                  79
#define GLFW_KEY_P                  80
#define GLFW_KEY_Q                  81
#define GLFW_KEY_R                  82
#define GLFW_KEY_S                  83
#define GLFW_KEY_T                  84
#define GLFW_KEY_U                  85
#define GLFW_KEY_V                  86
#define GLFW_KEY_W                  87
#define GLFW_KEY_X                  88
#define GLFW_KEY_Y                  89
#define GLFW_KEY_Z                  90
#define GLFW_KEY_LEFT_BRACKET       91 
#define GLFW_KEY_BACKSLASH          92 
#define GLFW_KEY_RIGHT_BRACKET      93 
#define GLFW_KEY_GRAVE_ACCENT       96 
#define GLFW_KEY_WORLD_1            161
#define GLFW_KEY_WORLD_2            162
// --keys_to_control
#define GLFW_KEY_ESCAPE             256
#define GLFW_KEY_ENTER              257
#define GLFW_KEY_TAB                258
#define GLFW_KEY_BACKSPACE          259
#define GLFW_KEY_INSERT             260
#define GLFW_KEY_DELETE             261
#define GLFW_KEY_RIGHT              262
#define GLFW_KEY_LEFT               263
#define GLFW_KEY_DOWN               264
#define GLFW_KEY_UP                 265
#define GLFW_KEY_PAGE_UP            266
#define GLFW_KEY_PAGE_DOWN          267
#define GLFW_KEY_HOME               268
#define GLFW_KEY_END                269
#define GLFW_KEY_CAPS_LOCK          280
#define GLFW_KEY_SCROLL_LOCK        281
#define GLFW_KEY_NUM_LOCK           282
#define GLFW_KEY_PRINT_SCREEN       283
#define GLFW_KEY_PAUSE              284
#define GLFW_KEY_F1                 290
#define GLFW_KEY_F2                 291
#define GLFW_KEY_F3                 292
#define GLFW_KEY_F4                 293
#define GLFW_KEY_F5                 294
#define GLFW_KEY_F6                 295
#define GLFW_KEY_F7                 296
#define GLFW_KEY_F8                 297
#define GLFW_KEY_F9                 298
#define GLFW_KEY_F10                299
#define GLFW_KEY_F11                300
#define GLFW_KEY_F12                301
#define GLFW_KEY_F13                302
#define GLFW_KEY_F14                303
#define GLFW_KEY_F15                304
#define GLFW_KEY_F16                305
#define GLFW_KEY_F17                306
#define GLFW_KEY_F18                307
#define GLFW_KEY_F19                308
#define GLFW_KEY_F20                309
#define GLFW_KEY_F21                310
#define GLFW_KEY_F22                311
#define GLFW_KEY_F23                312
#define GLFW_KEY_F24                313
#define GLFW_KEY_F25                314
#define GLFW_KEY_KP_0               320
#define GLFW_KEY_KP_1               321
#define GLFW_KEY_KP_2               322
#define GLFW_KEY_KP_3               323
#define GLFW_KEY_KP_4               324
#define GLFW_KEY_KP_5               325
#define GLFW_KEY_KP_6               326
#define GLFW_KEY_KP_7               327
#define GLFW_KEY_KP_8               328
#define GLFW_KEY_KP_9               329
#define GLFW_KEY_KP_DECIMAL         330
#define GLFW_KEY_KP_DIVIDE          331
#define GLFW_KEY_KP_MULTIPLY        332
#define GLFW_KEY_KP_SUBTRACT        333
#define GLFW_KEY_KP_ADD             334
#define GLFW_KEY_KP_ENTER           335
#define GLFW_KEY_KP_EQUAL           336
#define GLFW_KEY_LEFT_SHIFT         340
#define GLFW_KEY_LEFT_CONTROL       341
#define GLFW_KEY_LEFT_ALT           342
#define GLFW_KEY_LEFT_SUPER         343
#define GLFW_KEY_RIGHT_SHIFT        344
#define GLFW_KEY_RIGHT_CONTROL      345
#define GLFW_KEY_RIGHT_ALT          346
#define GLFW_KEY_RIGHT_SUPER        347
#define GLFW_KEY_MENU               348

#define GLFW_KEY_LAST               GLFW_KEY_MENU
// --==</keyborad_glfw>==--

// --==<keyboard_nw>==--
// --keys_to_print
#define GLIB_KEY_SPACE_32              GLFW_KEY_SPACE             
#define GLIB_KEY_APOSTROPHE_39         GLFW_KEY_APOSTROPHE        
#define GLIB_KEY_COMMA_44              GLFW_KEY_COMMA             
#define GLIB_KEY_MINUS_45              GLFW_KEY_MINUS             
#define GLIB_KEY_PERIOD_46             GLFW_KEY_PERIOD            
#define GLIB_KEY_SLASH_47              GLFW_KEY_SLASH             
#define GLIB_KEY_0_48                  GLFW_KEY_0                 
#define GLIB_KEY_1_49                  GLFW_KEY_1                 
#define GLIB_KEY_2_50                  GLFW_KEY_2                 
#define GLIB_KEY_3_51                  GLFW_KEY_3                 
#define GLIB_KEY_4_52                  GLFW_KEY_4                 
#define GLIB_KEY_5_53                  GLFW_KEY_5                 
#define GLIB_KEY_6_54                  GLFW_KEY_6                 
#define GLIB_KEY_7_55                  GLFW_KEY_7                 
#define GLIB_KEY_8_56                  GLFW_KEY_8                 
#define GLIB_KEY_9_57                  GLFW_KEY_9                 
#define GLIB_KEY_SEMICOLON_59          GLFW_KEY_SEMICOLON         
#define GLIB_KEY_EQUAL_61              GLFW_KEY_EQUAL             
#define GLIB_KEY_A_65                  GLFW_KEY_A                 
#define GLIB_KEY_B_66                  GLFW_KEY_B                 
#define GLIB_KEY_C_67                  GLFW_KEY_C                 
#define GLIB_KEY_D_68                  GLFW_KEY_D                 
#define GLIB_KEY_E_69                  GLFW_KEY_E                 
#define GLIB_KEY_F_70                  GLFW_KEY_F                 
#define GLIB_KEY_G_71                  GLFW_KEY_G                 
#define GLIB_KEY_H_72                  GLFW_KEY_H                 
#define GLIB_KEY_I_73                  GLFW_KEY_I                 
#define GLIB_KEY_J_74                  GLFW_KEY_J                 
#define GLIB_KEY_K_75                  GLFW_KEY_K                 
#define GLIB_KEY_L_76                  GLFW_KEY_L                 
#define GLIB_KEY_M_77                  GLFW_KEY_M                 
#define GLIB_KEY_N_78                  GLFW_KEY_N                 
#define GLIB_KEY_O_79                  GLFW_KEY_O                 
#define GLIB_KEY_P_80                  GLFW_KEY_P                 
#define GLIB_KEY_Q_81                  GLFW_KEY_Q                 
#define GLIB_KEY_R_82                  GLFW_KEY_R                 
#define GLIB_KEY_S_83                  GLFW_KEY_S                 
#define GLIB_KEY_T_84                  GLFW_KEY_T                 
#define GLIB_KEY_U_85                  GLFW_KEY_U                 
#define GLIB_KEY_V_86                  GLFW_KEY_V                 
#define GLIB_KEY_W_87                  GLFW_KEY_W                 
#define GLIB_KEY_X_88                  GLFW_KEY_X                 
#define GLIB_KEY_Y_89                  GLFW_KEY_Y                 
#define GLIB_KEY_Z_90                  GLFW_KEY_Z                 
#define GLIB_KEY_LEFT_BRACKET_91       GLFW_KEY_LEFT_BRACKET      
#define GLIB_KEY_BACKSLASH_92          GLFW_KEY_BACKSLASH         
#define GLIB_KEY_RIGHT_BRACKET_93      GLFW_KEY_RIGHT_BRACKET     
#define GLIB_KEY_GRAVE_ACCENT_96       GLFW_KEY_GRAVE_ACCENT      
#define GLIB_KEY_WORLD_1_161           GLFW_KEY_WORLD_1           
#define GLIB_KEY_WORLD_2_162           GLFW_KEY_WORLD_2           
// keys_to_control
#define GLIB_KEY_ESCAPE_27             GLFW_KEY_ESCAPE             
#define GLIB_KEY_BACKSPACE_8          GLFW_KEY_BACKSPACE          
#define GLIB_KEY_HTAB_9                GLFW_KEY_TAB                
#define GLIB_KEY_ENTER_10              GLFW_KEY_ENTER              
#define GLIB_KEY_INS_45             GLFW_KEY_INSERT             
#define GLIB_KEY_DEL_46             GLFW_KEY_DELETE             
#define GLIB_KEY_RIGHT_38              GLFW_KEY_RIGHT              
#define GLIB_KEY_LEFT_37               GLFW_KEY_LEFT               
#define GLIB_KEY_DOWN_40               GLFW_KEY_DOWN               
#define GLIB_KEY_UP_38                 GLFW_KEY_UP                 
#define GLIB_KEY_PAGE_UP            GLFW_KEY_PAGE_UP            
#define GLIB_KEY_PAGE_DOWN          GLFW_KEY_PAGE_DOWN          
#define GLIB_KEY_HOME               GLFW_KEY_HOME               
#define GLIB_KEY_END                GLFW_KEY_END                
#define GLIB_KEY_CAPS_LOCK          GLFW_KEY_CAPS_LOCK          
#define GLIB_KEY_SCROLL_LOCK        GLFW_KEY_SCROLL_LOCK        
#define GLIB_KEY_NUM_LOCK           GLFW_KEY_NUM_LOCK           
#define GLIB_KEY_PRINT_SCREEN       GLFW_KEY_PRINT_SCREEN       
#define GLIB_KEY_PAUSE              GLFW_KEY_PAUSE              
#define GLIB_KEY_F1                 GLFW_KEY_F1                 
#define GLIB_KEY_F2                 GLFW_KEY_F2                 
#define GLIB_KEY_F3                 GLFW_KEY_F3                 
#define GLIB_KEY_F4                 GLFW_KEY_F4                 
#define GLIB_KEY_F5                 GLFW_KEY_F5                 
#define GLIB_KEY_F6                 GLFW_KEY_F6                 
#define GLIB_KEY_F7                 GLFW_KEY_F7                 
#define GLIB_KEY_F8                 GLFW_KEY_F8                 
#define GLIB_KEY_F9                 GLFW_KEY_F9                 
#define GLIB_KEY_F10                GLFW_KEY_F10                
#define GLIB_KEY_F11                GLFW_KEY_F11                
#define GLIB_KEY_F12                GLFW_KEY_F12                
#define GLIB_KEY_F13                GLFW_KEY_F13                
#define GLIB_KEY_F14                GLFW_KEY_F14                
#define GLIB_KEY_F15                GLFW_KEY_F15                
#define GLIB_KEY_F16                GLFW_KEY_F16                
#define GLIB_KEY_F17                GLFW_KEY_F17                
#define GLIB_KEY_F18                GLFW_KEY_F18                
#define GLIB_KEY_F19                GLFW_KEY_F19                
#define GLIB_KEY_F20                GLFW_KEY_F20                
#define GLIB_KEY_F21                GLFW_KEY_F21                
#define GLIB_KEY_F22                GLFW_KEY_F22                
#define GLIB_KEY_F23                GLFW_KEY_F23                
#define GLIB_KEY_F24                GLFW_KEY_F24                
#define GLIB_KEY_F25                GLFW_KEY_F25                
#define GLIB_KEY_KP_0               GLFW_KEY_KP_0               
#define GLIB_KEY_KP_1               GLFW_KEY_KP_1               
#define GLIB_KEY_KP_2               GLFW_KEY_KP_2               
#define GLIB_KEY_KP_3               GLFW_KEY_KP_3               
#define GLIB_KEY_KP_4               GLFW_KEY_KP_4               
#define GLIB_KEY_KP_5               GLFW_KEY_KP_5               
#define GLIB_KEY_KP_6               GLFW_KEY_KP_6               
#define GLIB_KEY_KP_7               GLFW_KEY_KP_7               
#define GLIB_KEY_KP_8               GLFW_KEY_KP_8               
#define GLIB_KEY_KP_9               GLFW_KEY_KP_9               
#define GLIB_KEY_KP_DECIMAL         GLFW_KEY_KP_DECIMAL         
#define GLIB_KEY_KP_DIVIDE          GLFW_KEY_KP_DIVIDE          
#define GLIB_KEY_KP_MULTIPLY        GLFW_KEY_KP_MULTIPLY        
#define GLIB_KEY_KP_SUBTRACT        GLFW_KEY_KP_SUBTRACT        
#define GLIB_KEY_KP_ADD             GLFW_KEY_KP_ADD             
#define GLIB_KEY_KP_ENTER_13           GLFW_KEY_KP_ENTER
#define GLIB_KEY_KP_EQUAL           GLFW_KEY_KP_EQUAL
#define GLIB_KEY_SHIFT_LEFT         GLFW_KEY_LEFT_SHIFT
#define GLIB_KEY_SHIFT_RIGHT        GLFW_KEY_RIGHT_SHIFT
#define GLIB_KEY_CONTROL_LEFT       GLFW_KEY_LEFT_CONTROL
#define GLIB_KEY_CONTROL_RIGHT      GLFW_KEY_RIGHT_CONTROL
#define GLIB_KEY_ALT_LEFT           GLFW_KEY_LEFT_ALT
#define GLIB_KEY_ALT_RIGHT          GLFW_KEY_RIGHT_ALT
#define GLIB_KEY_LEFT_SUPER         GLFW_KEY_LEFT_SUPER
#define GLIB_KEY_RIGHT_SUPER        GLFW_KEY_RIGHT_SUPER
#define GLIB_KEY_MENU               GLFW_KEY_MENU

#define GLIB_KEY_LAST GLFW_KEY_LAST
// --==</keyboard_nw>==--

// --==<mouse_glfw>==--
#define GLFW_MOUSE_BUTTON_1         0
#define GLFW_MOUSE_BUTTON_2         1
#define GLFW_MOUSE_BUTTON_3         2
#define GLFW_MOUSE_BUTTON_4         3
#define GLFW_MOUSE_BUTTON_5         4
#define GLFW_MOUSE_BUTTON_6         5
#define GLFW_MOUSE_BUTTON_7         6
#define GLFW_MOUSE_BUTTON_8         7
#define GLFW_MOUSE_BUTTON_LAST      GLFW_MOUSE_BUTTON_8
#define GLFW_MOUSE_BUTTON_LEFT      GLFW_MOUSE_BUTTON_1
#define GLFW_MOUSE_BUTTON_RIGHT     GLFW_MOUSE_BUTTON_2
#define GLFW_MOUSE_BUTTON_MIDDLE    GLFW_MOUSE_BUTTON_3
// --==</mouse_glfw>==--

// --==<mouse_nw>==--
#define GLIB_MS_BTN_0         GLFW_MOUSE_BUTTON_1
#define GLIB_MS_BTN_1         GLFW_MOUSE_BUTTON_2
#define GLIB_MS_BTN_2         GLFW_MOUSE_BUTTON_3
#define GLIB_MS_BTN_3         GLFW_MOUSE_BUTTON_4
#define GLIB_MS_BTN_4         GLFW_MOUSE_BUTTON_5
#define GLIB_MS_BTN_5         GLFW_MOUSE_BUTTON_6
#define GLIB_MS_BTN_6         GLFW_MOUSE_BUTTON_7
#define GLIB_MS_BTN_7         GLFW_MOUSE_BUTTON_8
#define GLIB_MS_BTN_LAST      GLFW_MOUSE_BUTTON_8
#define GLIB_MS_BTN_LEFT      GLFW_MOUSE_BUTTON_1
#define GLIB_MS_BTN_RIGHT     GLFW_MOUSE_BUTTON_2
#define GLIB_MS_BTN_MIDDLE    GLFW_MOUSE_BUTTON_3
// --==</mouse_nw>==--

// --==<events_nw>==--
#define GLFW_RELEASE 0
#define GLFW_PRESS 1
#define GLFW_REPEAT 2

#define GLIB_RELEASE GLFW_RELEASE
#define GLIB_PRESS GLFW_PRESS
#define GLIB_REPEAT GLFW_REPEAT

#define GLIB_MS_PRESS_LEFT 0
#define GLIB_MS_PRESS_RIGHT 1
#define GLIB_MS_PRESS_2 2
#define GLIB_MS_PRESS_3 3
#define GLIB_MS_PRESS_4 4

#define GLIB_MS_PRESS_DOUBLE 0

#define GLIB_MS_MOVED 1
#define GLIB_MS_WHEELED 2
#define GLIB_MS_HWHEELED 3
// --==</events_nw>==--

#endif // GLIB_WINDOW

#if (GLIB_GAPI & GLIB_GAPI_OGL)
// --==<data_types_ogl>==--
#define GL_BOOL								0x8B56
#define GL_BYTE								0x1400
#define GL_UNSIGNED_BYTE					0x1401
#define GL_SHORT							0x1402
#define GL_UNSIGNED_SHORT					0x1403
#define GL_INT								0x1404
#define GL_UNSIGNED_INT						0x1405
#define GL_FLOAT							0x1406
#define GL_DOUBLE							0x140A
#define GL_SAMPLER_1D 0x8B5D
// --==</data_types_ogl>==--

// --==<types_of_data_nw>==--
#define GLIB_ZERO 0
#define GLIB_ONE 1
#define GLIB_BOOL			GL_BOOL
#define GLIB_INT16		GL_SHORT
#define GLIB_UINT16		GL_UNSIGNED_SHORT
#define GLIB_INT8			GL_BYTE
#define GLIB_UINT8		GL_UNSIGNED_BYTE
#define GLIB_INT32		GL_INT
#define GLIB_UINT32		GL_UNSIGNED_INT
#define GLIB_FLOAT32		GL_FLOAT
#define GLIB_FLOAT64		GL_DOUBLE
#define GLIB_FLOAT32_VEC2	(GLIB_FLOAT32 + 0x0020)
#define GLIB_FLOAT32_VEC3	(GLIB_FLOAT32 + 0x0030)
#define GLIB_FLOAT32_VEC4	(GLIB_FLOAT32 + 0x0040)
#define GLIB_FLOAT32_MAT2	(GLIB_FLOAT32 + 0x0100)
#define GLIB_FLOAT32_MAT3	(GLIB_FLOAT32 + 0x0200)
#define GLIB_FLOAT32_MAT4	(GLIB_FLOAT32 + 0x0300)
#define GLIB_SAMPLER_1D	GL_SAMPLER_1D
// --==</types_of_data_nw>==--

// --==<draw_modes_ogl>==--
#define GL_POINT 0x1B00
#define GL_LINE 0x1B01
#define GL_FILL 0x1B02
// --primitives
#define GL_POINTS 0x0000
#define GL_LINES 0x0001
#define GL_LINE_STRIP 0x0003
#define GL_LINE_LOOP 0x0002
#define GL_LINE_BIT 0x00000004
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_QUADS 0x0007
#define GL_QUAD_STRIP 0x0008
#define GL_POLYGON 0x0009
// --==</draw_modes_ogl>==--

// --==<draw_modes_nw>==--
#define GLIB_POINT 0x1B00
#define GLIB_LINE 0x1B01
#define GLIB_FILL 0x1B02
// --primitives
#define GLIB_POINTS 0x0000
#define GLIB_LINES 0x0001
#define GLIB_LINE_STRIP 0x0003
#define GLIB_LINE_LOOP 0x0002
#define GLIB_LINE_BIT 0x00000004
#define GLIB_TRIANGLES 0x0004
#define GLIB_TRIANGLE_STRIP 0x0005
#define GLIB_TRIANGLE_FAN 0x0006
#define GLIB_QUADS 0x0007
#define GLIB_QUAD_STRIP 0x0008
#define GLIB_POLYGON 0x0009
// --==</draw_modes_NW>==--

// --==<planes_ogl>==--
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_LEFT 0x0406
#define GL_RIGHT 0x0407
#define GL_FRONT_AND_BACK 0x0408
// --==</planes_ogl>==--
// --==<planes_nw>==--
#define GLIB_FRONT GL_FRONT
#define GLIB_BACK GL_BACK
#define GLIB_LEFT GL_LEFT
#define GLIB_RIGHT GL_RIGHT
#define GLIB_FRONT_AND_BACK GL_FRONT_AND_BACK
// --==</planes_nw>==--

// --==<Shaders_ogl>==--
#define GL_SHADER 0x82E1
#define GL_PROGRAM 0x82E2
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_GEOMETRY_SHADER 0x8DD9
#define GL_VERTEX_SHADER 0x8B31

#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_ATTACHED_SHADERS 0x8B85
// --==<shaders_ogl>==--

// --==<shaders_nw>==--
#define GLIB_SHADER				GL_PROGRAM
#define GLIB_SHADER_VERTEX		GL_VERTEX_SHADER
#define GLIB_SHADER_GEOMETRY		GL_GEOMETRY_SHADER
#define GLIB_SHADER_PIXEL			GL_FRAGMENT_SHADER

#define GLIB_COMPILE_STATUS		GL_COMPILE_STATUS
#define GLIB_LINK_STATUS			GL_LINK_STATUS
// --==</Shaders_NW>==--

// --==<configurations_ogl>==--
#define GL_SRC_COLOR 0x0300
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_DST_ALPHA 0x0304
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DST_COLOR 0x0306
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_POINT_SIZE 0x0B11
#define GL_LINE_SMOOTH 0x0B20
#define GL_LINE_WIDTH 0x0B21

#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
#define GL_FRONT_FACE 0x0B46
#define GL_CW 0x0900
#define GL_CCW 0x0901

#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_FUNC 0x0B74

#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_FUNC 0x0B92

#define GL_BLEND_DST 0x0BE0
#define GL_BLEND_SRC 0x0BE1
#define GL_BLEND 0x0BE2

#define GL_KEEP				0x1E00
#define GL_REPLACE			0x1E01
#define GL_INCR				0x1E02
#define GL_DECR				0x1E03
// --==</configurations_ogl>==--

// --==<configurations_nw>==--
#define GLIB_SRC_COLOR GL_SRC_COLOR
#define GLIB_ONE_MINUS_SRC_COLOR GL_ONE_MINUS_SRC_COLOR
#define GLIB_SRC_ALPHA GL_SRC_ALPHA
#define GLIB_ONE_MINUS_SRC_ALPHA GL_ONE_MINUS_SRC_ALPHA
#define GLIB_DST_ALPHA GL_DST_ALPHA
#define GLIB_ONE_MINUS_DST_ALPHA GL_ONE_MINUS_DST_ALPHA
#define GLIB_DST_COLOR GL_DST_COLOR
#define GLIB_ONE_MINUS_DST_COLOR GL_ONE_MINUS_DST_COLOR
#define GLIB_SRC_ALPHA_SATURATE GL_SRC_ALPHA_SATURATE
#define GLIB_POINT_SIZE GL_POINT_SIZE
#define GLIB_LINE_SMOOTH GL_LINE_SMOOTH
#define GLIB_LINE_WIDTH GL_LINE_WIDTH

#define GLIB_CULL_FACE		GL_CULL_FACE
#define GLIB_CULL_FACE_MODE	GL_CULL_FACE_MODE
#define GLIB_FRONT_FACE		GL_FRONT_FACE
#define GLIB_CW				GL_CW
#define GLIB_CCW				GL_CCW

#define GLIB_DEPTH_TEST		GL_DEPTH_TEST
#define GLIB_DEPTH_FUNC		GL_DEPTH_FUNC

#define GLIB_STENCIL_TEST		GL_STENCIL_TEST
#define GLIB_STENCIL_FUNC		GL_STENCIL_FUNC

#define GLIB_BLEND_DST		GL_BLEND_DST
#define GLIB_BLEND_SRC		GL_BLEND_SRC
#define GLIB_BLEND			GL_BLEND

#define GLIB_KEEP				 GL_KEEP		
#define GLIB_REPLACE			 GL_REPLACE	
#define GLIB_INCR				 GL_INCR		
#define GLIB_DECR				 GL_DECR		
// --==</configurations_nw>==--

// --==<expressions_ogl>==--
// --constants
#define GL_NONE 0
#define GL_FALSE 0
#define GL_TRUE 1
#define GL_ZERO 0
#define GL_ONE 1
// --conditions
#define GL_NEVER 0x0200
#define GL_LESS 0x0201
#define GL_EQUAL 0x0202
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207
// --logic
#define GL_AND 0x1501
#define GL_AND_REVERSE 0x1502
#define GL_COPY 0x1503
#define GL_AND_INVERTED 0x1504
#define GL_NOOP 0x1505
#define GL_XOR 0x1506
#define GL_OR 0x1507
#define GL_NOR 0x1508
#define GL_EQUIV 0x1509
#define GL_INVERT 0x150A
#define GL_OR_REVERSE 0x150B
#define GL_COPY_INVERTED 0x150C
#define GL_OR_INVERTED 0x150D
#define GL_NAND 0x150E
// --==</expressions_ogl>==--

// --==<expressions_nw>==--
// --constants
#define GLIB_NONE 0
#define GLIB_FALSE 0
#define GLIB_TRUE 1
// --conditions
#define GLIB_NEVER 0x0200
#define GLIB_LESS 0x0201
#define GLIB_EQUAL 0x0202
#define GLIB_LEQUAL 0x0203
#define GLIB_GREATER 0x0204
#define GLIB_NOTEQUAL 0x0205
#define GLIB_GEQUAL 0x0206
#define GLIB_ALWAYS 0x0207
// --logic
#define GLIB_AND 0x1501
#define GLIB_AND_REVERSE 0x1502
#define GLIB_COPY 0x1503
#define GLIB_AND_INVERTED 0x1504
#define GLIB_NOOP 0x1505
#define GLIB_XOR 0x1506
#define GLIB_OR 0x1507
#define GLIB_NOR 0x1508
#define GLIB_EQUIV 0x1509
#define GLIB_INVERT 0x150A
#define GLIB_OR_REVERSE 0x150B
#define GLIB_COPY_INVERTED 0x150C
#define GLIB_OR_INVERTED 0x150D
#define GLIB_NAND 0x150E
// --==</expressions_nw>==--

// --==<colors_ogl>==--
#define GL_COLOR 0x1800
#define GL_RED 0x1903
#define GL_GREEN 0x1904
#define GL_BLUE 0x1905
#define GL_ALPHA 0x1906
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
#define GL_RGBA8 0x8058
// --==</colors_ogl>==--

// --==<colors_nw>==--
#define GLIB_COLOR		GL_COLOR
#define GLIB_RED			GL_RED
#define GLIB_GREEN		GL_GREEN
#define GLIB_BLUE			GL_BLUE
#define GLIB_ALPHA		GL_ALPHA
#define GLIB_RGB			GL_RGB
#define GLIB_RGBA			GL_RGBA
#define GLIB_RGBA8		GL_RGBA8
// --==</colors_nw>==--

// --==<textures_ogl>==--
// --types
#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_3D 0x0DE2
// --filters
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
// --wrappers
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_CLAMP 0x2900
#define GL_REPEAT 0x2901
// --==</textures_ogl>==--

// --==<textures_nw>==--
// --types
#define GLIB_TEXTURE_1D	GL_TEXTURE_1D
#define GLIB_TEXTURE_2D	GL_TEXTURE_2D
#define GLIB_TEXTURE_3D	GL_TEXTURE_3D
// --filters
#define GLIB_TEXTURE_MAG_FILTER			GL_TEXTURE_MAG_FILTER
#define GLIB_TEXTURE_MIN_FILTER			GL_TEXTURE_MIN_FILTER
#define GLIB_TEXTURE_FILTER_NEAREST		GL_NEAREST
#define GLIB_TEXTURE_FILTER_LINEAR		GL_LINEAR
// --wrappers
#define GLIB_TEXTURE_WRAP_S			GL_TEXTURE_WRAP_S
#define GLIB_TEXTURE_WRAP_T			GL_TEXTURE_WRAP_T
#define GLIB_TEXTURE_WRAP_R			GL_TEXTURE_WRAP_R
#define GLIB_TEXTURE_WRAP_CLAMP		GL_CLAMP
#define GLIB_TEXTURE_WRAP_REPEAT		GL_REPEAT
// --==</textures_nw>==--

// --==<gbuffers_ogl>==--
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_UNIFORM_BUFFER 0x8A11
// --==</gbuffers_ogl>==--

// --==<buffers_ogl>==--
#define GL_COLOR_BUFFER_BIT					0x00004000
#define GL_DEPTH_BUFFER_BIT					0x00000100
#define GL_ACCUM_BUFFER_BIT					0x00000200
#define GL_STENCIL_BUFFER_BIT				0x00000400
// --==</buffers_ogl>==--


// --==<gbuffers_nw>==--
#define GLIB_GBUFFER_VERTEX GL_ARRAY_BUFFER
#define GLIB_GBUFFER_INDEX GL_ELEMENT_ARRAY_BUFFER
#define GLIB_GBUFFER_SHADER GL_UNIFORM_BUFFER
// --==</gbuffers_nw>==--

// --==<framebuffers_nw>==--
#define GLIB_BUFFER_COLOR_BIT					GL_COLOR_BUFFER_BIT
#define GLIB_BUFFER_DEPTH_BIT					GL_DEPTH_BUFFER_BIT
#define GLIB_BUFFER_STENCIL_BIT				GL_STENCIL_BUFFER_BIT
// --==</framebuffers_nw>==--

// --==<data_load_types_ogl>==--
#define GL_STATIC_DRAW 0x88E4
#define GL_STREAM_DRAW 0x88E0
#define GL_DYNAMIC_DRAW 0x88E8
// --==</data_load_types_ogl>==--

// --==<data_load_types_nw>==--
#define GLIB_STATIC_DRAW		GL_STATIC_DRAW 
#define GLIB_STREAM_DRAW		GL_STREAM_DRAW 
#define GLIB_DYNAMIC_DRAW		GL_DYNAMIC_DRAW
// --==</data_load_types_nw>==--

// --==<error_codes_ogl>==--
#define GL_NO_ERROR                       0
#define GL_INVALID_ENUM                   0x0500
#define GL_INVALID_VALUE                  0x0501
#define GL_INVALID_OPERATION              0x0502
#define GL_STACK_OVERFLOW                 0x0503
#define GL_STACK_UNDERFLOW                0x0504
#define GL_OUT_OF_MEMORY                  0x0505
// --==</error_codes_ogl>==--

// --==<error_codes_nw>==--
#define GLIB_OK							GL_NO_ERROR         
#define GLIB_INVALID_ENUM					GL_INVALID_ENUM     
#define GLIB_INVALID_VALUE				GL_INVALID_VALUE    
#define GLIB_INVALID_OPERATION			GL_INVALID_OPERATION
#define GLIB_STACK_OVERFLOW				GL_STACK_OVERFLOW   
#define GLIB_STACK_UNDERFLOW				GL_STACK_UNDERFLOW  
#define GLIB_OUT_OF_MEMORY				GL_OUT_OF_MEMORY  

#define GLIB_ERR_DATA_LOSS				0b1110'0000'0000

#define GLIB_ERR_NO_SUPPORT				0b1110'0000'0001
#define GLIB_ERR_NO_DATA					0b1110'0000'0001
#define GLIB_ERR_NO_INIT					0b1110'0000'0010
#define GLIB_ERR_NO_QUIT					0b1110'0000'0011
#define GLIB_ERR_NO_STATE					0b1110'0000'0100

#define GLIB_ERR_UNKNOWN_ID				0b1111'0000'0000

#define GLIB_ERR_SHADER_INVALID_FORMAT	0b0011'0000'0000
#define GLIB_ERR_SHADER_LOAD_PATH			0b1000'0000'0000
#define GLIB_ERR_SHADER_LOAD_FAIL			0b1001'0000'0000
#define GLIB_ERR_SHADER_LINK				0b1011'0000'0000
#define GLIB_ERR_SHADER_COMPILE			0b1100'0000'0000
// --==</error_codes_nw>==--

// --==<info_ogl>==--
#define GL_VENDOR                         0x1F00
#define GL_RENDERER                       0x1F01
#define GL_VERSION                        0x1F02
#define GL_EXTENSIONS                     0x1F03
// --==</info_ogl>==--
// Nothing for now... 08.11.20
#endif // GLIB_GAPI

#endif	// GLIB_DEF_HPP