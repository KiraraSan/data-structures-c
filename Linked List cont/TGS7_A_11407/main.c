#include "header.h"

int main() {
    List L;
    address P, Pp, before;
	Data D;
	
    char menu;
    int number, no = 1, n = 1, menu_two, menu_three;

    createEmpty(&L);

    do {
        system("cls");
        printf("====== [ Mie Gacoan ] =======");
        printf("\n[1] Show All Order");
        printf("\n[2] Add Order");
        printf("\n[3] Delete Order");
        printf("\n[4] Sort Order");
        printf("\n[0] Exit");
        printf("\n>>> "); menu = getch();

        switch (menu) {
            case '1':
                printf("\n============= [ Mie Gacoan Orders ] =============\n");
				printData(L);
                break;

            case '2':
                printf("\n===== [ Input New Orders ] =====\n");
				no = 1;
				for (P = L.first; P != NULL; P = P->next) {
					printf("[%d] %s      : %d - Rp %d\n", no, P->data.name, P->data.quantity, P->data.total);
       				no++;
				}		
                printf("\nInput in number : "); scanf("%d", &number);
                if (!(number >= 1 && number <= no)) {
                	printf("\n\tNumber tidak tersedia [!]");
                	break;
				}
                if (number == 1) {
                	printf("\nNama Menu : "); fflush(stdin); gets(D.name);
                	printf("Jumlah    : "); scanf("%d", &D.quantity);
                	printf("Harga     : "); scanf("%d", &D.total);
                	P = alokasiData(D);
                	insertFirst(&L, P);
                	printf("\n\tBerhasil input...");
                	break;
				}
				if (number == no) {
                	printf("\nNama Menu : "); fflush(stdin); gets(D.name);
                	printf("Jumlah    : "); scanf("%d", &D.quantity);
                	printf("Harga     : "); scanf("%d", &D.total);
                	P = alokasiData(D);
                	insertLast(&L, P);
                	printf("\n\tBerhasil input...");
                	break;
				}
				n = 1;
				for (P = L.first; P != NULL; P = P->next){
					if (n == number) {
						break;	
					}
					n++;
				}
				printf("\nNama Menu : "); fflush(stdin); gets(D.name);
               	printf("Jumlah    : "); scanf("%d", &D.quantity);
                printf("Harga     : "); scanf("%d", &D.total);
                Pp = alokasiData(D);
                insertAfter(P, Pp);
                printf("\n\tBerhasil input...");
                break;

            case '3':
                printf("\n===== [ Delete Order ] =====");
                printf("\n[1] Delete All");
        		printf("\n[2] Delete Spesific Order");
        		printf("\n>>> "); scanf("%d", &menu_two);
        		
        		switch (menu_two) {
        			case 1:
						if (isEmpty(L)) {
		                    printf("\n\t[!] List kosong");
		                } else {
	        				while(!isEmpty(L)) {
	        					deleteLast(&L);
							}
						}
        				break;
        				
        			case 2:
						if (isEmpty(L)) {
		                    printf("\n\t[!] List kosong");
		                } else {
	        				no = 1;
							for (P = L.first; P != NULL; P = P->next) {
								printf("[%d] %s      : %d - Rp %d\n", no, P->data.name, P->data.quantity, P->data.total);
			       				no++;
							}
							printf("\nDelete order no : "); scanf("%d", &number);
	                		if (!(number >= 1 && number <= no)) {
	                			break;
							}
							n = 1;
							for (P = L.first; P != NULL; P = P->next) {
								if (n == number) {
									deleteAt(&L, P);
									printf("\n\tBerhasil hapus orderan [ %d ]...", number);
									break;
								}
								n++;
							}
						}
        				break;
        				
        			default:
        				printf("\n\t[!] Menu Invalid");
        				break;
				}
                break;

            case '4':
                if (isEmpty(L)) {
                    printf("\n\t[!] List kosong");
           		} else {
           			printf("\n[1] Name");
	        		printf("\n[2] Total");
					printf("\n[ESC] Back");	
	        		printf("\n>>> "); scanf("%d", &menu_three);
	        		
	        		switch (menu_three) {
	        			case 1:
							sortName(&L);
	        				break;
	        				
	        			case 2:
	        				sortTotal(&L);
	        				break;
	
	        			default:
	        				printf("\n\t[!] Menu invalid");
	        				break;
					} getch();
				}
                break;

            case '0':
            	printf("\n\tAlexis Divasonda Sigat Ngaing - 210711407");
            	printf("\n\tSemoga harimu menyenagkan :)");
                break;

            default:
                printf("\n\t[!] Menu Invalid");
                break;
                
        } getch();
    } while (menu != '0');

    return 0;
}
