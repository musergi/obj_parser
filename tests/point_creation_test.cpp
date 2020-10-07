#include <obj_parser/point.hpp>

int main()
{
	Point point(1, 1, 1);
	if (!point.hasTextureVertex()) return 1;
	if (!point.hasVertexNormal()) return 1;
	Point point_no_vt(1, 0, 1);
	if (point_no_vt.hasTextureVertex()) return 1;
	if (!point_no_vt.hasVertexNormal()) return 1;
	Point point_no_vn(1, 1, 0);
	if (!point_no_vn.hasTextureVertex()) return 1;
	if (point_no_vn.hasVertexNormal()) return 1;
	Point val_point(35, 267, 4);
	if (val_point.getGeometricVertexPointer() != 35) return 1;
	if (val_point.getTextureVertexPointer() != 267) return 1;
	if (val_point.getVertexNormalPointer() != 4) return 1;
	return 0;
}
