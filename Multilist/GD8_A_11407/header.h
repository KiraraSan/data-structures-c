#ifndef NORMAL_HEADER
#define NORMAL_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char string[50];
typedef struct Child *AddressChild;
typedef struct Parent *AddressParent;

// data parent dan data child
typedef struct DataChild {
    string nama;
    int umur;

} DataChild;

typedef struct DataParent {
    int idTim;
    string namaTim;

} DataParent;

typedef struct Child {
    DataChild dataChild;
    AddressChild next;

} NodeChild;

typedef struct Parent {
    DataParent dataParent;
    AddressParent next;

    AddressChild firstChild;

} NodeParent;

typedef struct {
    AddressParent firstParent;

} Multilist;

// sourceParent;
void createEmpty(Multilist *l);
void insertFirstParent(Multilist *l, DataParent data);
void insertAtParent(Multilist *l, int idParent, DataParent data);
void insertLastParent(Multilist *l, DataParent data);

void deleteFirstParent(Multilist *l);
void deleteAtParent(Multilist *l, int idParent);
void deleteLastParent(Multilist *l);

void deleteAllChild(AddressParent parent);

void printParent(AddressParent parent);
void printAll(Multilist l);
void printAllParent(Multilist l);

AddressParent alokasiParent(DataParent data);
AddressParent findParent(Multilist l, int cariId);

bool isEmpty(Multilist l);
bool haveChild(AddressParent ap);

// sourceChild;
AddressChild alokasiChild(DataChild data);

void insertFirstChild(Multilist l, int idParent, DataChild data);
void insertLastChild(Multilist l, int idParent, DataChild data);

void deleteFirstChild(Multilist l, int idParent);
void deleteLastChild(Multilist l, int idParent);

void printChild(AddressChild child);
void printAllChild(AddressParent parent);

// Umum
DataParent makeDataParent(int id, string namaTim);
DataChild makeDataChild(string nama, int umur);
bool isUnik(Multilist l, int id);

#endif

