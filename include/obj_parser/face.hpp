#pragma once

#include <vector>
#include "point.hpp"

class Face {
  public:
    void addPoint(const Point &point);
    int getPointCount() const;
    const Point &getPoint(int index) const;

  private:
    std::vector<Point> points;
};
