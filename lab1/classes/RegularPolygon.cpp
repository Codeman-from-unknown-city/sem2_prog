#include <cmath>
#include <stdexcept>

#include "../lib/extended_math.h"
#include "RegularPolygon.h"

geometry::RegularPolygon::RegularPolygon(unsigned int n_sides, double side_len)
        : n_sides(n_sides)
        , side_len(side_len)
{
    if (n_sides < 3 && side_len < 1)
        throw std::runtime_error("Invalid regular polygon");
}

geometry::RegularPolygon::~RegularPolygon() = default;

double geometry::RegularPolygon::getArea() {
    return (double) n_sides / 4 * exmath::sqr(side_len) * ((double)1 / tan(M_PI / n_sides));
}

double geometry::RegularPolygon::getPerimeter() {
    return n_sides * side_len;
}

geometry::RegularPolygon::RegularPolygon(const geometry::RegularPolygon &regular_polygon)
    : n_sides(regular_polygon.n_sides)
    , side_len(regular_polygon.side_len)
{}

geometry::RegularPolygon&
geometry::RegularPolygon::operator=(const geometry::RegularPolygon &regular_polygon) {
    if (this != &regular_polygon) {
        n_sides = regular_polygon.n_sides;
        side_len = regular_polygon.side_len;
    }
    return *this;
}
