#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "master.h"

int main(){
    int stop = 0;
    int trouve = 0;
    int nbCoups = 0;
    int i = 0;
    int tab_solutions[NB_COLONNES];
    int tab_proposition[NB_COLONNES];
    int plateau[10][NB_COLONNES + 2];



    
    initialiser_plateau(plateau);
    

    while(!stop){
        initialiser_solution(tab_solutions);
        
        while(!trouve && nbCoups < 10){
            printf("Saisir un jeu de couleur comme 1 1 2 3, validez par entree\n");
            fflush(stdout);
            scanf("%d %d %d %d", &tab_proposition[0], &tab_proposition[1], &tab_proposition[2], &tab_proposition[3]);

            for(i=0; i<4; i++){
                plateau[nbCoups][i] = tab_proposition[i];
            }

            compiler_proposition(tab_proposition, tab_solutions, &plateau[nbCoups][4], &plateau[nbCoups][5]);

            

            afficherPlateau(plateau);

            

            if(plateau[nbCoups][4] == 4){
                trouve = 1;
            }

            nbCoups += 1;

        }


        stop = 1;
    }
    

}


