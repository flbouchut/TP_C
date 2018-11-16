#include "vecteur.h"
#include<stdio.h>
#include<stdlib.h>


// definition des fonctions declarees dans vecteur.h



void vecteurToFile(FILE * flux, float * vecteur, int ordre) 
{
	int i;
	
	
	fprintf(flux, "[ ");
	for(i=0; i<ordre; i++){
		fprintf(flux, "%.3f ",*(vecteur + i)); 
	}
	fprintf(flux, "]");
}



float * vecteurFromFileByName(const char * nom_fichier, int * p_ordre) 
{
	int i = 0;
	float * retour = NULL;
	FILE * fd;
	
	fd = fopen(nom_fichier, "r");
	
	if(fd == 0)
		printf("Probleme a l'ouverture");
	else {
		fscanf(fd, "%d", p_ordre);
		retour = malloc(sizeof(float) * (*p_ordre));
		while(!feof(fd) && i<(*p_ordre)){
			fscanf(fd, "%f", retour + i);
			i++;
		}	
	fclose(fd);
	}
		
	
	

	return retour;
}


/*
float   produitScalaire() 
{
	float retour;

    return retour;
} 
*/

