#include "header.h"

int main(int argc, char *argv[]) {
	Video V[N];
	string judul, random;
    int menu, i, n = 1, c, j, temp, view, check, num;
    int find, found = -1;

	char randomAlphabet[10];
    createEmpty(V);
	
	do {
		system("cls");
		printf("\n\t\t--- UNGUIDED SEARCHING ---\n");
		insertRandomAlphabet(randomAlphabet);
		printf("\n\tKarakter Random : ");
		for (i = 0; i < 10; i++) {
			printf("%c ", randomAlphabet[i]);
		}
		printf("\n\n\t[1] Cari Karakter");
		printf("\n\t[2] Input Video");
		printf("\n\t[3] Cari Jumlah Video");
		printf("\n\t[4] Edit Video");
		printf("\n\t[0] EXIT\n");
		printf("\n\t[5] Cari Nama Video [Tugas]");
		printf("\n\t>>> "); scanf("%d", &menu);
		
		switch (menu) {
			case 1:
				
				break;
				
			case 2:
				if (isFull(V) != -1) {
					for (i=0; i<N; i++) {
						printf("\n\tVideo [%d]", n);
						printf("\n\tJudul   : "); fflush(stdin); gets(judul);
						while (!uniqueCheckVideo(V, judul)) {
							printf("\n\tJudul   : "); fflush(stdin); gets(judul);
						}
						strcpy(V[i].judul, judul);
						n++;
					}
					printf("\n\t\t[*] Please Wait [*]");
					insertRandomView(V);
					printf("\n\t\tBerhasil input video...");
				} else {
					printf("\n\t\t[!] Sudah input video");
				}
				break;
				
			case 3:
				if (isEmpty(V) != -1) {
					bubbleSort(V);
					printArray(V);

					printf("\n\n\tCari video berdasarkan jumlah : "); scanf("%d", &find);
					found = binarySearch(V, 0, N-1, find);

					if (found != -1) {
						printf("\n\t\tVideo [ %s ] ditemukan di index [ %d ]", V[found].judul, found);
					} else {
						printf("\n\t\t[!] Data tidak ditemukan");
					}
				} else {
					printf("\n\t\tData is empty [!]");
				}
				break;
				
			case 4:
				if (isEmpty(V) != -1) {
					if (found != -1) {
						printf("\n\tEdit Video [ %s ] pada index [ %d ]\n", V[found].judul, found);
						printf("\n\tJudul   : "); fflush(stdin); gets(judul);
						while (!uniqueCheckVideo(V, judul)) {
							printf("\n\tJudul   : "); fflush(stdin); gets(judul);
						}
						strcpy(V[found].judul, judul);
						printf("\n\t\tBerhasil edit video...");
					} else {
						printf("\n\t\t[!] Data belum ditemukan");
					}
					
				}
				break;
			
			case 5:
				if (isEmpty(V) != -1) {
					bubbleSort(V);
					printArray(V);

					printf("\n\n\tCari video berdasarkan nama/judul : "); fflush(stdin); gets(judul);
					found = binarySearch(V, 0, N-1, judul);

					if (found != -1) {
						printf("\n\t\tVideo [ %s ] ditemukan di index [ %d ]", V[found].judul, found);
					} else {
						printf("\n\t\t[!] Data tidak ditemukan");
					}
				} else {
					printf("\n\t\tData is empty [!]");
				}
				break;
				
			case 0:
				printf("\n\tAlexis Divasonda Sigat Ngaing - 210711407 - A");
				printf("\n\n\t\tSemoga harimu menyenangkan :)");
				break;
				
			default:
				printf("\n\tMenu invalid [!]");
				break;
		} getch();
	} while (menu != 0);
	return 0;
}
