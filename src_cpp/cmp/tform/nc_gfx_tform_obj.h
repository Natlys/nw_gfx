#ifndef NC_GFX_TRANSFORM_OBJECT_H
#define NC_GFX_TRANSFORM_OBJECT_H
#include "nc_gfx_core.hpp"
#if (defined NC_GAPI)
#	include "nc_gfx_tform.h"
namespace NC
{
	/// graphics_transform_object class
	class NC_API gfx_tform_obj : public gfx_tform
	{
	public:
		using obj_t = gfx_tform_obj;
		using obj_tc = const obj_t;
	public:
		gfx_tform_obj();
		gfx_tform_obj(obj_tc& copy);
		gfx_tform_obj(obj_t&& copy);
		virtual ~gfx_tform_obj();
		// getters //
		// setters //
		// predicates //
		// operators //
		inline obj_t& operator=(obj_tc& copy) { NC_CHECK(remake(), "remake error!", return *this); return *this; }
		inline obj_t& operator=(obj_t&& copy) { NC_CHECK(remake(), "remake error!", return *this); return *this; }
		// commands //
		virtual v1bit_t remake() override;
		virtual v1nil_t on_draw() override;
	protected:
	};
}
#endif	// NC_GAPI
#endif	// NC_GFX_TRANSFORM_OBJECT_H