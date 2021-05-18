#include "test.h"

int testmakeshit() { // test 1
    absh * newvector = makeshit(10);
    if (!newvector) {
        fprintf(stdout, "testmakeshit(): makeshit RETURN NULL\n");
        return -1;
    }
    if (newvector->size != 10) {
        fprintf(stdout, "testmakeshit(): makeshit INVALID SIZE\n");
        return 1;
    }
    deleteshit(newvector);
    newvector = makeshit(0);
    if (newvector) {
        fprintf(stdout, "testmakeshit(): makeshit INVALID SIZE 0\n");
        return 2;
    }
    return 0;
}

int testadd() { // test 2
    absh * new = makeshit(4);
    int a[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int res = 0;
    for(int i = 0; i < 20; i ++){
        res = add(new, a + i);
    }
    if (res == -1) {
        fprintf(stdout ,"testadd(): ERROR REALLOC DATA\n");
        deleteshit(new);
        return -1;
    } else if( res == -2)  {
        fprintf(stdout, "testadd(): ERROR MEMCPY DATA\n");
        deleteshit(new);
        return -2;
    }
    return 0;
}

int testsumi() {
    FILE * tsfile = fopen("test/sumi.test","r");
    if (!tsfile) {
        fprintf(stderr, "testsumi(): TEST FILE NOT FOUND\n");
        return -1;
    }
    int n = 0; // amount test
    fscanf(tsfile, "%d", &n);
    for (int i = 1; i <= n; i++) {
        int n1;
        fscanf(tsfile, "%d", &n1);
        int *a1 = readi(tsfile, n1);

        int *a2 = readi(tsfile, n1);

        int *a3 = readi(tsfile, n1);

        vector * v1 = newVectorIn(a1, n1);
        vector * v2 = newVectorIn(a2, n1);
        vector * v3 = newVectorIn(a3, n1);
        vector * summ = sumi(v1, v2);
        if (memcmp(summ->head, v3->head, n1 * sizeof(int))) {
            fprintf(stdout ,"testsumi(): ERORR SUMI in test: %d" , i);
            deleteshit(v1);
            deleteshit(v2);
            deleteshit(v3);
            deleteshit(summ);
            free(a1);
            free(a2);
            free(a3);
            return -i;
        }
        deleteshit(v1);
        deleteshit(v2);
        deleteshit(v3);
        deleteshit(summ);
        free(a1);
        free(a2);
        free(a3);
    }
    return 0;
}

int testsumf() {
    FILE * tsfile = fopen("test/sumf.test","r");
    if (!tsfile) {
        fprintf(stderr, "testsumf(): TEST FILE NOT FOUND\n");
        return -1;
    }
    int n = 0; // amount test
    fscanf(tsfile, "%d", &n);
    for (int i = 1; i <= n; i++) {
        int n1;
        fscanf(tsfile, "%d", &n1);
        float *a1 = readf(tsfile, n1);

        float *a2 = readf(tsfile, n1);

        float *a3 = readf(tsfile, n1);

        vector * v1 = newVectorFn(a1, n1);
        vector * v2 = newVectorFn(a2, n1);
        vector * v3 = newVectorFn(a3, n1);
        vector * summ = sumf(v1, v2);
        if (memcmp(summ->head, v3->head, n1 * sizeof(float))) {
            fprintf(stdout ,"testsumf(): ERORR SUMI in test: %d" , i);
            deleteshit(v1);
            deleteshit(v2);
            deleteshit(v3);
            deleteshit(summ);
            free(a1);
            free(a2);
            free(a3);
            return -i;
        }
        deleteshit(v1);
        deleteshit(v2);
        deleteshit(v3);
        deleteshit(summ);
        free(a1);
        free(a2);
        free(a3);
    }
    return 0;
}
int testmulti() {
    FILE * tsfile = fopen("test/multi.test","r");
    if (!tsfile) {
        fprintf(stderr, "testmulti(): TEST FILE NOT FOUND\n");
        return -1;
    }
    int n = 0; // amount test
    fscanf(tsfile, "%d", &n);
    for (int i = 1; i <= n; i++) {
        int n1;
        fscanf(tsfile, "%d", &n1);
        int *a1 = readi(tsfile, n1);

        int *a2 = readi(tsfile, n1);

        vector * v1 = newVectorIn(a1, n1);
        vector * v2 = newVectorIn(a2, n1);
        int ans;
        fscanf(tsfile, "%d", &ans);
        int res = multi(v1, v2);
        if (ans != res) {
            fprintf(stderr ,"testmulti(): ERORR MULTI in test: %d" , i);
            deleteshit(v1);
            deleteshit(v2);
            free(a1);
            free(a2);
            return -i;
        }
        deleteshit(v1);
        deleteshit(v2);
        free(a1);
        free(a2);
    }
    return 0;
}

int testmultf() {
    FILE * tsfile = fopen("test/multf.test","r");
    if (!tsfile) {
        fprintf(stderr, "testmultf(): TEST FILE NOT FOUND\n");
        return -1;
    }
    int n = 0; // amount test
    fscanf(tsfile, "%d", &n);
    for (int i = 1; i <= n; i++) {
        int n1;
        fscanf(tsfile, "%d", &n1);
        float *a1 = readf(tsfile, n1);

        float *a2 = readf(tsfile, n1);

        vector * v1 = newVectorFn(a1, n1);
        vector * v2 = newVectorFn(a2, n1);

        float ans;
        fscanf(tsfile, "%f", &ans);

        float res = multf(v1, v2);
        if (ans != res) {
            fprintf(stderr ,"testmultf(): ERORR MULTF in test: %d" , i);
            deleteshit(v1);
            deleteshit(v2);
            free(a1);
            free(a2);
            return -i;
        }
        deleteshit(v1);
        deleteshit(v2);
        free(a1);
        free(a2);
    }
    return 0;
}


int test() {
    int errsum = 0;
    errsum += testmakeshit(); 
    errsum += testadd();

    errsum += testsumi(); 
    errsum += testsumf();
    errsum += testmulti();
    errsum += testmultf();
    return errsum;
}

