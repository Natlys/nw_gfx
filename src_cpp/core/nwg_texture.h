#ifndef NW_TEXTURE_H
#define NW_TEXTURE_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_rsc.h>
#include <lib/nwg_tools.h>
#include <lib/nwg_image.h>
namespace NW
{
	/// abstarct texture class
	/// description:
	class NW_API a_texture : public a_image
	{
	public:
		using txr_fmt = texture_formats;
		using data = darray<ubyte>;
#if (NW_GAPI & NW_GAPI_DX)
		using dx_rsc_view = ID3D11ShaderResourceView;
#endif		
	public:
		a_texture(cstring name);
		virtual ~a_texture();
		// --getters
		inline ui8 get_slot() const				{ return m_slot; }
		inline txr_fmt get_txr_fmt() const		{ return m_txr_fmt; }
#if (NW_GAPI & NW_GAPI_OGL)
		inline GLuint get_ogl_id() const		{ return m_ogl_id; }
#endif
#if (NW_GAPI & NW_GAPI_DX)
		inline dx_rsc_view* get_dx_view()		{ return m_dx_view; }
#endif
		// --setters
		void set_slot(ui8 texture_slot);
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const = 0;
		virtual in_stream& operator>>(in_stream& stm) = 0;
		// --core_methods
		virtual bit remake(const a_image& img) = 0;
		virtual void clear(ptr value) = 0;
		virtual void on_draw() = 0;
	protected:
		ui8 m_slot;
		txr_fmt m_txr_fmt;
#if (NW_GAPI & NW_GAPI_OGL)
		GLuint m_ogl_id;
#endif
#if (NW_GAPI & NW_GAPI_DX)
		dx_rsc_view* m_dx_view;
#endif
	};
}
#endif	// NW_GAPI
#endif // GFX_TEXTURE_H