#include "obj_content.hpp"
#include <iostream>

ObjContent::ObjContent(const char *path)
{
    std::string line;
    std::ifstream input_file_stream(path);
    while (std::getline(input_file_stream, line))
    {
        if (std::regex_match(line, std::regex("v( -?\\d+.\\d+){3,4}")))
        {
            float x, y, z;
            std::sscanf(line.c_str(), "v %f %f %f", &x, &y, &z);
            addGeometricVertex(GeometricVertex(x, y, z));
        }
        else if (std::regex_match(line, std::regex("vn( -?\\d+.\\d+){3}")))
        {
            float i, j, k;
            std::sscanf(line.c_str(), "vn %f %f %f", &i, &j, &k);
            addVertexNormal(VertexNormal(i, j, k));
        }
    }
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

const std::string ObjContent::to_string() const
{
    std::ostringstream ss;
    ss << "(";
    ObjContent::addVectorToInputStringStream(ss, m_geometric_vertices);
    ss << ", ";
    ObjContent::addVectorToInputStringStream(ss, m_vertex_normals);
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
