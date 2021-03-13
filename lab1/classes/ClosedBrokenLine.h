#pragma once

#include "BrokenLine.h"

namespace geometry {
    class ClosedBrokenLine : public BrokenLine {
    public:
        explicit ClosedBrokenLine(Points points);

    private:
        static bool isOnOneLie(Point& p1, Point& p2, Point& p3);
    };
}
