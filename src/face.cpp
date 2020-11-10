#include "obj_parser/face.hpp"

void Face::addPoint(const Point &point) { points.push_back(point); }

int Face::getPointCount() const { return points.size(); }

const Point &Face::getPoint(int index) const { return points.at(index); }