#pragma once

#include <map>
#include <regex>
#include <string>
#include "obj_content.hpp"

class LineParser
{
    std::map<std::string, void (*)(const char*, ObjContent *)> m_parsers;
public:
    LineParser();
    void parse(const std::string &line, ObjContent *content) const;

private:
    static void parseGeometricVertex(const char *line, ObjContent *content);
    static void parseVertexNormal(const char *line, ObjContent *content);
};
