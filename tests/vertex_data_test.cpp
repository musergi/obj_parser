#include <obj_parser/vertex_data.hpp>
#include <cassert>

void assert_empty(const VertexData vertex_data) {
    assert(vertex_data.getGeometricVertexCount() == 0);
    assert(vertex_data.getTextureVertexCount() == 0);
    assert(vertex_data.getVertexNormalCount() == 0);
};

int main() {
    VertexParser vertex_parser("v 2.0 0.3 5.0");
    Vertex<4> vertex(vertex_parser);
    VertexData vertex_data;
    assert_empty(vertex_data);
    vertex_data.addGeometricVertex(vertex);
    assert(vertex_data.getGeometricVertexCount() == 1);
    Vertex<4> retrieved = vertex_data.getGeometricVertex(1);
    assert(retrieved[0] == vertex[0]);
    assert(retrieved[1] == vertex[1]);
    assert(retrieved[2] == vertex[2]);
    return 0;
}