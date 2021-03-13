#pragma once

#include "../interfaces/Shape.h"

namespace geometry {
    class Trapezoid : public Shape {
    public:
        Trapezoid(double a, double b, double c, double d);
        ~Trapezoid();

        Trapezoid(const Trapezoid& trapezoid);
        Trapezoid& operator=(const Trapezoid& trapezoid);

        double getPerimeter() override;
        double getArea() override;

    private:
        double a, b, c, d;
        double calcHeight() const;
    };
}
