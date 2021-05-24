#pragma once

#include <vector>

#include "constants.h"

namespace game {
    class Edge {
    public:
        Edge(EDGE_POSITION pos, COLORS color);

        EDGE_POSITION left_neigh() const;
        EDGE_POSITION right_neigh() const;
        EDGE_POSITION up_neigh() const;
        EDGE_POSITION down_neigh() const;

    private:
        std::vector<std::vector<COLORS>> squares;
        EDGE_POSITION pos;
    };
}
