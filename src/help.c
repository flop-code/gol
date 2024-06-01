#include "gol.h"
#include <raylib.h>

void help(void) {
    draw_field();
    draw_grid();
    draw_pause();
    draw_darker();
    draw_help();

    if (IsKeyPressed(KEY_H))
        loop = &edit_field;
}
