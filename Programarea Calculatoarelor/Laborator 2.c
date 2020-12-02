/*folosiți break și/sau continue în cadrul unei instrucțiuni for/while
folosiți instrucțiuni repetitive îmbricate pentru afișarea tuturor perechilor de două numere de la 1 la 5

1. Pentru valori întregi citite de la tastatură să se tiparească valoarea corespunzătoare în binar. 
Pentru verificare, folosiți aplicația "Calculator".

2. Se citesc 2 numere întregi x și n unde n este între 0 si 15. 
Să se afișeze: 
bitul n din x, 
numărul x în care se setează bitul n,
numărul x în care se șterge bitul n, 
numărul x în care se complementează bitul n.

3. Se citesc întregii x, y, n, p. 
Să se copieze în x, începând din poziția p, ultimii n biți din y și 
să se afișeze noua valoare a lui x.

4. Scrieți un program care primește ca input de la tastatură scrierea unui număr în baza 2
 și calculează direct scrierea acestuia în baza 16 (nu mai trece prin baza intermediară 10). 
 Realizați acest lucru inversând cele două baze (input – scrierea în baza 16, output – scrierea în baza 2).

*/

#include <stdio.h>
#include <stdint.h>

void repetitiva() {
    for (int i = 0; i < 10; i++) {
        if (i == 5) continue;
        printf("%d\n", i);
    }
    
    int j = 30;
    while (j != 0) {
        j /= 2;
        if (j < 10) break;
        printf("%d\n", j);
    }
}

void perechi() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++)
            printf("Afisez pereche: '{%d %d}'\n", i, j);
    }
}

int* alocare(int nr) {
    int *v;
    v = (int*) malloc(nr * sizeof(int));
    return v;
}

void prob1_v1(int nr) {
    int *v = (int*) alocare(nr);
    int i = 0;
    while (nr != 0) {
        int val = nr % 2;
        nr = nr / 2;
        i++;
        v[i] = val;
    }
    for (int j = i; j > 0; j--)
        printf("%d", v[j]);

    free(v);
}

void prob1_v2(int nr) {
    if (nr > 0) {
        printf("%d", nr & 1);
        prob1_v2(nr >> 1);
    }
}

void prob2(unsigned int bit, int nr) {
    printf("Bitul %d din %d este: %d\n", bit, nr, (nr >> bit) & 1);
    printf("Numarul %d in care se seteaza bitul %d este: %d\n", nr, bit, nr | (1 << bit));
    printf("Numarul %d in care stergem bitul %d este: %d", nr, bit, nr & ~(1 << bit));
    printf("Numarul %d in care se complementeaza bitul %d este: %d", nr, bit, nr ^ (1 << bit));
}

void prob3(int nr, int y, int poz, int n) {
    printf("Numarul %d in care se copiaza ultimii %d biti in numarul %d incepand cu pozitia %d este: %d",
     y, n, nr, poz, ((nr >> (poz - 1)) << (poz - 1)) + (y & ~(1 << n)));
}

char replace(int nr) {
    if (nr < 10) return nr + "";
    else
    {
        switch (nr) {
            case 10:
                return "A";
            case 11:
                return "B";
            case 12:
                return "C";
            case 13:
                return "D";
            case 14:
                return "E";
            case 15:
                return "F";
            default:
                replace(nr % 15);
                break;
        }
    }
    
}

void prob4(int nr) {
}

int main() {
    //repetitiva();
    //perechi();
    int nr;
    //int poz;
    //int n;
    //int y;
    //unsigned int bit;

    //scanf("%d", &y);
    //scanf("%d", &bit);
    //prob2(bit, nr);
    //prob1_v1(nr);
    /* Trebuiesc invers bitii */
    //prob1_v2(nr);
    //scanf("%d", &n);
    scanf("%d", &nr);
    //scanf("%d", &poz);
    //prob3(nr, y, poz, n);
    return 0;
}