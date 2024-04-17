#include <stdio.h>
typedef struct {
	float doDai;
	int dau, cuoi;
}Canh;

typedef struct {
	Canh A[50];
	int PA[50];
	int m, n;	
}DoThi;

void READFILE(DoThi *G) {
	FILE *f = fopen("TSP.txt", "r");
	int n;
	G->m = 0;
	float tmp;
	fscanf(f, "%d", &n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i < j) {
				fscanf(f, "%f", &G->A[G->m].doDai);
				G->A[G->m].dau = i;
				G->A[G->m++].cuoi = j;
			} else {
				fscanf(f, "%f", &tmp);
			}
		}
	}
	G->n = n;
	fclose(f);
}

void PRINTDATA(DoThi *G) {
	int m = G->m; 
	for(int i=0; i<m; i++) {
		printf("%d-%d: %4.2f\n", G->A[i].dau, G->A[i].cuoi, G->A[i].doDai);
	}
}

void swap(Canh *x, Canh *y) {
	Canh tmp = *x;
	*x = *y;
	*y = tmp;
}

void BubbleSort(DoThi *G) {
	int m = G->m;
	for(int i=0; i<m-1; i++) {
		for(int j=m-1; j>i; j--) {
			if(G->A[j].doDai < G->A[j-1].doDai) {
				swap(&G->A[j], &G->A[j-1]);
			}
		}
	}
}

void initForest(Dothi *G, int parent) {
	for(int i=1; i<=G->n; i++) {
		G->A[i] = i;
	}
}

int checkDinhCap3(DoThi *G, Canh canhMoi) {
	int dem = 1;
	int i=0;
	while(i<G->m && dem<3) {
		if(canhMoi.dau == G->PA[i].dau || canhMoi.dau == G->PA[i].cuoi)
			dem++;
		i++;
	} 
	if(dem >= 3) return 1;//co dinh 3
	i = 0;
	dem = 1;
	while(i<G->m && dem<3) {
		if(canhMoi.cuoi == G->PA[i].dau || canhMoi.cuoi == G->PA[i].cuoi)
			dem++;
		i++;
	} 
	return dem >= 3;
}

int find_root(int parent[], int u) {
	if(u==parent[u]) return u;
	find_root(parent, parent[u]);
}

int chuTrinh(int source, int target) {
	return source == target;
}

void update_forest(int parent[], int start, int source) {
	parent[target]=source;
}

void TSP(DoThi *G) {
	//(1): sort
	BubbleSort(G);
	
	//(2): 
	int parent[50];
	initForest(G, parent);
	int source, target;
	int i, j=0;
	for(i=0; i<G->m && j<G->n-1; i++) {
		source = find_root(parent, G->A[i].dau);
		target = find_root(parent, G->A[i].cuoi);
		if(!checkDinhCap3(G, G->A[i]) && chuTrinh(source, target)) {
			G->PA[j++] = G->A[i];
		}
	}
}

int main() {
	DoThi G;
	READFILE(&G);
//	PRINTDATA(&G);
	
	PRINTDATA(&G);
	return 0;
}
