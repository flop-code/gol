#include "gol.h"
#include <raylib.h>

void draw_field(void) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if ((*cur)[i][j])
                DrawRectangleRounded(CELL_BOUNDS(i * CELL_SIZE, j * CELL_SIZE), 0.2, 0, RAYWHITE);
}

void draw_grid(void) {
    const Color color = ColorAlpha(RAYWHITE, 0.15);

    for (int i = 0; i < N; i++) {
        DrawRectangle(0, i * CELL_SIZE - 2, WINDOW_SIZE, 4, color);
        DrawRectangle(i * CELL_SIZE - 2, 0, 4, WINDOW_SIZE, color);
    }
}

void draw_pause(void) {
    static const int WIDTH = WINDOW_SIZE/16, HEIGHT = WINDOW_SIZE/13;
    static const int X = WINDOW_SIZE/2 - WIDTH/2, Y = WINDOW_SIZE*4/5 - HEIGHT/2;
    static const float ROUNDNESS = 0.6;
    const Color color = ColorAlpha(RAYWHITE, 0.6);

    DrawRectangleRounded((Rectangle){X, Y, WIDTH/3, HEIGHT}, ROUNDNESS, 0, color);
    DrawRectangleRounded((Rectangle){X + WIDTH * 2/3, Y, WIDTH/3, HEIGHT}, ROUNDNESS, 0, color);
}

void draw_help_alert(void) {
    static const char *msg = "[h] - Help";
    static const int font_size = WINDOW_SIZE / 47;
    const int msg_width = MeasureText(msg, font_size);
    
    DrawText(msg, WINDOW_SIZE - msg_width - font_size, WINDOW_SIZE - font_size*1.5, font_size, ColorAlpha(RAYWHITE, 0.3));
}

void draw_darker(void) {
    DrawRectangle(0, 0, WINDOW_SIZE, WINDOW_SIZE, ColorAlpha(BLACK, 0.75));
}

void draw_help(void) {
    static const char *MSGS[] = {
        "Hotkeys",

        "[c] - Clear the field",
        "[s] - Change the speed",
        "[z] - Change the field size",
        "[t] - Change the theme",

        "[h] - Back to the edit mode"
    };

    static const int FONT_SIZE = WINDOW_SIZE / 37;
    static const int MARGIN = WINDOW_SIZE / 25;
    static const int MSGS_N = sizeof(MSGS) / sizeof(MSGS[0]);

    DrawText(
        MSGS[0],
        WINDOW_SIZE/2 - MeasureText(MSGS[0], FONT_SIZE*1.5)/2,
        WINDOW_SIZE/3 - FONT_SIZE/2 - MARGIN,
        FONT_SIZE*1.5, ColorAlpha(RAYWHITE, 0.95)
    );

    for (int i = 1; i < MSGS_N - 1; i++) {
        DrawText(
            MSGS[i],
            WINDOW_SIZE/2 - MeasureText(MSGS[i], FONT_SIZE)/2,
            WINDOW_SIZE/3 - FONT_SIZE/2 + FONT_SIZE*i + MARGIN*i,
            FONT_SIZE, ColorAlpha(RAYWHITE, 0.95)
        );
    }

    DrawText(
        MSGS[MSGS_N - 1],
        WINDOW_SIZE/2 - MeasureText(MSGS[MSGS_N - 1], FONT_SIZE*2/3)/2,
        WINDOW_SIZE/3 + FONT_SIZE/2 + FONT_SIZE*(MSGS_N-1) + MARGIN*(MSGS_N-1),
        FONT_SIZE*2/3, ColorAlpha(RAYWHITE, 0.6)
    );
   
}
