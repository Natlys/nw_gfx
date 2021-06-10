#ifndef NC_GFX_LIBRARY_HXX
#   define NC_GFX_LIBRARY_HXX
#   include "../nc_gfx_core.hxx"
#   if (defined(NC_API))
/* includes */
/* defines */
/* typedef */
/* graphics_library_type */
typedef struct nc_gfx_lib_t nc_gfx_lib_t;
/* codetor */
/* getters */
/* setters */
/* vetters */
/* command */
NC_API_CALL NC_API v1bit_t nc_gfx_lib_init(nc_gfx_lib_t* ref);
NC_API_CALL NC_API v1bit_t nc_gfx_lib_quit(nc_gfx_lib_t* ref);
NC_API_CALL NC_API v1bit_t nc_gfx_lib_olog(nc_gfx_lib_t* ref);
#   endif  /* NC_API */
#endif  /* NC_GFX_LIBRARY_HXX */
/* end_of_file */