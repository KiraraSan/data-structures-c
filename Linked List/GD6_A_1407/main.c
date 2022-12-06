#include "header.h"

int main(int argc, char *argv[]) {
    List L;
    Data D;

    int menu, NPP;
    string namaDosen;
    createEmpty(&L);

    do {
        system("cls");
        printf("\n===== LINKED LIST =====");
        printf("\n[1] Insert First");
        printf("\n[2] Insert Last");
        printf("\n[3] Delete First");
        printf("\n[4] Delete Last");
        printf("\n[5] Show List");
        printf("\n[0] Exit");
        printf("\n >>> "); scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\nInput Data");
                printf("\nInput Nama Dosen : "); fflush(stdin); gets(namaDosen);
                printf("\nInput NPP Dosen  : "); scanf("%d", &NPP);

                D = makeData(namaDosen, NPP);
                insertFirst(&L, D);
                break;

            case 2:
                printf("\nInput Data");
                printf("\nInput Nama Dosen : "); fflush(stdin); gets(namaDosen);
                printf("\nInput NPP Dosen  : "); scanf("%d", &NPP);

                D = makeData(namaDosen, NPP);
                insertLast(&L, D);
                break;

            case 3:
                deleteFirst(&L);
                break;

            case 4:
                deleteLast(&L);
                break;

            case 5:
                showList(L);
                break;

            case 0:
                break;
        }
        getch();
    } while (menu != 0);

    return 0;
}

