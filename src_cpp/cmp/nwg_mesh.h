#ifndef NWG_MESH_H
#define NWG_MESH_H
#include <nwg_core.hpp>
#if (defined NWG_GAPI)
#include <core/nwg_switch.h>
namespace NWG
{
	struct NWG_API vtx_2f
	{
		v2f vtx_crd = { 0.0f, 0.0f };
	};
	struct NWG_API vtx_2f2f
	{
		v2f vtx_crd = { 0.0f, 0.0f };
		v2f tex_crd = { 0.0f, 0.0f };
	};
	struct NWG_API vtx_2f2f4u8
	{
		v2f vtx_crd = { 0.0f, 0.0f };
		v2f tex_crd = { 0.0f, 0.0f };
		v4ui8 vtx_clr = { 0u, 0u, 0u, 0u };
	};
	struct NWG_API vtx_3f
	{
		v3f vtx_crd = { 0.0f, 0.0f, 0.0f };
	};
	struct NWG_API vtx_3f2f
	{
		v3f vtx_crd = { 0.0f, 0.0f, 0.0f };
		v2f txr_crd = { 0.0f, 0.0f };
	};
	struct NWG_API vtx_3f2f3f
	{
		v3f vtx_crd = { 0.0f, 0.0f, 0.0f };
		v2f tex_crd = { 0.0f, 0.0f };
		v3f nrm_crd = { 0.0f, 0.0f, 0.0f };
	};
}
namespace NWG
{
	struct NWG_API buf_m4f {
		m4f model = m4f32(1.0f);
	};
	struct NWG_API buf_m4fm4f {
		m4f view = m4f32(1.0f);
		m4f proj = m4f32(1.0f);
	};
	struct NWG_API buf_m4fm4fm4f {
		m4f model = m4f32(1.0f);
		m4f view = m4f32(1.0f);
		m4f proj = m4f32(1.0f);
	};
}
namespace NWG
{
	/// graphics mesh data class
	/// description:
	/// --makes render data for primitives;
	/// interface:
	/// --add vertex data one by one;
	/// --update_idx_data for required topology;
	/// --use index and vertex data for drawing;
	template<typename vtype, typename itype = ui32>
	class NWG_API gfx_mesh_data
	{
		using vertices = darray<vtype>;
		using indices = darray<itype>;
	public:
		gfx_mesh_data() : m_vtxs(vertices()), m_idxs(indices()), m_iter(0) { }
		// --getters
		inline vtype* get_vtx_data() { return &m_vtxs[0]; }
		inline size get_vtx_count()	const { return m_vtxs.size(); }
		inline vertices& get_vertices() { return m_vtxs; }
		inline vtype& get_vertex(ui32 idx) { return m_vtxs[idx % m_vtxs.size()]; }
		inline itype* get_idx_data() { return &m_idxs[0]; }
		inline ui32 get_idx_count()	const { return m_idxs.size(); }
		inline indices& get_indices() { return m_idxs; }
		inline itype& get_index(ui32 idx) { return m_idxs[idx % m_idxs.size()]; }
		// --setters
		void add_vertex(const vtype& vtx) { m_vtxs.push_back(vtx); }
		// --core_methods
		void update_indices(gfx_primitives primitive_topology) {
			switch (primitive_topology) {
				if (m_vtxs.size() < 1) { break; }
			case GPT_POINTS: case GPT_LINE_LOOP: case GPT_LINE_STRIP: case GPT_TRIANGLE_FAN: {
				while (m_iter < m_vtxs.size() - 0) {
					m_idxs.push_back(m_iter + 0);
					m_iter++;
				}
				m_iter++;
				break;
			}
			case GPT_LINES: {
				if (m_vtxs.size() < 2) { break; }
				while (m_iter < m_vtxs.size() - 1) {
					m_idxs.push_back(m_iter + 0);
					m_idxs.push_back(m_iter + 1);
					m_iter++;
				}
				m_iter++;
				break;
			}
			case GPT_TRIANGLES: {
				if (m_vtxs.size() < 3) { break; }
				ui32 first = m_iter;
				while (m_iter < m_vtxs.size() - 1) {
					m_idxs.push_back(first);
					m_idxs.push_back(m_iter + 0);
					m_idxs.push_back(m_iter + 1);
					m_iter++;
				}
				m_iter++;
				break;
			}
			case GPT_TRIANGLE_STRIP: {
				if (m_vtxs.size() < 3) { break; }
				ui32 first = m_iter;
				while (m_iter < m_vtxs.size() - 0) {
					m_idxs.push_back(first);
					m_idxs.push_back(m_iter + 0);
					m_iter++;
				}
				m_iter++;
				break;
			}
			default: break;
			}
		}
		void remake() {
			m_vtxs.clear();
			m_idxs.clear();
			m_iter = 0;
		}
	private:
		vertices m_vtxs;
		indices m_idxs;
		ui32 m_iter;
	};
}
namespace NWG
{
	class NWG_API gfx_mesh_info : public a_info
	{
	public:
		gfx_mesh_info();
		// --operators
		virtual std::ostream& operator<<(std::ostream& stm) const override;
		virtual std::istream& operator>>(std::istream& stm) override;
	};
}
#endif	// NWG_GAPI
#endif	// NWG_MESH_H