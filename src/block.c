#include "block.h"

void drawBlockWithColor(block b, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
    SDL_RenderFillRect(renderer,&b.rect);
}

void drawBlock(block b) {
    drawBlockWithColor(b,b.color);
}
