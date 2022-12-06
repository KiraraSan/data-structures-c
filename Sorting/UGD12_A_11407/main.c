#include "header.h"

int main(int argc, char *argv[]) {
	array a, temp;
	int menu, n = 0, find;
	
	createEmpty(&a);
	
	do {
		system("cls");
		printf("\n[1] Tambah Data");
		printf("\n[2] Print Array");
		printf("\n[3] Boarding Roket");
		printf("\n[4] Sort Kapasitas Roket (Bubble)");
		printf("\n[5] Sort Nama Roket (Merge)");
		printf("\n[6] Sort Kode Roket (Quick)");
		printf("\n[0] Exit");
		printf("\n>>> "); scanf("%d", &menu);
		
		switch (menu) {
			case 1:
				printf("\n\tNama      : "); fflush(stdin); gets(a.D[n].namaRoket);
				printf("\n\tKode      : "); scanf("%d", &a.D[n].kodeRoket);
				printf("\n\tKapasitas : "); scanf("%d", &a.D[n].kapasitas);
				a.D[n].status = 0;
				n++;
				a.akhir = n-1;
				printf("\n\t\tBerhasil input data...");
				break;
			
			case 2:
				printf("\n\tRoket Belum Berangkat");
				printArray(a);
				
				printf("\n\n\tRoket Sudah Berangkat");
				printArray_two(a);
				break;
				
			case 3:
				printf("\n\tKode Roket yang ingin diboarding : "); scanf("%d", &find);
				int index = findArray(a, find);
				
				if (index == -1) {
					printf("\n\t\tRoket tidak ditemukan [!]");
				} else {
					a.D[index].status = 1;
					printf("\n     ^		\n");
					printf("   {   }	\n");
					printf("  |     |	\n");
					printf("  |     |	\n");
					printf("  |  N  |	\n");
					printf(" ^|  A  |^ \n");
					printf("| |  S  | |\n");
					printf("| |  A  | |\n");
					printf("| |     | |\n");
					printf("| |     | |\n");
					printf("| |     | |\n");
					printf("| |     | |\n");
					printf("| |     | |\n");
					printf("| |     | |\n");
					printf("| |     | |\n");
					printf("||| ||| |||\n\n");
					printf("===== TO THE MOON =====");
				}
				break;
			
			case 4:
				temp = cloneArray(a);
				printf("\n\t===== Data Sebelum Sorting =====");
				printf("\n\tRoket Belum Berangkat");
				printArray(temp);
				printf("\n\n\tRoket Sudah Berangkat");
				printArray_two(temp);
				
				printf("\n\n\n\t===== Data Sesudah Sorting =====");
				bubbleSort(&temp);
				printf("\n\tRoket Belum Berangkat");
				printArray(temp);
				printf("\n\n\tRoket Sudah Berangkat");
				printArray_two(temp);
				break;
				
			case 5:
				temp = cloneArray(a);
				printf("\n\t===== Data Sebelum Sorting =====");
				printf("\n\tRoket Belum Berangkat");
				printArray(temp);
				printf("\n\n\tRoket Sudah Berangkat");
				printArray_two(temp);
				
				printf("\n\n\n\t===== Data Sesudah Sorting =====");
				mergeSort(&temp);
				printf("\n\tRoket Belum Berangkat");
				printArray(temp);
				printf("\n\n\tRoket Sudah Berangkat");
				printArray_two(temp);
				break;
				
			case 6:
				temp = cloneArray(a);
				printf("\n\t===== Data Sebelum Sorting =====");
				printf("\n\tRoket Belum Berangkat");
				printArray(temp);
				printf("\n\n\tRoket Sudah Berangkat");
				printArray_two(temp);
				
				printf("\n\n\n\t===== Data Sesudah Sorting =====");
				quickSort(&temp, 0, temp.akhir);
				printf("\n\tRoket Belum Berangkat");
				printArray(temp);
				printf("\n\n\tRoket Sudah Berangkat");
				printArray_two(temp);
				break;
				
			case 0:
				printf("\n\tAlexis Divasonda Sigat Ngaing / 210711407 / A");
				printf("\n\n\t\tSemoga harimu menyenangkan :)");
				break;
				
			default:
				break;
				
		} getch();
	} while (menu != 0);
	return 0;
}
