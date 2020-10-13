#include <obj_parser/vertex.hpp>
#include <cassert>

int main() {
    VertexParser vertex_parser("v 2.0 0.3 5.0");
    Vertex<4> vertex(vertex_parser);
    assert(vertex.getUsedComponents() == 3);
    assert(vertex[0] == 2.0f);
    assert(vertex[1] == 0.3f);
    assert(vertex[2] == 5.0f);
    return 0;
}