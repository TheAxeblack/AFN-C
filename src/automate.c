#include "automate.h"
#include <stdlib.h>
#include <stdio.h>

afn AFN_initialiser() {
    int i, j;
    afn n;
    n = (afn) malloc(sizeof(afn_t));

    if (n == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        exit(1);
    }

    ENS_initialiser(n->final);
    ENS_initialiser(n->initial);
    for (i = 0; i < NB_ETATS_MAX; i++) {
        for (j = 0; j < TAILLE_ALPHABET; j++)
            ENS_initialiser(n->trans[i][j]);
    }
    return n;
}

int AFN_rendre_final(int e, afn a) {
    return ENS_ajouter(e, a->final);
}

int AFN_rendre_initial(int e, afn a) {
    return ENS_ajouter(e, a->initial);
}

int AFN_ajouter_transition(int p, char x, int r, afn a) {
    return ENS_ajouter(r, a->trans[p][x - 'a']);
}

int AFN_afficher(afn a) {
    int i, j;
    printf("Etats initiaux : ");
    ENS_afficher(a->initial);
    printf("Etats finaux : ");
    ENS_afficher(a->final);
    printf("Transitions : \n");
    for (i = 0; i < NB_ETATS_MAX; i++) {
        for (j = 0; j < TAILLE_ALPHABET; j++) {
            if (!ENS_estvide(a->trans[i][j])) {
                printf("\t%d -- %c --> ", i, j + 'a');
                ENS_afficher(a->trans[i][j]);
            }
        }
    }
    return 0;
}