#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

void surface ()
{
    SDL_Surface* background = SDL_LoadBMP("/home/koboyo/Pictures/background.bmp");
    SDL_Surface* vaisseau = SDL_LoadBMP("/home/koboyo/Pictures/vaisseau.bmp");
    SDL_Surface* vaisseaubad = SDL_LoadBMP("/home/koboyo/Pictures/vaisseaubad.bmp");
    SDL_Surface* gameover = SDL_LoadBMP("/home/koboyo/Pictures/game_over.bmp");

    if(!background)
    {
    printf("Erreur de chargement du background : %s \n",SDL_GetError());
    }
    if(!vaisseau)
    {
    printf("Erreur de chargement du vaisseau : %s \n",SDL_GetError());
    }
    if(!vaisseaubad)
    {
    printf("Erreur de chargement du vaisseaubad : %s \n",SDL_GetError());
    }
    if(!gameover)
    {
    printf("Erreur de chargement du vaisseaubad : %s \n",SDL_GetError());
    }

}