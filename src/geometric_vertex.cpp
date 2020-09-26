#include "geometric_vertex.hpp"

GeometricVertex::GeometricVertex(float x, float y, float z, float w)
    : m_x(x), m_y(y), m_z(z), m_w(w)
{
}

bool GeometricVertex::operator==(GeometricVertex other)
{
    return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z
        && m_w == other.m_w;
}