#include <stdio.h>

typedef struct {
    int key;
    float value;
} Record;

typedef struct {
    Record A[50];
    int size;
} Data;

void swap(Record *x, Record *y) {
    Record tmp = *x;
    *x = *y;
    *y = tmp;
}

void READFILE(Data *D) {
    int n=0;
    FILE *f = fopen("data.txt", "r");
    while(!feof(f)) {
        fscanf(f, "%d%f", &D->A[n].key, &D->A[n].value);
        n++;
    }
    D->size=n;
    fclose(f);
}
void PRINTFILE(Data *D) {
    int i, n=D->size;
    for(i=0; i<n; i++) {
        printf("%d %.2f\n", D->A[i].key, D->A[i].value);
    }
}

void sort(Data *D) {
    int i, j;
    int n = D->size;
    for(i=1; i<n; i++) {
        j=i;
        while(j>0 && D->A[j].key < D->A[j-1].key) {
            swap(&D->A[j], &D->A[j-1]);
            j--;
        }
    }
}

int main() {
    Data D;
    READFILE(&D);
    PRINTFILE(&D);

    printf("\nSap Xep Xen:\n");
    sort(&D);
    PRINTFILE(&D);
    return 0;
}