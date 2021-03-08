#include <nwg_pch.hpp>
#include "nwg_state.h"
#if (defined NWG_GAPI)
namespace NWG
{
}
#if (NWG_GAPI & NWG_GAPI_OGL)
#include <lib/nwg_load_base.h>
namespace NWG
{
	//
}
#endif
#if (NWG_GAPI & NWG_GAPI_DX)
namespace NWG
{
	//
}
#endif
#endif	// NWG_GAPI