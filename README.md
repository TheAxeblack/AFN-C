# AFN-C

Ce repository contient l'implémentation en langage C d'[automates finis non-déterministe (AFN)](https://fr.wikipedia.org/wiki/Automate_fini_non_déterministe) ainsi que les fonctions permettant de les manipuler.

## Description

Un automate fini non-déterministe (AFN) est une structure mathématique utilisée pour modéliser des systèmes avec des états multiples et des transitions entre ces états, où ces transitions peuvent ne pas être déterministes. Ce projet fournit une implémentation en C des AFN, permettant de les créer, de les manipuler et de les analyser.

## Structure d'un AFN

Un AFN $(Q,A,T,I,F)$ est représenter comme suit :

* $Q = {1, 2, ..., n_q}$ : l'ensemble des états.
* $A$ : l'alphabet des symboles, numérotés de 1 à $n_a$.
* $T$ : l'ensemble des transitions.
* $I$ : l'ensemble des états initiaux.
* $F$ : l'ensemble des états finaux.

Ainsi un AFN est de la forme $(n_q,n_a,T,I,F)$.

## Installation 

Pour utilsier ce projet, cloner le repository et compile le code source.
```bash
git clone https://github.com/TheAxeblack/AFN-C.git
cd AFN-C
make
```

## Auteurs

* TheAxeblack - *Créateur et Développeur* - [Mon profil](https://github.com/TheAxeblack)
