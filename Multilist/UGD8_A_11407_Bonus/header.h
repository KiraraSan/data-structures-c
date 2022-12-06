#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[50];

typedef struct Child* AddressChild;
typedef struct Parent* AddressParent;

typedef struct DataChild {
    string noPlat;
    string merek;
    float bensin;
} DataChild;

typedef struct DataParent {
    int id;
    string ruangan;
    bool status;
} DataParent;

typedef struct Child {
    DataChild data;
    AddressChild next;
} NodeChild;

typedef struct Parent {
    DataParent data;
    AddressParent next;

    AddressChild firstChild;
} NodeParent;

typedef struct {
    AddressParent firstParent;
} Multilist;

void createEmpty(Multilist* l);
void insertFirstParent(Multilist* l, DataParent data);
void insertAfterParent(Multilist* l, int idParent, DataParent data);
void insertLastParent(Multilist* l, DataParent data);

void deleteFirstParent(Multilist* l);
void deleteAtParent(Multilist* l, int idParent);
void deleteLastParent(Multilist* l);

void deleteAllChild(AddressParent parent);

void printParent(AddressParent parent);
void printAll(Multilist l);
void printAllParent(Multilist l);

AddressParent alokasiParent(DataParent data);
AddressParent findParent(Multilist l, int idParent);
AddressParent findParentRuangan(Multilist l, string ruangan);
AddressChild alokasiChild(DataChild data);

bool isEmpty(Multilist l);
bool haveChild(AddressParent parent);

void insertFirstChild(Multilist l, int idParent, DataChild data);
void insertLastChild(Multilist l, int idParent, DataChild data);

void deleteFirstChild(Multilist l, int idParent);
void deleteLastChild(Multilist l, int idParent);

void printChild(AddressChild child);
void printAllChild(AddressParent parent);

DataParent makeDataParent(int id, string ruangan, bool status, int temp);
DataChild makeDataChild(string noPlat, string merek, float bensin);

bool isParentUnik(Multilist l, int id);
bool isChildUnik(Multilist l, string noPlat);
void distribusi(Multilist* l);
