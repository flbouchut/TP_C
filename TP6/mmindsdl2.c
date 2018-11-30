#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "master.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

int main(){
    int stop = 0;
    int trouve = 0;
    int nbCoups = 0;
    int i = 0;
    int tab_solutions[NB_COLONNES];
    int tab_proposition[NB_COLONNES];
    int plateau[10][NB_COLONNES + 2];

    int width = 600;
    int height = 800;
    int running = 1;
    SDL_Event event;
    SDL_Rect rect;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture  *avatar;

    int flags=IMG_INIT_JPG|IMG_INIT_PNG;
    int initted= 0;

    if(SDL_Init(SDL_INIT_VIDEO) == -1){
        fprintf(stderr, "ERREUR d'initialisation de la SDL : %s\n, SDL_GetError()) ");
        return EXIT_FAILURE;
    }

    if (TTF_Init() != 0){
        fprintf(stderr, "Erreur d'initialisation TTF : %s\n", TTF_GetError());
    }


    initted = IMG_Init(flags);

    if((initted&flags) != flags){
        printf("IMG_Init: Impossible d'initialiser le support des formats JPG et PNG requis!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
    }


    

    window = SDL_CreateWindow("SDL2 Programme 0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,SDL_WINDOW_RESIZABLE);

    if (window == 0){
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        /* on peut aussi utiliser SLD_Log() */
    }


    
    initialiser_plateau(plateau);

    

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED ); /*  SDL_RENDERER_SOFTWARE */
    if (renderer == 0) {
         fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        /* faire ce qu'il faut pour quitter proprement */
    }

    /*SDL_Surface *image = NULL;
    image=IMG_Load("loic.png");*/
    /* image=SDL_LoadBMP("loic.bmp"); fonction standard de la SDL2 */
    /*if(!image) {
        printf("IMG_Load: %s\n", IMG_GetError());
    }

    avatar = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    rect.x = 600;
    rect.y = 110;
    rect.w = rect.h = 128;
    SDL_RenderCopy(renderer, avatar, NULL, &rect);*/

    while (running){

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 0);
        rect.x = 100;
        rect.y = 660;
        rect.w = 60;
        rect.h = 40;
        SDL_RenderFillRect(renderer, &rect );

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
        rect.x = 160;
        rect.y = 660;
        rect.w = 60;
        rect.h = 40;
        SDL_RenderFillRect(renderer, &rect );

        

        /*SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
        rect.x = rect.y = 0;
        rect.w = rect.h = 600;
        SDL_RenderFillRect(renderer, &rect );*/



        while (SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_WINDOWEVENT:
                    printf("window event\n");
                    switch (event.window.event){
                        case SDL_WINDOWEVENT_CLOSE:
                            printf("appui sur la croix\n");
                            break;
                        case SDL_WINDOWEVENT_SIZE_CHANGED:
                            width = event.window.data1;
                            height = event.window.data2;
                            printf("Size : %d%d\n", width, height);
                        //default:
                            //afficherEcran();
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    printf("Appui :%d %d\n", event.button.x, event.button.y);
                    // afficherEcran() ?
                    break;
                case SDL_QUIT :
                    printf("on quitte\n");
                    running = 0;
                    break;
            }
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(1); //  delai minimal
    }
    

    /*while(!stop){
        initialiser_solution(tab_solutions);
        
        while(!trouve && nbCoups < 10){
            printf("Saisir un jeu de couleur comme 1 1 2 3, validez par entree\n");
            fflush(stdout);
            scanf("%d %d %d %d", &tab_proposition[0], &tab_proposition[1], &tab_proposition[2], &tab_proposition[3]);

            for(i=0; i<4; i++){
                plateau[nbCoups][i] = tab_proposition[i];
            }

            compiler_proposition(tab_proposition, tab_solutions, &plateau[nbCoups][4], &plateau[nbCoups][5]);

            

            //afficherPlateau(plateau);

            

            if(plateau[nbCoups][4] == 4){
                trouve = 1;
            }

            nbCoups += 1;

        }


        stop = 1;
    }*/

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();
    IMG_Quit();
    

}