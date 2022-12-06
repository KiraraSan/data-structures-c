#include "header.h"

int main(int argc, char *argv[]) {
	
	Motor M[motorMAX];
	string nama, merk, plat, cari;
	int menu, submenu, cc, temp, i, index;
	float uang, kembalian;
	
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
					while(strcmp(M[i].plat, plat)==0) {
						printf("\n\t[!] Plat tidak boleh sama");
						printf("Plat   : "); fflush(stdin); gets(plat);
					}
					create(M, nama, merk, cc, plat, temp);
					printf("\n\t[+] Berhasil. Silakan lakukan pembayaran");
				} else {
				printf("[!] Hanya dapat membeli 5 motor");
				}
			break;
			
			case 2 :
				if(isEmpty(M) != -1) {
					printf("Data Motor Anda\n");
					read(M);
				} else {
					printf("\n\t[!] Data masih kosong");
				}
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
						printf("\n\t[1] Servis");
						printf("\n\t[2] Ganti Oli");	
						printf("\n\t[3] Servis");
						printf("\n\t[0] kembali");	
						printf("\n\t>>> "); scanf("%d", &submenu);
						
						switch(submenu) {
							case 1 :
								if(M[index].cc < 150) {
									printf("\n\n\tBiaya Servis : Rp 125.000");
									printf("\n\tMasukkan Uang Anda : Rp "); scanf("%f", &uang);
									if(uang < 125000) {
										printf("\n\t\t[!] Uang Anda kurang");
									} else {
										kembalian = uang - 125000;
										printf("\n\n\tKembalian : Rp %.2f", kembalian);
									}
								} 
								else if(M[index].cc >= 150 && M[index].cc <= 500) {
									printf("\n\n\tBiaya Servis : Rp 300.000");
									printf("\n\tMasukkan Uang Anda : Rp "); scanf("%f", &uang);
									if(uang < 300000) {
										printf("\n\t\t[!] Uang Anda kurang");
									} else {
										kembalian = uang - 300000;
										printf("\n\n\tKembalian : Rp %.2f", kembalian);
									}
								} 
								if(M[index].cc >= 500) {
									printf("\n\n\tBiaya Servis : Rp 400.000");
									printf("\n\tMasukkan Uang Anda : Rp "); scanf("%f", &uang);
									if(uang < 400000) {
										printf("\n\t\t[!] Uang Anda kurang");
									} else {
										kembalian = uang - 400000;
										printf("\n\n\tKembalian : Rp %.2f", kembalian);
									}
								} 
							break;
							
							case 2 :
								printf("\n\tGanti Oli");
								printf("\n\tBiaya Rp 60.000");
								printf("\n\tMasukkan Uang Anda : Rp "); scanf("%f", &uang);
								if(uang < 60000) {
									printf("\n\t\t[!] Uang Anda kurang");
								} else {
									kembalian = uang - 60000;
									printf("\n\n\tKembalian : Rp %.2f", kembalian);
								}
							break;
							
							case 3 :
								printf("\n\tGanti Oli");
								printf("\n\tBiaya Rp 60.000");
								printf("\n\tMasukkan Uang Anda : Rp "); scanf("%f", &uang);
								if(uang < 250000) {
									printf("\n\t\t[!] Uang Anda kurang");
								} else {
									kembalian = uang - 250000;
									printf("\n\n\tKembalian : Rp %.2f", kembalian);
								}
							break;
							
							case 0 :
								printf("Kembali");
							break;
							
							default :
								printf("\n\t\t[!] Menu invalid");
							break;
						} 
						getch();
						printf("\n\t[+] ");
					} else {
						printf("\n\t[!] Motor tidak ditemukan");
					}
				} else {
					printf("\n\t[!] Data masih kosong");
				}
			break;
			
			case 5 :
				
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
