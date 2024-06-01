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
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
