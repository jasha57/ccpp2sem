#include "utilit.h"


int * readi(FILE * f, int n) {
    int *a = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d", a+i);
    }
    return a;
}


float * readf(FILE * f, int n) {
    float *a = (float *)calloc(n, sizeof(float));
    if (!a) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        if(!fscanf(f, "%f", a + i)) {
            if(!a) {
                return NULL;
            } else {
                free(a);
                return NULL;
            }
        }
    }
    return a;
}