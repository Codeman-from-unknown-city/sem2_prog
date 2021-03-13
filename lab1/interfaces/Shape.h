#pragma once

namespace geometry {
    class Shape {
    public:
        virtual double getPerimeter() = 0;
        virtual double getArea() = 0;
    };
}
