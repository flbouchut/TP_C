#ifndef master_h
#define master_h

/* DECLARATION DES CONSTANTES SYMBOLIQUES */

#define NB_COLONNES 4
#define NB_COULEURS 6
#define NB_LIGNES 10


/* DECLARATION DES TYPES PERSONNELS */
// et de leur typedef si besoin
/*
typedef struct {
	int bienp;
	int malp;

} combinaison;
*/
/* DECLARATIONS DES METHODES */

void initialiser_solution(int tab_solutions[4]);
void initialiser_plateau (int plateau[10][NB_COLONNES + 2]);
void compiler_proposition(int tab_proposition[NB_COLONNES], int tab_solutions[NB_COLONNES], int *bienp, int *malp);
void afficherPlateau(int plateau[10][NB_COLONNES + 2]);
// le prototype est a adapter
// mettre ici les autres declarations

#endif
