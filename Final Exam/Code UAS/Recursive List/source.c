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

addr FindMaxNode(List L) {
	if (isOneElm(L)) {
		return L->data;
	} else {
		addr temp = FindMaxNode(L->next);
		if (temp > L->data) {
			return temp;
		} else {
			return L->data;
		}
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

int CacahNodeAntara(List L, int nilai1, int nilai2) {
	if (isEmpty(L)) {
		return 0;
	} else {
		if (L->data < nilai2 && L->data > nilai1) {
			return 1 + CacahNodeAntara(L->next, nilai1, nilai2);
		} else {
			return CacahNodeAntara(L->next, nilai1, nilai2);
		}
	}
}

//int findNumber(List L) {
//	if (isOneElm(L)) {
//		return L->data;
//	} else {
//		if (L->data > findNumber(L->next))
//			return L->data;
//		else 
//			return (findNumber(L->next));
//	}
//}

//int findNumber(List L) {
//	if (isOneElm(L)) {
//		return L->data;
//	} else {
//		if (L->data < findNumber(L->next))
//			return L->data;
//		else 
//			return (findNumber(L->next));
//	}
//}


//A
//int findNumber(List L, int cari) {
//	if (isEmpty(L)) 
//		return 0;
//	else {
//		if (L->data == cari)
//			return L;
//		else
//			return findNumber(L->next, cari);
//	}
//}

//B
//int findNumber(List L, int cari) {
//	if (isEmpty(L)) 
//		return NULL;
//	else {
//		if (L->data == cari)
//			return L;
//		else
//			return findNumber(L->next, cari);
//	}
//}

//C
//int findNumber(List L, int cari) {
//	if (isEmpty(L)) 
//		return 0;
//	else {
//		if (L->data == cari)
//			return findNumber(L->next, cari);
//		else
//			return 1;
//	}
//}

//D
int findNumber(List L, int cari) {
	if (isEmpty(L)) 
		return 0;
	else {
		if (L->data == cari)
			return 1;
		else
			return findNumber(L->next, cari);
	}
}
