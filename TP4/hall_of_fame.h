#ifndef hall_of_fame_h
#define hall_of_fame_h

#define TAILLE_MAX 50

/* DECLARATION DES TYPES PERSONNELS */
// et de leur typedef si besoin
typedef struct donnee{
	int score;
	char nom[100];
	char alias[40];
	struct donnee *suivant; /*Bien utiliser stuct donnee !*/
}donnee_t;

/* DECLARATIONS DES METHODES */
void afficherDonnee(FILE *, donnee_t);
void saisirDonnee (FILE * , donnee_t *);
void saisie(char *s, int size, FILE *stream);
void afficherListe(donnee_t *tetereelle);
donnee_t* insererListe(donnee_t *tetereelle, donnee_t *element);
void rendezLaMemoireAuxAbonnes(donnee_t *tetereelle);
// mettre ici les autres declarations

#endif
