#include "face.hpp"

Point::Point(unsigned int geometric_vertex, unsigned int texture_vertex,
    unsigned int vertex_normal) : m_geometric_vertex(geometric_vertex),
    m_texture_vertex(texture_vertex), m_vertex_normal(vertex_normal)
{
}

bool Point::hasTextureVertex() const
{
    return m_texture_vertex < 0;
}

bool Point::hasVertexNormal() const
{
    return m_vertex_normal < 0;
}

unsigned int Point::getGeometricVertex() const
{
    return m_geometric_vertex;
}

unsigned int Point::getTextureVertex() const
{
    return m_texture_vertex;
}

unsigned int Point::getVertexNormal() const
{
    return m_vertex_normal;
}

const std::string Point::to_string() const
{
    std::ostringstream ss;
    ss << "(" << m_geometric_vertex << ", " << m_texture_vertex
        << ", " << m_vertex_normal << ")";
    return ss.str();
}

int Face::getNumberPoints() const
{
    return (int) m_points.size();
}

void Face::addPoint(const Point &point)
{
    m_points.push_back(point);
}

const Point &Face::getPoint(int index) const
{
    return m_points[index];
}