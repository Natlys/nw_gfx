#include "../nc_gfx_pch.hxx"
#include "nc_gfx_sys.hxx"
#if (defined(NC_API))
/* includes */
/* defines */
/* typedef */
typedef struct nc_gfx_sys_t {
    v1bit_t is_working;
} nc_gfx_sys_t;
static nc_gfx_sys_t nc_gfx_sys = {
    .is_working = NC_FALSE
};
/** getters **/
/** setters **/
/** vetters **/
/** command **/
NC_API_CALL v1bit_t nc_gfx_sys_init() {
    /* init */
    /* work */
    /* quit */
    return NC_TRUTH;
}
NC_API_CALL v1bit_t nc_gfx_sys_quit() {
    /* init */
    /* work */
    /* quit */
    return NC_TRUTH;
}
NC_API_CALL v1bit_t nc_gfx_sys_work() {
    /* init */
    /* work */
    /* quit */
    return NC_TRUTH;
}
NC_API_CALL v1bit_t nc_gfx_sys_olog() {
    /* init */
    /* work */
    /* quit */
    return NC_TRUTH;
}
NC_API_CALL v1bit_t nc_gfx_sys_mset(ptr_t* data, size_t isize, size_t osize)  {
    /* init */
    /* work */
    NC_MEM_EDIT(data, isize, osize);
    /* quit */
    return NC_TRUTH;
}
#endif  /* NC_API */
/* end_of_file */