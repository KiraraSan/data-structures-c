#include "header.h"

int main(int argc, char *argv[]) {
	Queue Q, pertalite, pertamax;
	Bengsin temp;
	int menu, menu_two, menu_three, index;
	temp.id = 1000;
	
	createEmpty(&Q);
	
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
				if(!isFull(Q)) {
					do {
//						system("cls");
						printf("\n\tPilih Jenis Bahan Bakar");
						printf("\n\t[1] Pertalite");
						printf("\n\t[2] Pertamax");
						printf("\n\t>>> "); scanf("%d", &menu_two);
						
//						printf("\n\t\t--- Input Data ---\n");
						switch(menu_two) {
							case 1 :
								printf("\n\t\t--- Input Data ---\n");
								strcpy(temp.jenis, "Pertalite");
								temp.id = temp.id+1;
								printf("\n\tID              : %d", temp.id); 
								printf("\n\tMasukkan Nama   : "); fflush(stdin); gets(temp.nama);
								while(strcpy(temp.nama, "-")==0 || strcpy(temp.nama, " ")==0) {
									printf("\n\t\t[!] Nama tidak boleh kosong [!]");
									printf("\n\tMasukkan Nama   : "); fflush(stdin); gets(temp.nama);
								}
								printf("\tJenis           : %s", temp.jenis);
								printf("\n\tMasukkan Uang   : "); scanf("%f", &temp.uang);
								while(temp.uang < 10000) {
									printf("\n\t\t[!] Uang Anda kurang [!]");
									printf("\n\tMasukkan Uang   : "); scanf("%f", &temp.uang);
								}
								Enqueue(&pertalite, makeBengsin(temp.id, temp.nama, temp.jenis, temp.uang));
								menu_two = 0;
							break;
							
							case 2 :
								printf("\n\t\t--- Input Data ---\n");
								strcpy(temp.jenis, "Pertamax");
								temp.id = temp.id+1;
								printf("\n\tID              : %d", temp.id); 
								printf("\n\tMasukkan Nama   : "); fflush(stdin); gets(temp.nama);
								while(strcpy(temp.nama, "-")==0 || strcpy(temp.nama, " ")==0) {
									printf("\n\t\t[!] Nama tidak boleh kosong [!]");
									printf("\n\tMasukkan Nama   : "); fflush(stdin); gets(temp.nama);
								}
								printf("\tJenis           : %s", temp.jenis);
								printf("\n\tMasukkan Uang   : "); scanf("%f", &temp.uang);
								while(temp.uang < 14500) {
									printf("\n\t\t[!] Uang Anda kurang [!]");
									printf("\n\tMasukkan Uang   : "); scanf("%f", &temp.uang);
								}
								Enqueue(&pertamax, makeBengsin(temp.id, temp.nama, temp.jenis, temp.uang));
								menu_two = 0;
							break;
							
							default :
								printf("\n\t\t[!] Menu invalid [!]");
							break;
						} getch();
					} while(menu_two != 0);
				} else {
					printf("\n\t[!] Antrian penuh [!]");
				}
			break;
			
			case 2 :
				do {
					printf("\n\tPilih Jenis Bahan Bakar");
					printf("\n\t[1] Pertalite");
					printf("\n\t[2] Pertamax");
					printf("\n\t>>> "); scanf("%d", &menu_three);
					
					switch(menu_three) {
						case 1 :
							if(isEmpty(pertalite)==0) {
								Dequeue(&pertalite);
							} else {
								printf("\n\t[!] Antrian kosong [!]");
							}
						break;
						
						case 2 :
							if(isEmpty(pertamax)==0) {
								Dequeue(&pertamax);
							} else {
								printf("\n\t[!] Antrian kosong [!]");
							}
						break;
					} getch();
				} while(menu_three != 0);	
			break;
			
			case 3 :
				printf("\n\t--- Antrian Pertalite ---\n");
					tampil(pertalite);
				printf("\n\n\t--- Antrian Pertamax ---\n");
					tampil(pertamax);
			break;
			
			case 4 :
				if(!isEmpty(Q)) {
					printf("\n\nMasukkan ID pengunjung : "); scanf("%d", temp.id);
					index = isFound(Q, temp.id);
					
					if(index != -1) {
						printf("\n\t\t--- Tampil Data ---");
						printf("\n\t\tID    : %d", Q.B[index].id);
						printf("\n\t\tNama  : %s", Q.B[index].nama);
						printf("\n\t\tJenis : %s", Q.B[index].jenis);
						printf("\n\t\tUang  : %s", Q.B[index].uang);
					} else {
						printf("\n\t[!] Data yang dicari tidak ditemukan");
					}
				} else {
					printf("\n\t[!] Antrian masih kosong [!]");
				}
			break;
			
			case 5 :
				if(!isEmpty(Q)) {
					printf("\n\nMasukkan ID pengunjung : "); scanf("%d", temp.id);
					index = isFound(Q, temp.id);
					
					if(index != -1) {
						if(strcmpi(Q.B[index].jenis, "Pertalite")==0) {
							printf("\n\t\t--- Tampil Data ---");
							printf("\n\tMasukkan Nama   : "); fflush(stdin); gets(Q.B[index].nama);
							while(strcmp(Q.B[index].nama, "-")==0 || strcmp(Q.B[index].nama, " ")==0) {
								printf("\n\t\t[!] Nama tidak boleh kosong [!]");
								printf("\n\tMasukkan Nama   : "); fflush(stdin); gets(Q.B[index].nama);
							}
							printf("\n\tMasukkan Uang   : "); scanf("%f", &Q.B[index].uang);
							while(Q.B[index].uang < 10000) {
								printf("\n\t\t[!] Uang Anda kurang [!]");
								printf("\n\tMasukkan Uang   : "); scanf("%f", &Q.B[index].uang);
							}
						}	
						else if(strcmpi(Q.B[index].jenis, "Pertamax")==0) {
							printf("\n\t\t--- Tampil Data ---");
							printf("\n\tMasukkan Nama   : "); fflush(stdin); gets(Q.B[index].nama);
							while(strcmp(Q.B[index].nama, "-")==0 || strcmp(Q.B[index].nama, " ")==0) {
								printf("\n\t\t[!] Nama tidak boleh kosong [!]");
								printf("\n\tMasukkan Nama   : "); fflush(stdin); gets(Q.B[index].nama);
							}
							printf("\n\tMasukkan Uang   : "); scanf("%f", &Q.B[index].uang);
							while(Q.B[index].uang < 10000) {
								printf("\n\t\t[!] Uang Anda kurang [!]");
								printf("\n\tMasukkan Uang   : "); scanf("%f", &Q.B[index].uang);
							}
						}
					} else {
						printf("\n\t[!] Data yang dicari tidak ditemukan");
					}
				} else {
					printf("\n\t[!] Antrian masih kosong [!]");
				}
			break;
			
			case 6 :
				printf("\n\t\t--- Riwayat ---");
				printf("\n\t\t[!] Program Maintenance [!]");
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
