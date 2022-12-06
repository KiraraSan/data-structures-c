#include "header.h"

int main() {
    List L;
    address temp, before;
    infotype bil;
    char menu;

    createEmpty(&L);

    do {
        system("cls");
        printf("\n\n\t=== GUIDED LINKED LIST 2 ===\n");
        printf("\n\t[1] Insert First");
        printf("\n\t[2] Insert After");
        printf("\n\t[3] Insert Last");
        printf("\n\t[4] Delete First");
        printf("\n\t[5] Delete At");
        printf("\n\t[6] Delete Last");
        printf("\n\t[7] Print Data");
        printf("\n\t[0] EXIT");
        printf("\n\tInput Menu\t: "); menu = getch();
        printf("\n\t\n");

        switch (menu) {
            case '1':
                printf("\n\tEnter Number\t: "); scanf("%d", &bil);
                temp = alokasi(bil);
                insertFirst(&L, temp);
                printf("\n\tInsert successfully");
                break;

            case '2':
                printf("\n\tInsert number after : "); scanf("%d", &bil);
                before = findNode(L, bil);
                if (before == NULL) {
                    printf("\n\t[!] 404 not found");
                    break;
                }
                printf("\n\tEnter number\t: "); scanf("%d", &bil);
                temp = alokasi(bil);
                insertAfter(before, temp);
                printf("\n\tInsert successfully");
                break;

            case '3':
                printf("\n\tEnter number\t: "); scanf("%d", &bil);
                temp = alokasi(bil);
                insertLast(&L, temp);
                printf("\n\tInsert successfully");
                break;

            case '4':
                if (isEmpty(L)) {
                    printf("\n\t[!] List kosong");
                    break;
                }
                deleteFirst(&L);
                printf("\n\tDelete successfully");
                break;

            case '5':
                if (isEmpty(L)) {
                    printf("\n\t[!] List kosong");
                    break;
                }
                printf("\n\tNumber you want to delete\t: "); scanf("%d", &bil);
                temp = findNode(L, bil);
                if (temp == NULL) {
                    printf("\n\t[!] 404 not found");
                    break;
                }
                deleteAt(&L, temp);
                printf("\n\tDelete successfully");
                break;

            case '6':
                if (isEmpty(L)) {
                    printf("\n\t[!] List kosong");
                    break;
                }
                deleteLast(&L);
                printf("\n\tDelete successfully");
                break;

            case '7':
                if (isEmpty(L)) {
                    printf("\n\t[!] List kosong");
                    break;
                }
                printData(L);
                break;

            case '0':
                printf("\n\tExit");
                break;

            default:
                printf("\n\t[!] Menu invalid");
                break;
        }
        getch();
    } while (menu != '0');

    return 0;
}

