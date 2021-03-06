#pragma once

#include <string>
#include <sstream>

class VertexNormal
{
private:
    float m_i, m_j, m_k;

public:
    VertexNormal(float i, float j, float k);
    bool operator==(const VertexNormal &other) const;
    const std::string to_string() const;
};
