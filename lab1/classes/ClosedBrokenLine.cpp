#include <utility>

#include "ClosedBrokenLine.h"

geometry::ClosedBrokenLine::ClosedBrokenLine(Points points): BrokenLine(std::move(points))
{}

geometry::ClosedBrokenLine::ClosedBrokenLine(const geometry::ClosedBrokenLine& other)
    : BrokenLine(other.points)
{}

geometry::ClosedBrokenLine& 
geometry::ClosedBrokenLine::operator=(const geometry::ClosedBrokenLine& other) {
    if (this != &other)
        points = other.points;
    return *this;
}

double geometry::ClosedBrokenLine::calcLen() const {
    return BrokenLine::calcLen() + points[0].distTo(points[points.size() - 1]);
}
