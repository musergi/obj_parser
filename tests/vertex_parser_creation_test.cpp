#include "obj_parser/vertex_parser.hpp"

int main()
{
	VertexParser v_vertex_parser("v 1.0 -1.0 0.0");
	if (v_vertex_parser.hasFloat() != true) return 1;
	if (v_vertex_parser.getType() != "v") return 1;
	VertexParser vt_vertex_parser("vt 0.5 1.0");
	if (vt_vertex_parser.hasFloat() != true) return 1;
	if (vt_vertex_parser.getType() != "vt") return 1;
	VertexParser vn_vertex_parser("vn 0.0 0.0 1.0");
	if (vn_vertex_parser.hasFloat() != true) return 1;
	if (vn_vertex_parser.getType() != "vn") return 1;
	return 0;
}
