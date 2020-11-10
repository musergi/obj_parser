#pragma once

class Point {
  private:
    unsigned int vertices_pointers[3];

  public:
    Point(
        unsigned int geometric_vertex_pointer, unsigned int texture_vertex_pointer, unsigned int vertex_normal_pointer);
    bool hasTextureVertex() const;
    bool hasVertexNormal() const;
    unsigned int getGeometricVertexPointer() const;
    unsigned int getTextureVertexPointer() const;
    unsigned int getVertexNormalPointer() const;
};
