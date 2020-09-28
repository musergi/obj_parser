#include "vertex_normal.hpp"

VertexNormal::VertexNormal(float i, float j, float k)
    : m_i(i), m_j(j), m_k(k)
{
}

bool VertexNormal::operator==(const VertexNormal &other) const
{
    return m_i == other.m_i && m_j == other.m_j
        && m_k == other.m_k;
}

const std::string VertexNormal::to_string() const
{
    std::stringstream ss;
    ss << "(" << m_i << ", " << m_j << ", " << m_k << ")";
    return ss.str();
}
