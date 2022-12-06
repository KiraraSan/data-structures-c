#include "header.h"

int main(int argc, char *argv[]) {
	array a, temp;
	int jmlElemen, menu;
	
	do {
		system("cls");
		printf("\n[1] Set Array");
		printf("\n[2] Print Array");
		printf("\n[3] Bubble Sort");
		printf("\n[4] Merge Sort");
		printf("\n[5] Quick Sort");
		printf("\n>>> "); scanf("%d", &menu);
		switch (menu) {
			case 1:
				printf("\n Jumlah Elemen Yang Ingin Ditampung :"); scanf("%d", &jmlElemen);
				setArray(&a, jmlElemen);
				break;
			
			case 2:
				printf("\nTampil Array Unsorted : ");
				printInfo(a);
				break;
			
			case 3:
				temp = cloneArray(a);
				printf("\nTampil Array Sebelum Sorting (Bubble Sort) : ");
				printInfo(temp);
				printf("\nTampil Array Sesudah Sorting (Bubble Sort) : ");
				bubbleSort(&temp);
				printInfo(temp);
				break;
				
			case 4:
				temp = cloneArray(a);
				printf("\nTampil Array Sebelum Sorting (Merge Sort): ");
				printInfo(temp);
				printf("\nTampil Array Sesudah Sorting (Merge Sort) : ");
				mergeSort(&temp);
				printInfo(temp);
				break;
				
			case 5:
				temp = cloneArray(a);
				printf("\nTampil Array Sebelum Sorting (Quick Sort): ");
				printInfo(temp);
				printf("\nTampil Array Sesudah Sorting (Quick Sort) : ");
				quickSort(&temp,0,temp.akhir);
				printInfo(temp);
				break;
		} getch();
	} while (menu != 0);
	return 0;
}
