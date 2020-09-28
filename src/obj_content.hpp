#pragma once

#include <vector>
#include "geometric_vertex.hpp"
#include "vertex_normal.hpp"

class ObjContent
{
private:
    std::vector<GeometricVertex> m_geometric_vertices;

public:
    void addGeometricVertex(const GeometricVertex &geometric_vertex);
    const GeometricVertex &getGeometricVertex(int index) const;
};
