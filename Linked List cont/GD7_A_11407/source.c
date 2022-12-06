#include "header.h"

void createEmpty(List *L) {
    (*L).first = NULL;
}

bool isEmpty(List L) {
    return L.first == NULL;
}

bool isOneElement(List L) {
    return !isEmpty(L) && L.first->next == NULL;
}

address alokasi(infotype X) {
    address P;

    P = (node*)malloc(sizeof(node));
    P->data = X;
    P->next = NULL;

    return P;
}

void insertFirst(List *L, address newNode) {
    newNode->next = (*L).first;
    (*L).first = newNode;
}

void insertAfter(address before, address newNode) {
    if (before != NULL) {
        newNode->next = before->next;
        before->next = newNode;
    }
}

void insertLast(List *L, address newNode) {
    address P;

    if (isEmpty((*L))) {
        insertFirst(L, newNode);
    } else {
    	for(P = (*L).first; P->next != NULL; P->next);
    	P->next = newNode;
	}
}

void deleteFirst(List *L) {
    if (!isEmpty((*L))) {
        address del = (*L).first;
        (*L).first = (*L).first->next;
        free(del);
    }
}

void deleteAt(List *L, address del) {
    address P;

    if (!isEmpty((*L))) {
        if ((*L).first == del) {
            deleteFirst(L);
        } else {
            P = (*L).first;
            while (P->next != del) {
                P = P->next;
            }
            P->next = del->next;
            free(del);
        }
    }
}

void deleteLast(List *L) {
    address P;

    if (!isEmpty((*L))) {
        if (isOneElement(*L)) {
            deleteFirst(L);
        } else {
            for (P = (*L).first; P->next->next != NULL; P = P->next);
            free(P->next);
            P->next = NULL;
        }
    }
}

void printData(List L) {
    address P;

    printf("\n\t");
    for (P = L.first; P != NULL; P = P->next) {
        printf("%d ,", P->data);
    }
}

address findNode(List L, infotype X) {
    address P;

    for (P = L.first; P != NULL && P->data != X; P = P->next);
    return P;
}

