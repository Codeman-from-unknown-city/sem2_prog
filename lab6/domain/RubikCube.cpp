#include "RubikCube.h"

game::RubikCube::RubikCube()
{
    EDGE_POSITION edge_pos;
    COLORS edge_color;
    for (int i = 0; i < N_EDGES; ++i) {
        edge_pos = static_cast<EDGE_POSITION>(i);
        edge_color = static_cast<COLORS>(i);
        edges.emplace_back(edge_pos, edge_color);
    }
}
