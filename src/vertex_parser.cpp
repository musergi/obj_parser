#include "obj_parser/vertex_parser.hpp"

VertexParser::VertexParser(const std::string &vertex_string)
	: content_offset(0)
{
	std::size_t space_pos = vertex_string.find(" ");
	vertex_type = vertex_string.substr(0, space_pos);
	vertex_content = vertex_string.substr(space_pos + 1);
}

bool VertexParser::hasFloat() const
{
	return content_offset < vertex_content.size();
}


const std::string &VertexParser::getType() const
{
	return vertex_type;
}

float VertexParser::getNextFloat()
{
	std::size_t next_space_offset;
	float next_float = std::stof(
			vertex_content.substr(content_offset),
			&next_space_offset);
	content_offset += next_space_offset + 1;
	return next_float;
}
