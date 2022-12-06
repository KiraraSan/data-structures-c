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

addr findNode(List L, int data) {
    if (isEmpty(L)) {
        return NULL;
    } else {
        if (L->data != data) {
            return findNode(L->next, data);
        }
        return L;
    }
}

addr alokasi(int data) {
    addr N = (Node *)malloc(sizeof(Node));

    N->next = NULL;
    N->data = data;

    return N;
}

void insertFirst(List *L, addr newNode) {
    newNode->next = (*L);
    (*L) = newNode;
}

void insertAfter(List *L, addr newNode, int prevData) {
    addr prevNode = findNode(*L, prevData);

    if (prevNode != NULL) {
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    } else {
        printf("\ndata tidak ada");
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
    if (!isEmpty(L)) {
        printf("\n%d", L->data);
        printAll(L->next);
    }
}

