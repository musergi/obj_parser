#include "line_parser.hpp"

#define REGEX_V R"(v( [+-]?\d+\.\d+){3})"
#define REGEX_VN R"(vn( [+-]?\d+\.\d+){3})"

LineParser::LineParser()
{
    m_parsers[REGEX_V] = &parseGeometricVertex;
    m_parsers[REGEX_VN] = &parseVertexNormal;
}

void LineParser::parse(const std::string &line, ObjContent *content) const
{
    for (auto const &parser : m_parsers)
    {
        if (std::regex_match(line, std::regex(parser.first)))
        {
            parser.second(line.c_str(), content);
            break;
        }
    }
}

void LineParser::parseGeometricVertex(const char *line, ObjContent *content)
{
    float x, y, z;
    sscanf(line, "v %f %f %f", &x, &y, &z);
    content->addGeometricVertex(GeometricVertex(x, y, z));
}

void LineParser::parseVertexNormal(const char *line, ObjContent *content)
{
    float i, j, k;
    sscanf(line, "vn %f %f %f", &i, &j, &k);
    content->addVertexNormal(VertexNormal(i, j, k));
}
