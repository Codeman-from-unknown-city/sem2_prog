#pragma once

#include "../interfaces/Shape.h"

namespace geometry {
    class RegularPolygon: public Shape {
    public:
        RegularPolygon(unsigned n_sides, double side_len);
        ~RegularPolygon();

        RegularPolygon(const RegularPolygon& regular_polygon);
        RegularPolygon& operator=(const RegularPolygon& regular_polygon);

        double getArea() override;
        double getPerimeter() override;

    private:
        unsigned n_sides;
        double side_len;
    };
}