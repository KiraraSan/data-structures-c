#include "header.h"

int main(int argc, char *argv[]) {
    arrayType array, sortArray;
    int menu;
    int find, found;

    createEmpty(array);

    do {
        system("cls");
        printf("\n\t===== GUIDED SEARCHING =====");
        printf("\n\t[1] Generate Number");
        printf("\n\t[2] Sequential Search");
        printf("\n\t[3] Binary Search");
        printf("\n\t[0] Exit");
        printf("\n\t>>> "); scanf("%d", &menu);

        switch (menu) {
            case 1:
                if (isFull(array)) {
                    createEmpty(array);
                }
                insertRandom(array);
                printf("\n\tGenerate Array : ");
                printArray(array);
                break;

            case 2:
                if (isEmpty(array)) {
                    printf("\n\tArray kosong [!]");
                    break;
                }
                printf("\n\tData Array : ");
                printArray(array);
                printf("\n\tCari : "); scanf("%d", &find);
                found = sequentialSearch(array, find);

                if (found == -1) {
                    printf("\n\t\tData tidak ditemukan [!]");
                } else {
                    printf("\n\t\tData %d ditemukan di index ke-%d", array[found], found);
                }
                break;

            case 3:
                if (isEmpty(array)) {
                    printf("\n\tArray kosong [!]");
                    break;
                }
                printf("\n\tData Sebelum Sorting :");
                printArray(array);
                copyArray(array, sortArray);

                bubbleSort(sortArray);
                printf("\n\tData Sesudah Sorting :");
                printArray(sortArray);

                printf("\n\tCari : "); scanf("%d", &find);
                found = sequentialSearch(sortArray, find);

                if (found == -1) {
                    printf("\n\t\tData tidak ditemukan [!]");
                } else {
                    printf("\n\t\tData %d ditemukan di index ke-%d", sortArray[found], found);
                }
                break;

            case 0:
                printf("\n\tAlexis Divasonda Sigat Ngaing | 210711407 | A");
                printf("\n\n\t\tSemoga harimu menyenangkan :)");
                break;

            default:
                printf("\n\tMenu invalid [!]");
                break;
        } getch();
    } while (menu != 0);

    return 0;
} 