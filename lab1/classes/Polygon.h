#pragma once

#include "ClosedBrokenLine.h"
#include "../interfaces/Shape.h"

namespace geometry {
    class Polygon: public Shape {
    public:
        explicit Polygon(const ClosedBrokenLine &line);
        ~Polygon();

        Polygon(const Polygon &polygon);
        Polygon& operator=(const Polygon& polygon);

        double getPerimeter() override;
        double getArea() override;

    private:
        static double calcCrossProduct(const Point &a, const Point &b, const Point &c) ;
        static bool isConvex(const Points &points);
        ClosedBrokenLine line;
    };
}
