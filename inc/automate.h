#ifndef AUTOMATE_H
#define AUTOMATE_H

#include "ensemble.h"
#include "piles.h"

#define NB_ETATS_MAX 40   /* nombre d'etats max */
#define TAILLE_ALPHABET 2 /* taille de l'alphabet */

typedef struct afn_t
{
    ensemble final;                                /* ensemble des etats finaux */
    ensemble initial;                              /* ensemble des etats initiaux */
    ensemble trans[NB_ETATS_MAX][TAILLE_ALPHABET]; /* tableau des transitions */
} afn_t;

/* etats -> de 1 a n
 * alphabet -> de 0 a k
 * trans[2][0] on peut atteindre 2 etats par un chemin etiquette 'a'
 * si besoin de stocker la ligne 0 des etats est disponible (pas d'etats vide)
 * on doit obligatoirement passer par les fonctions définies dans le fichier ensemble.c/ensemble.h */

typedef struct afn_t *afn; /* type automate */

/* Prototypage des fonctions */
afn AFN_initialiser(); /* automate vide */

int AFN_rendre_final(int e, afn a); /* rend l'etat e final */

int AFN_rendre_initial(int e, afn a); /* rend l'etat e initial */

int AFN_ajouter_transition(int p, char x, int r, afn a); /* ajoute une transition de p a r etiquette x */

int AFN_afficher(afn a); /* affiche l'automate */

int AFN_analyser_mot(char *mot, afn a); /* teste si le mot est reconnu par l'automate */

/*
int AFN_determiniser(afn a, afn r);
 */

#endif /* AUTOMATE_H */