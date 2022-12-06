// Bonus 1

#include "header.h"

int main(int argc, char *argv[]) {
	List L, Lr;
	Perabotan P;
	address temp, temp_two;
	
	string namaBarang, bahanBarang, merk, bahanBarang_bayar;
	int menu, harga, uang;
    
    createEmpty(&L);
    createEmpty(&Lr);
    
    do {
    	system("cls");
        printf("===== TOKO PERABOTAN MAKMURZ =====");
        printf("\n[1] Input Data");
        printf("\n[2] Bayar");
        printf("\n[3] Tampil Perabotan");
        printf("\n[4] Cari Perabotan");
        printf("\n[5] Riwayat Pembelian");
        printf("\n[0] Exit");
        printf("\n>>> "); scanf("%d", &menu);
        
        switch (menu) {
        	case 1:
        		printf("\n--- Input Data ---\n");
                printf("Nama  : "); fflush(stdin); gets(namaBarang);
                printf("Bahan : "); fflush(stdin); gets(bahanBarang);
                while (strcmpi(bahanBarang, "Kayu") != 0 && strcmpi(bahanBarang, "Rotan") != 0) {
                	printf("\tBahan tidak tersedia (only: Kayu & Rotan) [!]\n");
                	printf("Bahan : "); fflush(stdin); gets(bahanBarang);
				}
                printf("Merk  : "); fflush(stdin); gets(merk);
                printf("Harga : "); scanf("%d", &harga);

                P = makePerabot(namaBarang, bahanBarang, merk, harga);
                if (strcmpi(bahanBarang, "Kayu") == 0) {
                	insertFirst(&L, P);
				}
				if (strcmpi(bahanBarang, "Rotan") == 0) {
					insertLast(&L, P);
				}
        		break;
        		
        	case 2:
        		if (!isEmpty(L)) {
        			printf("\n--- Bayar ---");
        			printf("\nPilih bahan barang pada list yang ingin dibayar : "); fflush(stdin); gets(bahanBarang_bayar);
        			if (strcmpi(bahanBarang_bayar, "Kayu") == 0) {
	                	if (strcmpi(L.first->P.bahanBarang, "Kayu") == 0) {
	                		printf("\nHarga barang : Rp %d", L.first->P.harga);
		                	printf("\nMasukkan uang pembayaran : "); scanf("%d", &uang);
		                	while (uang < L.first->P.harga) {
		                		printf("\n\tUang Anda kurang [!]");
		                		printf("\nMasukkan uang pembayaran : "); scanf("%d", &uang);
							}
							insertFirst(&Lr, L.first->P);
							deleteFirst(&L);
							printf("\nBerhasil melakukan pembayaran (Kayu)...");
						} else {
							printf("\n\tBahan kosong [!]");
						}
					} else if (strcmpi(bahanBarang_bayar, "Rotan") == 0) {
						if (strcmpi(L.first->P.bahanBarang, "Rotan") == 0) {
							printf("\nHarga barang : Rp %d", L.first->P.harga);
							printf("\nMasukkan uang pembayaran : "); scanf("%d", &uang);
		                	while (uang < L.first->P.harga) {
		                		printf("\n\tUang Anda kurang [!]");
		                		printf("\nMasukkan uang pembayaran : "); scanf("%d", &uang);
							}
							insertFirst(&Lr, L.first->P);
							deleteLast(&L);
							printf("\nBerhasil melakukan pembayaran (Rotan)...");
						} else {
							printf("\n\tBahan kosong [!]");
						}
					} else {
						printf("\n\tBahan invalid [!]");
					}	
				} else {
					printf("\n\tList kosong [!]");
				}
				break;
				
			case 3:
				if (!isEmpty(L)) {
					print(L);
				} else {
					printf("\n\tList kosong [!]");
				}
				break;
				
			case 4:
				if (!isEmpty(L)) {
					printf("\n--- Cari Barang ---");
					printf("\nMasukkan nama barang yang ingin dicari : "); fflush(stdin); gets(namaBarang);
					
					Perabotan *p = cari(L, namaBarang);
					
					if (p != NULL) {
						printf("\nNama  : %s", p->namaBarang);
			            printf("\nBahan : %s", p->bahanBarang);
			            printf("\nMerk  : %s", p->merk);
			            printf("\nHarga : %d", p->harga);	
					} else {
						printf("\n\tBarang tidak ditemukan [!]");
					}
				} else {
					printf("\n\tList kosong [!]");
				}
				break;	
				
			case 5:
				if (!isEmpty(Lr)) {
					print(Lr);
				} else {
					printf("\n\tList kosong [!]");
				}
				break;
				
			case 0:
				printf("\n\tAlexis Divasonda Sigat Ngaing - 210711407");
				printf("\n\tBerhasil keluar");
				printf("\n\n\t\tSemoga harimu menyenangkan...");
				break;
				
			default:
				printf("\n\tMenu invalid [!]");
				break;
		} getch();
	} while (menu != 0);
	
	return 0;
}
