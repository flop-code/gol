#include "gol.h"
#include <raylib.h>
#include <stdio.h>

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

bool eval_cell(int cx, int cy) {
    int nbors = -(*cur)[cx][cy];
    
    for (int dx = -1; dx < 2; dx++)
        for (int dy = -1; dy < 2; dy++)
            nbors += (*cur)[IN_BOUNDS(cx+dx)][IN_BOUNDS(cy+dy)];

    return (nbors == 3 || (nbors == 2 && (*cur)[cx][cy]));
}

void eval_state(void) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            (*next)[i][j] = eval_cell(i, j);
}

void simulate(void) {
    if (GetTime() - last_simulation_time >= 1.0/FPS) {
        eval_state();
        PTR_SWAP(next, cur);

        last_simulation_time = GetTime();
    }
    
    draw_field();
}

void edit_field(void) {
    draw_field();
    draw_grid();

    if (IsWindowFocused()) {
        int m_pos_x = GetMouseX(), m_pos_y = GetMouseY();
        if (m_pos_x >= 0 && m_pos_x < WINDOW_SIZE && m_pos_y >= 0 && m_pos_y < WINDOW_SIZE) {
            int cell_x = m_pos_x / CELL_SIZE, cell_y = m_pos_y / CELL_SIZE;
            
            if (cell_x >= 0 && cell_x < N && cell_y >= 0 && cell_y < N) {
                Color color = (*cur)[cell_x][cell_y] ? ColorAlpha(BLACK, 0.3) : ColorAlpha(RAYWHITE, 0.4);

                DrawRectangleRounded(CELL_BOUNDS(cell_x * CELL_SIZE, cell_y * CELL_SIZE), 0.2, 0, color);
                
                if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                    (*cur)[cell_x][cell_y] = true;
                } else if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
                    (*cur)[cell_x][cell_y] = false;
                }
            }
        }
    }

    draw_pause();
}

int main(void) {
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(60);
    InitWindow(WINDOW_SIZE, WINDOW_SIZE, "Game Of Life");
    
    loop = &edit_field;

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
