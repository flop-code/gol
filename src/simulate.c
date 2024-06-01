#include "gol.h"
#include <raylib.h>

static bool buff1[N][N], buff2[N][N];
bool (*next)[N][N] = &buff1, (*cur)[N][N] = &buff2;

double last_simulation_time = 0;

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
    
    if (IsKeyPressed(KEY_SPACE))
            loop = &edit_field;

    draw_field();
}
