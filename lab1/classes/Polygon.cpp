#include <functional>
#include <utility>

#include "Polygon.h"

geometry::Polygon::Polygon(geometry::Points points) : ClosedBrokenLine(std::move(points)) {
    if (!isConvex(points))
        throw std::runtime_error("Only convex polygon supported");
}

geometry::Polygon::~Polygon() = default;

geometry::Polygon::Polygon(const geometry::Polygon &polygon): ClosedBrokenLine(polygon.points)
{}

geometry::Polygon &geometry::Polygon::operator=(const geometry::Polygon &polygon) {
    if (this != &polygon)
        points = polygon.points;
    return *this;
}

double geometry::Polygon::calcCrossProduct(const geometry::Point &a, const geometry::Point &b, const geometry::Point &c) {
    double BAx = a.x - b.x;
    double BAy = a.y - b.y;
    double BCx = c.x - b.x;
    double BCy = c.y - b.y;
    return (BAx * BCy - BAy * BCx);
}

bool geometry::Polygon::isConvex(Points &points) {
    bool neg = false;
    bool pos = false;
    int n = points.size();
    for(int i = 0; i < n; i++){
        int a = i;
        int b = (i + 1) % n;
        int c = (i + 2) % n;
        double crossProduct = calcCrossProduct(*points[a], *points[b], *points[c]);
        if(crossProduct < 0)
            neg = true;
        else if(crossProduct > 0)
            pos = true;
        if(neg && pos)
            return false;
    }
    return true;
}

double geometry::Polygon::getPerimeter() {
    double perimeter = 0;
    int n_elems = points.size();
    for (int i = 0; i < n_elems - 1; ++i)
        perimeter += points[i]->distTo(*points[i + 1]);
    perimeter += points[0]->distTo(*points[n_elems - 1]);
    return perimeter;
}

double geometry::Polygon::getArea() {
    double area = 0;
    int n = points.size();
    int j = n - 1;
    Point* p1;
    Point* p2;
    for (int i = 0; i < n; ++i) {
        p1 = points[i];
        p2 = points[j];
        area += (p1->x + p2->x) * (p1->y - p2->y);
        j = i;
    }
    return std::abs(area / 2.0);
}
