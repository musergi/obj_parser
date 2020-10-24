#include <obj_parser/obj_parser.hpp>
#include <cassert>

int main() {
    ObjContent obj_content;
    ObjParser obj_parser(&obj_content);
    obj_parser.parse("test_cube.obj");
    assert(obj_content.vertex_data.getGeometricVertexCount() == 8);
    assert(obj_content.vertex_data.getTextureVertexCount() == 14);
    assert(obj_content.vertex_data.getVertexNormalCount() == 6);
    assert(obj_content.getFaceCount() == 12);
    return 0;
}