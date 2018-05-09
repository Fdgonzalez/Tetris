
#ifndef TETRIS_DEFS_H
#define TETRIS_DEFS_H

//Constant definitions
#define FPS 60
/*Although WIDTH and HEIGHT can be set independently to get the tetromino blocks to be square
 0,04 * HEIGHT should be equal to 0,048 * WIDTH*/
#define WIDTH 500
#define HEIGHT 600
#define BOARDH 24
#define BOARDW 10
#define WHITE (SDL_Color) {255,255,255,0}
#define RED (SDL_Color) {232,69,69,0}
#define BLUE (SDL_Color) {69,72,232,0}
#define GREEN (SDL_Color) {69,232,121,0}
#define YELLOW (SDL_Color) {232,232,69,0}
#define GHOSTCOLOR (SDL_Color) {35,96,52,0}
#define LBLUE (SDL_Color){69,226,232}
#define ORANGE (SDL_Color) {232,158,69}
#define VIOLET (SDL_Color) {134,69,232}
#define FONT "../resource/Xolonium-Regular.ttf"
//Library includes
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_audio.h"
#include <stdbool.h>
#include "SDL_mixer.h"



//Global variables
SDL_Renderer *renderer;
SDL_Window *screen;
TTF_Font *scoreFont;
bool lost;
#endif //TETRIS_DEFS_H
