#include <stdio.h>

typedef struct {
    float dodai;
    int dau, cuoi, PA;
} Canh;

typedef struct {
	Canh E[50][50];
	int n;
} Graph;

void READFILE(Graph *G) {
    FILE *f = fopen("TSP.txt", "r");
    int n, i, j;
    fscanf(f, "%d", &n);
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            fscanf(f, "%f", &G->E[i][j].dodai);
            G->E[i][j].dau = i;
            G->E[i][j].cuoi = j;
            G->E[i][j].PA = 0;
        }
    }
    G->n=n;
    fclose(f);
}

void PRINT(Graph *G) {
    int i, j, n = G->n;
    printf("%d\n", n);
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%-5.2f ", G->E[i][j].dodai);
        }
        printf("\n");
    }
}

float CanDuoi(Graph *G, float TGT, int bac) {
    float Cmin = 9999;
    int i, j, n=G->n; 
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i!=j && !G->E[i][j].PA && G->E[i][j].dodai < Cmin) {
                Cmin = G->E[i][j].dodai;
            }
        }
    }
    return TGT+(n-bac)*Cmin;
}

int ktraChuTrinh(Canh x[], int bac, int ke) {
    int i;
    for(i=0; i<bac; i++) {
        if(x[i].dau == ke) 
            return 1;
    }
    return 0;
}
Canh kq[50];
void capNhat(Graph *G, float TGT, float *GTNN, Canh x[]) {
    int n=G->n;
    x[n-1] = G->E[x[n-2].cuoi][x[0].dau];
    TGT+=x[n-1].dodai;
    if(TGT<*GTNN) {
        *GTNN = TGT;
        int i;
        for(i=0; i<n; i++) {
            kq[i] = x[i];
        }
    }
}

void NhanhCan(Graph *G, int bac, int curDinh, float pTGT, float *GTNN, Canh x[]) {
    int n=G->n, k;
    for(k=0; k<n; k++) {
        if(k!=curDinh && !G->E[curDinh][k].PA && !ktraChuTrinh(x, bac, k)) {
            float TGT = pTGT + G->E[k][curDinh].dodai;
            float CD = CanDuoi(G, TGT, bac+1);
            if(CD < *GTNN) {
                x[bac]=G->E[curDinh][k];
                G->E[curDinh][k].PA = 1;
                G->E[k][curDinh].PA = 1;
                if(bac == n-2) {
                    capNhat(G, TGT, GTNN, x);
                } else {
                    NhanhCan(G, bac+1, k, TGT, GTNN, x);
                }
            }
            G->E[curDinh][k].PA = 0;
            G->E[k][curDinh].PA = 0 ;
        }
    }
 }

 
void printResult(Canh kq[], int n){
    printf("Phuong an tim duoc:\n");
    for(int i = 0; i < n; i++){
        printf("  Canh %c%c = %5.2f\n", kq[i].dau+97, kq[i].cuoi+97, kq[i].dodai);        
    }
    float sum = 0;
    printf("Chu trinh:\n  ");
    for(int i = 0; i < n; i++){
        printf("%c -> ", kq[i].dau+97);
        sum += kq[i].dodai;
    }
    printf("%c\n", kq[0].dau+97);
    printf("Tong do dai cac canh cua chu trinh = %5.2f\n\n", sum);
}


int main() {
    Graph G;
    READFILE(&G);
    PRINT(&G);
    float GTNN = 9999;
    Canh x[50];
    NhanhCan(&G, 0, 0, 0, &GTNN, x);
    printResult(kq, G.n);
    return 0;
}