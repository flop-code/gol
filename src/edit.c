#include "gol.h"
#include <raylib.h>

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
