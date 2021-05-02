#ifndef GREEDY_MATRICE_H
#define GREEDY_MATRICE_H

/**
 * Functia de citire a datelor
 * @int* n - Numarul de linii si coloane
 * @int* k - Coloana pe care se doreste suma minima
 */
void citire(int *n, int *k);

/**
 * Functia de dezalocare a memoriei alocate dinamic
 * @int*** v - Matricea
 * @int n - Numarul de linii si coloane
 */
void dezalocare(int ***v, int n);

/**
 * Functia de afisare a matricei
 * @**v v - Matricea
 * @int n - Numarul de linii si coloane
 */
void afisare(int **v, int n);

/**
 * Functia de completare a matricei
 * @***v v - Matricea
 * @int n - Numarul de linii si coloane
 * @int k - Coloana pe care se doreste suma minima
 */
void completare(int ***v, int n, int k);

/**
 * Functia de alocare dinamic a matricei
 * @int*** v - Matricea
 * @int n - Numarul de linii si coloane
 */
void alocare(int ***v, int n);

#endif //GREEDY_MATRICE_H
