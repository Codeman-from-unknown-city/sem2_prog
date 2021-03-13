#include "BrokenLine.h"

#include <utility>
#include <stdexcept>

geometry::BrokenLine::BrokenLine(geometry::Points points): points(std::move(points)) {
    deleteDuplicatePoints(this->points);
    if (!checkOnNull(this->points))
        throw std::runtime_error("Points shouldn\'t be null");
    if (!checkN(this->points))
        throw std::runtime_error("The number of points must be more than 2");
}

void geometry::BrokenLine::deleteDuplicatePoints(geometry::Points &points) {
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
}

bool geometry::BrokenLine::checkOnNull(const geometry::Points &points) {
    return std::all_of(points.begin(), points.end(), [](const Point* point) {return point != nullptr;});
}

bool geometry::BrokenLine::checkN(const geometry::Points &points) {
    return points.size() > 2;
}
