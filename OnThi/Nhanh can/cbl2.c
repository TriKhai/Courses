#include <stdio.h>
#define min(a, b) (a>b)?b:a;
typedef struct {
    int g, v, PA, sl;
    float dg;
    char name[50];
} BL;

void readData(BL arr[], int *W, int *n) {
    int i=0, m;
    FILE *f = fopen("CaiBalo2.txt", "r");
    fscanf(f, "%d", &m);
    while(!feof(f)) {
        fscanf(f, "%d%d%d%[^\n]", &arr[i].g, &arr[i].v, &arr[i].sl, &arr[i].name);
        arr[i].dg = (float)arr[i].v/arr[i].g;
        arr[i].PA=0;
        i++;
    }
    (*n)=i;
    (*W)=m;
    fclose(f);
}

void print(BL arr[], int W, int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%-5d %-5d %-5d %s %-5.2f\n", arr[i].g, arr[i].v, arr[i].sl, arr[i].name, arr[i].dg);
    }
    printf("%d\n\n", W);
}

void swap(BL *a, BL *b) {
	BL tmp = *a;
	*a = *b;
	*b = tmp;
}

// Bubble Sort
void Sort(BL arr[], int n) {
	for(int i=0; i<n-1; i++) {
		for(int j=n-1; j>=i+1; j--) {
			if(arr[j].dg > arr[j-1].dg) {
				swap(&arr[j], &arr[j-1]);
			}
		}
	}
}

void NhanhCan(BL arr[], int W, int n, float pTGT, float *GTLNTT, int bac, int x[]) {
    printf("%d\n",W);
    int PA = min(W/arr[bac].g, arr[bac].sl);
    do {
        float TGT = pTGT + PA*arr[bac].v;
        int curW = W - PA*arr[bac].g;
        float CT = TGT+W*arr[bac+1].dg;
        if(CT>*GTLNTT) {
            x[bac] = PA;
            if((bac==n-1|| curW==0) && TGT>*GTLNTT) {
                (*GTLNTT)=TGT;
                int k;
                for(k=0; k<n; k++) {
					arr[k].PA = x[k];
				}
            } else {
                NhanhCan(arr, curW, n, TGT, GTLNTT, bac+1, x);
            }
        } 
        x[bac]=0;
        PA--;
    } while (PA>=0);
}

void printChart (BL arr[], int n, int W){
    int total_val = 0, total_weight = 0;
    printf("+---+---------------------+-----------+-------+-------+---------+\n");
	printf("|%-3s|%-21s|%-11s|%-7s|%-7s|%-9s|\n", "STT", "     Ten do vat", "Trong luong", "Gia tri", "Don gia","Phuong an");
	printf("|---+---------------------+-----------+-------+-------+---------+\n");
	for(int i = 0, k = 1; i < n; i++){        
        printf("| %-2d| %-20s|%11d|%7d|%7.2f|%9d|\n", k++
		, arr[i].name, arr[i].g, arr[i].v, 
		arr[i].dg, arr[i].PA);
        total_val += arr[i].v*arr[i].PA;
        total_weight += arr[i].g*arr[i].PA;
	}	
	printf("+---+---------------------+-----------+-------+-------+---------+\n");	
	printf("Phuong an (theo thu tu DG giam dan): X(");
	for(int i=0; i<n-1; i++){
		printf("%d,", arr[i].PA);
	}	
	printf("%d)\n", arr[n-1].PA);
	printf("Trong luong cua ba lo = %5d\n", W);
    printf("Tong trong luong      = %5d\n", total_weight);
    printf("Tong gia tri          = %5d\n", total_val);
}


int main() {
    BL arr[50];
    int W, n;
    readData(arr, &W, &n);
    print(arr, W, n);
    Sort(arr, n);
    print(arr, W, n);
    float GTLNTT = -9999;
    int x[50];
    NhanhCan(arr, W, n, 0, &GTLNTT, 0, x);
    printChart(arr, n, W);
    
    return 0;
}