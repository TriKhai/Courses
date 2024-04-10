#include <stdio.h>
#include <malloc.h>
#define MAX_N 100
#define MIN_F 3.4e38

typedef struct {
	float doDai;
	int dau, cuoi, daDung;
}Canh;

typedef struct {
	Canh E[MAX_N][MAX_N];
	int n;
} Graph;

void readFile(Graph *G) {
	FILE *f = fopen("TSP.txt", "r");
	fscanf(f, "%d", &G->n);
	int i, j;
	for(i=0; i<G->n; i++) {
		for(j=0; j<G->n; j++) {
			fscanf(f, "%f", &G->E[i][j].doDai);
			G->E[i][j].dau = i;
			G->E[i][j].cuoi = j;
			G->E[i][j].daDung = 0;
		}
	}
	fclose(f);
}

void printGraph(Graph *G) {
	printf("Do thi TSP:\n");
	int i, j;
	for(i=0; i<G->n; i++) {
		for(j=0; j<G->n; j++) {
			printf("%c-%c=%5.2f ", G->E[i][j].dau+97, G->E[i][j].cuoi+97, G->E[i][j].doDai);
		}
		printf("\n");
	}
}

void reset(Graph *G){
    for(int i = 0; i < G->n; i++){
        for(int j = 0; j < G->n; j++){
            G->E[i][j].daDung = 0;
        }
    }
}
Canh kq[MAX_N];
int canDuoi(Graph *G, float TGT, int bac) {
	float Cmin= MIN_F;
	for(int i=0; i<G->n; i++) {
		for(int j=0; j<G->n; j++) {
			if(i!=j && !G->E[i][j].daDung && G->E[i][j].doDai<Cmin) {
				Cmin=G->E[i][j].doDai;
			}
		}
	}
	return TGT+(G->n-bac)*Cmin;
}

int coChuTrinh(Canh x[], int k, int keTiep) {
	for(int i=0; i<k; i++) {
		if(x[i].dau == keTiep) {
			return 1;
		}
	}
	return 0;
}

void CapNhat(Graph *G, float TGT, float *GTNN, Canh x[]) {
	int n = G->n;
	x[G->n-1] = G->E[x[n-2].cuoi][x[0].dau];
	TGT+=x[n-1].doDai;
	if(TGT<*GTNN) {
		*GTNN=TGT;
		for(int i = 0; i < n; i++){
            kq[i] = x[i];
        }
	}
}

void NhanhCan(Graph *G, int bac, int dinhHienTai, Canh x[], float pTGT, float *GTNN) {
	int n=G->n;
	for(int keTiep=0; keTiep<n; keTiep++) {
		if(dinhHienTai!=keTiep 
		&& !G->E[dinhHienTai][keTiep].daDung 
		&& !coChuTrinh(x, bac, keTiep)) {
			float TGT = pTGT + G->E[dinhHienTai][keTiep].doDai;
			float CD = canDuoi(G, TGT, bac+1);
			if(CD < *GTNN) {
				x[bac]=G->E[dinhHienTai][keTiep];
				G->E[dinhHienTai][keTiep].daDung = 1;
				G->E[keTiep][dinhHienTai].daDung = 1;
				if(bac==n-2) {
					CapNhat(G, TGT, GTNN, x);
				} else 
					NhanhCan(G, bac+1, keTiep, x, TGT, GTNN);
			}
			G->E[dinhHienTai][keTiep].daDung = 0;
			G->E[keTiep][dinhHienTai].daDung = 0;
		}
	}
}

void printResult(Canh x[], int n){
    printf("Phuong an tim duoc:\n");
    for(int i = 0; i < n; i++){
        printf("  Canh %c%c = %5.2f\n", x[i].dau+97, x[i].cuoi+97, x[i].doDai);        
    }
    float sum = 0;
    printf("Chu trinh:\n  ");
    for(int i = 0; i < n; i++){
        printf("%c -> ", x[i].dau+97);
        sum += x[i].doDai;
    }
    printf("%c\n", x[0].dau+97);
    printf("Tong do dai cac canh cua chu trinh = %5.2f\n\n", sum);
}

int main() {
	printf("hello world");
	Graph G;
	readFile(&G);
	printGraph(&G);
	float GTNN = MIN_F;
	Canh x[MAX_N];
	NhanhCan(&G, 0, 0, x, 0, &GTNN);
	printResult(kq, G.n);
	return 0;
}
