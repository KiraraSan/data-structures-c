#include "header.h"

int main(int argc, char *argv[]) {
    int menu, menu2, id;
    char pilihData;
    Data data[DataMAX];
    Data *ptrDisplay;

    ptrDisplay = data;
    initData(data);

    do {
        system("cls");
        tampilData(data);
        printf("\n\n\t\tPosisi sekarang di data :");
        printf("\n\t    ID             : %d", ptrDisplay->id);
        printf("\n\t    Nama           : %s", ptrDisplay->nama);
        printf("\n\t    Tanggal Terbit : %s\n\n", ptrDisplay->tanggalTerbit);

        puts("  [1] Pilih Posisi");
        puts("  [2] Isi Data");
        puts("  [0] Keluar");
        printf("\n  >> "); scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n\t\t=== Pindah Posisi ===");
                printf("\n\t[1] Pilih Data by ID");
                printf("\n\t[2] Geser Kanan");
                printf("\n\t[3] Geser Kiri");
                printf("\n\t >>> "); menu2 = getche();

                switch (menu2) {
                    case '1':
                        printf("\n\t\tMasukkan ID data yang ingin dituju : "); scanf("%d", &id);
                        if (cariBerdasarID(ptrDisplay, data, id)->id == ptrDisplay->id) {
                            printf("\n\t\t[!] Sudah berada di ID yang dimaksud [!]");
                        } else if (cariBerdasarID(ptrDisplay, data, id)->id == 0) {
                            printf("\n\t\t[!] ID tidak ditemukan [!]");
                        } else {
                            ptrDisplay = cariBerdasarID(ptrDisplay, data, id);
                            printf("\n\t\t  Berpindah ke ID-%d...", id);
                        }
                        getch();
                        break;

                    case '2':
                        if (ptrDisplay->id == 10) {
                            printf("\n\t\t[!] Sudah mentok [!]");
                            getch();
                        } else {
                            ptrDisplay++;
                        }
                        break;

                    case '3':
                        if (ptrDisplay->id == 1) {
                            printf("\n\t\t[!] Sudah mentok [!]");
                            getch();
                        } else {
                            ptrDisplay--;
                        }
                        break;

                    default:
                        break;
                }
                break;

            case 2:
                if (strcmpi(ptrDisplay->nama, "-") != 0) {
                    printf("\n\t\t[!} Sudah terisi data [!]");
                } else {
                    printf("\n\t\t=== Isi Data ===");
                    inputan(ptrDisplay);
                    printf("\n\t\tBerhasil input data...");
                }
                getch();
                break;

            default:
                break;
        }
    } while (menu != 0);
    return 0;
}
