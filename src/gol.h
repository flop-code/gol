#ifndef gol_h
#define gol_h

#include <stdbool.h>

#define FPS 10.0
#define N 25
#define WINDOW_SIZE 900
#define CELL_SIZE (WINDOW_SIZE/N)

#define PTR_SWAP(x, y) ((x)=(__typeof__(x))((uintptr_t)(x)^(uintptr_t)(y)),\
                        (y)=(__typeof__(y))((uintptr_t)(x)^(uintptr_t)(y)),\
                        (x)=(__typeof__(x))((uintptr_t)(x)^(uintptr_t)(y)))
#define IN_BOUNDS(n) ((n)>=N?0:((n)<0?N-1:(n)))
#define CELL_BOUNDS(x,y) (Rectangle){(x),(y),CELL_SIZE,CELL_SIZE}

bool buff1[N][N], buff2[N][N];
bool (*next)[N][N] = &buff1, (*cur)[N][N] = &buff2;

void draw_field(void);
void draw_grid(void);
void draw_pause(void);

double last_simulation_time = 0;

bool eval_cell(int cx, int cy);
void eval_state(void);

void (*loop)(void);
void simulate(void);
void edit_field(void);

#endif /* gol_h */
