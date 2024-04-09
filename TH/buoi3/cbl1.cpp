#include <stdio.h>
#define min(a, b) (a>b?b:a)

typedef struct {
	int GT, TL ,PA = 0;
	float DG;
	int soDVDuocChon;
	char name[50];
} DoVat;

void ReadData(DoVat arr[], int *w, int *size) {
	FILE *f;
	f = fopen("CaiBalo1.txt", "r");
	fscanf(f, "%d", w);
	if(f==NULL) {
		printf("Loi mo file!\n");
		return;
	}
	int i=0;
	while(!feof(f)) {
		fscanf(f, "%d%d%[^\n]", &arr[i].TL, &arr[i].GT, &arr[i].name);
		arr[i].DG = (float)arr[i].GT/arr[i].TL;
		i++;
	}
	*size = i;
	fclose(f);
}

void printData(DoVat arr[], int size) {
	for(int i=0; i<size; i++) {
		printf("%d %d %s %d %.2f\n", arr[i].TL, arr[i].GT, arr[i].name, arr[i].PA, arr[i].DG);
	}
}

void TaoNutGoc(float W, float *TGTConLai, float *TGT, float *CT, float *GiaLNTT, float DonGiaLonNhat) {
	*TGT = 	0.0;
	*TGTConLai = W;
	*CT = (*TGTConLai)*(DonGiaLonNhat);
	*GiaLNTT = 0.0;
}

void CapNhatGTLNTT(int x[], float *TGT, float *GiaLNTT, DoVat *dsdv, int n) {
	int i;
	if(*GiaLNTT < *TGT) {
		*GiaLNTT  = *TGT;
		for(i=0; i<n; i++) {
			dsdv[i].soDVDuocChon = x[i];
		}
	}
}

void NhanhCan(float *TGT, float *CT, float *TLConLai, float *GiaLNTT, int x[], int i, DoVat *dsdv, int n) {
	int j;
	int soDoVatLonNhatCoTheChon = *TLConLai/dsdv[i].TL;
	printf("%d", soDoVatLonNhatCoTheChon);
	for(j=soDoVatLonNhatCoTheChon; j>=0; j--) {
		*TGT = *TGT + j*dsdv[i].GT;
		*TLConLai -= j*dsdv[i].TL;
		if(*GiaLNTT < *CT) {
			x[i]=j;
			if(i==n-1 || *TLConLai==0.0)
				CapNhatGTLNTT(x, TGT, GiaLNTT, dsdv, n);
			else 
				NhanhCan(TGT, CT, TLConLai, GiaLNTT, x, i, dsdv, n);
		}
		x[i]=0;
		*TGT-=j*dsdv[i].GT;
		*TLConLai+=j*dsdv[i].TL;
	}
}

void swap(DoVat *x, DoVat *y) {
	DoVat temp = *x;
	*x = *y;
	*y = temp;
}

void BubleSort(DoVat arr[], int size) {
	for(int i=0; i<size-1; i++) {
		for(int j=size-1; j>=i+1; j--) {
			if(arr[j].DG > arr[j-1].DG) {
				swap(&arr[j], &arr[j-1]);
			}
		}
	} 
}

void printNhanhCan(DoVat *dsdv, int size) {
	for(int i=0; i<size; i++) {
		printf("%d\n", dsdv[i].soDVDuocChon);
	}
}

int main() {
	DoVat dsdv[50];
	int size, w;
	float TGT, TLConLai, GiaLNTT, CT;
	ReadData(dsdv, &w, &size);
	int x[size];
//	printData(dsdv, size);
	BubleSort(dsdv, size);
//	printData(dsdv, size);
	TaoNutGoc(w, &TLConLai, &TGT, &CT, &GiaLNTT, dsdv[0].DG);
	NhanhCan(&TGT, &CT, &TLConLai, &GiaLNTT, x, 0, dsdv, size);
	printNhanhCan(dsdv, size);
	return 0;
}
