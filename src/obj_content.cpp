#include "obj_parser/obj_content.hpp"
#include "obj_parser/obj_file_parser.hpp"

ObjContent::ObjContent() = default;

ObjContent::ObjContent(const char *path)
{
	ObjFileParser obj_file_parser(this);
    obj_file_parser.parse(path);
}

void ObjContent::addGeometricVertex(const GeometricVertex &geometric_vertex)
{
    m_geometric_vertices.push_back(geometric_vertex);
}

const GeometricVertex &ObjContent::getGeometricVertex(int index) const
{
    return m_geometric_vertices[index];
}

void ObjContent::addVertexNormal(const VertexNormal &vertex_normal)
{
    m_vertex_normals.push_back(vertex_normal);
}

const VertexNormal &ObjContent::getVertexNormal(int index) const
{
    return m_vertex_normals[index];
}

void ObjContent::addFace(const Face &face)
{
    m_faces.push_back(face);
}

const std::string ObjContent::to_string() const
{
    std::ostringstream ss;
    ss << "(";
    ObjContent::addVectorToInputStringStream(ss, m_geometric_vertices);
    ss << ", ";
    ObjContent::addVectorToInputStringStream(ss, m_vertex_normals);
    ss << ", ";
    ObjContent::addVectorToInputStringStream(ss, m_faces);
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
