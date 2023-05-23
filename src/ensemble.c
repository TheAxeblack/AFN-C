#include <stdio.h>
#include "ensemble.h"

int ENS_initialiser(ensemble e) {
    int i;

    e[0] = 0;

    for (i = 1; i < NB_MAX; i++) {
        e[i] = 0;
    }

    return 0;
}

int ENS_ajouter(int elem, ensemble e) {
    if (!ENS_appartient(elem, e)) {
        e[e[0] + 1] = elem;
        e[0]++;
        return 1;
    }
    return 0;
}

int ENS_appartient(int elem, ensemble e) {
    int i;
    for (i = 1; i <= e[0]; i++)
        if (e[i] == elem)
            return 1;
    return 0;
}

int ENS_estvide(ensemble e) {
    return (e[0] == 0);
}

int ENS_afficher(ensemble e) {
    int i;

    printf("{");
    for (i = 1; i <= e[0]; i++) {
        printf("%d", e[i]);
        if (i < e[0])
            printf(", ");
    }
    printf("}\n");
    return 0;
}

int ENS_retirer_un_element(ensemble e) {
    int elem;
    int i;
    if (!ENS_estvide(e)) {
        elem = e[1];
        for (i = 1; i < e[0]; i++) {
            e[i] = e[i + 1];
        }
        e[0]--;
        return elem;
    }
    return -1;
}

int ENS_ajouter_les_elements_de(ensemble s, ensemble d) {
    int i;
    for (i = 1; i <= s[0]; i++) {
        ENS_ajouter(s[i], d);
    }
    return 0;
}

int ENS_affecter(ensemble s, ensemble d) { /* s = d, le précèdent contenu de s est perdu */
    ENS_initialiser(s);

    if (ENS_estvide(d))
        return 1; /* rien à faire */

    ENS_ajouter_les_elements_de(d, s);
    return 0;
}


int ENS_intersection(ensemble a, ensemble b, ensemble r) {
    int i;
    ENS_initialiser(r);
    for (i = 1; i <= a[0]; i++) {
        if (ENS_appartient(a[i], b))
            ENS_ajouter(a[i], r);
    }
    return 0;
}

int ENS_union(ensemble a, ensemble b, ensemble r) {
    ENS_initialiser(r);
    ENS_ajouter_les_elements_de(a, r);
    ENS_ajouter_les_elements_de(b, r);
    return 0;
}

int ENS_egal(ensemble a, ensemble b) {
    int i;

    if (a[0] != b[0])
        return 0;

    for (i = 1; i <= a[0]; i++) {
        if (!ENS_appartient(a[i], b))
            return 0;
    }
    return 1;
}