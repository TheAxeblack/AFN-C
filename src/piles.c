#include <stdio.h>
#include "piles.h"

int PILE_initialiser(pile p)
{
    int i;

    p[0] = 0;

    for (i = 1; i < NB_MAX; i++)
    {
        p[i] = 0;
    }
    return 1;
}

int PILE_empiler(int elem, pile p)
{
    if (p[0] < NB_MAX)
    {
        p[p[0] + 1] = elem;
        p[0]++;
        return 1;
    }
    return 0;
}

int PILE_estvide(pile p)
{
    return (p[0] == 0);
}

int PILE_depiler(pile p)
{
    int elem;

    if (!PILE_estvide(p))
    {
        elem = p[p[0]];
        p[p[0]] = 0;
        p[0]--;
        return elem;
    }
    return -1;
}

int PILE_afficher(pile p)
{
    int i;

    if (!PILE_estvide(p))
    {
        printf("[");
        for (i = 1; i <= p[0]; i++)
        {
            printf("%d", p[i]);
            if (i < p[0])
                printf(", ");
        }
        printf("]\n");
        return 0;
    }
    printf("[]\n");
    return 1;
}