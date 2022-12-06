#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
 
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = { 22, 8, 10, 5, 9, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

//#include "header.h"
//
//int main(int argc, char *argv[]) {
//	BinaryTree BT_BST;
//	createEmpty(&BT_BST);
//	
//	int menu, health;
//	string jenisPokemon, ubah, hapus;
//	address P, cari;
//	
//	do {
//		system("cls");
//		printf("----- Guided Binary Tree Alexis Divasonda Sigat Ngaing / 210711407 -----");
//		printf("\n[1] Insert Data");
//		printf("\n[2] Print Data");
//		printf("\n[3] Update Data");
//		printf("\n[4] Delete Data");
//		printf("\n[0] Exit");
//		printf("\n>>> "); scanf("%d", &menu);
//		
//		switch (menu) {
//			case 1:
//				printf("\nMasukkan jenis Pokemon : "); fflush(stdin); gets(jenisPokemon);
//				printf("Masukkan health Pokemon : "); scanf("%d", &health);
//				P = alokasi(health, jenisPokemon);
//				insTreeBST(&BT_BST, P);
//				break;
//			
//			case 2:
//				if (isEmpty(BT_BST)) {
//					printf("\nBinary Tree kosong [!]");
//				} else {
//					printf("\nPre Order  : ");
//					preOrder(BT_BST);
//					printf("\nIn Order   : ");
//					inOrder(BT_BST);
//					printf("\nPost Order : ");
//					postOrder(BT_BST);
//				}
//				break;
//				
//			case 3:
//				if (isEmpty(BT_BST)) {
//					printf("\nBinary Tree Kosong [!]");
//				} else {
//					printf("\nMasukkan jenis Pokemon yang ingin diubah : "); fflush(stdin); gets(ubah);
//					if (isFound(BT_BST, ubah)) {
//						printf("\nMasukkan jenis Pokemon yang baru : "); fflush(stdin); gets(jenisPokemon);
//						updateTree(&BT_BST, ubah, jenisPokemon);
//						printf("\nBerhasil mengubah Jenis Pokemon");
//					} else {
//						printf("\nNode tidak ditemukan [!]");
//					}
//				}
//				break;
//				
//			case 4:
//				printf("\nMasukkan Jenis Pokemon yang ingin dihapus : "); fflush(stdin); gets(hapus);
//				if(isFound(BT_BST, hapus)) {
//					delTreeAt(&BT_BST, hapus);
//					printf("\nBerhasil menghapus node");
//				} else {
//					printf("\nNode tidak ditemukan [!]");
//				}
//				break;
//				
//			case 0:
//				printf("\nExit...");
//				break;
//				
//			default:
//				printf("\nMenu invalid [!]");
//				break;
//		} getch();
//	} while (menu != 0);
//	return 0;
//}
