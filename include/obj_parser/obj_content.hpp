#pragma once

#include <vector>
#include "vertex_data.hpp"
#include "face.hpp"

class ObjContent {
public:
	void addFace(const Face &face);
	int getFaceCount() const;
	const Face &getFace(int index) const;
	VertexData vertex_data;

private:
	std::vector<Face> faces;
};
