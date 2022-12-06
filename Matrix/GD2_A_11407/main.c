#include "header.h"

int main(int argc, char *argv[]) {
	Data data[ROW][COL];
	
	int i;
	int j;
	int menu;
	int angka;
	Index index;
	
	initMatriks(data);
	
	do {
		system("cls");
		printf("\n\t===== Guided Matrix =====");
		printf("\nNama : Alexis Divasonda Sigat Ngaing");
		printf("\nNPM  : 210711407");
		printf("\n[1]. Isi Data");
		printf("\n[2]. Cari Data");
		printf("\n[3]. Print Data");
		printf("\n[0]. Keluar");
		printf("\n>>>> "); scanf("%d", &menu);
		
		switch(menu) {
			case 1 :
				printf("\n\t==== Input Data ====");
				do {
					printf("\n\n\tIndex I : "); scanf("%d", &index.i);
					if(index.i < 0) {
						printf("\t\t[!] Index tidak boleh < 0\n");
					} else if(index.i >= ROW) {
						printf("\t\t[!] Batas ROW adalah %d\n", ROW-1);
					} else {
						break;
					}
				} while(true);
				
				do {
					printf("\n\n\tIndex J : "); scanf("%d", &index.j);
					if(index.j < 0) {
						printf("\t\t[!] Index tidak boleh < 0\n");
					} else if(index.j >= COL) {
						printf("\t\t[!] Batas COL adalah %d\n", COL-1);
					} else {
						break;
					}
				} while(true);
				
				if(sudahIsi(data, index)) {
					printf("\n\t\t[!] Data sudah terisi");
				} else {
					printf("\n\t\tInput Angka : "); scanf("%d", &angka);
					data[index.i][index.j] = buatData(angka, "Sudah Input");
					printf("\n\t\t [*] Berhasil input data");
				}
			break;
			
			case 2 :
				printf("\n\t==== Cari Data ====");
				printf("\n\n\tInput angka yang ingin dicari : "); scanf("%d", &angka);
				
				index = cariData(data, angka);
				
				if(index.i == -1) {
					printf("\n\t\t[!] Data tidak ditemukan");
				} else {
					printf("\n\t\t[*] Data pertama kali ditemukan pada index");
					printf("\n\t\t i : %d", index.i);
					printf("\n\t\t j : %d", index.j);
				}
			break;
			
			case 3 :
				printf("\n\t==== Print Data ====\n\n");
				printData(data);
			break;
			
			case 0 :
				printf("\n\t\t[*] Keluar");
				printf("\n\t\tAlexis Divasonda Sigat Ngaing");
				printf("\n\t\t210711407");
			break;
			
			default :
				printf("\n\t\t[!] Menu tidak ditemukan");
			break;
		} getch();
	} while(menu != 0);
	
	return 0;
}
