#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

typedef struct {
	int numberMoney, solution;
	char nameMoney[MAX_LENGTH];
} Money;

void ReadData(Money arr[], int *n) {
	FILE *f;
	f = fopen("ATM.txt", "r");
	
	if(f==NULL) {
		printf("Loi mo file!\n");
		return;
	}
	int i=0;
	while(!feof(f)) {
		fscanf(f, "%d%[^\n]", &arr[i].numberMoney, &arr[i].nameMoney);
		arr[i++].solution = 0;
	}
	*n = i;
	fclose(f);
}

void swap(Money *x, Money *y) {
	Money temp = *x;
	*x = *y;
	*y = temp;
}

void BubleSort(Money arr[], int size) {
	for(int i=0; i<size-1; i++) {
		for(int j=size-1; j>=i+1; j--) {
			if(arr[j].numberMoney > arr[j-1].numberMoney) {
				swap(&arr[j], &arr[j-1]);
			}
		}
	} 
}

void PrintData(Money arr[], int n) {
	for(int i=0; i<n; i++) {
		printf("%d\t%s\t%d\n", arr[i].numberMoney, arr[i].nameMoney, arr[i].solution);
	}
}

void ATM(Money arr[], int size) {
	int exchangeMoney;
	printf("\nNhap tien can rut: ");
	scanf("%d", &exchangeMoney);
	int i = 0;
	while(i<size && exchangeMoney>0) {
		arr[i].solution = exchangeMoney/arr[i].numberMoney;
		exchangeMoney -= arr[i].solution*arr[i].numberMoney;
		i++;
	}
	printf("Tien rut dc la: \n");
	PrintData(arr, size);
}

void ATMnoSort(Money arr[], int size) {
	int exchangeMoney;
	printf("\nNhap tien can rut: ");
	scanf("%d", &exchangeMoney);
	for(int i=size-1; i>=0; i--) {
		arr[i].solution = exchangeMoney/arr[i].numberMoney;
		exchangeMoney -= arr[i].solution*arr[i].numberMoney;
	}
	printf("Tien rut dc la: \n");
	PrintData(arr, size);
} 

int main() {
	Money arr[MAX_LENGTH];
	int n;
	ReadData(arr, &n);
//	BubleSort(arr, n);
	PrintData(arr, n);
//	ATM(arr, n);
	ATMnoSort(arr, n);
	return 0;
}

