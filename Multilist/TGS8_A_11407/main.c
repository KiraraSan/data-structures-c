#include "header.h"

int main() {
	Multilist l;
    AddressParent tempParent;
    AddressChild tempChild;
    
    createEmpty(&l);
    
    int id, menu, count, temp;
	string ruangan, noPlat, merek, konfirmasi;
	bool status;
    float bensin;
    
    do {
    	system("cls");
    	printf("=== UGD Multilist ===");
    	printf("\n[1] Input Ruangan");
    	printf("\n[2] Edit Status Ruangan");
    	printf("\n[3] Hapus Data Ruangan\n");
    	printf("\n[4] Input Data Mobil");
    	printf("\n[5] Hitung Jumlah Ruangan\n");
    	printf("\n[6] Tampil Seluruh Data");
    	printf("\n[7] Distribusi Mobil");
    	printf("\n[0] Keluar\n");
    	printf("\n>>> "); scanf("%d", &menu);
    	
    	switch (menu) {
    		case 1:
    			printf("\n\t--- Input Ruangan ---");
    			printf("\n\tInput ID Ruangan     : "); scanf("%d", &id);
    			while (id == 0) {
    				printf("\n\t\tID tidak boleh nol [!]");
    				printf("\n\tInput ID Ruangan     : "); scanf("%d", &id);
				}
    			while (id < 0) {
    				printf("\n\t\tID tidak boleh negatif [!]");
    				printf("\n\tInput ID Ruangan     : "); scanf("%d", &id);
				}
				while (!isParentUnik(l, id)) {
    				printf("\n\t\tID harus unik [!]");
    				printf("\n\tInput ID Ruangan     : "); scanf("%d", &id);
				}
				printf("\tInput Nama Ruangan   : "); fflush(stdin); gets(ruangan);
				while (strlen(ruangan) == 0) {
    				printf("\n\t\tRuangan tidak boleh kosong [!]");
    				printf("\n\tInput Nama Ruangan   : "); fflush(stdin); gets(ruangan);
				}
				printf("\tInput Status Ruangan : "); scanf("%d", &temp);
				while (temp != 1 && temp != 0) {
					printf("\n\t\tStatus ruangan invalid [!]");
					printf("\n\t\tAngka 1 = Aktif");
					printf("\n\t\tAngka 0 = Tidak Aktif");
					printf("\n\tInput Status Ruangan : "); scanf("%d", &temp);
				}
				if (id % 2 != 0) {
					insertLastParent(&l, makeDataParent(id, ruangan, status, temp));
					printf("\n\t\tBerhasil input Ruangan Lama...");
				} else {
					insertFirstParent(&l, makeDataParent(id, ruangan, status, temp));
					printf("\n\t\tBerhasil input Ruangan Baru...");
				} getch();
    			break;
    			
    		case 2:
    			printf("\n\t--- Edit Status Ruangan ---");
                printf("\n\tInput ID Ruangan : "); scanf("%d", &id);

                tempParent = findParent(l, id);
                if (tempParent == NULL) {
                    printf("\n\t\tRuangan tidak ditemukan [!]");
                } else {
                    printParent(tempParent);
                    if (tempParent->data.status == true) {
                        printf("\n\tApakah yakin ingin mengubah status menjadi 'Tidak Aktif'? [Y/n]"); fflush(stdin); gets(konfirmasi);
                        if (strcmpi(konfirmasi, "Y") == 0) {
                            tempParent->data.status = false;
                            printf("\n\t\tBerhasil mengubah status ruangan...");
							printf("\n\t\t[*] Sekarang Anda tidak bisa menginput mobil di ruangan ini");
                        } else {
                            printf("\n\t\tStatus ruangan tidak jadi diubah [!]");
                        }
                    } else {
                        printf("\nApakah yakin ingin mengubah status menjadi 'Aktif'? [Y/n]"); fflush(stdin); gets(konfirmasi);
                        if (strcmpi(konfirmasi, "Y") == 0) {
                            tempParent->data.status = true;
                            printf("\n\t\tBerhasil mengubah status ruangan...");
                        } else {
                            printf("\n\t\tStatus ruangan tidak jadi diubah [!]");
                        }
                    }
                }
    			break;
    			
    		case 3:
    			printf("\n\t--- Hapus Data ---");
				printf("\n\tInput Nama Ruangan : "); fflush(stdin); gets(ruangan);

                tempParent = findParentRuangan(l, ruangan);
                if (tempParent == NULL) {
                    printf("\n\t\tRuangan tidak ditemukan [!]");
                } else {
                	deleteAtParent(&l, id);
                	printf("\n\t\tBerhasil hapus data ruangan...");
				}
    			break;
    			
    		case 4:
    			printf("\n\t--- Input Mobil ---");
                printf("\n\tInput ID : "); scanf("%d", &id);
                
                tempParent = findParent(l, id);
                if (tempParent == NULL) {
                    printf("\n\t\tData tidak ditemukan [!]");
                } else {
                    if (tempParent->data.status == false) {
                        printf("\n\t\tStatus ruangan sedang tidak aktif [!]");
                        break;
                    }
                    printf("\n\tInput Nomor Plat       : "); fflush(stdin); gets(noPlat);
                    while (strlen(noPlat) == 0) {
                    	printf("\n\t\tTidak boleh kosong [!]");
                    	printf("\n\tInput Nomor Plat       : "); fflush(stdin); gets(noPlat);
					}
					while (!isChildUnik(l, noPlat)) {
                    	printf("\n\t\tTidak boleh kosong [!]");
                    	printf("\n\tInput Nomor Plat       : "); fflush(stdin); gets(noPlat);
					}
					printf("\tInput Merek Mobil      : "); fflush(stdin); gets(merek);
					while (strlen(merek) == 0) {
                    	printf("\n\t\tTidak boleh kosong [!]");
                    	printf("\n\tInput Merek Mobil      : "); fflush(stdin); gets(merek);
					}
					printf("\tInput Kapasitas Bensin : "); scanf("%f", &bensin);
					while (bensin < 1) {
                    	printf("\n\t\tTidak boleh nol [!]");
                    	printf("\n\tInput Kapasitas Bensin : "); scanf("%f", &bensin);
					}
					while (bensin < 0) {
                    	printf("\n\t\tTidak boleh negatif [!]");
                    	printf("\n\tInput Kapasitas Bensin : "); scanf("%f", &bensin);
					}
                    insertFirstChild(l, id, makeDataChild(noPlat, merek, bensin));
                    printf("\n\t\tBerhasil menginput mobil...");
                } 
    			break;
    			
    		case 5:
    			printf("\n\t--- Jumlah Ruangan ---");
    			count = 0;
                for (tempParent = l.firstParent; tempParent != NULL; tempParent = tempParent->next) {
                    count++;
                }
                printf("\n\tJumlah Ruangan saat ini : %d", count);
    			break;
    			
    		case 6:
    			if (isEmpty(l)) {
    				printf("\n\tList masih kosong [!]");
				} else {
					printAll(l);
				}
    			break;
    			
    		case 7:
    			if (isEmpty(l)) {
    				printf("\n\tList masih kosong [!]");
				} else {
					distribusi(&l);
					printf("\n\tDistribusi selesai...");
				}
    			break;
    			
    		case 0:
    			printf("\n\tAlexis Divasonda Sigat Ngaing - 210711407 - A");
    			printf("\n\tBerhasil keluar...");
    			printf("\n\tSemoga harimu menyenangkan :)");
    			break;
    			
    		default:
    			printf("\n\tMenu invalid [!]");
    			break;
		} getch();
	} while (menu != 0);
	return 0;
}
