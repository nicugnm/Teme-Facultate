/*
 * 13.
 * Se citesc de la tastatura doua numere naturale n si k.
 * Generati o matrice cu n linii si n coloane, care sa indeplineasca simultan urmatoarele conditii:
 * - contine toate numerele naturale de la 1 la n^2, fiecare numar luat o singura data
 * - pe fiecare linie elementele sunt asezate crescator de la stanga la dreapta
 * - suma elementelor de pe o coloana k sa fie minima
 *
 * Explicatii:
 * - Complexitate O(n^2)
 */

#include "matrice.h"

int main() {
    int n, k, **v;

    citire(&n, &k);
    alocare(&v, n);
    completare(&v, n, k);
    afisare(v, n);
    dezalocare(&v, n);

    return 0;
}
