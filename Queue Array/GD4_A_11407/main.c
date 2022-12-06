#include "header.h"

int main(int argc, char *argv[]) {
	Queue Q;
	int menu, index;
	Data temp;
	
	createEmpty(&Q);
	
	do {
		system("cls");
		printf("\n[1] Enqueue / Tambah Data");
		printf("\n[2] Dequeue / Hapus Data");
		printf("\n[3] Show");
		printf("\n[4] Cari Data");
		printf("\n[0] Keluar");	
		printf("\n>>> "); scanf("%d", &menu);
		
		switch(menu) {
			case 1 :
				if(!isFull(Q)) {
					printf("\n\tInput Data");
					printf("\n\nNama   : "); fflush(stdin); gets(temp.nama);
					printf("NPM    : "); fflush(stdin); gets(temp.npm);
					printf("IPK    : "); scanf("%f", &temp.ipk);
					
					Enqueue(&Q, makeData(temp.nama, temp.npm, temp.ipk));
				} else {
					printf("\n\t[!] Queue sudah penuh");
				}
			break;
			
			case 2 :
				if(!isEmpty(Q)) {
					Dequeue(&Q);
				} else {
					printf("\n\t[!] Queue masih kosong");
				}
			break;
			
			case 3 :
				if(!isEmpty(Q)) {
					print(Q);
				} else {
					printf("\n\t[!] Queue masih kosong");
				}
			break;
			
			case 4 :
				if(!isEmpty(Q)) {
					printf("\n\tPencarian Data");
					printf("\n\nMasukkan NPM yang ingin dicari : "); fflush(stdin); gets(temp.npm);
					index = isFound(Q, temp.npm);
					
					if(index!=-1) {
						printf("\n\tData yang ditemukan");
						printf("\n\t\tNama : %s", Q.D[index].nama);
						printf("\n\t\tNPM  : %s", Q.D[index].npm);
						printf("\n\t\tIPK  : %.2f", Q.D[index].ipk);
					} else {
						printf("\n\t[!] Data yang dicari tidak ditemukan");
					}
				} else {
					printf("\n\t[!] Queue masih kosong");
				}
			break;
			
			case 0 :
				printf("\n\n\tCODING ITU MENYENANGKAN :')");
			break;
			
			default :
				printf("\n\t[!] Menu tidak tersedia");
			break;
		} getch();
	} while(menu!=0);
	return 0;
}
