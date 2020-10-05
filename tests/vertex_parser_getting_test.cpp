#include "obj_parser/vertex_parser.hpp"
#include <iostream>

int main()
{
	VertexParser vertex_parser("v 1.0 -1.0 0.0");
	if (vertex_parser.getNextFloat() != 1.0f) return 1;
	if (vertex_parser.getNextFloat() != -1.0f) return 1;
	if (vertex_parser.getNextFloat() != 0.0f) return 1;
	if (vertex_parser.hasFloat()) return 1;
	return 0;
}
