#include "header.h"

void createEmpty(List *L) {
    (*L) = NULL;
}

int isOneElm(List L) {
    return L->next == NULL;
}

int isEmpty(List L) {
    return L == NULL;
}

addr findNode(List L, int id) {
    if (isEmpty(L)) {
        return NULL;
    } else {
        if (L->data.id != id) {
            return findNode(L->next, id);
        }
        return L;
    }
}

addr findPeminjam(List L, string namaPeminjam) {
    if (isEmpty(L)) {
        return NULL;
    } else {
        if (strcmpi(L->data.namaPeminjam, namaPeminjam) != 0) {
            return findPeminjam(L->next, namaPeminjam);
        }
        return L;
    }
}

addr alokasi(Data data) {
    addr N = (Node *)malloc(sizeof(Node));

    N->next = NULL;
    N->data = data;

    return N;
}

void insertFirst(List *L, addr newNode) {
    newNode->next = (*L);
    (*L) = newNode;
}

void insertAfter(List *L, addr newNode, int id) {
    addr prevNode = findNode(*L, id);

    if (prevNode != NULL) {
        newNode->next = prevNode->next;
        prevNode->next = newNode;
        printf("\n\t\tData berhasil disimpan...");
    } else {
        printf("\n\t\tData tidak ada [!]");
    }
}

void insertLast(List *L, addr newNode) {
    if (isEmpty(*L)) {
        insertFirst(L, newNode);
    } else {
        insertLast(&(*L)->next, newNode);
    }
}

void deleteFirst(List *L) {
    addr del = (*L);
    (*L) = (*L)->next;
    free(del);
}

void deleteAt(List *L, addr delNode) {
    if ((*L) != delNode) {
        deleteAt(&(*L)->next, delNode);
    } else {
        deleteFirst(L);
    }
}

void deleteLast(List *L) {
    if (!isOneElm(*L)) {
        deleteLast(&(*L)->next);
    } else {
        deleteFirst(L);
    }
}

void printAll(List L) {
	int n;
    if (!isEmpty(L)) {
        printf("\nData ke-%d | ID-%d", n + 1, L->data.id);
        printf("\nJenis Motor    : %s", L->data.jenisMotor);
        printf("\nNama Peminjam  : %s", L->data.namaPeminjam);
        printf("\nTanggal Pinjam : %s", L->data.tanggalPinjam);
        printf("\nStatus         : %s", L->data.status);
        printf("\nHarga Pinjam   : Rp %.2f\n", L->data.hargaPinjam);
        printAll(L->next);
    }
}

void printRiwayat(List Lr, float pendapatan) {
	int n;
	printf("\nTotal Pendapatan : %.2f\n", pendapatan);
    if (!isEmpty(Lr)) {
        printf("\nData ke-%d | ID-%d", n + 1, Lr->data.id);
        printf("\nJenis Motor    : %s", Lr->data.jenisMotor);
        printf("\nNama Peminjam  : %s", Lr->data.namaPeminjam);
        printf("\nTanggal Pinjam : %s", Lr->data.tanggalPinjam);
        printf("\nStatus         : %s", Lr->data.status);
        printf("\nHarga Pinjam   : Rp %.2f", Lr->data.hargaPinjam);
        printRiwayat(Lr->next, pendapatan);
    }
}
