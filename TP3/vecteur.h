// on appelle cette constante symbolique un gardien, cela permet de s'assurer que ce fichier
// ne sera pas inclus de maniere recursive
#ifndef C3__VECTEUR_H
#define C3__VECTEUR_H

#include <stdio.h>

// prototypes incomplets des fonctions a coder
void    vecteurToFile(FILE * flux, float * vecteur, int ordre);
float * vecteurFromFileByName();
// float   produitScalaire();

typedef float * VecteurType;

#endif
