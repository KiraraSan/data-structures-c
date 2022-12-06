#include "header.h"

void createEmpty(Multilist *l) {
    l->firstParent = NULL;
}

bool isEmpty(Multilist l) {
    return l.firstParent == NULL;
}

bool haveChild(AddressParent ap) {
    return ap->firstChild != NULL;
}

AddressParent alokasiParent(DataParent data) {
    AddressParent ap;

    ap = (AddressParent)malloc(sizeof(NodeParent));

    ap->next = NULL;
    ap->firstChild = NULL;
    ap->dataParent = data;

    return ap;
}

AddressParent findParent(Multilist l, int cariId) {
    AddressParent parentBantu = NULL;

    parentBantu = l.firstParent;

    while (parentBantu != NULL) {
        if (parentBantu->dataParent.idTim == cariId) {
            return parentBantu;
        }

        parentBantu = parentBantu->next;
    }

    return NULL;
}

void insertFirstParent(Multilist *l, DataParent data) {
    AddressParent dataParent = alokasiParent(data);

    dataParent->next = l->firstParent;
    l->firstParent = dataParent;
}

// sebenarnya lebih tepat disebut insertAfter
void insertAtParent(Multilist *l, int idParent, DataParent data) {
    AddressParent dataBaru = alokasiParent(data);

    if (!isEmpty(*l)) {
        AddressParent temp = findParent(*l, idParent);

        if (temp != NULL) {
            dataBaru->next = temp->next;
            temp->next = dataBaru;
        }
    }
}

void insertLastParent(Multilist *l, DataParent data) {
    AddressParent dataParent = alokasiParent(data);

    if (isEmpty(*l)) {
        insertFirstParent(l, data);
    } else {
        AddressParent temp = l->firstParent;

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = dataParent;
    }
}

void deleteFirstParent(Multilist *l) {
    AddressParent temp = l->firstParent;

    if (!isEmpty(*l)) {
        deleteAllChild(temp);

        l->firstParent = l->firstParent->next;
        free(temp);
    }
}

void deleteAtParent(Multilist *l, int idParent) {
    AddressParent temp = l->firstParent;
    AddressParent hapus;

    if (!isEmpty(*l)) {
        if (temp->dataParent.idTim == idParent) {
            deleteFirstParent(l);
        } else {
            while (temp->next != NULL) {
                if (temp->next->dataParent.idTim == idParent) {
                    hapus = temp->next;
                    temp->next = temp->next->next;

                    deleteAllChild(hapus);
                    free(hapus);
                    break;
                }

                temp = temp->next;
            }
        }
    }
}

void deleteLastParent(Multilist *l) {
    AddressParent temp = l->firstParent;

    if (!isEmpty(*l)) {
        if (temp->next == NULL) {
            deleteFirstParent(l);
        } else {
            while (temp->next->next != NULL) {
                temp = temp->next;
            }

            deleteAllChild(temp->next);
            free(temp->next);

            temp->next = NULL;
        }
    }
}

void deleteAllChild(AddressParent parent) {
    AddressChild temp;

    while (haveChild(parent)) {
        temp = parent->firstChild;
        parent->firstChild = parent->firstChild->next;

        free(temp);
    }
}

void printParent(AddressParent parent) {
    printf("\n\t=== Parent ===");
    printf("\n\t[-] Id Tim : %d", parent->dataParent.idTim);
    printf("\n\t[-] Nama Tim : %s", parent->dataParent.namaTim);
}

void printAllParent(Multilist l) {
    AddressParent temp = l.firstParent;

    while (temp != NULL) {
        printParent(temp);

        printf("\n");
        temp = temp->next;
    }
}

void printAll(Multilist l) {
    AddressParent temp = l.firstParent;

    while (temp != NULL) {
        printParent(temp);

        printAllChild(temp);
        printf("\n");

        temp = temp->next;
    }
}

