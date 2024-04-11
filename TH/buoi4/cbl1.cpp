#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_N 50
typedef struct {
	int gi, vi, sl=0;
	char name[MAX_N];
} Item;

typedef struct {
	Item items[MAX_N];
	int n, W;
} Balo;
typedef struct bang[50][50];

void readFile(Balo *B) {
	FILE *f = fopen("QHD_CaiBalo1.txt", "r");
	fscanf(f, "%d", &B->W);
	int i=0;
	
	while(!feof(f)) {
		fscanf(f, "%d%d%[^\n]", &B->items[i].gi, &B->items[i].vi, &B->items[i].name);
		i++;
	}
	B->n=i;
	fclose(f);
}

void printFile(Balo *B) {
	for(int i=0; i<B->n; i++) {
		printf("%d %d %s %d\n", B->items[i].gi, B->items[i].vi, B->items[i].name, B->items[i].sl);
	}
	printf("%d %d", B->n, B->W);
}

void TaoBang(Balo *B, bang F, bang X) {
	int xk, ykm k, Fmax, Xmax;
	int W = B->W, n = B->n;
	
	for(int i=0; i<=W; i++) {
		X[0][i] = i/B->items[0].gi;
		V[0][i] = X[0][i]*B->items[0].vi;
	}
	
	for(int i=1; i<n; i++) {
		for(int j=0; j<-W; j++) {
			F[i][j] = F[i-1][j];
            X[i][j] = 0;
            int max_qty = j/B->items[i].gi;
			for(int k = 1; k <= max_qty; k++){
                if(k*B->items[i].vi + F[i-1][j-k*B->items[i].gi] > F[i][j]){
                    F[i][j] = k*B->items[i].vi	 + F[i-1][j-k*B->items[i].gi];
                    X[i][j] = k;
                }
            }
		}
	}
}

int main() {
	Balo B;
	readFile(&B);
	printFile(&B);
	return 0;
}
