#include "gol.h"
#include <raylib.h>

void draw_field(void) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if ((*cur)[i][j])
                DrawRectangleRounded(CELL_BOUNDS(i * CELL_SIZE, j * CELL_SIZE), 0.2, 0, RAYWHITE);
}

void draw_grid(void) {
    Color color = ColorAlpha(RAYWHITE, 0.15);

    for (int i = 0; i < N; i++) {
        DrawRectangle(0, i * CELL_SIZE - 2, WINDOW_SIZE, 4, color);
        DrawRectangle(i * CELL_SIZE - 2, 0, 4, WINDOW_SIZE, color);
    }
}

void draw_pause(void) {
    int width = WINDOW_SIZE/16, height = WINDOW_SIZE/13;
    int x = WINDOW_SIZE/2 - width/2, y = WINDOW_SIZE*4/5 - height/2;
    float roundness = 0.6;
    Color color = ColorAlpha(RAYWHITE, 0.6);

    DrawRectangleRounded((Rectangle){x, y, width/3, height}, roundness, 0, color);
    DrawRectangleRounded((Rectangle){x + width * 2/3, y, width/3, height}, roundness, 0, color);
}
