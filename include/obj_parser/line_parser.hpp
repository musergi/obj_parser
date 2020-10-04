#pragma once

#include <map>
#include <regex>
#include <string>
#include "obj_content.hpp"

class LineParser
{
    std::map<std::string, void (*)(const std::string &, ObjContent *)> parsers;
public:
    LineParser();
    void parse(const std::string &line, ObjContent *content) const;

private:
    static void parseGeometricVertex(const std::string &line,
    	ObjContent *content);
    static void parseVertexNormal(const std::string &line, ObjContent *content);
    static void parseFace(const std::string &line, ObjContent *content);
};
