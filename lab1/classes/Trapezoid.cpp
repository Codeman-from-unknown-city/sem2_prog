#include <cmath>

#include "Trapezoid.h"
#include "../lib/extended_math.h"

geometry::Trapezoid::Trapezoid(double a, double b, double c, double d)
    : a(a)
    , b(b)
    , c(c)
    , d(d)
{}

geometry::Trapezoid::~Trapezoid() = default;

geometry::Trapezoid::Trapezoid(const geometry::Trapezoid &trapezoid)
    : a(trapezoid.a)
    , b(trapezoid.b)
    , c(trapezoid.c)
    , d(trapezoid.d)
{}

geometry::Trapezoid &geometry::Trapezoid::operator=(const geometry::Trapezoid &trapezoid) {
    if (this != &trapezoid) {
        a = trapezoid.a;
        b = trapezoid.b;
        c = trapezoid.c;
        d = trapezoid.d;
    }
    return *this;
}


double geometry::Trapezoid::getPerimeter() {
    return a + b + c + d;
}

double geometry::Trapezoid::getArea() {
    return (a + b) / 2 * calcHeight();
}

double geometry::Trapezoid::calcHeight() const {
    return std::sqrt(exmath::sqr(c) - exmath::sqr(
            (exmath::sqr(a - b) + exmath::sqr(c) - exmath::sqr(d)) / (2 * (a - b))
    ));
}
