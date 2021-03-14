#ifndef NW_SHADER_H
#define NW_SHADER_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_rsc.h>
#include <core/nwg_layout.h>
#include <core/nwg_buf_shd.h>
#include <core/nwg_texture.h>
namespace NW
{
	class NW_API a_shader : public a_data_rsc
	{
	public:
		using txr = mem_ref<a_texture>;
		using txrs = darray<txr>;
		using buf = mem_ref<buf_shd>;
		using bufs = darray<buf>;
	public:
		a_shader(cstring name);
		virtual ~a_shader();
		// --getters
		inline cstring get_src_code() const	{ return &m_src_code[0]; }
		inline buf& get_buf(ui8 idx)		{ return m_bufs[idx % m_bufs.size()]; }
#if (NW_GAPI & NW_GAPI_OGL)
		inline GLuint get_ogl_id() const	{ return m_ogl_id; }
#endif
#if (NW_GAPI & NW_GAPI_DX)
		inline ID3DBlob* get_dx_blob()		{ return m_dx_blob; }
#endif
		// --setters
		void set_src_code(cstring source_code);
		void add_buf(buf& ref);
		void rmv_buf(ui8 idx);
		// --operators
		virtual out_stream& operator<<(out_stream& stm) const = 0;
		virtual in_stream& operator>>(in_stream& stm) = 0;
		// --core_methods
		virtual bit remake(cstring source_code) = 0;
		virtual void bind_txr(txr& ref) = 0;
		virtual void on_draw() = 0;
	protected:
		dstring m_src_code;
		bufs m_bufs;
#if (NW_GAPI & NW_GAPI_OGL)
		GLuint m_ogl_id;
#endif
#if(NW_GAPI & NW_GAPI_DX)
		ID3DBlob* m_dx_blob;
#endif
	};
}
#endif	// NW_GAPI
#endif // NW_SHADER_H