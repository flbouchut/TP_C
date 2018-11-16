#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "master.h"

// Genere une combinaison à trouver
void initialiser_solution(int tab_solutions[NB_COLONNES]) {
   int i;
   srand(time(NULL));
   for(i=0; i<NB_COLONNES; i++){
   	tab_solutions[i] = rand() % 6 + 1;
   }
}

// un petit commentaire ?
void initialiser_plateau(int plateau[10][NB_COLONNES + 2]){
   int i,j;
   for(i=0; i<10; i++){
   	for(j=0; j<NB_COLONNES + 2; j++){
   		plateau[i][j] = 0;
   	}
   }
}


void compiler_proposition(int tab_proposition[NB_COLONNES], int tab_solution[NB_COLONNES], int *bienp, int *malp) {
	
	*bienp = 0;
	*malp = 0;
	
	int tab_eliminationSolution[NB_COLONNES];
	int tab_eliminationProposition[NB_COLONNES];
	int i;
	int j = 0;
	int k = 0;
	
	
	for(i=0; i<NB_COLONNES; i++){
		tab_eliminationSolution[i] = tab_solution[i];
		tab_eliminationProposition[i] = tab_proposition[i];
	}
	
	
	for(i=0; i<NB_COLONNES; i++){
		if(tab_proposition[i] == tab_solution[i]){
			*bienp += 1;
			tab_eliminationProposition[i] = 0;
			tab_eliminationSolution[i] = 0;
		}
	}
	
	for(j=0; j<NB_COLONNES; j++){
		if(tab_eliminationProposition[j]!= 0){
			for(k=0; k<NB_COLONNES; k++){ 
				if(tab_eliminationSolution[k]!= 0){
					if(tab_eliminationProposition[j] == tab_eliminationSolution[k]){
						tab_eliminationSolution[k] = 0;
						*malp += 1;
					}
				}
			}
		}
	}
	
	
}

void afficherPlateau(int plateau[10][NB_COLONNES + 2]){
	int i = 0;
	int j = 0;

	printf("=======================\n");
	for(i=0; i<10; i++){
		printf("| ");
		for(j=0; j<NB_COLONNES + 2; j++){
		
			printf("%d ", plateau[i][j]);
			if(j == 3){
				printf("|| ");
			}
		}
		printf("|\n");
	}
	printf("=======================\n");


}
