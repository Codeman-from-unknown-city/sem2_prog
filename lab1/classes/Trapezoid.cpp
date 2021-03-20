#include <cmath>

#include "Trapezoid.h"
#include "../lib/extended_math.h"

geometry::Trapezoid::Trapezoid(double base1, double base2, double side1, double side2)
    : base1(base1)
    , base2(base2)
    , side1(side1)
    , side2(side2)
{}

geometry::Trapezoid::~Trapezoid() = default;

geometry::Trapezoid::Trapezoid(const geometry::Trapezoid &trapezoid)
    : base1(trapezoid.base1)
    , base2(trapezoid.base2)
    , side1(trapezoid.side1)
    , side2(trapezoid.side2)
{}

geometry::Trapezoid &geometry::Trapezoid::operator=(const geometry::Trapezoid &trapezoid) {
    if (this != &trapezoid) {
        base1 = trapezoid.base1;
        base2 = trapezoid.base2;
        side1 = trapezoid.side1;
        side2 = trapezoid.side2;
    }
    return *this;
}


double geometry::Trapezoid::getPerimeter() {
    return base1 + base2 + side1 + side2;
}

double geometry::Trapezoid::getArea() {
    return (base1 + base2) / 2 * calcHeight();
}

double geometry::Trapezoid::calcHeight() const {
    return std::sqrt(exmath::sqr(side1) - exmath::sqr(
            (exmath::sqr(base1 - base2) + exmath::sqr(side1) - exmath::sqr(side2)) / (2 * (base1 - base2))
    ));
}
