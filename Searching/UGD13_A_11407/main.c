#include "header.h"

int main(int argc, char *argv[]) {
	// arrayType array, sortArray;
	Video V[N];
	string judul, random;
    int menu, i, n = 1, c, j, temp, view, check, num;
    int find, found;

	// char character[26] = {'A', 'B', 'C', 'D', 'E',
	// 					  'F', 'G', 'H', 'I', 'J',
	// 					  'K', 'L', 'M', 'N', 'O',
	// 					  'P', 'Q', 'R', 'S', 'T',
	// 					  'U', 'V', 'W', 'X', 'Y',
	// 					  'Z'};

	// static const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	// const size_t alphabet_count = sizeof(alphabet) - 1;
	// size_t a, j;
	// char random_alpha;
	// int index;

    createEmpty(V);
	
	do {
		system("cls");
		
		char randomAlphabet = ' ';
		int counter = 0, randomNumber = 0;
		srand(time(NULL));

		for (counter = 0; counter < 10; counter++) {
			randomNumber = 26 * (rand() / (RAND_MAX + 1.0));

			randomNumber += 65;
			randomAlphabet = (char) randomNumber;

			printf("\n\tKarakter Random : %c ", randomAlphabet);
		}
		// srand(time(NULL));

		// for (a=0; a<10; a++) {
		// 	for (j=0; j<alphabet_count; j++) {
		// 		random_alpha;
		// 		index = (double)rand() / RAND_MAX * alphabet_count;
		// 		random_alpha = alphabet[index];

		// 		printf("\n\tKarakter Random %g : %c ", j, random_alpha);
		// 	}
		// }

		printf("\n\t\t--- UNGUIDED SEARCHING ---\n");
		// printf("\n\tKarakter Random : %c ", random);
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

						// srand((unsigned) time(NULL));
						// num = rand() % 1000 + 1;
						// if (uniqueCheckView(V, num)) {
						// 	// num = rand() % 1000 + 1;
						// 	V[i].view = num;
						// } else {
						// 	i--;
						// }
						// num = rand() % 1000 + 1;

						n++;
					}
					insertRandomView(V);
					// srand((unsigned) time(NULL));
					// for (j=0; j<N; j++) {
					// 	num = rand() % 1000 + 1;
					// 	if (uniqueCheckView(V, view)) {
					// 		// num = rand() % 1000 + 1;
					// 		V[i].view = num;
					// 	} else {
					// 		j--;
					// 	}
					// }
				} else {
					printf("\n\t[!] Sudah input video");
				}
				break;
				
			case 3:
				if (isEmpty(V) != -1) {
					// insertRandomView(V);
					bubbleSort(V);
					printArray(V);

					printf("\n\tCari video berdasarkan jumlah : "); scanf("%d", &find);
					found = binarySearch(V, 0, N-1, find);

					if (found != -1) {
						printf("\n\tVideo [ %s ] ditemukan di index [ %d ]", V[found].judul, found);
					} else {
						printf("\n\t[!] Data tidak ditemukan");
					}
				} else {
					printf("\n\tData is empty [!]");
				}
				break;
				
			case 4:
				if (isEmpty(V) != -1) {
					
				}
				break;
			
			case 5:
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
