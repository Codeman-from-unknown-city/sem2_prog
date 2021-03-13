#include <functional>
#include <utility>

#include "ClosedBrokenLine.h"

geometry::ClosedBrokenLine::ClosedBrokenLine(Points points): BrokenLine(std::move(points)) {
    Point* first = this->points[0];
    Point* second = this->points[1];
    Point* prev_last = this->points[this->points.size() - 2];
    if (isOnOneLie(*first, *second, *prev_last))
        throw std::runtime_error("The segments p1 - p2 and pN-1 - pN must not lie on one straight line");
}

bool geometry::ClosedBrokenLine::isOnOneLie(geometry::Point &p1, geometry::Point &p2, geometry::Point &p3) {
    return (p3.x - p1.x) / (p2.x - p1.x) == (p3.y - p1.y) / (p2.y - p1.y);
}
