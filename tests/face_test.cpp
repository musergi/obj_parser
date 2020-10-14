#include <obj_parser/face.hpp>
#include <cassert>

int main() {
    Face face;
    assert(face.getPointCount() == 0);
    face.addPoint(Point(2u, 3u, 6u));
    assert(face.getPointCount() == 1);
    assert(face.getPoint(0).getGeometricVertexPointer() == 2u);
    assert(face.getPoint(0).getTextureVertexPointer() == 3u);
    assert(face.getPoint(0).getVertexNormalPointer() == 6u);
    return 0;
}