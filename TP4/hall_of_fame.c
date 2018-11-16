#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hall_of_fame.h"



// un petit commentaire ?
void afficherDonnee(FILE * file, donnee_t d) {
   fprintf(file, "%s : %s avec %d\n", d.nom, d.alias, d.score);
}

// un petit commentaire ?
void saisirDonnee(FILE *file, donnee_t * p){
	char temp[10];
	if(file != NULL){
		saisie(p->nom, sizeof(p->nom), file);
		saisie(p->alias, sizeof(p->alias), file);
		fgets(temp, sizeof(temp), file);
		p->score = atoi(temp);
	}
}

void saisie(char *s, int size, FILE *stream){
	fgets(s, size, stream);
	s[strlen(s)-1] = '\0';
}

int tableauFromFilename(char * nomFichier, donnee_t tab[TAILLE_MAX]){
	FILE * fd = NULL;
 
	fd  = fopen(nomFichier, "r");

	int i = 0;
	
	if (fd != NULL){
		while(fd != NULL && !feof(fd)){
			saisirDonnee(fd, &tab[i]);
			afficherDonnee(stdout, tab[i]);
			i++;
		}
		return i;
	}else{
		return 0;
	}
	
}
