#include <stdio.h>

typedef struct {
	float doDai;
	int dau, cuoi;
} Canh;

void ReadData(Canh arr[], int *size, int *vertex) {
	FILE *f;
	f = fopen("TSP.txt", "r");
	fscanf(f, "%d", vertex);
	float tmp;
	for(int i=1; i<=*vertex; i++) {
		for(int j=1; j<=*vertex; j++) {
			if(j<=i) {
				fscanf(f, "%f", &tmp);
			} else {
				arr[*size].dau = i;
				arr[*size].cuoi = j;
				fscanf(f, "%f", &arr[*size].doDai);
				(*size)++;
			}
		}
	}
	fclose(f);
}

void printData(Canh arr[], int size) {
	int i = 0;
	while(i<size) {
		printf("[%d, %d] : %.2f\n", 
		arr[i].dau, arr[i].cuoi, arr[i].doDai);
		i++;
	}
}

void swap(Canh *x, Canh *y) {
	Canh tmp = *x;
	*x = *y;
	*y = tmp;
}

void BubleSort(Canh arr[], int size) {
	for(int i=0; i<size-1; i++) {
		for(int j=size-1; j >= i+1; j--) {
			if(arr[j].doDai < arr[j-1].doDai) {
				swap(&arr[j], &arr[j-1]);
			}
		}
	}
}

int dinhCap3(Canh PA[], int size, Canh newEdge) {
	int count = 1;
	int i = 0;
	while(i<size && count<3) {
		if(newEdge.dau == PA[i].dau || newEdge.dau == PA[i].cuoi) {
			count++;
		}
		i++;
	}
	if(count >= 3) {
		return 1;
	}
	count =1, i=0;
	while(i<size && count<3) {
		if(newEdge.cuoi == PA[i].dau || newEdge.cuoi == PA[i].cuoi) {
			count++;
		}
		i++;
	}
	return count==3;
}

void initForest(int parent[], int vertex) {
	for(int i=1; i<=vertex; i++) {
		parent[i]=i;
	}
}

int findRoot(int parent[], int u) {
	if(u==parent[u]) return u;
	return findRoot(parent, parent[u]);
}

void updateForest(int parent[], int r1, int r2) {
	parent[r2]=r1;
}

int chutrinh(int r_dau, int r_cuoi) {
	return r_dau==r_cuoi;
}

void Greedy(Canh arr[], int vertex, int size, Canh PA[]) {
	int parent[vertex];
	initForest(parent, vertex);
	int r_dau, r_cuoi;
	int i;
	int j=0;
	for(i=0; i<size && j<vertex-1; i++) {
		
		r_dau = findRoot(parent, arr[i].dau);
		r_cuoi = findRoot(parent, arr[i].cuoi);
		if(!dinhCap3(PA, size, arr[i]) && 
		!chutrinh(r_dau, r_cuoi)) {
			PA[j++] = arr[i];
			updateForest(parent, r_dau, r_cuoi);
		}	
	}
	
	for(; i<size; i++) {
		r_dau = findRoot(parent, arr[i].dau);
		r_cuoi = findRoot(parent, arr[i].cuoi);
		if(!dinhCap3(PA, size-1, arr[i]) && chutrinh(r_dau, r_cuoi)) {
			PA[vertex-1]=arr[i];
			break;
		}
	}
}
	
int printDataWithName(Canh arr[], int size) {
	char name[] = {'z' , 'a', 'b', 'c', 'd', 'e', 'f'};
	int i = 0, sum=0;
	while(i<size) {
		printf("[%c, %c] : %.2f\n", 
		name[arr[i].dau], name[arr[i].cuoi], arr[i].doDai);
		sum+=arr[i].doDai;
		i++;
	}
	return sum;
}	
	
int main() {
	
	Canh arr[50];
	Canh PA[50];
	int size = 0, vertex = 0;
	ReadData(arr, &size, &vertex);
	printf("Danh sach chua xep:\n");
	printf("size: %d, vertex: %d\n", size, vertex);
	printData(arr, size);
	
	printf("\nDanh sach da xep:\n");
	BubleSort(arr, size);
	printData(arr, size);
	
	printf("\nDuong di:\n");
	Greedy(arr, vertex, size, PA);
	int sumLength = printDataWithName(PA, vertex);
	printf("Tong do dai: %d", sumLength);
	
	return 0;
}
