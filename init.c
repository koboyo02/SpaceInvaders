#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

void initial ()
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s \n", SDL_GetError());
    }

    window = SDL_CreateWindow("Galactic Mission", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 480, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, 0);

    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s \n", SDL_GetError());
    }
}