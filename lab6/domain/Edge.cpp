#include "Edge.h"

game::Edge::Edge(EDGE_POSITION pos, COLORS color)
        : squares(3, std::vector<COLORS>(3, color))
        , pos(pos)
{}

game::EDGE_POSITION game::Edge::left_neigh() const
{
    switch (pos) {
        case FRONT_EDGE:
        case UP_EDGE:
        case DOWN_EDGE:
            return LEFT_EDGE;
        case BACK_EDGE:
            return RIGHT_EDGE;
        case LEFT_EDGE:
            return BACK_EDGE;
        case RIGHT_EDGE:
            return FRONT_EDGE;
    }
}

game::EDGE_POSITION game::Edge::right_neigh() const
{
    switch (pos) {
        case FRONT_EDGE:
        case DOWN_EDGE:
        case UP_EDGE:
            return RIGHT_EDGE;
        case LEFT_EDGE:
            return FRONT_EDGE;
        case BACK_EDGE:
            return LEFT_EDGE;
        case RIGHT_EDGE:
            return BACK_EDGE;
    }
}

game::EDGE_POSITION game::Edge::up_neigh() const
{
    switch (pos) {
        case BACK_EDGE:
        case LEFT_EDGE:
        case RIGHT_EDGE:
        case FRONT_EDGE:
            return UP_EDGE;
        case UP_EDGE:
            return BACK_EDGE;
        case DOWN_EDGE:
            return FRONT_EDGE;
    }
}

game::EDGE_POSITION game::Edge::down_neigh() const
{
    switch (pos) {
        case FRONT_EDGE:
        case LEFT_EDGE:
        case RIGHT_EDGE:
        case BACK_EDGE:
            return DOWN_EDGE;
        case UP_EDGE:
            return FRONT_EDGE;
        case DOWN_EDGE:
            return BACK_EDGE;
    }
}
