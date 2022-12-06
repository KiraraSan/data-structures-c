#include "header.h"

int main(int argc, char *argv[]) {
	
	Max max;
	Stack S;
	int init = -1, menu, index;
	float harga;
	string judul, nama, jenis;
	
	do {
		system("cls");
		printf("\t===== Toko Buku Atma =====");
		printf("\n[1] Inisialisasi");
		printf("\n[2] Input Data");
		printf("\n[3] Ubah Data");
		printf("\n[4] Delete Data");
		printf("\n[5] Show Data");
		printf("\n[0] Exit");
		printf("\n>>> "); scanf("%d", &menu);
		
		switch(menu) {
			case 1 :
				if(init != 1) {
					inisialisasi(&S);
					init = 1;
					printf("\n\tInisialisasi berhasil");
				} else {
					printf("\n[!] Anda sudah inisialisasi");
				}
			break;
			
			case 2 :
				if(init != -1) {
					if(!isFull(S)) {
						printf("\nJudul Buku   : "); fflush(stdin); gets(max.judul);
						printf("Nama Penulis : "); fflush(stdin); gets(max.nama);
						printf("Jenis Buku   : "); fflush(stdin); gets(max.jenis);
					//	while(strcmpi((*S).max[i].jenis, "Novel")==0 && (*S).max[i].jenis, "Novel")
						printf("Harga        : "); scanf("%f", &max.harga);
						
						push(&S, max);
						printf("\n\t[*] Berhasil menginput data");
					} else {
						printf("\n[!] Stack Penuh ");
					}
				} else {
					printf("\n\t[!] Inisialisasi terlebih dahulu");
				}
			break;
			
			case 3 :
				if(init != -1) {	
					if(!isEmpty(S)) {
						edit(&S);
						printf("\n\t[*] Berhasil mengubah data");
					} else {
						printf("\n[!] Stack Kosong ");
					}
				} else {
					printf("\n\t[!] Inisialisasi terlebih dahulu");
				}
			break;
			
			case 4 :
				if(init != -1) {
					if(!isEmpty(S)) {
						printf("\nData %d berhasil dihapus", pop(&S));
					} else {
						printf("\nStack Kosong [!]");
					}
				} else {
					printf("\n\t[!] Inisialisasi terlebih dahulu");
				}
			break;
			
			case 5 :
				if(init != -1) {
					if(!isEmpty(S)) {
						show(S);
					} else {
						printf("\nStack Kosong [!]");
					}
				} else {
					printf("\n\t[!] Inisialisasi terlebih dahulu");
				}
			break;
			
			case 0 :
				printf("\n\tAlexis Divasonda Sigat Ngaing");
				printf("\n\tKelas A");
				printf("\n\t210711407");
				printf("\n\tSemoga harimu menyenangkan...");
			break;
		} getch();
	} while(menu!=0);
	return 0;
}
