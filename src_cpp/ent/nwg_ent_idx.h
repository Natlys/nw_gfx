#ifndef NWG_INDEXED_ENTITY_H
#define NWG_INDEXED_ENTITY_H
#include <nwg_core.hpp>
#if (defined NW_GAPI)
#include <core/nwg_ent.h>
#include <cmp/buf/nwg_buf_idx.h>
namespace NW
{
	/// indexed drb class
	class NW_API ent_idx : public a_gfx_ent
	{
		using buffer = mem_ref<buf_idx>;
	public:
		ent_idx(gfx_engine& graphics);
		virtual ~ent_idx();
		// --getters
		buffer& get_buf() { return m_ibuf; }
		// --setters
		// --core_methods
		virtual void on_draw() override;
	private:
		buffer m_ibuf;
	};
}

#endif	// NW_GAPI
#endif	// NWG_INDEXED_ENTITY_H