#ifndef TETRIS_GRID_H
#define TETRIS_GRID_H

#include "point.h"
#include "block.h"

bool outsideBounds(point p);
bool isOccupied(point p);
void drawGrid();
void createGrid();
int updateGrid(); // return lines cleared
block grid[BOARDW][BOARDH];

#endif //TETRIS_GRID_H
