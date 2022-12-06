#include "header.h"

Peserta makePeserta(int id, string no_urut, string nama, string daftar, string gender, string status) {
	Peserta p;
	
    p.id = id;
    strcpy(p.no_urut, no_urut);
    strcpy(p.nama, nama);
    strcpy(p.daftar, daftar);
    strcpy(p.gender, gender);
    strcpy(p.status, status);

    return p;
}

void inisialisasi(Peserta peserta[]) {
    int i, id = 1;
    Peserta *pPeserta;

    pPeserta = peserta;

    for(i=0; i<dataMAX; i++) {
        *pPeserta = makePeserta(id, "-", "-", "-", "?", "-");

        id++;
        pPeserta++;
    }
}

void print(Peserta peserta[]) {
    int i;
    Peserta *pPeserta;

    pPeserta = peserta;

    printf("\n\n\t");
    for (i=0; i<5; i++) {
        printf("[%d   | %s (%s)]\t", pPeserta->id, pPeserta->no_urut, pPeserta->gender);
        pPeserta++;
    }
    printf("\n\n\t");
    for (i=5; i<10; i++) {
        printf("[%d   | %s (%s)]\t", pPeserta->id, pPeserta->no_urut, pPeserta->gender);
        pPeserta++;
	}
	printf("\n\n\t");
	for (i=10; i<15; i++) {
        printf("[%d  | %s (%s)]\t", pPeserta->id, pPeserta->no_urut, pPeserta->gender);
        pPeserta++;
	}
	printf("\n\n\t");
	for (i=15; i<20; i++) {
        printf("[%d  | %s (%s)]\t", pPeserta->id, pPeserta->no_urut, pPeserta->gender);
        pPeserta++;
	}
}

void input(Peserta *ptrDisplay) {
    while (true) {
    	printf("\n\tMasukkan No Urut : "); fflush(stdin); gets(ptrDisplay->no_urut);
    	if(strlen(ptrDisplay->no_urut)==0 || strcmpi(ptrDisplay->no_urut, "-")==0) {
    		printf("\n\t\t[!] No urut harus diisi [!]");
		} else if(strlen(ptrDisplay->no_urut)<4) {
			printf("\n\t\tNo urut harus 4 digit [!]");
		} else {
			break;
		}
	}
	while(true) {	
        printf("\n\tMasukkan Nama    : "); fflush(stdin); gets(ptrDisplay->nama);
        if(strlen(ptrDisplay->nama)==0 || strcmpi(ptrDisplay->nama, "-")==0) {
            printf("\n\t\tNama harus diisi [!]");
        } else {
            break;
        }
    }
    while(true) {    
        printf("\n\tMasukkan Tanggal Daftar : "); fflush(stdin); gets(ptrDisplay->daftar);
        if(strlen(ptrDisplay->daftar)==0 || strcmpi(ptrDisplay->daftar, "-")==0) {
            printf("\n\t\tTanggal harus diisi [!]");
        } else {
            break;
        }
	}
	while(true) {
        printf("\n\tMasukkan Jenis Kelamin  : "); fflush(stdin); gets(ptrDisplay->gender);
        if(strcmpi(ptrDisplay->gender, "L")!=0 && strcmpi(ptrDisplay->gender, "P")!=0) {
            printf("\n\t\tJenis kelamin invalid (only: L & P) [!]");
        } else {
            break;
        }
    }
    while(true) {    
        printf("\n\tMasukkan Status  : "); fflush(stdin); gets(ptrDisplay->status);
        if(strlen(ptrDisplay->status)==0 || strcmpi(ptrDisplay->status, "-")==0) {
            printf("\n\t\tStatus harus diisi [!]");
        } else {
            break;
        }
	}
}

Peserta* cariID(Peserta *ptrDisplay, Peserta peserta[], int id) {
    int i, j;
    Peserta p = makePeserta(0, "-", "-", "-", "?", "-");
    Peserta *ptrCopy, *temp;

    ptrCopy = peserta;
    temp = &p;

    for (i=0; i<dataMAX; i++) {
        if (ptrCopy->id == id) {
            return ptrCopy;
        } else if (ptrDisplay->id == id) {
            return ptrDisplay;
        }
        ptrCopy++;
    }
    return temp;
}
