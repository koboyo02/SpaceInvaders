#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    SDL_bool marche = SDL_TRUE;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Rect rectvai;
    SDL_Rect rectback;
    SDL_Rect rectvaibad;

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

    if(0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s \n", SDL_GetError());
    }

    window = SDL_CreateWindow("Galactic Mission", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 480, SDL_WINDOW_SHOWN);
    if(NULL == window)
    {
        fprintf(stderr, "Erreur SDL_CreateWindow : %s \n", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, -1, 0);


    SDL_Surface* background = SDL_LoadBMP("/img/background.bmp");
    SDL_Surface* vaisseau = SDL_LoadBMP("/img/vaisseau.bmp");
    SDL_Surface* vaisseaubad = SDL_LoadBMP("/img/vaisseaubad.bmp");

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

    SDL_Texture* textureback = SDL_CreateTextureFromSurface(renderer, background);
    SDL_QueryTexture(textureback, NULL, NULL, &rectback.w, &rectback.h);
    SDL_Texture* texturevai = SDL_CreateTextureFromSurface(renderer, vaisseau);
    SDL_QueryTexture(texturevai, NULL, NULL, &rectvai.w, &rectvai.h);
    SDL_Texture* texturevaibad = SDL_CreateTextureFromSurface(renderer, vaisseaubad);
    SDL_QueryTexture(texturevai, NULL, NULL, &rectvaibad.w, &rectvaibad.h);
    if (textureback == NULL) 
    {
    fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
    exit(1);
    }
    if (texturevai == NULL) 
    {
    fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
    exit(1);
    }
    if (texturevaibad == NULL) 
    {
    fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
    exit(1);
    }
    
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
            rectvaibad.x -=1;

        if (rectvaibad.x == 48)
        {
            if (rectvai.y > rectvaibad.y-48 && rectvai.y < rectvaibad.y+48)
            {
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

        SDL_RenderCopy(renderer, textureback, NULL, &rectback);
        SDL_RenderCopy(renderer, texturevai, NULL, &rectvai);
        SDL_RenderCopy(renderer, texturevaibad, NULL, &rectvaibad);
        SDL_RenderPresent(renderer);
    }
    SDL_FreeSurface(vaisseaubad);
    SDL_FreeSurface(vaisseau);
    SDL_FreeSurface(background);
    SDL_RenderClear(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    
    return EXIT_SUCCESS;
}
