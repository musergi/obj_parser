#pragma once

#include <vector>
#include "vertex.hpp"

class VertexData {
  private:
    std::vector<Vertex<4>> geometric_vertices;
    std::vector<Vertex<3>> texture_vertices;
    std::vector<Vertex<3>> vertex_normals;

  public:
    unsigned int getGeometricVertexCount() const;
    unsigned int getTextureVertexCount() const;
    unsigned int getVertexNormalCount() const;
    void addGeometricVertex(const Vertex<4> &vertex);
    void addTextureVertex(const Vertex<3> &vertex);
    void addVertexNormal(const Vertex<3> &vertex);
    const Vertex<4> &getGeometricVertex(unsigned int pointer) const;
    const Vertex<3> &getTextureVertex(unsigned int pointer) const;
    const Vertex<3> &getVertexNormal(unsigned int pointer) const;
};
