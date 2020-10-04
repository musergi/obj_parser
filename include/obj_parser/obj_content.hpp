#pragma once

#include <vector>
#include "vertex.hpp"
#include "face.hpp"

class ObjContent
{
private:
    std::vector<Vertex<4>> geometric_vertices;
    std::vector<Vertex<3>> texture_vertices;
    std::vector<Vertex<3>> vertex_normals;
    std::vector<Face> faces;

public:
    ObjContent();
    ObjContent(const char *path);
    int getGeometricVertexCount() const;
    int getTextureVertexCount() const;
    int getVertexNormalCount() const;
    void addGeometricVertex(const Vertex<4> &geometric_vertex);
    void addTextureVertex(const Vertex<3> &texture_vertex);
    void addVertexNormal(const Vertex<3> &vertex_normal);
    void addFace(const Face &face);
    const Vertex<4> &getGeometricVertex(int index) const;
    const Vertex<3> &getTextureVertex(int index) const;
    const Vertex<3> &getVertexNormal(int index) const;
    const Face &getFace(int index) const;
    const std::string to_string() const;

private:
    template <class T>
    static void addVectorToInputStringStream(std::ostringstream &ss,
        const std::vector<T> &vector);
};
