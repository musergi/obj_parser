#include "test.hpp"
#include <obj_parser.hpp>

int main(int argc, char **argv)
{
    ObjContent obj;
    LineParser line_parser;
    line_parser.parse("v 1.0 -1.0 0.0", &obj);
    GeometricVertex parsed_vertex = obj.getGeometricVertex(0);
    assert_equals(parsed_vertex.to_string(), "(1, -1, 0, 1)");
    line_parser.parse("vn 0.0 0.0 1.0", &obj);
    VertexNormal parsed_normal = obj.getVertexNormal(0);
    assert_equals(parsed_normal.to_string(), "(0, 0, 1)");
    std::cout << "Tests passed." << std::endl;
    return 0;
}
