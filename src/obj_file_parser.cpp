#include "obj_parser/obj_file_parser.hpp"

ObjFileParser::ObjFileParser(ObjContent *obj_content)
	: m_obj_content(obj_content)
{
}

void ObjFileParser::parse(const char *path)
{
	std::ifstream input_file_stream(path);
	std::string line;
	while (std::getline(input_file_stream, line))
	{
		m_line_parser.parse(line, m_obj_content);
	}
}
