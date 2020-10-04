#include "test.hpp"
#include <obj_parser/vertex.hpp>

int main()
{
	Vertex<3> vertex("1.0 -1.0 0.0");
	assert_equals(vertex.getUsedComponents(), 3);
	assert_equals(vertex[0], 1.0f);
	assert_equals(vertex[1], -1.0f);
	assert_equals(vertex[2], 0.0f);
	float buffer[3];
	vertex.toBuffer(buffer, 3);
	assert_equals(buffer[0], 1.0f);
	assert_equals(buffer[1], -1.0f);
	assert_equals(buffer[2], 0.0f);
	std::cout << "Tests passed." << std::endl;
	return 0;
}
