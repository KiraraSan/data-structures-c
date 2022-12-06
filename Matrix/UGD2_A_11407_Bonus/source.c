#include "header.h"

void inisialisasi(Kursi K[ROW][COL]) {
	int i;
	int n;
	
	for(i=0; i<ROW; i++) {
		for(n=0; n<COL; n++) {
			strcpy(K[i][n].nama, "-");
			strcpy(K[i][n].id, "-");
			K[i][n].kode = -1;
			strcpy(K[i][n].cek, "-");
		}
	}
}

Kursi create(string nama, string id, int kode, string cek) {
	Kursi temp;
	
	strcpy(temp.nama, nama);
	strcpy(temp.id, id);
	temp.kode = kode;
	strcpy(temp.cek, cek);
	
	return temp;
}

Index found(Kursi K[ROW][COL], string cari) {
	int i;
	int n;
	Index index;
	
	index.i = -1;
	
	for(i=0; i<ROW; i++) {
		for(n=0; n<COL; n++) {
			if(strcmpi(K[i][n].id, cari)==0) {
				index.i = i;
				index.n = n;
				
				return index;
			}
		}
	}
	return index;
}

int isEmpty(Kursi K[ROW][COL]) {
	int i, n;
	
	for(i=0; i<ROW; i++) {
		for(n=0; n<COL; n++) {
			if(strcmpi(K[i][n].nama, "-")!=0) {
				return i;
			}	
		}	
	}
	return -1;
}

bool cekIsi(Kursi K[ROW][COL], Index index) {
	if(strcmpi(K[index.i][index.n].cek, "-")) {
		return true;
	} else {
		return false;
	}
}

void read(Kursi K[ROW][COL]) {
	int i;
	int n;
	
	for(i=0; i<ROW; i++) {
		printf("\t");
		for(n=0; n<COL; n++) {
			printf("[%s]\t\t", K[i][n].id);
		}
		printf("\n");
	}
}
