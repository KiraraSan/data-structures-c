#include "header.h"

Data makeData(int id, string nama, string t) {
    Data d;

    d.id = id;
    strcpy(d.nama, nama);
    strcpy(d.tanggalTerbit, t);

    return d;
}

void initData(Data data[]) {
    int i, id = 1;
    Data *pData;

    pData = data;

    for (i = 0; i < DataMAX; i++) {
        *pData = makeData(id, "-", "-");

        id++;
        pData++;
    }
}

void tampilData(Data data[]) {
    int i;
    Data *pData;

    pData = data;

    printf("\n\t");
    for (i = 0; i < DataMAX; i++) {
        printf("[%d | %s] ", pData->id, pData->nama);
        pData++;
    }
}

void inputan(Data *ptrDisplay) {
    while (true) {
        printf("\n\tMasukkan Nama : "); fflush(stdin); gets(ptrDisplay->nama);
        if (strlen(ptrDisplay->nama) == 0 || strcmpi(ptrDisplay->nama, "-") == 0) {
            printf("\n\t\t[!] Nama harus diisi [!]");
        } else {
            break;
        }
    }
    while (true) {
        printf("\n\tMasukkan Tanggal Lahir : "); fflush(stdin); gets(ptrDisplay->tanggalTerbit);
        if (strlen(ptrDisplay->tanggalTerbit) == 0 || strcmpi(ptrDisplay->tanggalTerbit, "-") == 0) {
            printf("\n\t\t[!] Tanggal lahir harus diisi [!]");
        } else {
            break;
        }
    }
}

Data* cariBerdasarID(Data *ptrDisplay, Data data[], int id) {
    int i, j;
    Data d = makeData(0, "-", "-");
    Data *ptrCopy, *temp;

    ptrCopy = data;
    temp = &d;

    for (i = 0; i < DataMAX; i++) {
        if (ptrCopy->id == id) {
            return ptrCopy;
        } else if (ptrDisplay->id == id) {
            return ptrDisplay;
        }
        ptrCopy++;
    }
    return temp;
}
