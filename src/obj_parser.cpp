#include "obj_parser/obj_parser.hpp"
#include <fstream>
#include <iostream>

ObjParser::ObjParser(ObjContent *obj_content) : obj_content(obj_content) {
}

void ObjParser::parse(const char *path) {
	std::ifstream file(path);
	if (!file.is_open())
		throw std::runtime_error("File not found");
	std::string line;
	while (std::getline(file, line)) {
		parseLine(line);
	}
}

void ObjParser::parseLine(const std::string &line) {
	if (line.size() == 0)
		return;
	if (line.at(0) == 'v') {
		parseVertex(line);
	} else if (line.at(0) == 'f') {
		parseFace(line);
	}
}

void ObjParser::parseVertex(const std::string &line) {
	VertexParser vertex_parser(line);
	if (vertex_parser.getType() == "v") {
		const Vertex<4> vertex(vertex_parser);
		obj_content->vertex_data.addGeometricVertex(vertex);
	} else if (vertex_parser.getType() == "vt") {
		const Vertex<3> vertex(vertex_parser);
		obj_content->vertex_data.addTextureVertex(vertex);
	} else if (vertex_parser.getType() == "vn") {
		const Vertex<3> vertex(vertex_parser);
		obj_content->vertex_data.addVertexNormal(vertex);
	}
}

void ObjParser::parseFace(const std::string &line) {
	FaceParser face_parser(line);
	Face face;
	while (face_parser.hasPoint()) {
		face.addPoint(face_parser.nextPoint());
	}
	obj_content->faces.push_back(face);
}
