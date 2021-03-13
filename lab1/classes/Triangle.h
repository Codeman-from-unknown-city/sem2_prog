#pragma once

#include "../interfaces/Shape.h"

namespace geometry {
    class Triangle: public Shape {
    public:
        Triangle(double a, double b, double c);
        ~Triangle();

        Triangle(const Triangle& other);
        Triangle& operator=(const Triangle& other);

        double getPerimeter() override;
        double getArea() override;

    private:
        double a;
        double b;
        double c;
    };
}