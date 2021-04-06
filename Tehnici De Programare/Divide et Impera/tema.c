/** Enunt:
 * (4)
 * Pe o suprafata este trasată o curbă închisă.
 * Suprafata este memorata ca o matrice cu M linii si N coloane, cu valori 0, iar punctele apartinand curbei sunt notate cu 1.
 * Dandu-se un punct din interiorul zonei marginite de curba, se cere sa se umpla cu 1 această zonă.
 * Date de intrare: fișierul date.in conține
 * -pe prima linie doua numere naturale, m și n;
 * -pe urmatoarele m linii elementele unei matrice cu m linii si n coloane, cu semnificatia din enunt.
 * -pe ultima linie doua numere l0,c0, reprezentand linia, respectiv coloana pe care se află punctul.
 * Date de ieșire: fișierul date.out conține matricea transformata.
 * Exemplu:
 *
 * Date de intrare:
10 8
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 1 1 1 1 0 0
0 1 1 0 0 1 0 0
1 1 0 0 0 1 1 0
1 0 0 0 0 0 1 0
1 1 0 1 1 1 1 0
0 1 0 1 0 0 0 0
0 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
5 4
 * Date de iesire:
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 1 1 1 1 0 0
0 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 1 1 1 0 0 0 0
0 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
 */


#include <stdio.h>
#include <stdlib.h>

// Functia de afisare
/**
 *
 * @int*** v - Matricea cu elemente
 * @int* m - Numarul de linii
 * @int* n - Numarul de coloane
 * @int l0 - Linia elementului de la care incepe transformarea
 * @int c0 - Coloana elementului de la care incepe transformarea
 */
void afisare(int **v, int m, int n, int l0, int c0) {
    // Printez dupa fiecare afisare o linie pentru a fi mai evidenta fiecare transformare
    puts("\n--------------");
    int i, j;
    // Printez fiecare element din matrice
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", v[i][j]);
        }
        // Printez o noua linie cand se termina toate elementele de pe linia respectiva
        puts("");
    }
    // Las un rand liber cand se termina de afisat toate liniile
    puts("");
    // Printez care este pozitia actuala a programului cand efectueaza transformarea
    printf("%d %d", l0, c0);
}

// Functia de scriere
/**
 *
 * @int*** v - Matricea cu elemente
 * @int* m - Numarul de linii
 * @int* n - Numarul de coloane
 */
void scriere(int **v, int m, int n) {

    // Deschid fisierul cu instructiunea de write
    FILE* f = fopen("date.out", "w");

    int i, j;

    // Scriu in fisier matricea dupa transformare
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            fprintf(f, "%d ", v[i][j]);
        }
        // Cand se termina toate elementele de pe linie, printez elementele de la capat de rand
        fprintf(f,"\n");
    }

    // In final, inchid fisierul
    fclose(f);
}

// Functia de transformare
/**
 *
 * @int*** v - Matricea cu elemente
 * @int* m - Numarul de linii
 * @int* n - Numarul de coloane
 * @int l0 - Linia elementului de la care incepe transformarea
 * @int c0 - Coloana elementului de la care incepe transformarea
 */
void transformare(int ***v, int m, int n, int l0, int c0) {
    /** Caz particular:
    * Sa presupunem ca avem o "gradina" care e deschisa. Atunci cand atingem capetele, transformarea se va opri.
    * Date de intrare:
    5 8
    0 0 0 0 0 0 0 0
    0 0 1 1 1 1 0 0
    0 1 1 0 0 1 0 0
    1 1 0 0 0 1 1 0
    1 0 0 0 0 0 1 0
    4 4
    * Date de iesire:
    0 0 0 0 0 0 0 0
    0 0 1 1 1 1 0 0
    0 1 1 1 1 1 0 0
    1 1 1 1 1 1 1 0
    1 1 1 1 1 1 1 0
     */
    if (l0 < 0 || c0 < 0 || l0 > m || c0 > n) return;

    int i, j;

    // Afisez dupa fiecare iterare noua matrice pentru a-mi fi mai usor de urmarit pasii transformarilor.
    afisare(*v, m, n, l0, c0);
    // Verific daca este 0 pe elementul dat din enunt.
    // In cazul in care elementul este pe linia si coloana respectiva, il modific cu 1.
    // In cazul in care este 1, nu se intampla nimic.
    // Dupa ce fac modificarea, urmez urmatorii pasi:
    // Verific daca la (stanga, dreapta, sus, jos) elementul este 0. Daca este 0, atunci vin si fac o transformare.
    // Dupa fiecare transformare, se verifica iar in toate partile si asa se va acoperi toata "portia".
    // Complexitatea: O(m*n)
    if ((*v)[l0][c0] == 0) {
        (*v)[l0][c0] = 1;
        if ((*v)[l0 - 1][c0] == 0) {
            transformare(v, m, n, l0 - 1, c0);
        }
        if ((*v)[l0 + 1][c0] == 0) {
            transformare(v, m, n, l0 + 1, c0);
        }
        if ((*v)[l0][c0 - 1] == 0) {
            transformare(v, m, n, l0, c0 - 1);
        }
        if ((*v)[l0][c0 + 1] == 0) {
            transformare(v, m, n, l0, c0 + 1);
        }
    }
}

// Functia de citire
/**
 *
 * @int*** v - Matricea cu elemente
 * @int* m - Numarul de linii
 * @int* n - Numarul de coloane
 * @int l0 - Linia elementului de la care incepe transformarea
 * @int c0 - Coloana elementului de la care incepe transformarea
 */
void citire(int ***v, int *m, int *n, int *l0, int *c0) {

    // Citesc datele din fisierul date.in
    FILE* f = fopen("date.in", "r");
    fscanf(f,"%d %d", m, n);

    // Aloc memorie pentru matricea respectiva
    *v = (int **) malloc(*m * sizeof(int *));
    int i, j;
    for (i = 0; i < *m; i++) {
        (*v)[i] = (int *) malloc(*n * sizeof(int));
    }

    // Introduc datele din fisier in matricea respectiva.
    for (i = 0; i < *m; i++) {
        for (j = 0; j < *n; j++) {
            fscanf(f, "%d", &(*v)[i][j]);
        }
    }

    // Citesc linia si coloana elementului de la care incepe transformarea.
    fscanf(f, "%d %d", l0, c0);

    // Inchid fisierul cand termin de lucrat cu el
    fclose(f);
}

 /**
  *
  * @return 0 -- Returnarea functiei main, inchiderea programului
  */
int main() {
    // Pentru a rezolva problema, voi folosi urmatoarele functii: citire, afisare, transformare.

    // Initializez valorile pe care le voi folosi in problema descrisa mai sus.
    int **v, m, n, l0, c0;

    // Functia de citire din fisierul date.in
    citire(&v, &m, &n, &l0, &c0);
    // Functia de transformare
    // Indexarea incepe de la 0 pentru linie si coloana.
    transformare(&v, m, n, l0 - 1, c0 - 1);

    // Functia de afisare
    afisare(v, m, n, l0, c0);

    // Functia de scriere in fisierul date.out
    scriere(v, m, n);

    // Eliberez memoria alocata dinamic.
    free(v);
    return 0;
}
