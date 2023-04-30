#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "ensemble.h"
#include "piles.h"

#define NB_ETATS_MAX 40
#define TAILLE_ALPHABET 2

typedef struct afn_t {
    ensemble final;
    ensemble initial;
    ensemble trans[NB_ETATS_MAX][TAILLE_ALPHABET];
} afn_t;

/* etats -> de 1 a n
 * alphabet -> de 0 a k
 * trans[2][0] on peut atteindre 2 etats par un chemin etiquette 'a'
 * si besoin de stocker la ligne 0 des etats est disponible (pas d'etats vide)
 * on doit obligatoirement passer par les fonctions définies dans le fichier ensemble.c/ensemble.h */

typedef struct afn_t *afn;

/* Prototypage des fonctions */
afn AFN_initialiser();

int AFN_rendre_final(int e, afn a);

int AFN_rendre_initial(int e, afn a);

int AFN_ajouter_transition(int p, char x, int r, afn a);

int AFN_afficher(afn a);

int AFN_analyser_mot(char *mot, afn a);

/*
int AFN_determiniser(afn a, afn r);
 */

#endif