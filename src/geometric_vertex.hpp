#pragma once

#include <string>
#include <sstream>

class GeometricVertex
{
private:
    float m_x, m_y, m_z, m_w;

public:
    GeometricVertex(float x, float y, float z, float w = 1.0f);
    bool operator==(GeometricVertex other) const;
    const std::string to_string() const;
};