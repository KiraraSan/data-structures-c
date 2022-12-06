#include "header.h"

int main(int argc, char *argv[]) {
	
	Mahasiswa m[5];
	string nama, npm;
	
	int menu, index;
	
	initMahasiswa(m);
	
	do {
		system("cls");
		printf("1. Tambah Data\n");
		printf("2. Tampil Data\n");
		printf("3. Hapus Data\n");
		printf("0. Keluar\n");
		printf(">>>> "); scanf("%d", &menu);
		
		switch(menu) {
			case 1 :
				index = isFull(m);
				if(isFull(m) != -1) {
					printf("\nMasukkan Nama Mahasiswa : "); fflush(stdin); gets(nama);
					printf("\nMasukkan NPM Mahasiswa  : "); fflush(stdin); gets(npm);
					
					m[index] = makeMahasiswa(nama, npm);
					printf("[+] Berhasil menambahkan data");
				} else {
					printf("[!] Data sudah penuh");
				}
			break;
			
			case 2 :
				tampilMahasiswa(m);
			break;
			
			case 3 :
				printf("\nMasukkan NPM Mahasiswa yang akan dihapus : "); fflush(stdin); gets(npm);
				hapusMahasiswa(m, npm);
			break;
			
			case 0 :
				printf("\n===== Keluar dari program =====");
			break;
			
			default : 
				printf("\n[!] Menu tidak tersedia");
			break;
		}
		getch();
	} while(menu != 0);
	
	return 0;
}
