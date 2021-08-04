#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "surface.h"
#include "rect.h"

void clear ()
{
    SDL_FreeSurface(gameover);
    SDL_FreeSurface(vaisseaubad);
    SDL_FreeSurface(vaisseau);
    SDL_FreeSurface(background);
    SDL_RenderClear(renderer);
    SDL_DestroyWindow(window);
}