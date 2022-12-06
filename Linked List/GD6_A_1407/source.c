#include "header.h"

void createEmpty(List *L) {
    L->first = NULL;
}

bool isEmpty(List L) {
    return L.first == NULL;
}

address alokasiData(Data D) {
    address p;

    p = (tNode *)malloc(sizeof(tNode));
    p->D = D;
    p->next = NULL;

    return p;
}

Data makeData(string nama, int NPP) {
    Data temp;

    strcpy(temp.nama, nama);
    temp.NPP = NPP;

    return temp;
}

void dealokasiData(address P) {
    free(P);
}

void insertFirst(List *L, Data D) {
    address P;

    P = alokasiData(D);
    P->next = L->first;
    L->first = P;

    printf("\nInsert first...");
}

void insertLast(List *L, Data D) {
    address P, last;

    if (isEmpty(*L)) {
        insertFirst(&(*L), D);
    } else {
        last = L->first;
        P = alokasiData(D);

        while (last->next != NULL) {
            last = last->next;
        }

        last->next = P;
        printf("\nInsert last...");
    }
}

void deleteFirst(List *L) {
    address hapus;

    if (isEmpty(*L)) {
        printf("\nList empty [!]");
    } else {
        hapus = L->first;
        L->first = L->first->next;
        free(hapus);
        printf("\nDelete...");
    }
}

void deleteLast(List *L) {
    address last, hapus;
    if (isEmpty(*L)) {
        printf("\nList empty [!]");
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

            printf("\nDelete...");
        }
    }
}

void showList(List L) {
    address P;

    if (isEmpty(L)) {
        printf("\nList empty [!]");
    } else {
        P = L.first;

        while (P != NULL) {
            printf("\nNama Dosen : %s", P->D.nama);
            printf("\nNPP        : %d\n", P->D.NPP);
            P = P->next;
        }
    }
}

