#pragma once

namespace geometry {
    class Point {
    public:
        double x;
        double y;

        Point(double x, double y);
        ~Point();

        Point(const Point& other);
        Point& operator=(const Point& other);

        double distTo(const Point& other) const;
    };

}
