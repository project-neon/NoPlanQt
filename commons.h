#ifndef COMMONS_H
#define COMMONS_H

class Commons
{
public:
    // RIGHT: do not reverse the coordinates
    // LEFT: reverse the coordinates
    enum FieldSide {RIGHT, LEFT};
    enum Color {YELLOW, BLUE};
    enum Sizes {

        SUPER_VERY_SMALL    = 32, //MELHORAR ESSE NOME
        VERY_SMALL          = 64,
        SMALL               = 128,
        MEDIUM              = 256,
        LARGE               = 512,
        VERY_LARGE          = 1024

    };

    enum Ui {

        WINDOW_WIDTH          = 1600,
        WINDOW_HEIGHT         = 990,
        MATCH_FIELD_WIDTH     = 1290,
        MATCH_FIELD_HEIGHT    = 990,
        FIELD_PLAYABLE_WIDTH  = 1045,
        FIELD_PLAYABLE_HEIGHT = 884,
        RIGHT_SIDE_GOAL_LINE  = 1170,
        LEFT_SIDE_GOAL_LINE   = 117,
        CONTROL_PANEL_WIDTH   = 310,
        CONTROL_PANEL_HEIGHT  = 990,

    };
};

#endif // COMMONS_H
