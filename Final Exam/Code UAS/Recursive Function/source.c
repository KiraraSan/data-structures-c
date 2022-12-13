#include "header.h"

void inisialisasi(Mahasiswa M[], int index) {
    M[index].no = 0;

    if (index >= MAX - 1) {
    } else {
        inisialisasi(M, index + 1);
    }
}

int getEmptyIndex(Mahasiswa M[], int index) {
    if (M[index].no == 0) {
        return index;
    }
    if (index >= MAX - 1) {
        return -1;
    } else {
        return getEmptyIndex(M, index + 1);
    }
}

void printAll(Mahasiswa M[], int index) {
    if (M[index].no != 0) {
        printf("\n\t%d", M[index].no);
    }
    if (index >= MAX - 1) {
    } else {
        printAll(M, index + 1);
    }
}

void printAllDesc(Mahasiswa M[], int index) {
	if (index < 0) {
		return;
	} else {
		printf("\n\t%d", M[index].no);
		printAllDesc(M, index - 1);
	}
}

int isEmpty(Mahasiswa M[], int index) {
    if (M[index].no != 0) {
        return 0;
    }
    if (index >= MAX - 1) {
        return 1;
    } else {
        return isEmpty(M, index + 1);
    }
}

