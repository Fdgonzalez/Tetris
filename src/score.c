
#include "defs.h"
#include "score.h"
void drawScore(){
    char scoreText[100];
     if(!lost)
    sprintf(scoreText,"Score = %d",score);
     else
       sprintf(scoreText,"You Lost, Score = %d",score);

    SDL_Surface *sf = TTF_RenderText_Blended(scoreFont,scoreText,WHITE);
    SDL_Texture *scoreTexture = SDL_CreateTextureFromSurface(renderer,sf);
    int textW = sf->w;
    int textH = sf->h;
    SDL_FreeSurface(sf);
    SDL_Rect textRect = (SDL_Rect) {(int) (WIDTH / 2 + WIDTH * 0.05), 200, textW, textH};
    SDL_RenderCopy(renderer,scoreTexture,NULL,&textRect);
}