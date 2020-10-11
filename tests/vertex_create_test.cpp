#include <obj_parser/vertex.hpp>

int main() {
    Vertex<4> vertex(VertexParser("v 0.0 0.0 0.0"));
    Vertex<2> undersized_vertex(VertexParser("v 0.0 0.0 0.0"));
    return 0;
}
