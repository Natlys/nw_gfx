#include <nwg_pch.hpp>
#include "nwg_state.h"
#if (defined NW_GAPI)
namespace NW
{
}
#if (NW_GAPI & NW_GAPI_OGL)
#include <lib/nwg_load_base.h>
namespace NW
{
	//
}
#endif
#if (NW_GAPI & NW_GAPI_DX)
namespace NW
{
	//
}
#endif
#endif	// NW_GAPI