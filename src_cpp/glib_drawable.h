#ifndef GLIB_DRAWABLE_H
#define GLIB_DRAWABLE_H

#include <glib_core.hpp>

namespace GLIB
{
	struct Drawable
	{
	public:
		RefKeeper<VertexArr> vtxArr;
		RefKeeper<VertexBuf> vtxBuf;
		RefKeeper<IndexBuf> idxBuf;
		RefKeeper<GMaterial> gMtl;
	public:
		Drawable();
		~Drawable();
	};
}

#endif	// GLIB_DRAWABLE_H