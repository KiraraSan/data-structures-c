#include "header.h"

int main(int argc, char *argv[]) {
	
	Max max, index, z;
	Stack S, z_novel, z_majalah, z_biografi;
	int init = -1, menu, index2, i;
	float harga;
	string judul, nama, jenis;
	
	do {
		system("cls");
		printf("\t===== Toko Buku Atma =====");
		printf("\n[1] Inisialisasi");
		printf("\n[2] Input Data");
		printf("\n[3] Ubah Data");
		printf("\n[4] Delete Data");
		printf("\n[5] Show Data\n");
		printf("\n\t===== BONUS (Sekaligus Tugas) =====");
		printf("\n[6] Input Data Descending");
		printf("\n[7] Delete Data At");
		printf("\n[8] Cluster");
		printf("\n[0] Exit");
		printf("\n>>> "); scanf("%d", &menu);
		
		switch(menu) {
			case 1 :
				if(init != 1) {
					inisialisasi(&S);
					inisialisasi(&z_novel);
					inisialisasi(&z_majalah);
					inisialisasi(&z_biografi);
					init = 1;
					printf("\n\tInisialisasi berhasil...");
				} else {
					printf("\n\t[!] Anda sudah inisialisasi");
				}
			break;
			
			case 2 :
				if(init != -1) {
					if(!isFull(S)) {
						printf("\nJudul Buku   : "); fflush(stdin); gets(max.judul);
						printf("Nama Penulis : "); fflush(stdin); gets(max.nama);
						printf("Jenis Buku   : "); fflush(stdin); gets(max.jenis);
						while(strcmpi(max.jenis, "Novel")!=0 && strcmpi(max.jenis, "Biografi")!=0 && strcmpi(max.jenis, "Majalah")!=0) {
							printf("\n[!] Jenis tidak tersedia (Novel, Biografi, dan Majalah)");
							printf("\nJenis Buku   : "); fflush(stdin); gets(max.jenis);
						}
						printf("Harga        : "); scanf("%f", &max.harga);
						
						push(&S, max);
						printf("\n\t[*] Berhasil menginput data");
					} else {
						printf("\n[!] Stack Penuh");
					}
				} else {
					printf("\n\t[!] Inisialisasi terlebih dahulu");
				}
			break;
			
			case 3 :
				if(init != -1) {	
					if(!isEmpty(S)) {
						edit(&S);
					} else {
						printf("\n[!] Stack Kosong");
					}
				} else {
					printf("\n\t[!] Inisialisasi terlebih dahulu");
				}
			break;

			case 4 :
				if(init != -1) {
					if(!isEmpty(S)) {
						index = pop(&S);
						printf("\nJudul Buku    : %s", index.judul);
						printf("\nNama Penulis  : %s", index.nama);
						printf("\nJenis Buku    : %s", index.jenis);
						printf("\nHarga Buku    : %.2f", index.harga);
						printf("\n\n\tData berhasil dihapus...");
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
			
			case 6 :
				if(init != -1) {
					if(!isFull(S)) {
						printf("\nJudul Buku   : "); fflush(stdin); gets(max.judul);
						printf("Nama Penulis : "); fflush(stdin); gets(max.nama);
						printf("Jenis Buku   : "); fflush(stdin); gets(max.jenis);
						while(strcmpi(max.jenis, "Novel")!=0 && strcmpi(max.jenis, "Biografi")!=0 && strcmpi(max.jenis, "Majalah")!=0) {
							printf("\n[!] Jenis tidak tersedia (Novel, Biografi, dan Majalah)");
							printf("\nJenis Buku   : "); fflush(stdin); gets(max.jenis);
						}
						printf("Harga        : "); scanf("%f", &max.harga);
						
						inputDesc(&S, max);
						push(&S, max);
						
						printf("\n\t[*] Berhasil menginput data");
					} else {
						printf("\nStack Kosong [!]");
					}
				} else {
					printf("\n\t[!] Inisialisasi terlebih dahulu");
				}	
			break;
			
			case 7 :
				if(init != -1) {
					if(!isEmpty(S)) {
						printf("\nInput judul buku yang ingin dihapus : "); fflush(stdin); gets(judul);
						index2 = found(S, judul);
						if(found(S, judul) != -1) {
							strcpy(S.max[index2].judul, "-");
							strcpy(S.max[index2].nama, "-");
							strcpy(S.max[index2].jenis, "-");
							S.max[index2].harga = 0;

							pop(&S);
							printf("\n\n\tData berhasil dihapus...");
						}
					} else {
						printf("\nStack Kosong [!]");
					}
				} else {
					printf("\n\t[!] Inisialisasi terlebih dahulu");
				}
			break;
			
			case 8 :
				if(init != -1) {
					if(!isEmpty(S)) {
						int i;
						
						for(i=0; i != S.top+1; i++) {
							if(strcmpi(S.max[i].jenis, "Novel")==0) {
								push(&z_novel, max);
							}
							if(strcmpi(S.max[i].jenis, "Majalah")==0) {
								push(&z_majalah, max);
							}
							if(strcmpi(S.max[i].jenis, "Biografi")==0) {
								push(&z_biografi, max);
							}
						}
						printf("\nData Novel\n");
						for(i=0; i != z_novel.top+1; i++) {
							printf("\n| %s - %s - %.2f |\n", z_novel.max[i].judul, z_novel.max[i].nama, z_novel.max[i].harga);
						}
						printf("\nData Majalah\n");
						for(i=0; i != z_majalah.top+1; i++) {
							printf("\n| %s - %s - %.2f |\n", z_majalah.max[i].judul, z_majalah.max[i].nama, z_majalah.max[i].harga);
						}
						printf("\nData Biografi\n");
						for(i=0; i != z_biografi.top+1; i++) {
							printf("\n| %s - %s - %.2f |\n", z_biografi.max[i].judul, z_biografi.max[i].nama, z_biografi.max[i].harga);
						}
					} else {
						printf("\nStack Kosong [!]");
					}
				} else {
					printf("\n\t[!] Inisialisasi terlebih dahulu");
				}
			break;
			
			case 0 :
				printf("\n\tAlexis Divasonda Sigat Ngaing - A - 210711407");
				printf("\n\tSemoga harimu menyenangkan...");
			break;
			
			default :
				printf("\n\t[!] Menu tidak tersedia");
			break;
		} getch();
	} while(menu!=0);
	return 0;
}
