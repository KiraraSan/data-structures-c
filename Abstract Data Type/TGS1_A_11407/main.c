#include "header.h"

int main(int argc, char *argv[]) {
	
	Roda R[rodaMAX];
	Motor M[motorMAX];
	string nama, merk, plat, cari, jenis;
	int menu, submenu, cc, temp, i, n, index;
	float uang, kembalian, bobot, total;
	
	inisialisasi(M);
	
	do {
		system("cls");
		printf("=== YAMAHA CABANG WAKANDA ===\n");
		printf("[1]. Create\n"); 
		printf("[2]. Read\n");
		printf("[3]. Update\n");
		printf("[4]. Calculate\n");
		printf("[5]. Delete (Bonus)\n");
		printf("[0]. Exit\n");
		printf(">>> "); scanf("%d", &menu);
		
		switch(menu) {
			case 1 :
				if(isFull(M) != -1) {
					for(i=0; i<motorMAX; i++) {
						temp = getEmpty(M);
						break;
					}
					printf("\nInputkan Data\n");
					printf("Nama   : "); fflush(stdin); gets(nama);
					printf("Merk   : "); fflush(stdin); gets(merk);
					printf("CC     : "); scanf("%d", &cc);
					printf("Plat   : "); fflush(stdin); gets(plat);
					while(strcmpi(M[i].plat, plat)==0) {
						printf("\n\t[!] Plat tidak boleh sama\n");
						printf("Plat   : "); fflush(stdin); gets(plat);
					}
					M[temp] = createMotor(nama, merk, cc, plat);
					
					printf("\n\tData Roda\n");
					for(n=0; n<rodaMAX; n++) {
						printf("\tRoda %d", i+1);
						printf("\n\tJenis : "); fflush(stdin); gets(jenis);
						printf("\tBobot : "); scanf("%f", &bobot);
						printf("\n");
						
						M[temp].R[n] = createRoda(jenis, bobot);
					}
					printf("\t[+] Berhasil menambahkan motor [ %s ] %d CC", M[i].nama, M[i].cc);
				} else {
				printf("[!] Hanya dapat membeli 5 motor");
				}
			break;
			
			case 2 :
				printf("\nData Motor Anda\n");
				read(M);
			break;
			
			case 3 :
				if(isEmpty(M) != -1) {
					printf("Ubah Data\n");
					printf("Masukkan Plat Nomor yang akan diubah : "); fflush(stdin); gets(plat);
					if(isFound(M, plat) != -1) {
						update(M, plat);
						printf("\n\t[+] Data berhasil diupdate");
					} else {
						printf("\n\t[!] Motor tidak ditemukan");
					}
				} else {
					printf("\n\t[!] Data masih kosong");
				}
			break;
			
			case 4 :
				if(isEmpty(M) != -1) {
					system("cls");
					printf("--- Pilih Jasa ---\n");
					printf("Masukkan Plat Nomor : "); fflush(stdin); gets(plat);
					index = isFound(M, plat);
					if(isFound(M, plat) != -1) {
					do {
						system("cls");
						printf("\n\t[1] Servis - Rp 125.000 - Rp 300.000 - Rp 400.000");
						printf("\n\t[2] Ganti Oli - Rp 60.000");	
						printf("\n\t[3] Ganti Ban - Rp 250.000 - Rp 400.000");
						printf("\n\t[0] Kembali");	
						printf("\n\t>>> "); scanf("%d", &submenu);
						
						switch(submenu) {
							case 1 :
								if(M[index].cc < 150) {
									total += 125000;
								}
								else if(M[index].cc >= 150) {
									total += 300000;
								}
								else if(M[index].cc >= 500) {
									total += 400000;
								}
								printf("\n\t[+] Berhasil pilih servis");
							break;
							
							case 2 :
								total += 60000;
								printf("\n\t[+] Berhasil ganti oli");
							break;
							
							case 3 :
								for(n=0; n<rodaMAX; n++) {
									if(M[index].R[n].bobot <= 5) {
									total += 250000;
									}
									if(M[index].R[n].bobot > 5) {
										total += 400000;
									}
								}
								printf("\n\t[+] Berhasil ganti ban");
							break;
							
							case 0 :
								printf("\n\tTotal harga : Rp %.0f", total);
								printf("\n\tMasukkan uang anda : "); scanf("%f", &uang);
								while(uang < total) {
									printf("\n\tMasukkan uang anda : "); scanf("%f", &uang);
									printf("\n\t[!] Uang anda kurang");
								} 
								kembalian = uang - total;
								printf("\n\tKembalian : Rp %.0f", kembalian);
							break;
							
							default :
								printf("\n\t\t[!] Menu invalid");
							break;
						} 
						getch();
					} while (submenu != 0);
					} else {
						printf("\n\t[!] Motor tidak ditemukan");
					}
				} else {
					printf("\n\t[!] Data masih kosong");
				}
			break;
			
			case 5 :
				if(isEmpty(M) != -1) {
					printf("Hapus Data\n");
					printf("Masukkan Nama yang akan dihapus : "); fflush(stdin); gets(nama);
					if(isFound2(M, nama) != -1) {
						hapus(M, nama);
						printf("\n\t[+] Data berhasil dihapus");
					} else {
						printf("\n\t[!] Data tidak ditemukan");
					}
				} else {
					printf("\n\t[!] Data masih kosong");
				}
			break;
			
			case 0 :
				printf("\n\tTerima Kasih\n");
				printf("\tKeluar Program...");
			break;
			
			default :
				printf("\n\t[!] Menu invalid");
			break;
		} getch();
	} while(menu != 0);
	return 0;
}
