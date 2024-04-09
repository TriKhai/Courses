#include <stdio.h>

typedef struct {
	int gi, vi, PA = 0;
	float dg;
	char name[50];
} Product;

void ReadData(Product arr[], int *w, int *size) {
	FILE *f;
	f = fopen("CaiBalo3.txt", "r");
	fscanf(f, "%d", w);
	if(f==NULL) {
		printf("Loi mo file!\n");
		return;
	}
	int i=0;
	while(!feof(f)) {
		fscanf(f, "%d%d%[^\n]",
		&arr[i].gi, &arr[i].vi, &arr[i].name);
		arr[i].dg = (float)arr[i].vi/arr[i].gi;
		i++;
	}
	*size = i;
	fclose(f);
}

void printData(Product arr[], int size) {
	for(int i=0; i<size; i++) {
		printf("%d %d  %s %d %.2f\n",
		 arr[i].gi, arr[i].vi, arr[i].name, arr[i].PA, arr[i].dg);
	}
}

void printPricePerWeigth(Product arr[], int size) {
	for(int i=0; i<size; i++) {
		printf("%s %d\n", arr[i].name, arr[i].PA);
	}
}

void swap(Product *x, Product *y) {
	Product temp = *x;
	*x = *y;
	*y = temp;
}

void BubleSort(Product arr[], int size) {
	for(int i=0; i<size-1; i++) {
		for(int j=size-1; j>=i+1; j--) {
			if(arr[j].dg > arr[j-1].dg) {
				swap(&arr[j], &arr[j-1]);
			}
		}
	} 
}

int greedy(Product arr[], int size, int w) {
	int i=0, curWeigth = w, sumValue = 0, amount = 0;
	while(i<size && curWeigth>0) {
		if(curWeigth >= arr[i].gi) {
			arr[i].PA = 1;
			curWeigth -= arr[i].PA*arr[i].gi;
			sumValue += arr[i].PA*arr[i].vi;
		} 
		i++;
	}
//	printf("\n(%d)\n", curWeigth);
	return sumValue;
}

int main() {
	Product products[50];
	int w, size=0;
	printf("Init:\n");
	ReadData(products, &w, &size);
	printData(products, size);
	
	printf("\nSorted:\n");
	BubleSort(products, size);
	printData(products, size);
	
	printf("greedy\n");
	int sumValue = greedy(products, size, w);
	printPricePerWeigth(products, size);
	printf("%d ", sumValue);

	return 0;
}
