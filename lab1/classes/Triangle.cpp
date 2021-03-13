#include <cmath>
#include <stdexcept>

#include "Triangle.h"

geometry::Triangle::Triangle(double a, double b, double c)
    : a(a)
    , b(b)
    , c(c)
{
    bool isValidTriangle = c < a + b && a < c + b && b < c + a
                           && c > 0 && a > 0 && b > 0;
    if (!isValidTriangle)
        throw std::runtime_error("Invalid triangle");
}

geometry::Triangle::~Triangle() = default;

geometry::Triangle::Triangle(const geometry::Triangle &other)
    : a(other.a)
    , b(other.b)
    , c(other.c)
{}

geometry::Triangle &geometry::Triangle::operator=(const geometry::Triangle &other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
        c = other.c;
    }
    return *this;
}

double geometry::Triangle::getPerimeter() {
    return a + b + c;
}

double geometry::Triangle::getArea() {
    double p = getPerimeter() / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}
