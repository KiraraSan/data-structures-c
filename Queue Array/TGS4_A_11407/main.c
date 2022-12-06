#include "header.h"

int main(int argc, char *argv[]) {
	Queue pertalite, pertamax;
	Bengsin B;
	int menu, menu_two, menu_three, index, id = 1001;
	int pPertalite = 0, pPertamax = 0, totalPembeli = 0;
	float uangPertalite = 0, uangPertamax = 0, totalUang = 0;
	
	createEmpty(&pertalite);
	createEmpty(&pertamax);
	
	do {
		system("cls");
		printf("=== UGD SPBU ===");
		printf("\n[1] Masuk Antrian");
		printf("\n[2] Bayar");
		printf("\n[3] Tampil Antrian");
		printf("\n[4] Cari Data");
		printf("\n\n=== Bonus/Tugas ===");
		printf("\n[5] Edit Data");
		printf("\n[6] Riwayat");
		printf("\n\n[0] Exit");
		printf("\n==> "); scanf("%d", &menu);
		
		switch(menu) {
			case 1 :
				printf("\n\tPilih Jenis Bahan Bakar");
				printf("\n\t[1] Pertalite");
				printf("\n\t[2] Pertamax");
				printf("\n\t>>> "); scanf("%d", &menu_two);

				switch(menu_two) {
					case 1 :
						if(!isFull(pertalite)) {		
							printf("\n\t\t--- Input Data ---\n");
							strcpy(B.jenis, "Pertalite");
							printf("\n\tID              : %d", id);
							B.id = id; 
							while(true) {
								printf("\n\tMasukkan Nama   : "); fflush(stdin); gets(B.nama);
								if(strlen(B.nama)==0 || strcmpi(B.nama, "-")==0 || B.nama[0] == ' ') {
									printf("\t[!] Nama tidak boleh kosong [!]\n");
								} else {
									break;
								}
							}
							printf("\tJenis           : Pertalite");
							printf("\n\tMasukkan Uang   : "); scanf("%f", &B.uang);
							while(B.uang < 10000) {
								printf("\n\t\t[!] Uang Anda kurang [!]");
								printf("\n\tMasukkan Uang   : "); scanf("%f", &B.uang);
							}
							Enqueue(&pertalite, makeBengsin(B.id, B.nama, B.jenis, B.uang));
							id++;
							} else {
								printf("\n\t\t[!] Antrian penuh [!]");
							}	
						break;
							
					case 2 :
						if(!isFull(pertamax)) {
							printf("\n\t\t--- Input Data ---\n");
							strcpy(B.jenis, "Pertamax");
							printf("\n\tID              : %d", id); 
							B.id = id;
							while(true) {
								printf("\n\tMasukkan Nama   : "); fflush(stdin); gets(B.nama);
								if(strlen(B.nama)==0 || strcmpi(B.nama, "-")==0 || B.nama[0] == ' ') {
									printf("\t[!] Nama tidak boleh kosong [!]\n");
								} else {
									break;
								}
							}
							printf("\tJenis           : Pertamax");
							printf("\n\tMasukkan Uang   : "); scanf("%f", &B.uang);
							while(B.uang < 14500) {
								printf("\n\t\t[!] Uang Anda kurang [!]");
								printf("\n\tMasukkan Uang   : "); scanf("%f", &B.uang);
							}
							Enqueue(&pertamax, makeBengsin(B.id, B.nama, B.jenis, B.uang));
							id++;
							} else {
								printf("\n\t\t[!] Antrian penuh [!]");
							}
						break;
							
					default :
						printf("\n\t\t[!] Menu invalid [!]");
						break;
					} 
				break;
			
			case 2 :
				printf("\n\tPilih Jenis Bahan Bakar");
				printf("\n\t[1] Pertalite");
				printf("\n\t[2] Pertamax");
				printf("\n\t>>> "); scanf("%d", &menu_three);
					
				switch(menu_three) {
					case 1 :
						if(!isEmpty(pertalite)) {
							printf("\n\t ID | %d | dengan nama | %s | berhasil melakukan pembayaran...", pertalite.B[pertalite.Head].id, pertalite.B[pertalite.Head].nama);
							pPertalite++;
							uangPertalite = uangPertalite + pertalite.B[pertalite.Head].uang;
							Dequeue(&pertalite);
						} else {
							printf("\n\t\t[!] Antrian kosong [!]");
						}
						break;
						
					case 2 :
						if(!isEmpty(pertamax)) {
							printf("\n\t ID | %d | dengan nama | %s | berhasil melakukan pembayaran...", pertamax.B[pertamax.Head].id, pertamax.B[pertamax.Head].nama);
							pPertamax++;
							uangPertamax = uangPertamax + pertamax.B[pertamax.Head].uang;
							Dequeue(&pertamax);
						} else {
							printf("\n\t\t[!] Antrian kosong [!]");
						}
						break;
				} 
				break;
			
			case 3 :
				printf("\n\t--- Antrian Pertalite ---\n");
				if(!isEmpty(pertalite)) {
					tampil(pertalite);
				}
				printf("\n\n\t--- Antrian Pertamax ---\n");
				if(!isEmpty(pertamax)) {
					tampil(pertamax);
				}
				break;
			
			case 4 :
				if(!isEmpty(pertalite) || !isEmpty(pertamax)) {
					printf("\nMasukkan ID pengunjung : "); scanf("%d", &B.id);
					
					index = isFound(pertalite, B.id);
					if(index != -1) {
						printf("\n\t--- Tampil Data ---");
						printf("\n\tID    : %d", pertalite.B[index].id);
						printf("\n\tNama  : %s", pertalite.B[index].nama);
						printf("\n\tJenis : %s", pertalite.B[index].jenis);
						printf("\n\tUang  : %.2f", pertalite.B[index].uang);
					} 
					
					index = isFound(pertamax, B.id);
					if(index != -1) {
						printf("\n\t--- Tampil Data ---");
						printf("\n\tID    : %d", pertamax.B[index].id);
						printf("\n\tNama  : %s", pertamax.B[index].nama);
						printf("\n\tJenis : %s", pertamax.B[index].jenis);
						printf("\n\tUang  : %.2f", pertamax.B[index].uang);
					} 
				} else {
					printf("\n\t[!] Antrian masih kosong [!]");
				}
				break;
			
			case 5 :
				if(!isEmpty(pertalite) || !isEmpty(pertamax)) {
					printf("\n\nMasukkan ID pembeli : "); scanf("%d", &B.id);
					
					index = isFound(pertalite, B.id);
					if(index != -1) {
						printf("\n\t\t--- Edit Data ---");
						while(true) {
								printf("\n\tMasukkan Nama   : "); fflush(stdin); gets(pertalite.B[index].nama);
								if(strlen(pertalite.B[index].nama)==0 || strcmpi(pertalite.B[index].nama, "-")==0 || B.nama[0] == ' ') {
									printf("\t[!] Nama tidak boleh kosong [!]\n");
								} else {
									break;
								}
							}
						printf("\tMasukkan Uang   : "); scanf("%f", &pertalite.B[index].uang);
						while(pertalite.B[index].uang < 10000) {
							printf("\n\t\t[!] Uang Anda kurang [!]");
							printf("\n\tMasukkan Uang   : "); scanf("%f", &pertalite.B[index].uang);
						}
						printf("\n\t--- Tampil Data ---");
						printf("\n\tID    : %d", pertalite.B[index].id);
						printf("\n\tNama  : %s", pertalite.B[index].nama);
						printf("\n\tJenis : %s", pertalite.B[index].jenis);
						printf("\n\tUang  : %.2f", pertalite.B[index].uang);
						printf("\n\n\t\tBerhasil edit data...");
						break;
					} 	
					
					index = isFound(pertamax, B.id);	
					if(index != -1) {	
						printf("\n\t\t--- Edit Data ---");
						while(true) {
								printf("\n\tMasukkan Nama   : "); fflush(stdin); gets(pertamax.B[index].nama);
								if(strlen(pertamax.B[index].nama)==0 || strcmpi(pertamax.B[index].nama, "-")==0 || B.nama[0] == ' ') {
									printf("\t[!] Nama tidak boleh kosong [!]\n");
								} else {
									break;
								}
							}
						printf("\n\tMasukkan Uang   : "); scanf("%f", &pertamax.B[index].uang);
						while(pertamax.B[index].uang < 10000) {
							printf("\n\t\t[!] Uang Anda kurang [!]");
							printf("\n\tMasukkan Uang   : "); scanf("%f", &pertamax.B[index].uang);
						}
						printf("\n\t--- Tampil Data ---");
						printf("\n\tID    : %d", pertamax.B[index].id);
						printf("\n\tNama  : %s", pertamax.B[index].nama);
						printf("\n\tJenis : %s", pertamax.B[index].jenis);
						printf("\n\tUang  : %.2f", pertamax.B[index].uang);
						printf("\n\n\t\tBerhasil edit data...");
						break;
					}
					printf("\n\t\t[!] ID tidak ditemukan [!]"); 
				} else {
					printf("\n\t[!] Antrian masih kosong [!]");
				}
				break;
			
			case 6 :
				printf("\n\t\t--- Riwayat ---");
				printf("\nPertalite");
				printf("\n\tJumlah Pembeli  : %d", pPertalite);
				printf("\n\tUang Kas        : %.2f", uangPertalite);
				printf("\n\nPertamax");
				printf("\n\tJumlah Pembeli  : %d", pPertamax);
				printf("\n\tUang Kas        : %.2f", uangPertamax);
				
				totalPembeli = pPertalite + pPertamax;
				totalUang = uangPertalite + uangPertamax;
				
				printf("\n\n\t\tTotal Pembeli : %d", totalPembeli);
				printf("\n\t\tTotal Kas     : %.2f", totalUang);
				break;
			
			case 0 :
				printf("\n\tAlexis Divasonda Sigat Ngaing - 210711407");
				break;
			
			default :
				printf("\n\t[!] Menu tidak tersedia [!]");
				break;
		}
		getch();
	} while(menu != 0);
	
	return 0;
}
