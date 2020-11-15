#pragma once

#include <istream>
#include <vector>

class Point {
  public:
    unsigned int vp, vt, vn;
    Point() : vp(0), vt(0), vn(0){};
    Point(const Point &point) = default;
    inline bool operator==(const Point &other) const {
        return vp == other.vp && vt == other.vt && vn == other.vn;
    }
};

class ObjParser {
  public:
    ObjParser(std::istream &input_stream);
    size_t getGLArrayBufferSize() const;
    size_t getGLElementArrayBufferSize() const;
    void toGLArrayBuffer(float *buffer, size_t buffer_size);
    void toGLElementArrayBuffer(unsigned int *buffer, size_t buffer_size);

  private:
    std::vector<float> positions;
    std::vector<float> textures;
    std::vector<float> normals;
    std::vector<Point> unique_points;
    std::vector<unsigned int> indices;
    bool findAndAddIndex(const Point &point);
};
