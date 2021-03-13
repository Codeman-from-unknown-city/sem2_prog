#include <cmath>

#include "Point.h"
#include "../lib/extended_math.h"

geometry::Point::Point(double x, double y)
  : x(x)
  , y(y)
{}

geometry::Point::~Point() = default;

geometry::Point::Point(const Point &other)
  : x(other.x)
  , y(other.y)
{}

geometry::Point& geometry::Point::operator=(const Point &other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

double geometry::Point::distTo(const Point &other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(exmath::sqr(dx) + exmath::sqr(dy));
}
