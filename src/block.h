#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H

#include "defs.h"

typedef struct _block{
    SDL_Rect rect;
    SDL_Color color;
}block;

void drawBlock(block block);
void drawBlockWithColor(block block,SDL_Color color);

#endif //TETRIS_BLOCK_H
