#pragma once

#include <vector>
#include "geometric_vertex.hpp"
#include "vertex_normal.hpp"
#include "face.hpp"

class ObjContent
{
private:
    std::vector<GeometricVertex> m_geometric_vertices;
    std::vector<VertexNormal> m_vertex_normals;
    std::vector<Face> m_faces;

public:
    ObjContent();
    ObjContent(const char *path);
    void addGeometricVertex(const GeometricVertex &geometric_vertex);
    const GeometricVertex &getGeometricVertex(int index) const;
    void addVertexNormal(const VertexNormal &vertex_normal);
    const VertexNormal &getVertexNormal(int index) const;
    void addFace(const Face &face);
    const std::string to_string() const;

private:
    template <class T>
    static void addVectorToInputStringStream(std::ostringstream &ss,
        const std::vector<T> &vector);
};
