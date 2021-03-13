#pragma once

#include <vector>

#include "Point.h"

namespace geometry {
    using Points = std::vector<Point*>;

    class BrokenLine {
    public:
        explicit BrokenLine(Points points);

    private:
        static bool checkN(const Points& points);
        static bool checkOnNull(const Points& points);
        static void deleteDuplicatePoints(Points& points);

    protected:
        Points points;
    };
}
