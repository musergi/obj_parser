#include <obj_parser/point.hpp>
#include <cassert>

int main() {
    Point point(2u, 5u, 3u);
    assert(point.hasTextureVertex() == true);
    assert(point.hasVertexNormal() == true);
    assert(point.getGeometricVertexPointer() == 2u);
    assert(point.getTextureVertexPointer() == 5u);
    assert(point.getVertexNormalPointer() == 3u);
    return 0;
}