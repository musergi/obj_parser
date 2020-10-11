#pragma once

#include <vector>
#include "vertex_data.hpp"
#include "face.hpp"

class ObjContent {
public:
	VertexData vertex_data;
	std::vector<Face> faces;
};
