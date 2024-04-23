#include <stdio.h>
#define min(a, b) (a>b?b:a);
typedef struct {
    int g, v, PA, sl;
    float dg;
    char ten[50];
} item;

void READFILE(item arr[], int *size, int *W) {
    int n=0, m;
    FILE *f = fopen("CaiBalo2.txt", "r");
    fscanf(f, "%d", &m);
    while(!feof(f)) {
        fscanf(f, "%d%d%d%[^\n]", &arr[n].g, &arr[n].v, &arr[n].sl, &arr[n].ten);
        arr[n].dg = (float)arr[n].v/arr[n].g;
        arr[n].PA=0;
        n++;
    }
    (*size)=n;
    (*W)=m;
    fclose(f);
}

void PRINT(item arr[], int n, int W) {
    printf("%d\n", W);
    int i;
    for(i=0; i<n; i++) {
        printf("%d %d %d %s %.2f\n",
		 arr[i].g, arr[i].v, arr[i].sl, arr[i].ten, arr[i].dg);
    }
}	

void swap(item *x, item *y) {
    item tmp = *x;
    *x = *y;
    *y = tmp;
}

void bbsort(item arr[], int n) {
    int i, j;
    for(i=0; i<n-1; i++) {
        for(j=n-1; j>i; j--) {
            if(arr[j].dg > arr[j-1].dg) {
                swap(&arr[j], &arr[j-1]);
            }
        }
    }
}

void greedy(item arr[], int n, int W) {
    int i=0;
    for(i=0; i<n; i++) {
        arr[i].PA = min(arr[i].sl, W/arr[i].g);
        W-=arr[i].g*arr[i].PA;
    }
}

void printPA(item arr[], int n, int W) {
    int sum = 0;
    int i;
    for(i=0; i<n; i++) {
        printf("PA = %d\n", arr[i].PA);
        sum+=arr[i].PA*arr[i].v;
        W -= arr[i].PA*arr[i].g;
    }

    printf("sum value = %d\n", sum);
    printf("w con lai = %d\n", W);
}

int main() {
    item arr[50];
    int n, W;
    READFILE(arr, &n, &W);
    PRINT(arr, n, W);
    bbsort(arr, n);
    printf("\nsorrt\n");
    PRINT(arr, n, W);
    printf("\ngreedy\n");
    greedy(arr, n, W);
    printPA(arr, n, W);
    return 0;
}
