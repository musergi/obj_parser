#include "obj_parser/line_parser.hpp"

#define REGEX_V R"(v( [+-]?\d+\.\d+){3})"
#define REGEX_VN R"(vn( [+-]?\d+\.\d+){3})"
#define REGEX_F R"(f( \d+\/\d*\/\d*){3})"

LineParser::LineParser()
{
	parsers[REGEX_V] = &parseGeometricVertex;
	parsers[REGEX_VN] = &parseVertexNormal;
	parsers[REGEX_F] = &parseFace;
}

void LineParser::parse(const std::string &line, ObjContent *content) const
{
    for (auto const &parser : parsers)
    {
        if (std::regex_match(line, std::regex(parser.first)))
        {
            parser.second(line.c_str(), content);
            return;
        }
    }
}

void LineParser::parseGeometricVertex(const std::string &line,
	ObjContent *content)
{
    const char *sub_line = strchr(line.c_str(), ' ') + 1;
    content->addGeometricVertex(Vertex<4>(sub_line));
}

void LineParser::parseVertexNormal(const std::string &line, ObjContent *content)
{
    const char *sub_line = strchr(line.c_str(), ' ') + 1;
    content->addVertexNormal(Vertex<3>(sub_line));
}

void LineParser::parseFace(const std::string &line, ObjContent *content)
{
	Face face;
	const char *line_str = line.c_str();
    while((line_str = std::strchr(line_str + 1, ' ')) != NULL)
    {
    	unsigned int v, vt, vn;
        sscanf(line_str + 1, "%u/%u/%u", &v, &vt, &vn);
        face.addPoint(Point(v - 1, vt - 1, vn - 1));
    }
    content->addFace(face);
}
