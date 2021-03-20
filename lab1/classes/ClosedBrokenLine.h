#pragma once

#include "BrokenLine.h"

namespace geometry {
    class ClosedBrokenLine : public BrokenLine {
    public:
        explicit ClosedBrokenLine(Points points);
        ClosedBrokenLine(const ClosedBrokenLine& other);
        ClosedBrokenLine& operator=(const ClosedBrokenLine& other);

        double calcLen() const;
    };
}
