#include <stdio.h>

typedef struct {
    int key;
    float value;
} Record;

typedef struct {
    int size;
    Record A[50];
} Data;

void READFILE(Data *D) {
    FILE *f = fopen("data.txt", "r");
    int n = 0;
    while(!feof(f)) {
        fscanf(f, "%d%f", &D->A[n].key, &D->A[n].value);
        n++;
    }
    D->size = n;
    fclose(f);
}

void PRINTFILE(Data *D) {
    int i;
    int n = D->size;
    for(i=0; i<n; i++) {
        printf("%d %.2f\n", D->A[i].key, D->A[i].value);
    }
}

void swap(Record *x, Record *y) {
    Record tmp = *x;
    *x = *y;
    *y = tmp;
}

void sort(Data *D) {
    int i, j, n=D->size;
    for(i=0; i<n-1; i++) {
        for(j=n-1; j>i; j--) {
            if(D->A[j].key < D->A[j-1].key) {
                swap(&D->A[j], &D->A[j-1]);
            }
        }
    }
}

int main() {
    Data D;
    READFILE(&D);
    PRINTFILE(&D);

    printf("\nSort bups boof\n");
    sort(&D);
    PRINTFILE(&D);
    return 0;
}