#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "surface.h"

void texture ()
{
SDL_Texture* textureback = SDL_CreateTextureFromSurface(renderer, background);
    SDL_QueryTexture(textureback, NULL, NULL, &rectback.w, &rectback.h);
    SDL_Texture* texturevai = SDL_CreateTextureFromSurface(renderer, vaisseau);
    SDL_QueryTexture(texturevai, NULL, NULL, &rectvai.w, &rectvai.h);
    SDL_Texture* texturevaibad = SDL_CreateTextureFromSurface(renderer, vaisseaubad);
    SDL_QueryTexture(texturevai, NULL, NULL, &rectvaibad.w, &rectvaibad.h);
    SDL_Texture* texturegameover = SDL_CreateTextureFromSurface(renderer, gameover);
    SDL_QueryTexture(texturevai, NULL, NULL, &rectgameover.w, &rectgameover.h);

    if (textureback == NULL) 
    {
    fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
    exit(1);
    }
}