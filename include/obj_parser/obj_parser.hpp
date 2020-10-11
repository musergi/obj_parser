#pragma once

#include "obj_content.hpp"
#include "vertex_parser.hpp"
#include "face_parser.hpp"

class ObjParser {
private:
	ObjContent *obj_content;

public:
	ObjParser(ObjContent *obj_content);
	void parse(const char *path);

private:
	void parseLine(const std::string &line);
	void parseVertex(const std::string &line);
	void parseFace(const std::string &line);
};
