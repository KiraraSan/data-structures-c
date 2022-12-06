#include "header.h"

void inisialisasi(Mahasiswa M[], int index) {
    strcpy(M[index].nama, "");
    strcpy(M[index].npm, "");
    M[index].ipk = 0.0;

    if (index >= MAX - 1) {
    } else {
        inisialisasi(M, index + 1);
    }
}

int getEmptyIndex(Mahasiswa M[], int index) {
    if (strcmpi(M[index].npm, "") == 0) {
        return index;
    }
    if (index >= MAX - 1) {
        return -1;
    } else {
        return getEmptyIndex(M, index + 1);
    }
}

void printAll(Mahasiswa M[], int index) {
    if (strcmpi(M[index].npm, "") != 0) {
        printf("\n\tMahasiswa ke-%d", index + 1);
        printf("\n\tNama\t: %s", M[index].nama);
        printf("\n\tNPM\t: %s", M[index].npm);
        printf("\n\tIPK\t: %.2f\n", M[index].ipk);
    }
    if (index >= MAX - 1) {
    } else {
        printAll(M, index + 1);
    }
}

int isEmpty(Mahasiswa M[], int index) {
    if (strcmpi(M[index].npm, "") != 0) {
        return 0;
    }
    if (index >= MAX - 1) {
        return 1;
    } else {
        return isEmpty(M, index + 1);
    }
}

