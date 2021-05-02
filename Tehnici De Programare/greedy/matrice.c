#include "matrice.h"

#include <stdlib.h>
#include <stdio.h>

void citire(int *n, int *k) {
    // Citesc n si k din problema
    scanf("%d %d", n, k);
}

void dezalocare(int ***v, const int n) {
    int i;
    // Dezaloc memoria pentru coloane
    for (i = 0; i < n; i++) {
        free((*v)[i]);
    }
    // Dezaloc memoria pentru linii
    free(*v);
}

void afisare(int **v, const int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // Afisez elementele matricei obtinute, spatiate printr-un ' '
            printf("%d ", v[i][j]);
        }
        // Afisez elementele pe o noua linie, cand trecem la linia urmatoare
        puts("");
    }
}

void completare(int ***v, const int n, const int k) {
    int i, j, s = 0;
    /**
     * Ideea: Afisez elementele ordonate, pana la coloana k.
     * Cand ajungem la coloana k, atunci mergem catre o noua linie.
     * Si afisam restul de numere, fara a restrange ceea ce se cere, crescator, pe coloanele k pana la n.
     */
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            (*v)[i][j] = s++;
        }
    }

    for (j = k; j < n; j++) {
        for (i = 0; i < n; i++) {
            (*v)[i][j] = s++;
        }
    }
}

void alocare(int ***v, const int n) {
    // Aloc memorie pentru linii
    *v = (int **) malloc( n * sizeof(int *));
    int i;
    for (i = 0; i < n; i++) {
        // Aloc memorie pentru coloane
        (*v)[i] = (int *) malloc(n * sizeof(int));
    }
}