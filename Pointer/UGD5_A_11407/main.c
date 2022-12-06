#include "header.h"

int main(int argc, char *argv[]) {
	int menu, menu_two, id;
    char pilihData;
    string hapus;
    
    Peserta peserta[dataMAX];
    Peserta *ptrDisplay;
    Peserta *pPeserta;

    ptrDisplay = peserta;
    inisialisasi(peserta);

    do {
        system("cls");
        print(peserta);
        printf("\n\n\t\tPosisi Anda sekarang :");
        printf("\n\t    ID             : %d", ptrDisplay->id);
        printf("\n\t    No Urut        : %s", ptrDisplay->no_urut);
        printf("\n\t    Nama           : %s", ptrDisplay->nama);
        printf("\n\t    Tanggal Daftar : %s", ptrDisplay->daftar);
        printf("\n\t    Jenis Kelamin  : %s", ptrDisplay->gender);
        printf("\n\t    Status         : %s\n\n", ptrDisplay->status);

		printf("  Menu UGD\n");
        puts("  [1] Pilih Posisi");
        puts("  [2] Isi Data");
        puts("  [3] Ubah Data\n");
        
        printf("  Menu Tugas\n");
        puts("  [4] Hapus Data");
        puts("  [5] Pindah Data\n");
        
        puts("  [0] Keluar");
        printf("\n  >> "); scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n\t\t=== Pilih Posisi ===");
                printf("\n\t[1] Pilih Langsung");
                printf("\n\t[2] Geser Kanan");
                printf("\n\t[3] Geser Kiri");
                printf("\n\t >>> "); menu_two = getche();

                switch (menu_two) {
                    case '1':
                        printf("\n\t\tMasukkan ID data yang ingin dituju : "); scanf("%d", &id);
                        if(cariID(ptrDisplay, peserta, id)->id == ptrDisplay->id) {
                            printf("\n\t\tSudah berada di ID yang dimaksud [!]");
                        } else if (cariID(ptrDisplay, peserta, id)->id == 0) {
                            printf("\n\t\tID tidak ditemukan [!]");
                        } else {
                            ptrDisplay = cariID(ptrDisplay, peserta, id);
                            printf("\n\t\tBerpindah ke ID-%d...", id);
                        }
                        getch();
                        break;

                    case '2':
                        if (ptrDisplay->id == 20) {
                            printf("\n\t\tSudah mentok [!]");
                            getch();
                        } else {
                            ptrDisplay++;
                        }
                        break;

                    case '3':
                        if (ptrDisplay->id == 1) {
                            printf("\n\t\tSudah mentok [!]");
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
                if(strcmpi(ptrDisplay->nama, "-")!=0) {
                    printf("\n\t\t[!] Data sudah terisi [!]");
                } else {
                    printf("\n\t\t=== Isi Data ===");
                    input(ptrDisplay);
                    printf("\n\t\tBerhasil isi data...");
                }
                getch();
                break;
                
            case 3:
            	if(strcmpi(ptrDisplay->nama, "-")==0) {
                    printf("\n\t\t[!] Data kosong [!]");
                } else {
                    printf("\n\t\t=== Ubah Data ===");
                    input(ptrDisplay);
                    printf("\n\t\tBerhasil ubah data...");
                }
                getch();
            	break;
            	
			case 4:
				if(strcmpi(ptrDisplay->nama, "-")==0) {
                    printf("\n\t\tData kosong [!]");
                } else {
					printf("\n\t\t=== Hapus Data ===");
                	printf("\n\tYakin ingin menghapus data? (y/n): "); fflush(stdin); gets(hapus);
                	if(strcmpi(hapus, "y")==0) {
					    strcpy(ptrDisplay->no_urut, "-");
					    strcpy(ptrDisplay->nama, "-");
					    strcpy(ptrDisplay->daftar, "-");
					    strcpy(ptrDisplay->gender, "?");
					    strcpy(ptrDisplay->status, "-");
                    	printf("\n\t\tBerhasil hapus data...");
					} else {
						printf("\n\t\tHapus dibatalkan...");
					}     
                }
                getch();
				break;
				
			case 5:
				if(strcmpi(ptrDisplay->nama, "-")==0) {
                    printf("\n\t\tData kosong [!]");
                } else {
                	printf("\n\t\tProgram Maintenance");
				}
				getch();
				break;	
				
			case 0:
            	printf("\n\t\tBerhasil keluar");
            	printf("\n\t\tAlexis Divasonda Sigat Ngaing - 210711407 - Kelas A");
            	printf("\n\n\t\tSemoga harimu menyenangkan...");
            	break;	
            	
            default:
                break;
        }
    } while(menu != 0);
	return 0;
}
