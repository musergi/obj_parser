#include <obj_parser/face_parser.hpp>

int main() {
	FaceParser face_parser("f 1/1/1 2//2 3//");
	if (!face_parser.hasPoint()) return 1;
	Point point1 = face_parser.nextPoint();
	if (point1.hasTextureVertex() == false) return 1;
	if (point1.hasVertexNormal() == false) return 1;
	if (point1.getGeometricVertexPointer() != 1) return 1;
	if (point1.getTextureVertexPointer() != 1) return 1;
	if (point1.getVertexNormalPointer() != 1) return 1;
	Point point2 = face_parser.nextPoint();
	if (point2.hasTextureVertex() == true) return 1;
	if (point2.hasVertexNormal() == false) return 1;
	if (point2.getGeometricVertexPointer() != 2) return 1;
	if (point2.getVertexNormalPointer() != 2) return 1;
	Point point3 = face_parser.nextPoint();
	if (point3.hasTextureVertex() == true) return 1;
	if (point3.hasVertexNormal() == true) return 1;
	if (point3.getGeometricVertexPointer() != 3) return 1;
	return 0;
}
