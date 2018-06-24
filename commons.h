#pragma once

class Commons {

public:

    // RIGHT: do not reverse the coordinates
    // LEFT: reverse the coordinates
    enum FieldSide {
        RIGHT,
        LEFT
    };
    enum Color {
        YELLOW,
        BLUE
    };
    enum Size {
        SUPER_VERY_SMALL    = 32, //MELHORAR ESSE NOME
        VERY_SMALL          = 64,
        SMALL               = 128,
        MEDIUM              = 256,
        LARGE               = 512,
        VERY_LARGE          = 1024
    };

    enum Ui {
        WINDOW_WIDTH          = 691,
        WINDOW_HEIGHT         = 461,
        MATCH_FIELD_WIDTH     = 691,
        MATCH_FIELD_HEIGHT    = 461,
        FIELD_PLAYABLE_WIDTH  = 564,
        FIELD_PLAYABLE_HEIGHT = 410,
    };
};
