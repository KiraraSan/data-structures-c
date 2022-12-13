#include <stdio.h>
#include <stdlib.h>

//typedef int array[10];

//int getEmptyIndex(int arr[], int i) {
//    if (arr[i] == 0) {
//        return index;
//    }
//    if (index >= MAX - 1) {
//        return -1;
//    } else {
//        return getEmptyIndex(M, index + 1);
//    }
//}

void printAll(int arr[], int i);
void printAllDesc(int arr[], int i);

int main(int argc, char *argv[]) {
	int i;
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
//	printf("Print Berurutan");
//	printAll(arr, 0);
	
	printf("\nPrint Terbalik");
	printAllDesc(arr, 9);
	return 0;
}

//void printAll(int arr[], int i) {
//	if (i < 0) {
//		return;
//	} else {
//		printf("\n\t%d", arr[i]);
//		printAll(arr, i - 1);
//	}
//}

void printAllDesc(int arr[], int i) {
	if (i < 0) {
		return;
	} else {
		printf("\n\t%d", arr[i]);
		printAllDesc(arr, i - 1);
	}
}
