#include "obj_parser/vertex_data.hpp"

unsigned int VertexData::getGeometricVertexCount() const { return geometric_vertices.size(); }

unsigned int VertexData::getTextureVertexCount() const { return texture_vertices.size(); }

unsigned int VertexData::getVertexNormalCount() const { return vertex_normals.size(); }

void VertexData::addGeometricVertex(const Vertex<4> &vertex) { geometric_vertices.push_back(vertex); }

void VertexData::addTextureVertex(const Vertex<3> &vertex) { texture_vertices.push_back(vertex); }

void VertexData::addVertexNormal(const Vertex<3> &vertex) { vertex_normals.push_back(vertex); }

const Vertex<4> &VertexData::getGeometricVertex(unsigned int pointer) const {
    return geometric_vertices.at(pointer - 1);
}

const Vertex<3> &VertexData::getTextureVertex(unsigned int pointer) const { return texture_vertices.at(pointer - 1); }

const Vertex<3> &VertexData::getVertexNormal(unsigned int pointer) const { return vertex_normals.at(pointer - 1); }
