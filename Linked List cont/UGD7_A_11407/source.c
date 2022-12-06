#include "header.h"

void createEmpty(List *L) {
    L->first = NULL;
}

bool isEmpty(List L) {
    return L.first == NULL;
}

bool isOneElement(List L) {
    return !isEmpty(L) && L.first->next == NULL;
}

address alokasiData(Data D) {
    address P;
    
	P = (Node *)malloc(sizeof(Node));
    P->data = D;
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
    if (isEmpty(*L)) {
        insertFirst(L, newNode);
    } else {
        for (P = L->first; P->next != NULL; P = P->next);
        P->next = newNode;
    }
}

void deleteFirst(List *L) {
    if (!isEmpty(*L)) {
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
	int no = 1;
	
    for (P = L.first; P != NULL; P = P->next) {
        printf("[%d] %s        : %d - Rp %d\n", no, P->data.name, P->data.quantity, P->data.total);
        no++;
    }
}

void sortName(List *L) {
    address P, Pp;
    for (P = L->first; P != NULL; P = P->next) {
        for (Pp = L->first; Pp->next != NULL; Pp = Pp->next) {
            if (Pp->data.name > Pp->next->data.name) {
                Data p = Pp->data;
                Pp->data = Pp->next->data;
                Pp->next->data = p;
            }
        }
    }
}

void sortTotal(List *L) {
    address P, Pp;
    for (P = L->first; P != NULL; P = P->next) {
        for (Pp = L->first; Pp->next != NULL; Pp = Pp->next) {
            if (Pp->data.total > Pp->next->data.total) {
                Data p = Pp->data;
                Pp->data = Pp->next->data;
                Pp->next->data = p;
            }
        }
    }
}
