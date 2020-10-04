#pragma once

#include <vector>
#include "vertex.hpp"
#include "face.hpp"

class ObjContent
{
private:
    std::vector<Vertex<4>> m_geometric_vertices;
    std::vector<Vertex<3>> m_vertex_normals;
    std::vector<Face> m_faces;

public:
    ObjContent();
    ObjContent(const char *path);
    void addGeometricVertex(const Vertex<4> &geometric_vertex);
    void addVertexNormal(const Vertex<3> &vertex_normal);
    void addFace(const Face &face);
    const Vertex<4> &getGeometricVertex(int index) const;
    const Vertex<3> &getVertexNormal(int index) const;
    const std::string to_string() const;

private:
    template <class T>
    static void addVectorToInputStringStream(std::ostringstream &ss,
        const std::vector<T> &vector);
};
