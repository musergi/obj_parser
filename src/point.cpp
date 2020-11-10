#include "obj_parser/point.hpp"

#define GEOMETRIC_VERTEX_INDEX 0
#define TEXTURE_VERTEX_INDEX 1
#define VERTEX_NORMAL_INDEX 2

#define POINTER_NOT_SET 0

Point::Point(
    unsigned int geometric_vertex_pointer, unsigned int texture_vertex_pointer, unsigned int vertex_normal_pointer) {
    vertices_pointers[GEOMETRIC_VERTEX_INDEX] = geometric_vertex_pointer;
    vertices_pointers[TEXTURE_VERTEX_INDEX] = texture_vertex_pointer;
    vertices_pointers[VERTEX_NORMAL_INDEX] = vertex_normal_pointer;
}

bool Point::hasTextureVertex() const { return vertices_pointers[TEXTURE_VERTEX_INDEX] != POINTER_NOT_SET; }

bool Point::hasVertexNormal() const { return vertices_pointers[VERTEX_NORMAL_INDEX] != POINTER_NOT_SET; }

unsigned int Point::getGeometricVertexPointer() const { return vertices_pointers[GEOMETRIC_VERTEX_INDEX]; }

unsigned int Point::getTextureVertexPointer() const { return vertices_pointers[TEXTURE_VERTEX_INDEX]; }

unsigned int Point::getVertexNormalPointer() const { return vertices_pointers[VERTEX_NORMAL_INDEX]; }
