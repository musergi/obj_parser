#include "test.hpp"
#include <obj_parser/obj_content.hpp>

int main(int argc, char **argv)
{
	ObjContent obj_content;
	obj_content.addGeometricVertex(Vertex<4>("1.0 -1.0 0.0"));
	assert_equals(obj_content.getGeometricVertexCount(), 1);
	Vertex<4> v = obj_content.getGeometricVertex(0);
	assert_equals(v[0], 1.0f);
	assert_equals(v[1], -1.0f);
	assert_equals(v[2], 0.0f);
	return 0;
}
