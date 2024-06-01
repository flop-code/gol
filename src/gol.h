#ifndef gol_h
#define gol_h

#include <stdbool.h>
#include <stdint.h>

#define FPS 10.0
#define N 25
#define WINDOW_SIZE 900
#define CELL_SIZE (WINDOW_SIZE/N)

#define PTR_SWAP(x, y) ((x)=(__typeof__(x))((uintptr_t)(x)^(uintptr_t)(y)),\
                        (y)=(__typeof__(y))((uintptr_t)(x)^(uintptr_t)(y)),\
                        (x)=(__typeof__(x))((uintptr_t)(x)^(uintptr_t)(y)))
#define IN_BOUNDS(n) ((n)>=N?0:((n)<0?N-1:(n)))
#define CELL_BOUNDS(x,y) (Rectangle){(x),(y),CELL_SIZE,CELL_SIZE}

extern bool (*next)[N][N], (*cur)[N][N];

bool eval_cell(int cx, int cy);
void eval_state(void);
void simulate(void);

void draw_field(void);
void draw_grid(void);
void draw_pause(void);
void draw_help_alert(void);
void draw_darker(void);
void draw_help(void);

void edit_field(void);

void help(void);

extern void (*loop)(void);

#endif /* gol_h */
