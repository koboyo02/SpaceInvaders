#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

void rect ()
{
    SDL_Rect rectvai;
    SDL_Rect rectback;
    SDL_Rect rectvaibad;
    SDL_Rect rectgameover;
    
    rectvai.x = 0;
    rectvai.y = 200;
    rectvai.w = 48;
    rectvai.h = 48;
    rectvaibad.x = 600;
    rectvaibad.y = 200;
    rectvaibad.w = 48;
    rectvaibad.h = 48;
    rectback.x = 0;
    rectback.y = 0;
    rectback.w = 640;
    rectback.h = 480;
    rectgameover.x = 280;
    rectgameover.y = 230;
    rectgameover.w = 640;
    rectgameover.h = 480;
}