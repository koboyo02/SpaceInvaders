#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "rect.h"

int mouv()
{
    SDL_bool marche = SDL_TRUE;
    
    while (marche)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_UP:
                    if (rectvai.y >0){
                        rectvai.y -=10;
                    }
                        continue;
                    case SDLK_DOWN:
                    if (rectvai.y <412){
                        rectvai.y +=10;
                    }
                        continue;
                    case SDLK_LEFT:
                    if (rectvai.x >0){
                        rectvai.x -=10;
                    }
                        continue;
                    case SDLK_RIGHT:
                    if (rectvai.x < 592){
                        rectvai.x +=10;
                    }
                        continue;
                    default:
                        continue;
                    }
            case SDL_QUIT:
                marche = SDL_FALSE;
                break;

            default:
                break;
            }
            
        }
            rectvaibad.x -=2;

        if (rectvaibad.x ==0)
        {
        if (rectvai.x  == rectvaibad.x-46)
        {
            if (rectvai.y > rectvaibad.y-50 && rectvai.y < rectvaibad.y+50)
            {
                SDL_RenderCopy(renderer, texturegameover, NULL, &rectgameover);
                SDL_RenderPresent(renderer);
                SDL_Delay(3000);
                marche = SDL_FALSE;
            }
            else 
            {
                int n;
                n = rand() % 412 + 48;
                rectvaibad.x = 600;
                rectvaibad.y = n;
            }
        }
        else 
            {
                int n;
                n = rand() % 412 + 48;
                rectvaibad.x = 600;
                rectvaibad.y = n;
            }
        }
    }
}