#include "header.h"

int main(int argc, char *argv[]) {
    Mahasiswa M[MAX], temp;
    int menu, index, i;

    inisialisasi(M, 0);

    do {
        system("cls");
        printf("=== GUIDED: MAHASISWA ===");
        printf("\n[1] Input Mahasiswa");
        printf("\n[2] Tampil Mahasiswa");
        printf("\n[0] Keluar");
        printf("\n>>> "); scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n\t--- Input Data Mahasiswa ---\n");
                index = getEmptyIndex(M, 0);
                if (index != -1) {
//                    while (1) {
						for (i = 0; i < MAX; i++) {
							printf("\tNO   : "); scanf("%d", &temp.no);
						
                        
//                        if (temp.no == 0) {
//                            printf("\n\t\tNO tidak boleh kosong [!]");
//                        } else {
//                            break;
//                        }
//                    }
                    M[index] = temp;
                }
                    printf("\n\t\tData berhasil disimpan...");
                } else {
                    printf("\n\tData penuh [!]");
                }
                break;

            case 2:
                printf("\n\t--- Tampil Data Mahasiswa ---");
                if (!isEmpty(M, 0)) {
                	printf("\n\n\tTampil Biasa");
                    printAll(M, 0);
                    
                	printf("\n\n\tTampil Terbalik");
                    printAllDesc(M, 0);
                } else {
                    printf("\n\tData kosong [!]");
                }
                break;

            case 0:
                printf("\n\t[+] Terima Kasih");
                printf("\n\tAlexis Divasonda Sigat Ngaing - 210711407 - Praktikum ISD A");
                printf("\n\n\t\tSemoga harimu menyenangkan...");
                break;

            default:
                printf("\n\tMenu invalid [!]");
                break;
        }
        getch();
    } while (menu != 0);
    return 0;
}

