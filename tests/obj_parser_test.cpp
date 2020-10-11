#include <obj_parser/obj_parser.hpp>

int main(int argc, char **argv) {
	ObjContent obj_content;
	ObjParser obj_parser(&obj_content);
	obj_parser.parse(argv[1]);
	if (obj_content.vertex_data.getGeometricVertexCount() != 8)
		return 1;
	if (obj_content.vertex_data.getTextureVertexCount() != 14)
		return 1;
	if (obj_content.vertex_data.getVertexNormalCount() != 6)
		return 1;
	if (obj_content.faces.size() != 12)
		return 1;
	return 0;
}
