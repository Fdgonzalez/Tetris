
#include "sound.h"
#include "defs.h"
Mix_Chunk *dropSound = NULL;
Mix_Music *music = NULL;
Mix_Chunk *lineSound = NULL;

bool loadSound(){
    dropSound = Mix_LoadWAV("../resource/drop.wav");
    music = Mix_LoadMUS("../resource/tetris.mp3");
    lineSound = Mix_LoadWAV("../resource/line.wav");
    if(dropSound == NULL || music == NULL || lineSound == NULL){
        printf("Failed to load sounds %s\n",Mix_GetError());
        return false;
    }
    Mix_VolumeChunk(dropSound,MIX_MAX_VOLUME);
    return true;
}
void startMusic(){
    Mix_PlayMusic(music,-1);
}
void playDrop(){
    Mix_PlayChannel(-1,dropSound,0);
}
void playLine(){
    Mix_PlayChannel(-1,lineSound,0);
}
bool initAudio(){//return success
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        return false;
    }
    return true;
}
