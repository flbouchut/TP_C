#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cellule
{
  char             ligne[255];
  struct cellule * suiv;
} cellule_t;


typedef struct liste
{
  cellule_t * tete;
  cellule_t * fin;
} liste_t;




/*void insertionTete(cellule_t * inser, ){

}*/

void insertionFin(liste_t * liste, char buffer[255]){
    cellule_t * inser = malloc(sizeof(cellule_t));
    strcpy(buffer, inser->ligne);
    inser->suiv = NULL;

    

    if(liste->tete == NULL){
        liste->tete = inser;
        liste->fin = inser;
    }else{
        (liste->fin)->suiv = inser;
        liste->fin = inser;
    }

}


int main(){
    liste_t * liste = malloc(sizeof(liste_t));
    liste->tete = NULL;
    liste->fin = NULL;

    char buffer[255];

    while(fgets(buffer, 255, stdin)!= NULL){
        
        insertionFin(liste, buffer);

    }

}




