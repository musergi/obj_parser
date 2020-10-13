#include <obj_parser/vertex_parser.hpp>
#include <cassert>

int main() {
    VertexParser vertex_parser("v 0.0 2.0 0.0");
    assert(vertex_parser.hasFloat() != false);
    return 0;
}
