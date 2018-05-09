
#ifndef TETRIS_TETROMINO_H
#define TETRIS_TETROMINO_H

#include <stdbool.h>
#include <SDL_pixels.h>
#include "point.h"

typedef struct _tetromino{
    int rotation;
    point a,b,c,d;
    char type;
    bool falling;
    SDL_Color color;
} tetromino;

void moveLeft();
void moveRight();
void rotate();
void currentGravity();
void dropCurrent();
void drawCurrent();
void updateGhost();
void drawGhost();
void swapCurrent();
void initializeBag(); // generate the first set of random tetrominos
int updateCurrent(); //return -1 if lost
bool tetrominoCollides(tetromino * t);
void spawnRandomTetromino();
#endif //TETRIS_TETROMINO_H
