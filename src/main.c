#include "gol.h"
#include <raylib.h>

void (*loop)(void) = &edit_field;

int main(void) {
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(60);
    InitWindow(WINDOW_SIZE, WINDOW_SIZE, "Game Of Life");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        (*loop)();
        if (IsKeyPressed(KEY_SPACE))
            loop = (loop == &simulate ? &edit_field : &simulate);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
