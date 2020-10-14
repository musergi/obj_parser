#include <obj_parser/face_parser.hpp>
#include <cassert>

void consume(FaceParser &face_parser, int n) {
    for (int i = 0; i < n; i++)
        face_parser.nextPoint();
}

int main() {
    FaceParser face_parser1("f 1 2 3");
    assert(face_parser1.hasPoint() == true);
    consume(face_parser1, 3);
    assert(face_parser1.hasPoint() == false);
    FaceParser face_parser2("f 1/1/1 2/2/3 3/3/2");
    assert(face_parser2.hasPoint() == true);
    consume(face_parser2, 3);
    assert(face_parser2.hasPoint() == false);
    FaceParser face_parser3("f 1//1 2//3 3//2 4//1");
    assert(face_parser3.hasPoint() == true);
    consume(face_parser3, 4);
    assert(face_parser3.hasPoint() == false);

    FaceParser face_parser4("f 3 1/2/3 4/3 2//3");
    const Point point1 = face_parser4.nextPoint();
    assert(point1.hasTextureVertex() == false);
    assert(point1.hasVertexNormal() == false);
    assert(point1.getGeometricVertexPointer() == 3u);
    const Point point2 = face_parser4.nextPoint();
    assert(point2.hasTextureVertex() == true);
    assert(point2.hasVertexNormal() == true);
    assert(point2.getGeometricVertexPointer() == 1u);
    assert(point2.getTextureVertexPointer() == 2u);
    assert(point2.getVertexNormalPointer() == 3u);
    const Point point3 = face_parser4.nextPoint();
    assert(point3.hasTextureVertex() == true);
    assert(point3.hasVertexNormal() == false);
    assert(point3.getGeometricVertexPointer() == 4u);
    assert(point3.getTextureVertexPointer() == 3u);
    const Point point4 = face_parser4.nextPoint();
    assert(point4.hasTextureVertex() == false);
    assert(point4.hasVertexNormal() == true);
    assert(point4.getGeometricVertexPointer() == 2u);
    assert(point4.getVertexNormalPointer() == 3u);
    return 0;
}