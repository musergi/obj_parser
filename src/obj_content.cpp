#include "obj_parser/obj_content.hpp"
#include "obj_parser/obj_file_parser.hpp"

ObjContent::ObjContent() = default;

ObjContent::ObjContent(const char *path)
{
	ObjFileParser obj_file_parser(this);
    obj_file_parser.parse(path);
}

void ObjContent::addGeometricVertex(const Vertex<4> &geometric_vertex)
{
    m_geometric_vertices.push_back(geometric_vertex);
}

void ObjContent::addVertexNormal(const Vertex<3> &vertex_normal)
{
    m_vertex_normals.push_back(vertex_normal);
}

void ObjContent::addFace(const Face &face)
{
    m_faces.push_back(face);
}

const Vertex<4> &ObjContent::getGeometricVertex(int index) const
{
    return m_geometric_vertices[index];
}

const Vertex<3> &ObjContent::getVertexNormal(int index) const
{
    return m_vertex_normals[index];
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
