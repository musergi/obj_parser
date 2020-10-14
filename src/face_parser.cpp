#include "obj_parser/face_parser.hpp"

#define DEFAULT_VT 0
#define DEFAULT_VN 0

FaceParser::FaceParser(const std::string &face_string)
		: face_string(face_string) {
	point_offset = face_string.find(' ') + 1;
	point_length = face_string.find(' ', point_offset) - point_offset;
}

bool FaceParser::hasPoint() const {
	return point_offset < face_string.size();
}

const Point FaceParser::nextPoint() {
	unsigned int v, vt = 0, vn = 0;
	const Point point = parsePoint(
			face_string.substr(point_offset, point_length));
	movePointers();
	return point;
}

void FaceParser::movePointers() {
	point_offset += point_length + 1;
	std::size_t next_space = face_string.find(' ', point_offset);
	if (next_space != std::string::npos)
		point_length = next_space - point_offset;
	else
		point_length = face_string.size() - point_offset;
}

const Point FaceParser::parsePoint(const std::string &point_string) {
	unsigned int v, vt = 0, vn = 0;
	std::size_t offset;
	v = std::stoul(point_string, &offset);
	if (offset < point_string.size() - 1) {
		if (point_string.at(++offset) != '/') {
			std::size_t num_length;
			vt = std::stoul(point_string.substr(offset), &num_length);
			offset += num_length;
		}
		if (++offset < point_string.size()) {
			vn = std::stoul(point_string.substr(offset));
		}
	}
	return Point(v, vt, vn);
}
