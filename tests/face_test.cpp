#include "test.hpp"
#include <obj_parser/obj_parser.hpp>

int main(int argc, char **argv)
{
    Face face;
    assert_equals(face.getNumberPoints(), 0);
    face.addPoint(Point(1, 2, 3));
    assert_equals(face.getNumberPoints(), 1);
    assert_equals(face.getPoint(0).getGeometricVertex(), (unsigned int) 1);
    assert_equals(face.getPoint(0).getTextureVertex(), (unsigned int) 2);
    assert_equals(face.getPoint(0).getVertexNormal(), (unsigned int) 3);
    assert_equals(face.to_string(), std::string("[(1, 2, 3)]"));
    std::cout << "Tests passed." << std::endl;
    return 0;
}
