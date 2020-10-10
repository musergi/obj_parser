#pragma once

#include <cstring>
#include <string>
#include "point.hpp"

class FaceParser {
private:
	const std::string face_string;
	std::size_t point_offset;
	std::size_t point_length;

public:
	FaceParser(const std::string &face_string);
	bool hasPoint() const;
	const Point nextPoint();

private:
	void movePointers();
	static const Point parsePoint(const std::string &point_string);
};
