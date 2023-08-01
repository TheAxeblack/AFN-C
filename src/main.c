#include <stdio.h>
#include <stdlib.h>
#include "../inc/automate.h"

void test_ENS(void)
{
    ensemble e1, e2, e3, e4, e5;
    int elem;

    ENS_initialiser(e1);
    ENS_initialiser(e2);
    ENS_initialiser(e3);
    ENS_initialiser(e4);
    ENS_initialiser(e5);

    printf("Test des fonctions ENS :\n");

    /* Test de ENS_ajouter et ENS_appartient */
    ENS_ajouter(5, e1);
    ENS_ajouter(2, e1);
    ENS_ajouter(9, e1);
    printf("e1 : ");
    ENS_afficher(e1);
    if (ENS_appartient(5, e1))
    {
        printf("5 appartient a e1\n");
    }
    if (!ENS_appartient(7, e1))
    {
        printf("7 n'appartient pas a e1\n");
    }

    /* Test de ENS_estvide */
    if (ENS_estvide(e2))
    {
        printf("e2 est vide\n");
    }
    else
    {
        printf("e2 n'est pas vide\n");
    }

    /* Test de ENS_retirer_un_element */
    ENS_ajouter(8, e3);
    ENS_ajouter(4, e3);
    printf("e3 avant : ");
    ENS_afficher(e3);
    elem = ENS_retirer_un_element(e3);
    printf("e3 apres : ");
    ENS_afficher(e3);
    printf("element retire de e3 : %d\n", elem);

    /*Test de ENS_ajouter_les_elements_de*/
    ENS_ajouter(3, e4);
    ENS_ajouter(7, e4);
    printf("e4 avant : ");
    ENS_afficher(e4);
    ENS_ajouter_les_elements_de(e1, e4);
    printf("e4 apres ajout des elements de e1 : ");
    ENS_afficher(e4);

    /* Test de ENS_affecter */
    printf("e5 : ");
    ENS_afficher(e5);
    printf("e4 avant affectation de e5 : ");
    ENS_afficher(e4);
    ENS_affecter(e4, e5);
    printf("e4 apres : ");
    ENS_afficher(e4);

    /* Test de ENS_intersection */
    ENS_ajouter(5, e2);
    ENS_ajouter(9, e2);
    printf("e1 : ");
    ENS_afficher(e1);
    printf("e2 : ");
    ENS_afficher(e2);
    ENS_intersection(e1, e2, e3);
    printf("e3 = intersection(e1, e2) : ");
    ENS_afficher(e3);

    /* Test de ENS_union */
    ENS_union(e1, e2, e4);
    printf("e4 = union(e1, e2) : ");
    ENS_afficher(e4);

    /* Test de ENS_egal */
    if (ENS_egal(e1, e4))
    {
        printf("e1 et e4 sont egaux\n");
    }
    else
    {
        printf("e1 et e4 ne sont pas egaux\n");
    }
}

void test_PILE(void)
{
    pile p;
    int elem;

    PILE_empiler(3, p);
    PILE_empiler(4, p);
    PILE_empiler(5, p);
    PILE_empiler(6, p);

    printf("\nTest des fonctions PILE :\n");

    printf("Contenu de la pile : ");
    PILE_afficher(p);

    if (PILE_estvide(p))
    {
        printf("La pile est vide\n");
    }
    else
    {
        printf("La pile n'est pas vide\n");
    }

    printf("p avant : ");
    PILE_afficher(p);

    elem = PILE_depiler(p);

    printf("p après : ");
    PILE_afficher(p);

    printf("élément dépilé : %d\n", elem);

    PILE_afficher(p);
}

void test_AFN_1(void)
{
    afn a;

    printf("\nTest des fonctions AFN module 1 :\n");
    a = AFN_initialiser();
    AFN_rendre_initial(1, a);
    AFN_rendre_final(2, a);
    AFN_ajouter_transition(1, 'a', 2, a);
    AFN_ajouter_transition(1, 'b', 3, a);
    AFN_ajouter_transition(3, 'a', 2, a);
    AFN_ajouter_transition(3, 'b', 4, a);
    AFN_afficher(a);

    free(a);
}

int main(void)
{
    afn afn1;

    test_ENS();
    test_PILE();
    test_AFN_1();

    printf("\nTest des fonctions AFN module 2 :\n");

    afn1 = AFN_initialiser();
    AFN_rendre_initial(1, afn1);
    AFN_rendre_final(1, afn1);
    AFN_rendre_final(2, afn1);
    AFN_ajouter_transition(1, 'a', 2, afn1);
    AFN_ajouter_transition(2, 'b', 3, afn1);
    AFN_ajouter_transition(3, 'b', 1, afn1);
    AFN_ajouter_transition(3, 'a', 3, afn1);
    AFN_ajouter_transition(3, 'b', 3, afn1);
    AFN_ajouter_transition(3, 'b', 1, afn1);
    printf("analyse de mots : \n");
    AFN_analyser_mot("ab", afn1);
    AFN_analyser_mot("abb", afn1);
    AFN_analyser_mot("babab", afn1);
    AFN_analyser_mot("bababab", afn1);

    free(afn1);
    exit(EXIT_SUCCESS);
}
