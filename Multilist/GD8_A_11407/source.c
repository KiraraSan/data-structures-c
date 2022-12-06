#include "header.h"

DataParent makeDataParent(int id, string namaTim) {
    DataParent data;

    data.idTim = id;
    strcpy(data.namaTim, namaTim);

    return data;
}

DataChild makeDataChild(string nama, int umur) {
    DataChild data;

    data.umur = umur;
    strcpy(data.nama, nama);

    return data;
}

bool isUnik(Multilist l, int id) {
    AddressParent temp = l.firstParent;

    while (temp != NULL) {
        if (temp->dataParent.idTim == id) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

