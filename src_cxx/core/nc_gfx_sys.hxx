#ifndef NC_GFX_SYSTEM_HXX
#   define NC_GFX_SYSTEM_HXX
#   include "../nc_gfx_core.hxx"
#   if (defined(NC_API))
/* includes */
/* defines */
/* typedef */
/* graphics_system_type */
typedef struct nc_gfx_sys_t nc_gfx_sys_t;
/** getters **/
/** setters **/
/** vetters **/
/** command **/
NC_API_CALL NC_API v1bit_t nc_gfx_sys_init();
NC_API_CALL NC_API v1bit_t nc_gfx_sys_quit();
NC_API_CALL NC_API v1bit_t nc_gfx_sys_work();
NC_API_CALL NC_API v1bit_t nc_gfx_sys_olog();
NC_API_CALL NC_API v1bit_t nc_gfx_sys_mset(ptr_t* data, size_t isize, size_t osize);
#   endif  /* NC_API */
#endif  /* NC_GFX_SYSTEM_HXX */
/* end_of_file */