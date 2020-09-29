#include "obj_content.hpp"

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
