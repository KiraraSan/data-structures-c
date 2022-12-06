#include "header.h"

int main(int argc, char *argv[]) {
	Peneliti P[MAX_P], temp;
    int menu, index, n = 1;
    string nama;
    float gajiPenelitian = 500000, gajiTotal;
	float gaji_P_0, gaji_P_1, gaji_P_2, gaji_P_3, gaji_P_4, gaji_P_5, gaji_P_6, gaji_P_7, gaji_P_8, gaji_P_9, gaji_P_10, gaji_P_11;
	float gaji_T_0, gaji_T_1, gaji_T_2, gaji_T_3, gaji_T_4, gaji_T_5, gaji_T_6, gaji_T_7, gaji_T_8, gaji_T_9, gaji_T_10, gaji_T_11;
    inisialisasi(P, 0);
	
	do {
		system("cls");
		printf("\n\t=== ATMA MICROLAB ===");
		printf("\n[1] Input Peneliti");
		printf("\n[2] Tampil Data");
		printf("\n[3] Edit Jumlah Penelitian Bulanan");
		printf("\n[4] Pembayaran Gaji\n");
		printf("\n\t=== TUGAS ===");
		printf("\n[5] Statistik Peneliti");
		printf("\n[6] Peneliti Berdasarkan Bidang Keahlian\n");
		printf("\n\t=== BONUS ===");
		printf("\n[7] Simulasi Perkembangan Bakteri");
		printf("\n[0] EXIT\n");
		printf("\n>>> "); scanf("%d", &menu);
		
		switch (menu) {
			case 1:
				printf("\n\t--- Input Peneliti ---");
				index = getEmptyIndex(P, 0);
                if (index != -1) {
					printf("\n\tNama Peneliti   : "); fflush(stdin); gets(temp.nama);
					while (strlen(temp.nama) == 0) {
						printf("\n\t\tNama tidak boleh kosong [!]");
						printf("\n\tNama Peneliti   : "); fflush(stdin); gets(temp.nama);
					}
					while (!isPenelitiUnik(P, index, nama)) {
						printf("\n\t\tNama harus unik [!]");
						printf("\n\tNama Peneliti   : "); fflush(stdin); gets(temp.nama);
					}
					printf("\tBidang Keahlian : "); fflush(stdin); gets(temp.bidangKeahlian);
					while (strlen(temp.bidangKeahlian) == 0) {
						printf("\n\t\tBidang Keahlian tidak boleh kosong [!]");
	                    printf("\n\tBidang Keahlian : "); fflush(stdin); gets(temp.bidangKeahlian);
	                }
	                while (strcmpi(temp.bidangKeahlian, "Virus") != 0 && strcmpi(temp.bidangKeahlian, "Bakteri") != 0) {
						printf("\n\t\tInvalid [Harus: Virus / Bakteri]");
						printf("\n\tBidang Keahlian : "); fflush(stdin); gets(temp.bidangKeahlian);
					} 
					printf("\tGaji Pokok      : "); scanf("%f", &temp.gajiPokok);
					printf("\n\t\t--- Jumlah Penelitian Bulanan ---\n");
//					if (MAX < 0) {
//					} else {
						printf("\t\tBulan ke-01  : "); scanf("%d", &temp.jmlPenelitianBln[0]);
						printf("\t\tBulan ke-02  : "); scanf("%d", &temp.jmlPenelitianBln[1]);
						printf("\t\tBulan ke-03  : "); scanf("%d", &temp.jmlPenelitianBln[2]);
						printf("\t\tBulan ke-04  : "); scanf("%d", &temp.jmlPenelitianBln[3]);
						printf("\t\tBulan ke-05  : "); scanf("%d", &temp.jmlPenelitianBln[4]);
						printf("\t\tBulan ke-06  : "); scanf("%d", &temp.jmlPenelitianBln[5]);
						printf("\t\tBulan ke-07  : "); scanf("%d", &temp.jmlPenelitianBln[6]);
						printf("\t\tBulan ke-08  : "); scanf("%d", &temp.jmlPenelitianBln[7]);
						printf("\t\tBulan ke-09  : "); scanf("%d", &temp.jmlPenelitianBln[8]);
						printf("\t\tBulan ke-10  : "); scanf("%d", &temp.jmlPenelitianBln[9]);
						printf("\t\tBulan ke-11  : "); scanf("%d", &temp.jmlPenelitianBln[10]);
						printf("\n\t\tBulan ke-12  : "); scanf("%d", &temp.jmlPenelitianBln[11]);
//						MAX - 1;
//						n + 1;
//					}
					P[index] = temp;
					printf("\n\t\t\tData berhasil disimpan...");
				} else {
					printf("\n\tData penuh [!]");
				}
				break;
				
			case 2:
				if (!isEmpty(P, 0)) {
                    printAll(P, 0);
                } else {
                    printf("\n\tData kosong [!]");
                }
				break;
				
			case 3:
				printf("\n\t--- Edit Jumlah Penelitian Bulanan ---");
				if (!isEmpty(P, 0)) {						
					printf("\n\tNama Peneliti : "); fflush(stdin); gets(nama);
					
					int find = cariPeneliti(P, index, nama);
	                if (cariPeneliti(P, MAX - 1, nama) < 0) {
	                    printf("\n\tPeneliti tidak ditemukan");
	                } else {
	//                if (MAX < 0) {
	//				} else {
						printf("\n\t\tBulan ke-01  : "); scanf("%d", &P[find].jmlPenelitianBln[0]);
						printf("\n\t\tBulan ke-02  : "); scanf("%d", &P[find].jmlPenelitianBln[1]);
						printf("\n\t\tBulan ke-03  : "); scanf("%d", &P[find].jmlPenelitianBln[2]);
						printf("\n\t\tBulan ke-04  : "); scanf("%d", &P[find].jmlPenelitianBln[3]);
						printf("\n\t\tBulan ke-05  : "); scanf("%d", &P[find].jmlPenelitianBln[4]);
						printf("\n\t\tBulan ke-06  : "); scanf("%d", &P[find].jmlPenelitianBln[5]);
						printf("\n\t\tBulan ke-07  : "); scanf("%d", &P[find].jmlPenelitianBln[6]);
						printf("\n\t\tBulan ke-08  : "); scanf("%d", &P[find].jmlPenelitianBln[7]);
						printf("\n\t\tBulan ke-09  : "); scanf("%d", &P[find].jmlPenelitianBln[8]);
						printf("\n\t\tBulan ke-10  : "); scanf("%d", &P[find].jmlPenelitianBln[9]);
						printf("\n\t\tBulan ke-11  : "); scanf("%d", &P[find].jmlPenelitianBln[10]);
						printf("\n\t\tBulan ke-12  : "); scanf("%d", &P[find].jmlPenelitianBln[11]);
	//					MAX - 1;
	//					n + 1;
	//					}
	                }
                } else {
					printf("\n\tData kosong [!]");
				}
				break;
				
			case 4:
				if (!isEmpty(P, 0)) {
                    printf("\n\tNama Peneliti : "); fflush(stdin); gets(nama);
					
					int find = cariPeneliti(P, index, nama);
	                if (cariPeneliti(P, MAX - 1, nama) < 0) {
	                	printf("\n\tPeneliti tidak ditemukan");
					} else {
						printf("\n\t--- Pembayaran Gaji ---");
						printf("\n\tNama Peneliti : %s\n", P[find].nama);
						printf("\n\tGaji Setiap Bulan");
						printf("\n\tGaji Pokok             : %s", P[find].gajiPokok);
						printf("\n\tGaji Setiap Penelitian : %.2f", gajiPenelitian);
						
						printf("\n\tBulan ke-01");
						printf("\n\t> Jumlah Penelitian  : %d", P[find].jmlPenelitianBln[0]);
						gaji_P_0 = P[find].jmlPenelitianBln[0] * gajiPenelitian;
						printf("\n\t> Gaji Penelitian    : %.2f", gaji_P_0);
						gaji_T_0 = P[find].gajiPokok + gaji_P_0;
						printf("\n\t> Total Gaji         : %.2f\n", gaji_T_0);
						
						printf("\n\tBulan ke-02");
						printf("\n\t> Jumlah Penelitian  : %d", P[find].jmlPenelitianBln[1]);
						gaji_P_1 = P[find].jmlPenelitianBln[1] * gajiPenelitian;
						printf("\n\t> Gaji Penelitian    : %.2f", gaji_P_1);
						gaji_T_1 = P[find].gajiPokok + gaji_P_1;
						printf("\n\t> Total Gaji         : %.2f\n", gaji_T_1);
						
						printf("\n\tBulan ke-03");
						printf("\n\t> Jumlah Penelitian  : %d", P[find].jmlPenelitianBln[2]);
						gaji_P_2 = P[find].jmlPenelitianBln[2] * gajiPenelitian;
						printf("\n\t> Gaji Penelitian    : %.2f", gaji_P_2);
						gaji_T_2 = P[find].gajiPokok + gaji_P_2;
						printf("\n\t> Total Gaji         : %.2f\n", gaji_T_2);
						
						printf("\n\tBulan ke-04");
						printf("\n\t> Jumlah Penelitian  : %d", P[find].jmlPenelitianBln[3]);
						gaji_P_3 = P[find].jmlPenelitianBln[3] * gajiPenelitian;
						printf("\n\t> Gaji Penelitian    : %.2f", gaji_P_3);
						gaji_T_3 = P[find].gajiPokok + gaji_P_3;
						printf("\n\t> Total Gaji         : %.2f\n", gaji_T_3);
						
						printf("\n\tBulan ke-05");
						printf("\n\t> Jumlah Penelitian  : %d", P[find].jmlPenelitianBln[4]);
						gaji_P_4 = P[find].jmlPenelitianBln[4] * gajiPenelitian;
						printf("\n\t> Gaji Penelitian    : %.2f", gaji_P_4);
						gaji_T_4 = P[find].gajiPokok + gaji_P_4;
						printf("\n\t> Total Gaji         : %.2f\n", gaji_T_4);
						
						printf("\n\tBulan ke-06");
						printf("\n\t> Jumlah Penelitian  : %d", P[find].jmlPenelitianBln[5]);
						gaji_P_5 = P[find].jmlPenelitianBln[5] * gajiPenelitian;
						printf("\n\t> Gaji Penelitian    : %.2f", gaji_P_5);
						gaji_T_5 = P[find].gajiPokok + gaji_P_5;
						printf("\n\t> Total Gaji         : %.2f\n", gaji_T_5);
						
						printf("\n\tBulan ke-07");
						printf("\n\t> Jumlah Penelitian  : %d", P[find].jmlPenelitianBln[6]);
						gaji_P_6 = P[find].jmlPenelitianBln[6] * gajiPenelitian;
						printf("\n\t> Gaji Penelitian    : %.2f", gaji_P_6);
						gaji_T_6 = P[find].gajiPokok + gaji_P_6;
						printf("\n\t> Total Gaji         : %.2f\n", gaji_T_6);
						
						printf("\n\tBulan ke-08");
						printf("\n\t> Jumlah Penelitian  : %d", P[find].jmlPenelitianBln[7]);
						gaji_P_7 = P[find].jmlPenelitianBln[7] * gajiPenelitian;
						printf("\n\t> Gaji Penelitian    : %.2f", gaji_P_7);
						gaji_T_7 = P[find].gajiPokok + gaji_P_0;
						printf("\n\t> Total Gaji         : %.2f\n", gaji_T_7);
						
						printf("\n\tBulan ke-09");
						printf("\n\t> Jumlah Penelitian  : %d", P[find].jmlPenelitianBln[8]);
						gaji_P_8 = P[find].jmlPenelitianBln[8] * gajiPenelitian;
						printf("\n\t> Gaji Penelitian    : %.2f", gaji_P_8);
						gaji_T_8 = P[find].gajiPokok + gaji_P_8;
						printf("\n\t> Total Gaji         : %.2f\n", gaji_T_8);
						
						printf("\n\tBulan ke-10");
						printf("\n\t> Jumlah Penelitian  : %d", P[find].jmlPenelitianBln[9]);
						gaji_P_9 = P[find].jmlPenelitianBln[9] * gajiPenelitian;
						printf("\n\t> Gaji Penelitian    : %.2f", gaji_P_9);
						gaji_T_9 = P[find].gajiPokok + gaji_P_9;
						printf("\n\t> Total Gaji         : %.2f\n", gaji_T_9);
						
						printf("\n\tBulan ke-11");
						printf("\n\t> Jumlah Penelitian  : %d", P[find].jmlPenelitianBln[10]);
						gaji_P_10 = P[find].jmlPenelitianBln[10] * gajiPenelitian;
						printf("\n\t> Gaji Penelitian    : %.2f", gaji_P_10);
						gaji_T_10 = P[find].gajiPokok + gaji_P_0;
						printf("\n\t> Total Gaji         : %.2f\n", gaji_T_10);
						
						printf("\n\tBulan ke-12");
						printf("\n\t> Jumlah Penelitian  : %d", P[find].jmlPenelitianBln[11]);
						gaji_P_11 = P[find].jmlPenelitianBln[11] * gajiPenelitian;
						printf("\n\t> Gaji Penelitian    : %.2f", gaji_P_11);
						gaji_T_11 = P[find].gajiPokok + gaji_P_11;
						printf("\n\t> Total Gaji         : %.2f\n", gaji_T_11);
						
						gajiTotal = gaji_T_0 + gaji_T_1 + gaji_T_2 + gaji_T_3 + gaji_T_4 + gaji_T_5 + gaji_T_6 + gaji_T_7 + gaji_T_8 + gaji_T_9 + gaji_T_10 + gaji_T_11;
						printf("\n\t>>> Total Gaji 1 Tahun : %.2f", gajiTotal);
					}
                } else {
                    printf("\n\tData kosong [!]");
                }
				break;
				
			case 5:
				printf("\n\tMaintenance [!]");
				break;
				
			case 6:
				printf("\n\tMaintenance [!]");
				break;
				
			case 7:
				printf("\n\t--- Simulasi Perkembangan Bakteri ---");
				printf("\n\tJumlah Bakteri Awal : ");
				break;
				
			case 0:
				printf("\n\tAlexis Divasonda Sigat Ngaing - 210711407 - A");
				printf("\n\tExit...");
				printf("\n\n\t\tSemoga harimu menyenangkan :)");
				break;
				
			default:
				printf("\n\tMenu invalid [!]");
				break;
		} getch();
	} while (menu != 0);
	
	return 0;
}
