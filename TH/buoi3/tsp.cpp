#include <stdio.h>
#define size 30
#define CMIN 3.40282e+38

typedef struct {
	float doDai;
	int dau, cuoi, daDung;
} Canh;


int ReadData(Canh arr[][size], int *soThanhPho) {
	FILE *f;
	f = fopen("tsp.txt", "r");
	fscanf(f, "%d", soThanhPho);
	float tmp;
	for(int i=1; i<=*soThanhPho; i++) {
		for(int j=1; j<=*soThanhPho; j++) {
			arr[i][j].dau = i;
			arr[i][j].cuoi = j;
			fscanf(f, "%f", &arr[i][j].doDai);
			arr[i][j].daDung = 0;
		}
	}
	fclose(f);
}

void printData(Canh arr[][size], int soThanhPho) {
	for(int i=1; i<=soThanhPho; i++) {
		for(int j=1; j<=soThanhPho; j++) {
			printf("%c%c=%-8.2f", arr[i][j].dau+64,
			 arr[i][j].cuoi+64, arr[i][j].doDai);
		}
		printf("\n");
	}
}

void reset(Canh arr[][size], int soThanhPho) {
	for(int i=1; i<=soThanhPho; i++) {
		for(int j=1; j<=soThanhPho; j++) {
			arr[i][j].daDung = 0;
		}
	}
}

float canhNhoNhat(Canh arr[][size], int soThanhPho) {
	float Cmin = CMIN;
	for(int i=1; i<=soThanhPho; i++) {
		for(int j=1; j<=soThanhPho; j++) {
			if(i!=j && !arr[i][j].daDung && arr[i][j].doDai<Cmin) {
				Cmin = arr[i][j].doDai;
			}
		}
	}
	return Cmin;
}

float canDuoi(Canh arr[][size], float TGT, int soThanhPho, int bacCuaNut) {
	return TGT+(soThanhPho-bacCuaNut)*canhNhoNhat(arr, soThanhPho);
}

int kiemTraChuTrinh(Canh x[], int k, int keTiep) {
	int coCT=0, i=0;
	while(i<k && !coCT) {
		if(keTiep == x[i].dau) coCT=1;
		else i++;
	}
	return coCT;
}

void CapNhatPATNTT(Canh arr[][size], int soThanhPho, float TGT, float *GiaNNTT, Canh x[], Canh PA[]) {
	x[soThanhPho]=arr[soThanhPho-1][x[1].dau];
	TGT = TGT+x[soThanhPho].doDai;
	if(*GiaNNTT>TGT) {
		*GiaNNTT = TGT;
		for(int i=1; i<=soThanhPho; i++) {
			PA[i]=x[i];
		}
	}
}

void NhanhCan(Canh arr[][size], int soThanhPho, int bacCuaNut, float *TGT, float *CD, float *GiaNNTT, Canh x[], Canh PA[]) {
	int j;//dinh ke tiep
	for(j=1; j<=soThanhPho; j++) {
		*TGT = *TGT + arr[dau][j].doDai;
		*CD = canDuoi(arr, *TGT, soThanhPho, bacCuaNut+1);
		if(*CD < *GiaNNTT) {
			x[bacCuaNut]=arr[dau][j];
			arr[dau][j].daDung=1;
			arr[j][dau].daDung=1;
			if(bacCuaNut == soThanhPho-2) {
				CapNhatPATNTT()
			} else {
				NhanhCan(arr, soThanhPho, bacCuaNut+1, j, TGT, CD, GiaNNTT, x, PA);
			}
		} 
		*TGT = *TGT = arr[dau][j].doDai;
		arr[dau][j].daDung=0;
		arr[j][dau].daDung=0;
	}
}

int main() {
	Canh arr[size][size];
	int soThanhPho;
	ReadData(arr, &soThanhPho);
	printData(arr, soThanhPho);
	
	return 0;
}
