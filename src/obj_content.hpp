#pragma once

#include <vector>
#include "geometric_vertex.hpp"
#include "vertex_normal.hpp"

class ObjContent
{
private:
    std::vector<GeometricVertex> m_geometric_vertices;
    std::vector<VertexNormal> m_vertex_normals;

public:
    void addGeometricVertex(const GeometricVertex &geometric_vertex);
    const GeometricVertex &getGeometricVertex(int index) const;
    void addVertexNormal(const VertexNormal &vertex_normal);
    const VertexNormal &getVertexNormal(int index) const;
};
