# AFN-C
Ce repository contient l'implémentation en langage C d'[automates finis non-déterministe (AFN)](https://fr.wikipedia.org/wiki/Automate_fini_non_déterministe) ainsi que les fonctions permettant de les manipuler.
Un AFN $(Q,A,T,I,F)$ est représenter comme suit :

* $Q = {1, 2, ..., n_q}$ est l'ensemble des états.
* Tous les symboles de $A$ sont numérotés de 1 à $n_a$.
* $T$ est l'ensemble des transitions.
* $I$ est l'ensemble des états initiaux.
* $F$ est l'ensemble des états finaux.

Un AFN est donc de la forme $(n_q,n_a,T,I,F)$
