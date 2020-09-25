#pragma once

class GeometricVertex
{
private:
    float m_x, m_y, m_z, m_w;

public:
    GeometricVertex(float x, float y, float z, float w = 1.0f);
};