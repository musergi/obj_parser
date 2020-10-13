#include <obj_parser/vertex_parser.hpp>
#include <cassert>

int main() {
    VertexParser vertex_parser("v 0.0 1.0 2.0 3.0");
    assert(vertex_parser.getNextFloat() == 0.0);
    assert(vertex_parser.getNextFloat() == 1.0);
    assert(vertex_parser.getNextFloat() == 2.0);
    assert(vertex_parser.getNextFloat() == 3.0);
    assert(vertex_parser.hasFloat() == false);
    return 0;
}