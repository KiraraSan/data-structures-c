#include "header.h"

void initMahasiswa(Mahasiswa m[]) {
	int i;
	for(i=0; i<5; i++) {
		strcpy(m[i].nama, "-");
		strcpy(m[i].npm, "-");
	}
}

Mahasiswa makeMahasiswa(string nama, string npm) {
	Mahasiswa m;
	strcpy(m.nama, nama);
	strcpy(m.npm, npm);
	
	return m;
}

void tampilMahasiswa(Mahasiswa m[]) {
	int i;
	
	for(i=0; i<5; i++) {
		printf("===== DATA %d =====\n", i+1);
		printf("Nama Mahasiswa : %s\n", m[i].nama);
		printf("NPM Mahasiswa  : %s\n\n", m[i].npm);
	}
}

void hapusMahasiswa(Mahasiswa m[], string npm) {
	int i;
	
	for(i=0; i<5; i++) {
		if(strcmp(m[i].npm, npm)==0) {
			m[i] = makeMahasiswa("-", "-");
			printf("\n[+] Data telah dihapus");
			return;
		}
	}
	printf("\n[!] Data tidak ditemukan");
}

int isFull(Mahasiswa m[]) {
	int i;
	for(i=0; i<5; i++) {
		if(strcmpi(m[i].nama, "-")==0) {
			return i;
		}
	}
	return -1;
}
