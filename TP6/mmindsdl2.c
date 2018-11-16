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

    int width = 800;
    int height = 600;
    int running = 1;
    SDL_Event event;

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


    SDL_Window *window;

    window = SDL_CreateWindow("SDL2 Programme 0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,SDL_WINDOW_RESIZABLE);

    if (window == 0){
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        /* on peut aussi utiliser SLD_Log() */
    }


    
    initialiser_plateau(plateau);

    while (running){
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


    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();
    IMG_Quit();
    

}