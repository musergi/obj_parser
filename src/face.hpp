#pragma once

#include <string>
#include <sstream>
#include <vector>

class Point
{
private:
    unsigned int m_geometric_vertex, m_texture_vertex, m_vertex_normal;

public:
    Point(unsigned int geometric_vertex, unsigned int texture_vertex=-1,
        unsigned int vertex_normal=-1);
    bool hasTextureVertex() const;
    bool hasVertexNormal() const;
    unsigned int getGeometricVertex() const;
    unsigned int getTextureVertex() const;
    unsigned int getVertexNormal() const;
    const std::string to_string() const;
};

class Face
{
private:
    std::vector<Point> m_points;
public:
    Face();
    void addPoint(const Point &point);
    int getNumberPoints() const;
    const Point &getPoint(int index) const;
    const std::string to_string() const;
};
