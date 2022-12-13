#include "header.h"

int main(int argc, char *argv[]) {
    List L;
    addr delNode, max;

    int menu = -1, data, prevData, nilai1, nilai2, find, i, cari;
    createEmpty(&L);

    while (menu != 0) {
        system("cls");
        printf("1. Insert first");
        printf("\n2. Insert after");
        printf("\n3. Insert last");
        printf("\n4. Delete first");
        printf("\n5. Delete at");
        printf("\n6. Delete last");
        printf("\n7. Find data");
        printf("\n8. Print all");
        printf("\n9. Find Max Node");
        printf("\n10. Cacah Node Antara");
        printf("\n12. Find");
        printf("\n0. Keluar");
        printf("\n>> "); scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\ndata: "); scanf("%d", &data);
                insertFirst(&L, alokasi(data));
                break;

            case 2:
                printf("\ndata: "); scanf("%d", &data);
                printf("masukkan setelah data: "); scanf("%d", &prevData);
                insertAfter(&L, alokasi(data), prevData);
                break;

            case 3:
            	for (i=0; i<5; i++) {
            		printf("\ndata: "); scanf("%d", &data);
              		insertLast(&L, alokasi(data));
				}
                break;

            case 4:
                deleteFirst(&L);
                break;

            case 5:
                printf("\ndata yang ingin dihapus: "); scanf("%d", &data);
                delNode = findNode(L, data);
                if (delNode != NULL) {
                	deleteAt(&L, delNode);
				} else {
                	printf("data tidak ada");
				}
                break;

            case 6:
                deleteLast(&L);
                break;

            case 7:
                printf("\ndata yang ingin dicari: ");
                scanf("%d", &data);
                if (findNode(L, data) == NULL) {
                	printf("\ndata tidak ada");
				} else {
                	printf("\ndata ada");
				}
                break;

            case 8:
                printAll(L);
                break;
                
            case 9:
            	max = FindMaxNode(L);
            	printf("\nMax Node : %d", max);
            	break;
            	
            case 10:
            	CacahNodeAntara(L, 9, 7);
            	printf("\n\tCacah Node Antara : %d", CacahNodeAntara(L, nilai1, nilai2));
            	break;
            	
            case 11:
//            	find = findNumber(L);
//            	
//            	printf("\n\tNumber : %d", find);
            	break;
            	
			case 12:
				printf("\n\tCari : "); scanf("%d", &cari);
				find = findNumber(L, cari);
				printf("\n\t%d", find);
				break;
            case 0:
                break;
                
            default:
                printf("\ninvalid");
        }
        getch();
    }
    return 0;
}


