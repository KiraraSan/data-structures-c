#include "header.h"

void createEmpty(List *L) {
    L->first = NULL;
}

bool isEmpty(List L) {
    return L.first == NULL;
}

address alokasiData(Perabotan P) {
    address p;

    p = (tNode *)malloc(sizeof(tNode));
    p->P = P;
    p->next = NULL;

    return p;
}

Perabotan makePerabot(string namaBarang, string bahanBarang, string merk, int harga) {
    Perabotan temp;

    strcpy(temp.namaBarang, namaBarang);
    strcpy(temp.bahanBarang, bahanBarang);
    strcpy(temp.merk, merk);
    temp.harga = harga;

    return temp;
}

void dealokasiData(address Pd) {
    free(Pd);
}

void insertFirst(List *L, Perabotan P) {
    address Pd;

    Pd = alokasiData(P);
    Pd->next = L->first;
    L->first = Pd;

    printf("\n\tInsert first...");
}

void insertLast(List *L, Perabotan P) {
    address Pd, last;

    if (isEmpty(*L)) {
        insertFirst(&(*L), P);
    } else {
        last = L->first;
        Pd = alokasiData(P);

        while (last->next != NULL) {
            last = last->next;
        }

        last->next = Pd;
        printf("\n\tInsert last...");
    }
}

void insertRiwayat(List_riwayat *Lr, Perabotan P) {
	address Pr;

    Pr = alokasiData(P);
    Pr->next = Lr->first_two;
    Lr->first_two = Pr;

    printf("\n\tInsert first...");
}

void deleteFirst(List *L) {
    address hapus;

    if (isEmpty(*L)) {
        printf("\n\tList kosong [!]");
    } else {
        hapus = L->first;
        L->first = L->first->next;
        free(hapus);
    }
}

void deleteLast(List *L) {
    address last, hapus;
    if (isEmpty(*L)) {
        printf("\n\tList kosong [!]");
    } else {
        if (L->first->next == NULL) {
            deleteFirst(&(*L));
        } else {
            last = L->first;

            while (last->next->next != NULL) {
                last = last->next;
            }

            hapus = last->next;
            last->next = NULL;
            free(hapus);
        }
    }
}

void print(List L) {
    address Pd;

    if (isEmpty(L)) {
        printf("\nList empty [!]");
    } else {
        Pd = L.first;

        while (Pd != NULL) {
            printf("\nNama  : %s", Pd->P.namaBarang);
            printf("\nBahan : %s", Pd->P.bahanBarang);
            printf("\nMerk  : %s", Pd->P.merk);
            printf("\nHarga : %d", Pd->P.harga);
            printf("\n---------------------------------\n");
            Pd = Pd->next;
        }
    }
}

void printRiwayat(List_riwayat Lr) {
    address Pr;

    Pr = Lr.first_two;

    while (Pr != NULL) {
        printf("\nNama  : %s", Pr->P.namaBarang);
        printf("\nBahan : %s", Pr->P.bahanBarang);
        printf("\nMerk  : %s", Pr->P.merk);
        printf("\nHarga : %d", Pr->P.harga);
        printf("\n---------------------------------\n");
        Pr = Pr->next;
    }
}

int cari(List L, string namaBarang) {
    address Pd;

    if (isEmpty(L)) {
        printf("\nList empty [!]");
    } else {
        Pd = L.first;

        while (Pd != NULL) {
            if(strcmpi(Pd->P.namaBarang, namaBarang)==0) {
			
			return Pd;
			}
			Pd = Pd->next;    
        }
        return -1;
    }
}

