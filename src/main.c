#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "defs.h"
#include "grid.h"
#include "tetromino.h"
#include "score.h"
#include "sound.h"

int main() {
    srand((unsigned int) time(NULL));
    if (SDL_Init(SDL_INIT_VIDEO) < 0){//| SDL_INIT_AUDIO ) < 0){
        printf("unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
    screen = SDL_CreateWindow("Tetris PE 0.1",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WIDTH, HEIGHT,
                              0);
    //SDL_WINDOW_FULLSCREEN);
    if(screen == NULL){
        printf("Could not creaate window: %s\n",SDL_GetError());
        return 1;
    }
    initAudio();
    loadSound();

    renderer = SDL_CreateRenderer(screen, -1, 0);
    if(renderer == NULL){
        printf("Error creating renderer: %s\n",SDL_GetError());
        return 1;

    }
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderClear(renderer);
    Uint32 start;
    createGrid();
    //Init text
    TTF_Init();
    scoreFont = TTF_OpenFont("/usr/share/fonts/dejavu/DejaVuSans.ttf",30);
    if(!scoreFont){
        fprintf(stderr,"FONT NOT FOUND\n");
        return 1;
    }

    bool running = true;
    int deleted;
    const Uint8 * keystate;
    score = 0;
    Uint32 timeA= 0;
    Uint32 timeD= 0;
    Uint32 timeW= 0;
    Uint32 timeS= 0;
    Uint32 timeSHIFT= 0;
    Uint32 timeSPACE= 0;
    Uint32 fallTime = 0;
    int SPEED = 500; //ms till next fall
    //Main Loop
    spawnRandomTetromino();
    startMusic();
    while(running){
        start = SDL_GetTicks();
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym){
                        case SDLK_ESCAPE: running = false; break;
                        default: break;
                    }
            }
        }
        //control
        SDL_PumpEvents();
        keystate = SDL_GetKeyboardState(NULL);
        if(start > timeA + 150 && keystate[SDL_SCANCODE_A]){
            moveLeft();
            timeA = start;
        }
        if(start > timeD + 150 && keystate[SDL_SCANCODE_D]){
            moveRight();
            timeD = start;
        }
        if(start > timeW + 150 && keystate[SDL_SCANCODE_W]){
            rotate();
            timeW = start;
        }
        if(start > timeSPACE + 150 && keystate[SDL_SCANCODE_SPACE]){
            dropCurrent();
            playDrop();
            timeSPACE = start;
        }
        if(start > timeS + 100 && keystate[SDL_SCANCODE_S]){
            currentGravity();
            timeS = start;
        }
        if(start > timeSHIFT + 150 && keystate[SDL_SCANCODE_LSHIFT]){
            swapCurrent();
            timeSHIFT = start;

        }

        //logic

        if(start > fallTime + SPEED && !lost){
            fallTime = start;
            currentGravity();
        }
        if(updateCurrent() == -1)
            lost = true;

        int deleted = updateGrid();
        switch(deleted){
            case 1: score+= 100; break;
            case 2: score+= 250; break;
            case 3: score+= 400; break;
            case 4: score+= 600; break;
        }
        if(deleted > 0)
            playLine(); // play line cleared sound
        //clear screen
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);

        updateGhost();
        drawGrid();
        drawGhost();
        drawCurrent();
        drawScore();

        //Draw
        SDL_RenderPresent(renderer);

        if(1000/FPS > SDL_GetTicks()-start)
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
    }
}