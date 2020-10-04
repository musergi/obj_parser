#include "obj_parser/obj_content.hpp"
#include "obj_parser/obj_file_parser.hpp"

ObjContent::ObjContent() = default;

ObjContent::ObjContent(const char *path)
{
	ObjFileParser obj_file_parser(this);
    obj_file_parser.parse(path);
}

int ObjContent::getGeometricVertexCount() const
{
	return geometric_vertices.size();
}

int ObjContent::getTextureVertexCount() const
{
	return texture_vertices.size();
}

int ObjContent::getVertexNormalCount() const
{
	return vertex_normals.size();
}

void ObjContent::addGeometricVertex(const Vertex<4> &geometric_vertex)
{
    geometric_vertices.push_back(geometric_vertex);
}

void ObjContent::addTextureVertex(const Vertex<3> &texture_vertex)
{
	texture_vertices.push_back(texture_vertex);
}

void ObjContent::addVertexNormal(const Vertex<3> &vertex_normal)
{
    vertex_normals.push_back(vertex_normal);
}

void ObjContent::addFace(const Face &face)
{
    faces.push_back(face);
}

const Vertex<4> &ObjContent::getGeometricVertex(int index) const
{
    return geometric_vertices[index];
}

const Vertex<3> &ObjContent::getTextureVertex(int index) const
{
	return texture_vertices[index];
}

const Vertex<3> &ObjContent::getVertexNormal(int index) const
{
    return vertex_normals[index];
}


const std::string ObjContent::to_string() const
{
    std::ostringstream ss;
    ss << "(";
    ObjContent::addVectorToInputStringStream(ss, geometric_vertices);
    ss << ", ";
    ObjContent::addVectorToInputStringStream(ss, vertex_normals);
    ss << ", ";
    ObjContent::addVectorToInputStringStream(ss, faces);
    ss << ")";
    return ss.str();
}

template <class T>
void ObjContent::addVectorToInputStringStream(
        std::ostringstream &ss, const std::vector<T> &vector)
{
    ss << "[";
    for (int i = 0; i < vector.size(); i++)
    {
        if (i != 0)
            ss << ", ";
        ss << vector[i].to_string();
    }
    ss << "]";
}
