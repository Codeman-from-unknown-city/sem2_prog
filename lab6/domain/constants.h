#pragma once

namespace game {
    const int N_EDGES = 6;
    const int CUBE_HEIGHT = 3;
    const int CUBE_WIDTH = 3;

    enum COLORS {
        GREEN,
        BLUE,
        RED,
        YELLOW,
        WHITE,
        ORANGE
    };

    enum ROTATE_DIRECTION {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    enum EDGE_POSITION {
        BACK_EDGE,
        LEFT_EDGE,
        FRONT_EDGE,
        UP_EDGE,
        RIGHT_EDGE,
        DOWN_EDGE
    };

    enum LINE_POSITION {
        LEFT_VERTICAL,
        UPPER_HORIZONTAL,
        RIGHT_VERTICAL,
        LOWER_HORIZONTAL
    };
}
