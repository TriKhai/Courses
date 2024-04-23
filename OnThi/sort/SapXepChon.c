#include <stdio.h>
#define MAX_N 50

typedef struct {
    int key;
    float value;
} Record;

typedef struct {
    Record A[MAX_N];
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
    if(f!=NULL) {
        while(!feof(f)) {
            fscanf(f, "%d%f", &D->A[n].key, &D->A[n].value);
            n++;
        }
        D->size = n;
    } else {
        printf("Loi doc file!\n");
    }
    fclose(f);
}

void PRINTFILE(Data *D) {
    int i;
    int n = D->size; 
    for(i=0; i<n; i++) {
        printf("%d %.3f\n", D->A[i].key, D->A[i].value);
    }
}

void SXChon(Data *D) {
    int i,j;
    int n = D->size;
    for(i=0; i<n; i++) {
        int index=i, key=D->A[i].key;
        for(j=i+1; j<n; j++) {
            if(key > D->A[j].key) {
                index = j;
                key = D->A[j].key;
            }
        }
        swap(&D->A[i], &D->A[index]);
    }
}


int main() {
    Data D;
    READFILE(&D);
    PRINTFILE(&D);
    
    printf("Section sort:\n");
    SXChon(&D);
    PRINTFILE(&D);

    return 0;
}