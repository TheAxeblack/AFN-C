#ifndef PILES_H
#define PILES_H

#include "ensemble.h"

typedef int pile[NB_MAX];
/*
 * pile[0] -> nombre d'elements
 * pile[n] -> n-ieme element , n de 1 a pile[0]
 */

int PILE_initialiser(pile p);

int PILE_empiler(int elem, pile p);

int PILE_estvide(pile p);

int PILE_depiler(pile p);

int PILE_afficher(pile p);

#endif