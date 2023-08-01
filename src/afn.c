#include "automate.h"
#include <stdio.h>

int AFN_analyser_mot(char *mot, afn a)
{
    int i;
    ensemble E, E_temp;
    pile P;

    ENS_initialiser(E);          /* E = vide */
    ENS_affecter(E, a->initial); /* E = initial */
    PILE_initialiser(P);         /* P = vide */

    for (i = 0; mot[i] != '\0'; i++)
    {
        ENS_initialiser(E_temp); /* E_temp = vide */
        ENS_affecter(E_temp, a->trans[ENS_retirer_un_element(E)][mot[i] - 'a']);
        while (!ENS_estvide(E_temp))
        {
            PILE_empiler(ENS_retirer_un_element(E_temp), P);
        }
        while (!PILE_estvide(P))
        {
            ENS_ajouter(PILE_depiler(P), E);
        }
    }

    while (!PILE_estvide(P))
    {
        ENS_ajouter(PILE_depiler(P), E);
    }

    ENS_intersection(E, a->final, E_temp);

    if (ENS_estvide(E_temp))
    {
        printf("Le mot %s n'est pas reconnu par l'automate\n", mot);
        return 0;
    }
    else
    {
        printf("Le mot %s est reconnu par l'automate\n", mot);
        return 1;
    }
}

/*
int AFN_determiniser(afn a, afn r) {
    return 1;
}
*/
