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

void printPenelitian(Peneliti P[], int index, int value) {
	if (value < MAX) {
		printf("%d ", P[index].jmlPenelitianBln[value]);
		printPenelitian(P, index, value + 1);
	}
}

void printAll(Peneliti P[], int index) {
	int n;
	
    if (strcmpi(P[index].nama, "") != 0) {
        printf("\n\t[%d] Nama Peneliti   : %s", index + 1, P[index].nama);
        printf("\n\t    Bidang Keahlian : %s", P[index].bidangKeahlian);
        printf("\n\t    Gaji Pokok      : %.2f", P[index].gajiPokok);
		printf("\n\t    Jumlah Penelitian Bulanan : ");
		printPenelitian(P, index, 0);
		printf("\n");
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

void inputPenelitian(Peneliti temp[], int index, int value) {
	if (value < MAX) {
		printf("\tBulan ke-%d : ", value + 1); scanf("%d", &temp[index].jmlPenelitianBln[value]);
		inputPenelitian(temp, index, value + 1);
	}
	if (value == MAX) {
		
	}
}

void edit(Peneliti temp[], Peneliti temp_two, int index) {
	if (strcmpi(temp[index].nama, temp_two.nama) == 0) {
		inputPenelitian(temp, index, 0);
	}
	if (index <= MAX_P - 1) {
		edit(temp, temp_two, index + 1);
	}
}

//int maximum(Peneliti P[], int index, int value) {
//    int max;
//
//    if (index >= value-2) {
//        if (P[index] > P[index + 1]) 
//            return P[index];
//        else
//            return P[index + 1];
//    }
//
//    max = maximum(P, index + 1, value);
//
//    if (P[index] > max)
//        return P[index];
//    else
//        return max;
//}
//
//int minimum(Peneliti P[], int index, int value) {
//    int min;
//
//    if (index >= value-2) {
//        if (P[index] < P[index + 1])
//            return P[index];
//        else
//            return P[index + 1];
//    }
//
//    min = minimum(P, index + 1, value);
//
//    if (P[index] < min)
//        return P[index];
//    else
//        return min;
//}

//void statistik
//void sorting
