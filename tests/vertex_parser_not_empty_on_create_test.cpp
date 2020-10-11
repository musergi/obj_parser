#include <obj_parser/vertex_parser.hpp>

int main() {
    VertexParser vertex_parser("v 0.0 2.0 0.0");
    if (vertex_parser.hasFloat() == false)
        return 1;
    return 0;
}
