#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"

/*int main(){
	donnee_t *teteListe = malloc(sizeof(donnee_t));
	donnee_t *finListe = malloc(sizeof(donnee_t));
	donnee_t *element = malloc(sizeof(donnee_t));

	teteListe->score = 100;
	strcpy(teteListe->nom, "Florian");
	strcpy(teteListe->alias, "Bouchut");
	teteListe->suivant = finListe;


	finListe->score = 1000000;
	strcpy(finListe->nom, "Antony");
	strcpy(finListe->alias, "Palarradu03");
	finListe->suivant = NULL;

	element->score = 4444;
	strcpy(element->nom, "Anonyme");
	strcpy(element->alias, "LeZZsilencieux");
	element->suivant = NULL;

	teteListe = insererListe(teteListe, element);
	

	afficherListe(teteListe);

	rendezLaMemoireAuxAbonnes(teteListe);

	
	

	return 0;
}*/

int main(){

	int quitter  = 0;
	int choix;
	printf("Menu Liste Chainee\n");
	
	while(!quitter){
		printf("Saisissez un nombre entre 1 et 5\n");
		choix = fgetc(stdin) - '0';
		
		switch(choix){
			case 1 : 
				printf("c'est bon");
				break;
			case 2 : 
				printf("c'est encore mieux");
				break;
			default :
				printf("pas entre 1 et 5");
		}
		quitter = 1;
	}
	

}

void afficherListe(donnee_t *tetereelle){

	while(tetereelle != NULL){
		afficherDonnee(stdout, *tetereelle);
		tetereelle = tetereelle->suivant;
	}
		

}

donnee_t* insererListe(donnee_t *tetereelle, donnee_t *element){

	element->suivant = tetereelle;
	return element;
}

void rendezLaMemoireAuxAbonnes(donnee_t *tetereelle){
	donnee_t *tmp;
	while(tetereelle != NULL){
		tmp = tetereelle->suivant;
		free(tetereelle);
		tetereelle = tmp;
	}
}






