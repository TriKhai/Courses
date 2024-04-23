#include <stdio.h>
typedef struct 
{
    int key;
    float value;
} Record;

void READFILE(Record arr[], int *n) {
    int i = 0;
    FILE *f = fopen("data.txt", "r");
    while(!feof(f)) {
        fscanf(f, "%d%f", &arr[i].key, &arr[i].value);
        i++;
    }
    (*n)=i;
    fclose(f);
}

void PRINT(Record arr[], int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%-5d %-5.2f\n", arr[i].key, arr[i].value);
    }
}

void swap(Record *x, Record *y) {
    Record tmp = *x;
    *x = *y;
    *y = tmp;
}

void pusDown(Record arr[], int s, int n) {
    int f = s;
    while(f<=(n-1)/2) {
        int L = 2*f+1;
        int R = 2*f+2;
        if(n == L) { // 1 con
            if(arr[L].key < arr[f].key) {
                swap(&arr[f], &arr[L]);
            }
            return;
        }
        // 2 con
        if(arr[f].key > arr[L].key && arr[R].key >= arr[L].key) {
            swap(&arr[f], &arr[L]);
            f=L;
        } else if(arr[f].key > arr[R].key && arr[R].key < arr[L].key) {
            swap(&arr[f], &arr[R]);
            f=R;
        } else return;
    }
}

void HeapSort(Record arr[], int n) {
    int i;
    // tao heap
    for(i=(n-2)/2; i>=0; i--) {
        pusDown(arr, i, n-1);
    }
    // sap xep
    for(i=(n-1); i>=2; i--) {
        swap(&arr[0], &arr[i]);
        pusDown(arr, 0, i-1);
    }
    swap(&arr[0], &arr[1]);
}

void heap(Record arr[], int n) {
    int i;
    for(i=(n-2)/2; i>=0; i--) {
        pusDown(arr, i, n-1);
    }
    for(i=n-1; i>=2; i--) {
        swap(&arr[0], &arr[i]);
        pusDown(arr, 0, i-1);
    }
    swap(&arr[0], &arr[1]);
}

int main() {
    Record arr[50];
    int n;
    READFILE(arr, &n);
    PRINT(arr, n);
    printf("Heap sort\n");
    HeapSort(arr, n);
    PRINT(arr, n);
    return 0;
}