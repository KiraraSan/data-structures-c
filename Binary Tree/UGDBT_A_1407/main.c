#include "header.h"

int main(int argc, char *argv[]) {
	BinaryTree BT_BST, BT_BNR;
	createEmpty(&BT_BST);
	createEmpty(&BT_BNR);
	
	int menu, ukuranSandal, depth, biner;
	string jenisSandal, warnaSandal, ubah, hapus, search;
	address P, PB, cari;
	
	do {
		system("cls");
		if (isEmpty(BT_BST)) {
			printf("\n\t=========================");
			printf("\n\t   [!] Data kosong [!]");
			printf("\n\t=========================");
		} else {
			printf("\n\t=============================================");
			printf("\n\tPre Order  : ");
			preOrder(BT_BST);
			printf("\n\tIn Order   : ");
			inOrder(BT_BST);
			printf("\n\tPost Order : ");
			postOrder(BT_BST);
			cekSimetri(&BT_BST);
			printf("\n\t=============================================");
		}
		
		printf("\n\n=*=*= Toko Sandal Swallow =*=*=");
		printf("\n\n--- Menu Utama ---");
		printf("\n[1] Input Data");
		printf("\n[2] Update Data");
		printf("\n[3] Delete Data");
		
		printf("\n\n--- Menu Bonus ---");
		printf("\n[4] Input Bonus");
		printf("\n[5] Show Bonus");
		printf("\n[6] Search\n");
		printf("\n[0] Exit");
		printf("\n>>> "); scanf("%d", &menu);
		
		switch (menu) {
			case 1:
				printf("\tJenis Sandal  : "); fflush(stdin); gets(jenisSandal);
				printf("\tUkuran Sandal : "); scanf("%d", &ukuranSandal);
				printf("\tWarna Sandal  : "); fflush(stdin); gets(warnaSandal);
				if (!isUkuranUnik(BT_BST, ukuranSandal)) {
					printf("\n\t\tUkuran Sandal sudah ada [!]");
				} else {
					P = alokasi(jenisSandal, ukuranSandal, warnaSandal);
					insTreeBST(&BT_BST, P);
					printf("\n\t\tBerhasil input data...");
				}
				break;
				
			case 2:
				if (isEmpty(BT_BST)) {
					printf("\n\tData Kosong [!]");
				} else {
					printf("\n\tMasukkan Jenis Sandal yang ingin diubah : "); fflush(stdin); gets(ubah);
					if (isFound(BT_BST, ubah)) {
						printf("\n\tMasukkan Jenis Sandal yang baru : "); fflush(stdin); gets(jenisSandal);
						printf("\tMasukkan Warna Sandal yang baru : "); fflush(stdin); gets(warnaSandal);
						updateTree(&BT_BST, ubah, jenisSandal, warnaSandal);
						printf("\n\t\tBerhasil di ubah...");
					} else {
						printf("\n\t\tData tidak ditemukan [!]");
					}
				}
				break;
				
			case 3:
				printf("\nMasukkan Jenis Sandal yang ingin dihapus : "); fflush(stdin); gets(hapus);
				if(isFound(BT_BST, hapus)) {
					delTreeAt(&BT_BST, hapus);
					printf("\n\t\tBerhasil di hapus...");
				} else {
					printf("\n\t\tData tidak ditemukan [!]");
				}
				break;
				
			case 4:
				printf("\nMasukkan bilangan biner : "); scanf("%d", &biner);
//				if (biner != 1 && biner != 0) {
//					printf("\n\tBiner invalid [!]");
//				} else {
					PB = alokasiBiner(biner);
					insTreeBST(&BT_BST, PB);
//				}
				break;
				
			case 5:
				printf("\n\tMaintenance [!]");
				break;
				
			case 6:
				if (isEmpty(BT_BST)) {
					printf("\n\tData Kosong [!]");
				} else {
					printf("\n\tMasukkan Jenis Sandal yang dicari : "); fflush(stdin); gets(search);
					int index = isFound(BT_BST, search);
					if (isFound(BT_BST, search)) {
						printf("\n\tJenis Sandal  : %s", BT_BST->sandal.jenisSandal);
						printf("\n\tUkuran Sandal : %d", BT_BST->sandal.ukuranSandal);
						printf("\n\tWarna Sandal  : %s", BT_BST->sandal.warnaSandal);
						printf("\n\tDepth         : %d", depth);
					} else {
						printf("\n\t\tData tidak ditemukan [!]");
					}
				}
				break;
				
			case 0:
				printf("\n\tExit...\n\n");
				printf("\n\t\t-----------------------------------------");
				printf("\n\t\t-         *                    *        -");
				printf("\n\t\t-                                       -");
				printf("\n\t\t----- Semoga harimu menyenangkan :) -----");
				printf("\n\t\t-                                       -");
				printf("\n\t\t-         *                    *        -");
				printf("\n\t\t-----------------------------------------");
				break;
				
			default:
				printf("\n\tMenu invalid [!]");
				break;
		} getch();
	} while (menu != 0);
	return 0;
}
