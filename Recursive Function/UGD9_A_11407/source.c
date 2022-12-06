#include "header.h"

void inisialisasi(Peneliti P[], int index) {
    strcpy(P[index].nama, "");
    strcpy(P[index].bidangKeahlian, "");
	P[index].gajiPokok = 0.0;
	if (MAX < 0) {
	} else {
		P[index].jmlPenelitianBln[MAX] = 0;	
		MAX - 1;
	}
    if (index >= MAX_P - 1) {
    } else {
        inisialisasi(P, index + 1);
    }
}


int getEmptyIndex(Peneliti P[], int index) {
    if (strcmpi(P[index].nama, "") == 0) {
        return index;
    }
    if (index >= MAX_P - 1) {
        return -1;
    } else {
        return getEmptyIndex(P, index + 1);
    }
}

void printAll(Peneliti P[], int index) {
	int n;
	
    if (strcmpi(P[index].nama, "") != 0) {
        printf("\n\t[%d] Nama Peneliti  : %s", index + 1, P[index].nama);
        printf("\n\t    Bidang Keahlian : %s", P[index].bidangKeahlian);
        printf("\n\t    Gaji Pokok      : %.2f", P[index].gajiPokok);
        printf("\n\t    Jumlah Penelitian Bulanan : %d %d %d %d %d %d %d %d %d %d %d %d", 
		P[index].jmlPenelitianBln[0], P[index].jmlPenelitianBln[1], P[index].jmlPenelitianBln[2], P[index].jmlPenelitianBln[3], P[index].jmlPenelitianBln[4],
		P[index].jmlPenelitianBln[5], P[index].jmlPenelitianBln[6], P[index].jmlPenelitianBln[7], P[index].jmlPenelitianBln[8], P[index].jmlPenelitianBln[9],
		P[index].jmlPenelitianBln[10], P[index].jmlPenelitianBln[11]);
    }
    if (index >= MAX_P - 1) {
    } else {
        printAll(P, index + 1);
    }
}

int isEmpty(Peneliti P[], int index) {
    if (strcmpi(P[index].nama, "") != 0) {
        return 0;
    }
    if (index >= MAX_P - 1) {
        return 1;
    } else {
        return isEmpty(P, index + 1);
    }
}

int isPenelitiUnik(Peneliti P[], int index, string nama) {
    
    if (strcmpi(P[index].nama, "") != 0) {
    	if (strcmpi(P[index].nama, nama) == 0) {
    		return -1;
		}
	}	
	if (index >= MAX_P - 1) {
        return 1;
    } else {
        return isPenelitiUnik(P, index + 1, nama);
    }
}

int cariPeneliti(Peneliti P[], int index, string nama) {
    if (index < 0) {
        return index;
    } else {
        if (strcmpi(P[index].nama, nama) == 0) {
        	return index;
		}
        cariPeneliti(P, index - 1, nama);
    }
}
