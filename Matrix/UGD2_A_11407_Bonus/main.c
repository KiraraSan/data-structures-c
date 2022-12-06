#include "header.h"

int main(int argc, char *argv[]) {
	
	Kursi K[ROW][COL];
	Index index;
	string z_nama, z_id, cek;
	int z_kode, menu;
	
	inisialisasi(K);
	
	do {
		system("cls");
		printf("\n===== SUS AIR [UNGUIDED] =====");
		printf("\n[1]. Input Data");
		printf("\n[2]. Edit Data");
		printf("\n[3]. Cari Data");
		printf("\n[4]. Tampil Data");
		printf("\n[5]. Hapus Data (Bonus)");
		printf("\n\n===== SUS AIR [TUGAS] =====");
		printf("\n[6]. Enkripsi Kode");
		printf("\n[7]. Enkripsi Data");
		printf("\n\n[0]. Keluar");
		printf("\n>>>> "); scanf("%d", &menu);
		
		switch(menu) {
			case 1 :
				printf("\n\t---- Input Data ----");
				printf("\n\tInput Index I : "); scanf("%d", &index.i);
				while(index.i < 0) {
					printf("\n\t[!] Index tidak boleh negatif");
					printf("\n\tInput Index I : "); scanf("%d", &index.i);
				}
				while(index.i > 7) {
					printf("\n\t[!] Index tidak boleh lebih dari 7");
					printf("\n\tInput Index I : "); scanf("%d", &index.i);
				}
				printf("\tInput Index N : "); scanf("%d", &index.n);
				while(index.n < 0) {
					printf("\n\t[!] Index tidak boleh negatif");
					printf("\n\tInput Index N : "); scanf("%d", &index.n);
				}
				while(index.n < 0) {
					printf("\n\t[!] Index tidak boleh lebih dari 4");
					printf("\n\tInput Index N : "); scanf("%d", &index.n);
				}
				
				if(cekIsi(K, index)) {
					printf("\n\t\t[!] Data sudah terisi");
				} else {
					printf("\n\tInput Nama Penumpang   : "); fflush(stdin); gets(z_nama);
					while(strlen(z_nama)==0) {
						printf("\n\t[!] Nama tidak boleh kosong\n");
						printf("\tInput Nama Penumpang  : "); fflush(stdin); gets(z_nama);
					}
					while(strcmpi(z_nama,"-")==0) {
						printf("\n\t[!] Nama tidak boleh -\n");
						printf("\tInput Nama Penumpang : "); fflush(stdin); gets(z_nama);
					}
					printf("\tInput ID Penumpang     : "); fflush(stdin); gets(z_id);
					while(strlen(z_id)==0) {
						printf("\n\t[!] ID tidak boleh kosong\n");
						printf("\tInput ID Penumpang     : "); fflush(stdin); gets(z_id);
					}
					while(strlen(z_id)!=5) {
						printf("\n\t[!] ID harus 5 digit\n");
						printf("\tInput ID Penumpang     : "); fflush(stdin); gets(z_id);
					}
					printf("\tInput Kode Kursi       : "); scanf("%d", &z_kode);
					while(z_kode < -1) {
						printf("\n\t[!] Kode kursi tidak boleh negatif\n");
						printf("\tInput Kode Kursi       : "); scanf("%d", &z_kode);
					}
					K[index.i][index.n] = create(z_nama, z_id, z_kode, "YES");
					printf("\n\t\t [*] Berhasil input data");
				}
			break;
			
			case 2 :
				if(isEmpty(K) != -1) {
					printf("\n\t---- Edit Data ----");
					printf("\n\tInput Index I : "); scanf("%d", &index.i);
					printf("\tInput Index N : "); scanf("%d", &index.n);
					
					if(!cekIsi(K, index)) {
						printf("\n\t\t[!] Data kosong");
					} else {
						printf("\n\tInput Nama Penumpang   : "); fflush(stdin); gets(z_nama);
						while(strlen(z_nama)==0) {
							printf("\n\t[!] Nama tidak boleh kosong\n");
							printf("\tInput Nama Penumpang  : "); fflush(stdin); gets(z_nama);
						}
						while(strcmpi(z_nama,"-")==0) {
							printf("\n\t[!] Nama tidak boleh -\n");
							printf("\tInput Nama Penumpang : "); fflush(stdin); gets(z_nama);
						}
						printf("\tInput ID Penumpang     : "); fflush(stdin); gets(z_id);
						while(strlen(z_id)==0) {
							printf("\n\t[!] ID tidak boleh kosong\n");
							printf("\tInput ID Penumpang     : "); fflush(stdin); gets(z_id);
						}
						while(strlen(z_id)!=5) {
							printf("\n\t[!] ID harus 5 digit\n");
							printf("\tInput ID Penumpang     : "); fflush(stdin); gets(z_id);
						}
						printf("\tInput Kode Kursi       : "); scanf("%d", &z_kode);
						while(z_kode < -1) {
							printf("\n\t[!] Kode kursi tidak boleh negatif\n");
							printf("\tInput Kode Kursi       : "); scanf("%d", &z_kode);
						}
							K[index.i][index.n] = create(z_nama, z_id, z_kode, "YES");
							printf("\n\t\t [*] Berhasil input data");
						}
				} else {
					printf("\n\t\t[!] Data kosong");
				}
			break;
			
			case 3 :
				if(isEmpty(K) != -1) {
					printf("\n\t---- Cari Data ----");
					printf("\n\tInput ID penumpang : "); fflush(stdin); gets(z_id);
					
					index = found(K, z_id);
					
					if(index.i != -1) {
						printf("\n\t[*] Data yang pertama ditemukan");
						printf("\n\tNama Penumpang : %s", K[index.i][index.n].nama);
						printf("\n\tID Penumpang   : %s", K[index.i][index.n].id);
						printf("\n\tKode Kursi     : %d", K[index.i][index.n].kode);
					} else {
						printf("\n\t[!] Penumpang tidak ditemukan");
					}
				} else {
					printf("\n\t\t[!] Data kosong");
				}
			break;
			
			case 4 :
				printf("\n\t\t     ---- Tampil Data Kursi ----\n\n");
				read(K);
			break;
			
			case 5 :
				if(isEmpty(K) != -1) {
					printf("\n\tInput Nama Penumpang : "); fflush(stdin); gets(z_nama);
					index = found(K, z_nama);
					
					if(index.i != -1) {
						int i;
						int n;
							
						strcpy(K[index.i][index.n].nama, "-");
						strcpy(K[index.i][index.n].id, "-");
						K[index.i][index.n].kode = -1;
						strcpy(K[index.i][index.n].cek, "-");	
					} else {
						printf("\n\t[!] Penumpang tidak ditemukan");
					}
				} else {
					printf("\n\t\t[!] Data kosong");
				}
			break;
			
			case 0 :
				printf("\n\t\tKeluar...");
				printf("\n\t\tAlexis Divasonda Sigat Ngaing");
				printf("\n\t\t210711407");
				printf("\n\t\tSemoga Harimu Menyenangkan");
			break;
			
			default :
				printf("\n\t[!] Menu invalid");
			break;
		} getch();
	} while(menu != 0);
	return 0;
}
