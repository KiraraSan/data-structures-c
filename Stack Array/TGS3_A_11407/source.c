#include "header.h"

void inisialisasi(Stack *S) {
	(*S).top = -1;
}

void push(Stack *S, Max max) {
	(*S).top++;
	(*S).max[(*S).top] = max;
}

Max pop(Stack *S) {
	Max temp;
	
	temp = (*S).max[(*S).top];
	(*S).top--;
	
	return temp;
}

int found(Stack S, string judul) {
	int i;
	
	for(i=S.top; i!=-1; i--) {
		if(strcmpi(S.max[i].judul, judul)==0) {
			return i;
		}
	}
	return -1;
}

void show(Stack S) {
	int i;
	
	for(i=0; i!=S.top+1; i++) {
		printf("\nData ke-%d", i+1);
		printf("\nJudul Buku    : %s ", S.max[i].judul);
		printf("\nNama Penulis  : %s ", S.max[i].nama);
		printf("\nJenis Buku    : %s ", S.max[i].jenis);
		printf("\nHarga Buku    : %.2f", S.max[i].harga);
		printf("\n------------------------------------------------\n");
	}
}

void edit(Stack *S) {
	Max max;
	string judul, nama, jenis;
	float harga;
	int index;
	
	printf("\nJudul buku yang ingin diubah : "); fflush(stdin); gets(judul);
	index = found((*S), judul);
	
	if(found((*S), judul) != -1) {				
		printf("\nJudul Buku   : "); fflush(stdin); gets(max.judul);
		printf("\nNama Penulis : "); fflush(stdin); gets(max.nama);
		printf("\nJenis Buku   : "); fflush(stdin); gets(max.jenis);
		printf("\nHarga        : "); scanf("%f", &max.harga);
		
		(*S).top++;				
		(*S).max[index] = max;
		
		printf("\n\tBerhasil edit data...");
	} else {
		printf("\n\t[!] Judul tidak ditemukan");
	}
}

int isFull(Stack S) {
	return S.top == stackMAX - 1;
}

int isEmpty(Stack S) {
	return S.top == -1;
}

void inputDesc(Stack *S, Max max) {
	int i, n;
	Max value;
	
	for(i=0; i<stackMAX; ++i) {
		for(n=i+1; n<stackMAX; ++n) {
			if((*S).max[i].harga < (*S).max[n].harga) {
				value = (*S).max[i];
				(*S).max[i] = (*S).max[n];
				(*S).max[n] = value;
			}
		}
	}
}
