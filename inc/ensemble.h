#ifndef ENSEMBLE_H
#define ENSEMBLE_H

#define NB_MAX 250 /* nombre maximum d'elements dans un ensemble */

typedef int ensemble[NB_MAX]; /* type ensemble */

/*
 * ensemble[0] -> nombre d'elements
 * ensemble[n] -> n-ieme element , n de 1 a ensemble[0]
 */

int ENS_initialiser(ensemble e); /* ensemble vide */

int ENS_ajouter(int elem, ensemble e); /* ajoute un element a l'ensemble */

int ENS_appartient(int elem, ensemble e); /* teste si un element appartient a l'ensemble */

int ENS_estvide(ensemble e); /* teste si l'ensemble est vide, 1 si vide, 0 sinon */

int ENS_afficher(ensemble e); /* affiche l'ensemble */

int ENS_retirer_un_element(ensemble e); /* retire un element de l'ensemble */

int ENS_ajouter_les_elements_de(ensemble s, ensemble d); /* ajoute les elements de s a d */

int ENS_affecter(ensemble s, ensemble d); /* s = d */

int ENS_intersection(ensemble a, ensemble b, ensemble r); /* r = a inter b */

int ENS_union(ensemble a, ensemble b, ensemble r); /* r = a U b */

int ENS_egal(ensemble a, ensemble b); /* teste si a = b */

#endif /* ENSEMBLE_H */