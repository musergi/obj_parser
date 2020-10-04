#include "test.hpp"
#include <obj_parser/obj_parser.hpp>

int main(int argc, char **argv)
{
    Point point1(1, 2, 3);
    assert_equals(point1.getGeometricVertex(), (unsigned int) 1);
    assert_equals(point1.getTextureVertex(), (unsigned int) 2);
    assert_equals(point1.getVertexNormal(), (unsigned int) 3);
    Point point2(34);
    assert_equals(point2.getGeometricVertex(), (unsigned int) 34);
    assert_equals(point2.getTextureVertex(), (unsigned int) -1);
    assert_equals(point2.getVertexNormal(), (unsigned int) -1);
    assert_equals(point1.to_string(), std::string("(1, 2, 3)"));
    std::cout << "Tests passed." << std::endl;
    return 0;
}
