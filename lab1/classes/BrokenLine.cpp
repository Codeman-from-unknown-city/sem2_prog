#include "BrokenLine.h"

#include <utility>
#include <stdexcept>

geometry::BrokenLine::BrokenLine(geometry::Points points): points(std::move(points)) {
    deleteDuplicatePoints(this->points);
    if (this->points.size() > 2)
        throw std::runtime_error("The number of points must be more than 2");
}

geometry::BrokenLine::BrokenLine(const geometry::BrokenLine &other): points(other.points)
{}

geometry::BrokenLine& geometry::BrokenLine::operator=(const geometry::BrokenLine &other) {
    if (this != &other)
        points = other.points;
    return *this;
}

void geometry::BrokenLine::deleteDuplicatePoints(geometry::Points &points) {
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
}

const geometry::Points& geometry::BrokenLine::getPoints() const {
    return points;
}

double geometry::BrokenLine::calcLen() const {
    double len = 0;
    for (size_t i = 0; i < points.size() - 1; i++)
        len += points[i].distTo(points[i + 1]);
    return len;
}
