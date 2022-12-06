#include "header.h"

void inisialisasi(Motor M[]) {
	int i;
	
	for(i=0; i<motorMAX; i++) {
		strcpy(M[i].nama, "-");
		strcpy(M[i].merk, "-");
		M[i].cc = 0;
		strcpy(M[i].plat, "-");
	}
}

void create(Motor M[], string nama, string merk, int cc, string plat, int temp) {
	strcpy(M[temp].nama, nama);
	strcpy(M[temp].merk, merk);
	M[temp].cc = cc;
	strcpy(M[temp].plat, plat);
}

void read(Motor M[]) {
	int i;
	
	for(i=0; i<motorMAX; i++) {
		if(strcmpi(M[i].nama, "-")!=0) {
			printf("\n--- Data %d ---\n", i+1);
			printf("Nama Pemilik : %s\n", M[i].nama);
			printf("Merk Motor   : %s\n", M[i].merk);
			printf("CC           : %s\n", M[i].cc);
			printf("Plat Nomor   : %s\n", M[i].plat);
		}
	}
}

int isFound(Motor M[], string plat) {
	int i;
	
	for(i=0; i<motorMAX; i++) {
		if(strcmpi(M[i].plat, plat)==0) {
			return i;
		}
	}
	return -1;
}
/*
void ubah(Motor M[], string nama, string merk, string cc, string plat, int index) {
	strcpy(M[index].nama, nama);
	strcpy(M[index].merk, merk);
	strcpy(M[index].cc, cc);
	strcpy(M[index].plat, plat);
}
*/

void hapus(Motor M[], string nama) {
	int i = isFound(M, nama);
	
	strcpy(M[i].nama, "-");
	strcpy(M[i].merk, "-");
	M[i].cc = 0;
	strcpy(M[i].plat, "-");
}

void update(Motor M[], string z_plat) {
	string nama, merk, plat;
	int i, cc;
	
	printf("\nNama   : "); fflush(stdin); gets(nama);
	printf("Merk   : "); fflush(stdin); gets(merk);
	printf("CC     : "); scanf("%d", &cc);
	printf("Plat   : "); fflush(stdin); gets(plat);
	
	i = isFound(M, z_plat);
	
	strcpy(M[i].nama, nama);
	strcpy(M[i].merk, merk);
	M[i].cc = cc;
	strcpy(M[i].plat, plat);
}

int isFull(Motor M[]) {
	int i;
	
	for(i=0; i<motorMAX; i++) {
		if(strcmpi(M[i].nama, "-")==0) {
			return i;
		}
	}
	return -1;
}

int isEmpty(Motor M[]) {
	int i;
	
	for(i=0; i<motorMAX; i++) {
		if(strcmpi(M[i].nama, "-")!=0) {
			return i;
		}
	}
	return -1;
}

int getEmpty(Motor M[]) {
	int i;
	
	for(i=0; i<motorMAX; i++) {
		if(strcmpi(M[i].nama, "-")==0) {
			return i;
		}
	}
	return -1;
}

