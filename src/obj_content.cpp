#include "obj_content.hpp"

void ObjContent::addGeometricVertex(const GeometricVertex &geometric_vertex)
{
    m_geometric_vertices.push_back(geometric_vertex);
}

const GeometricVertex &ObjContent::getGeometricVertex(int index) const
{
    return m_geometric_vertices[index];
}
