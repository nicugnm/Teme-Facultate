#include <stdio.h>;
#include <stdlib.h>

void main() {
    int val;
    scanf("%d", &val);
    float *v;
    v = (float*) malloc(val * sizeof(float));
    float nrval, prag;
    for (int i = 0; i < val; i++) {
        scanf("%f", &nrval);
        v[i] = nrval;
    }
    scanf("%f", &prag);
    int j = 0;
    for (int i = 0; i < val; i++) {
        if (v[i] > prag) {
            v[i] = 1;
        } else {
            v[i] = 0;
        }
    }
    for (int i = 0; i < val - 1; i++)
        if (v[i] != v[i + 1]) j++;

    if (j != 0) {
        printf("%d", j - 1);
    } else {
        printf("%d" , 1);
    }
    free(v);
}