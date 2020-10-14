#include <obj_parser/vertex.hpp>
#include <cassert>

int main() {
	VertexParser vertex_parser("v 2.0 0.3 5.0");
	Vertex<4> vertex(vertex_parser);
	float buffer[3];
	vertex.toBuffer(buffer, 3);
	assert(buffer[0] == 2.0f);
	assert(buffer[1] == 0.3f);
	assert(buffer[2] == 5.0f);
	return 0;
}