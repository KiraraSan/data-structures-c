#include "header.h"

int main(int argc, char *argv[]) {
	List L, Lr;
    addr delNode;
    Data D;

    int menu, submenu, prevData;
    int id = 1;
    float uang, kembalian, kurang, pendapatan = 0;
    string namaPeminjam;
    
    createEmpty(&L);
	
	do {
		system("cls");
		printf("\n===== Peminjaman Motor =====");
		printf("\n[1] Input Data Peminjaman");
		printf("\n[2] Tampil Data");
		printf("\n[3] Cari Data");
		printf("\n[4] Pengembalian\n");
		printf("\n===== Bonus =====");
		printf("\n[5] Riwayat\n");
		printf("\n[0] Exit");
		printf("\n>>> "); scanf("%d", &menu);
		
		switch (menu) {
			case 1:
				do {
					system("cls");
					printf("\n\t[1] Input Baru");
					printf("\n\t[2] Input Setelah ID");
					printf("\n\t[0] Menu Utama");
					printf("\n\t>>> "); scanf("%d", &submenu);
					
					switch (submenu) {
						case 1:
							printf("\n\tID-%d\n", id);
							D.id = id;
							while (true) {
								printf("\tJenis Motor    : "); fflush(stdin); gets(D.jenisMotor);
								if (strcmpi(D.jenisMotor, "Matic") != 0 && strcmpi(D.jenisMotor, "Manual") != 0) {
									printf("\n\t\tJenis Motor invalid (only: Manual / Matic) [!]\n");
								} else {
									break;
								}
							}
							printf("\tNama Peminjam  : "); fflush(stdin); gets(D.namaPeminjam);
							printf("\tTanggal Pinjam : "); fflush(stdin); gets(D.tanggalPinjam);
							strcpy(D.status, "Dipinjam");
							if (strcmpi(D.jenisMotor, "Matic") == 0) {
								D.hargaPinjam = 80000;
							} else {
								D.hargaPinjam = 75000;
							}
							insertFirst(&L, alokasi(D));
							id++;
							printf("\n\t\tData berhasil diinput...");
							break;
							
						case 2:
							printf("\n\tID - %d", id);
							D.id = id;
							while (true) {
								printf("\n\tJenis Motor    : "); fflush(stdin); gets(D.jenisMotor);
								if(strcmpi(D.jenisMotor, "Matic") == 0 && strcmpi(D.jenisMotor, "Manual") == 0) {
									printf("\n\t\tJenis Motor invalid (only: Manual / Matic) [!]\n");
								} else {
									break;
								}
							}
							printf("\tNama Peminjam  : "); fflush(stdin); gets(D.namaPeminjam);
							printf("\tTanggal Pinjam : "); fflush(stdin); gets(D.tanggalPinjam);
							strcpy(D.status, "Dipinjam");
							if (strcmpi(D.jenisMotor, "Matic")) {
								D.hargaPinjam = 80000;
							} else {
								D.hargaPinjam = 75000;
							}
							printf("\n\tMasukkan setelah ID : "); scanf("%d", &prevData);
                			insertAfter(&L, alokasi(D), prevData);
							id++;
							break;
							
						case 0:
							printf("\n\tKembali ke menu utama...");
							break;
							
						default:
							printf("\n\tMenu invalid [!]");
							break;
					} getch();
				} while (submenu != 0);
				break;
				
			case 2:
				if (!isEmpty(L)) {
					printAll(L);
				} else {
					printf("\n\tData kosong [!]");
				}
				break;
				
			case 3:
				printf("\nMasukkan Nama Peminjam : "); fflush(stdin); gets(namaPeminjam);
				if (findPeminjam(L, namaPeminjam) == NULL) {
					printf("\n\tData tidak ditemukan [!]");
				} else {
					printf("\nID-%d", L->data.id);
			        printf("\nJenis Motor    : %s", L->data.jenisMotor);
			        printf("\nNama Peminjam  : %s", L->data.namaPeminjam);
			        printf("\nTanggal Pinjam : %s", L->data.tanggalPinjam);
			        printf("\nStatus         : %s", L->data.status);
			        printf("\nHarga Pinjam   : Rp %.2f", L->data.hargaPinjam);
				}
				break;
				
			case 4:
				printf("\nMasukkan Nama Peminjam : "); fflush(stdin); gets(namaPeminjam);
				if (findPeminjam(L, namaPeminjam) == NULL) {
					printf("\n\tData tidak ditemukan [!]");
				} else {
					printf("\nID-%d", L->data.id);
			        printf("\nJenis Motor    : %s", L->data.jenisMotor);
			        printf("\nNama Peminjam  : %s", L->data.namaPeminjam);
			        printf("\nTanggal Pinjam : %s", L->data.tanggalPinjam);
			        printf("\nStatus         : %s", L->data.status);
			        printf("\nHarga Pinjam   : Rp %.2f\n", L->data.hargaPinjam);
			        
			        printf("\nMasukkan Uang  : "); scanf("%f", &uang);
			        
			        if (uang < L->data.hargaPinjam) {
			        	kurang = L->data.hargaPinjam - uang;
			        	
			        	printf("\nKekurangan - Rp %.2f", kurang);
			        	printf("\nBelum Lunas [!]");
			        	
			        	pendapatan += uang;
			        	
			        	strcpy(L->data.status, "Pending");
			        	L->data.hargaPinjam = kurang;
					} else {
						kembalian = uang - L->data.hargaPinjam;
						printf("\nBerhasil Dikembalikan - Kembalian = Rp %.2f", kembalian);
						
						pendapatan += L->data.hargaPinjam;
						
						insertFirst(&Lr, alokasi(L->data));
						delNode = findPeminjam(L, namaPeminjam);
						deleteAt(&L, delNode);
					}
				}
				break;
				
			case 5:
				if (!isEmpty(Lr)) {
					printRiwayat(Lr, pendapatan);
				} else {
					printf("\n\tData riwayat kosong [!]");
				}
				break;
				
			case 0:
				printf("\n\tAlexis Divasonda Sigat Ngaing - A - 210711407");
				printf("\n\tExit...");
				printf("\n\n\t\t--- Semoga harimu menyenangkan :) ---\n\n");
				break;
		} getch();
	} while (menu != 0);
	return 0;
}
