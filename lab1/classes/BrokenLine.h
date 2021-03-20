#pragma once

#include <vector>

#include "Point.h"

namespace geometry {
    using Points = std::vector<Point>;

    class BrokenLine {
    public:
        explicit BrokenLine(Points points);
        BrokenLine(const BrokenLine& other);
        BrokenLine& operator=(const BrokenLine& other);

        const Points& getPoints() const;
        double calcLen() const;

    private:
        static void deleteDuplicatePoints(Points& points);

    protected:
        Points points;
    };
}
