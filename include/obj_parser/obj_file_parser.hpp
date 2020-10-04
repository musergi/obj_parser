#pragma once

#include <fstream>
#include <string>
#include "obj_content.hpp"
#include "line_parser.hpp"

class ObjFileParser
{
private:
    ObjContent *m_obj_content;
    LineParser m_line_parser;

public:
    ObjFileParser(ObjContent *obj_content);
    void parse(const char *path);
};
