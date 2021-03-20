#pragma once

#include <vector>

#include "Point.h"

namespace geometry {
    using Points = std::vector<Point*>;

    class BrokenLine {
    public:
        explicit BrokenLine(Points points);
        BrokenLine(const BrokenLine& other);
        BrokenLine& operator=(const BrokenLine& other);

    private:
        static bool checkN(const Points& points);
        static bool checkOnNull(const Points& points);
        static void deleteDuplicatePoints(Points& points);

    protected:
        Points points;
    };
}
