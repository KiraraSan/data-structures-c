#include "header.h"

AddressChild alokasiChild(DataChild data) {
    AddressChild ac;
    ac = (AddressChild)malloc(sizeof(NodeChild));

    ac->next = NULL;
    ac->dataChild = data;

    return ac;
}

void insertFirstChild(Multilist l, int idParent, DataChild data) {
    AddressParent parent = findParent(l, idParent);

    if (parent != NULL) {
        AddressChild dataBaru = alokasiChild(data);
        dataBaru->next = parent->firstChild;

        parent->firstChild = dataBaru;
    }
}

void insertLastChild(Multilist l, int idParent, DataChild data) {
    AddressParent parent = findParent(l, idParent);

    if (parent != NULL) {
        if (!haveChild(parent)) {
            insertFirstChild(l, idParent, data);
        } else {
            AddressChild temp = parent->firstChild;
            AddressChild dataBaru = alokasiChild(data);

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = dataBaru;
        }
    }
}

void deleteFirstChild(Multilist l, int idParent) {
    AddressParent parent = findParent(l, idParent);

    if (parent != NULL) {
        if (haveChild(parent)) {
            AddressChild temp = parent->firstChild;
            parent->firstChild = parent->firstChild->next;

            free(temp);
        }
    }
}

void deleteLastChild(Multilist l, int idParent) {
    AddressParent parent = findParent(l, idParent);

    if (parent != NULL) {
        if (haveChild(parent)) {
            if (parent->firstChild->next == NULL) {
                deleteFirstChild(l, idParent);
            } else {
                AddressChild temp = parent->firstChild;

                while (temp->next->next != NULL) {
                    temp = temp->next;
                }

                free(temp->next);
                temp->next = NULL;
            }
        }
    }
}

void printChild(AddressChild child) {
    printf("\n\n\t\t=== Child ===");
    printf("\n\t\t[*] Nama : %s", child->dataChild.nama);
    printf("\n\t\t[*] Umur : %d", child->dataChild.umur);
}

void printAllChild(AddressParent parent) {
    AddressChild temp = parent->firstChild;

    while (temp != NULL) {
        printChild(temp);

        temp = temp->next;
    }
}

