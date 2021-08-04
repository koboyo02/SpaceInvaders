#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "surface.h"
#include "rect.h"

void affichage ()
{
    SDL_RenderCopy(renderer, textureback, NULL, &rectback);
    SDL_RenderCopy(renderer, texturevai, NULL, &rectvai);
    SDL_RenderCopy(renderer, texturevaibad, NULL, &rectvaibad);
    SDL_RenderPresent(renderer);
}