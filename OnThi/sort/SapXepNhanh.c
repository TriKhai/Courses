#include <stdio.h>

typedef struct 
{
    int key;
    float value;
} Record;

void swap(Record *x, Record *y) {
    Record tmp = *x;
    *x = *y;
    *y = tmp;
}

void READFILE(Record arr[], int *n) {
    (*n)=0;
    FILE *f = fopen("data.txt", "r");
    while(!feof(f)) {
        fscanf(f, "%d%f", &arr[(*n)].key, &arr[(*n)].value);
        (*n)++;
    }
    fclose(f);
}

void PRINTFILE(Record arr[], int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%-5d %-5.2f\n", arr[i].key, arr[i].value);
    }
}

int findPivot(Record arr[], int i, int j) {
    int key = arr[i].key;
    int k;
    for(k=i+1; k<=j; k++) {
        if(key != arr[k].key) {
            return (key>arr[k].key)?i:k;
        }
    }
    return -1;
}

int Partition(Record arr[], int L, int R, int pivot) {
    while (L<=R) {
        while(arr[L].key < pivot) L++;
        while(arr[R].key >=pivot) R--;
        if(L<R) {
            swap(&arr[L], &arr[R]);
        }
    }
    return L;
}


void QuickSort(Record arr[], int i, int j) {
    int indexPivot = findPivot(arr, i, j);
    if(indexPivot != -1) {
        int L = Partition(arr, i, j, arr[indexPivot].key);
        QuickSort(arr, i, L-1);
        QuickSort(arr, L, j);
    }
}

int main() {
    Record arr[50];
    int n=0;
    READFILE(arr, &n);
    PRINTFILE(arr, n);

    printf("\nQuick sort:\n");
    QuickSort(arr, 0, n-1);
    PRINTFILE(arr, n);
    return 0;
}
