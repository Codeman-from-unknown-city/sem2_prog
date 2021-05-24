#pragma once

#include "constants.h"
#include "Edge.h"

namespace game {
    class RubikCube {
    public:
        RubikCube();

        void rotate(EDGE_POSITION edge_pos, LINE_POSITION pos, ROTATE_DIRECTION dir);

        void shuffle();

    private:
        std::vector<Edge> edges;
    };
}
