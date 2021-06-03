#include "nc_gfx_pch.hxx"
#include "nc_gfx.hxx"

#if (defined NC_BUILD)
#   if (NC_BUILD & NC_BUILD_EXE)
int main(int arg_num, const char* arg_str[])
{
    printf("hello" NC_NAME_STR "!\n");
    system("pause");
    return 0;
}
#   endif   /* NC_BUILD_EXE */
#endif  /* NC_BUILD */
/* end_of_file */