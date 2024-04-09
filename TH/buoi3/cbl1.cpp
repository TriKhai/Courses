#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAX_N 100
#define max(a, b) (a>b?a:b)
#define min(a, b) (a<b?a:b)
//#define swap(a, b) (a ^= b ^= a ^= b)

typedef struct {
	int w, v, sl=0;
	float dg;
	char name[MAX_N];
}Item;

typedef struct {
	Item Items[MAX_N];
	int W, n;
}Balo;

void swap(Item *a, Item *b) {
	Item tmp = *a;
	*a = *b;
	*b = tmp;
}

// Bubble Sort
void Sort(Balo *Bl) {
	int n = Bl->n;
	for(int i=0; i<n-1; i++) {
		for(int j=n-1; j>=i+1; j--) {
			if(Bl->Items[j].dg > Bl->Items[j-1].dg) {
				swap(&Bl->Items[j], &Bl->Items[j-1]);
			}
		}
	}
}

void ReadFile(Balo *Bl) {
	FILE *f = fopen("CaiBaLo1.txt", "r");
	fscanf(f, "%d", &Bl->W);
	int i = 0;
	while(!feof(f)) {
		fscanf(f, "%d%d%[^\n]", &Bl->Items[i].w, 
		&Bl->Items[i].v, &Bl->Items[i].name);
		Bl->Items[i].dg = (float)Bl->Items[i].v / Bl->Items[i].w;
		i++;
	}
	Bl->n=i;	
	fclose(f);
}

void printInput(Balo *Bl) {
	int i = 0;
	int n = Bl->n;
	printf("\n[%d-%d]\n", Bl->n, Bl->W);
	printf("+----+----+-------------------+-----+\n");
	printf("| gi | vi |       name        | dg  |\n");
	printf("|----+----+-------------------+-----|\n");
	while(i < n) {
		printf("|%3d |%3d |%-18s |%3.2f |\n", Bl->Items[i].w, 
		Bl->Items[i].v, Bl->Items[i].name, Bl->Items[i].dg);
		i++;
	}	
	printf("+----+----+-------------------+-----+\n");
}

void NhanhCan(Balo *Bl, int x[], int pTGT, int i, float *GTLNTT, int W) {
	int n = Bl->n;
	for(int j=W/Bl->Items[i].w; j>=0; j--) {
		float TGT, Wconlai, CT;
		TGT = pTGT + j*Bl->Items[i].v;//TGT
		Wconlai = W - j*Bl->Items[i].w;//W con lai
		CT = TGT + Wconlai*Bl->Items[i+1].dg;//can tren
		if(CT > *GTLNTT) {
			x[i]=j;
			if((i==n-1 || Wconlai == 0)&&TGT>*GTLNTT) {
				*GTLNTT = TGT;
				for(int k=0; k<n; k++) {
					Bl->Items[k].sl = x[k];
				}
			}
			else {
				NhanhCan(Bl, x, TGT, i+1, GTLNTT, Wconlai);
			}
		}
		x[i]=0;
	}
}

void printChart (Balo *B){
    int total_val = 0, total_weight = 0;
    int n = B->n, W = B->W;
    printf("+---+---------------------+-----------+-------+-------+---------+\n");
	printf("|%-3s|%-21s|%-11s|%-7s|%-7s|%-9s|\n", "STT", "     Ten do vat", "Trong luong", "Gia tri", "Don gia","Phuong an");
	printf("|---+---------------------+-----------+-------+-------+---------+\n");
	for(int i = 0, k = 1; i < n; i++){        
        printf("| %-2d| %-20s|%11d|%7d|%7.2f|%9d|\n", k++
		, B->Items[i].name, B->Items[i].w, B->Items[i].v, 
		B->Items[i].dg, B->Items[i].sl);
        total_val += B->Items[i].v*B->Items[i].sl;
        total_weight += B->Items[i].w*B->Items[i].sl;
	}	
	printf("+---+---------------------+-----------+-------+-------+---------+\n");	
	printf("Phuong an (theo thu tu DG giam dan): X(");
	for(int i=0; i<n-1; i++){
		printf("%d,", B->Items[i].sl);
	}	
	printf("%d)\n", B->Items[n-1].sl);
	printf("Trong luong cua ba lo = %5d\n", W);
    printf("Tong trong luong      = %5d\n", total_weight);
    printf("Tong gia tri          = %5d\n", total_val);
}

int main() {
	Balo Bl;
	ReadFile(&Bl);
	printInput(&Bl);
	Sort(&Bl);
	printInput(&Bl);
	float GTLNTT = 0;
	int x[MAX_N];
	NhanhCan(&Bl, x, 0, 0, &GTLNTT, Bl.W);
	printChart(&Bl);
	return 0;
}
