#pragma once

#include "../interfaces/Shape.h"

namespace geometry {
    class Trapezoid : public Shape {
    public:
        Trapezoid(double base1, double base2, double side1, double side2);
        ~Trapezoid();

        Trapezoid(const Trapezoid& trapezoid);
        Trapezoid& operator=(const Trapezoid& trapezoid);

        double getPerimeter() override;
        double getArea() override;

    private:
        double base1, base2, side1, side2;
        double calcHeight() const;
    };
}
