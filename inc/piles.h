#ifndef PILES_H
#define PILES_H

#include "ensemble.h"

typedef int pile[NB_MAX]; /* type pile */
/*
 * pile[0] -> nombre d'elements
 * pile[n] -> n-ieme element , n de 1 a pile[0]
 */

int PILE_initialiser(pile p); /* pile vide */

int PILE_empiler(int elem, pile p); /* empile un element */

int PILE_estvide(pile p); /* teste si la pile est vide, 1 si vide, 0 sinon */

int PILE_depiler(pile p); /* depile un element */

int PILE_afficher(pile p); /* affiche la pile */

#endif