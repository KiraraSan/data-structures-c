#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char string[50];

typedef struct Node *address;

typedef struct {
    string namaBarang;
    string bahanBarang;
    string merk;
    int harga;
} Perabotan;

typedef struct Node {
    Perabotan P;
    address next;
} tNode;

typedef struct {
    address first;
} List;

typedef struct {
    address first_two;
} List_riwayat;

void createEmpty(List *L);
bool isEmpty(List L);

address alokasiData(Perabotan P);
Perabotan makePerabot(string namaBarang, string bahanBarang, string merk, int harga);

void dealokasiData(address Pd);

void insertFirst(List *L, Perabotan P);
void insertLast(List *L, Perabotan P);

void deleteFirst(List *L);
void deleteLast(List *L);

void print(List L);

Perabotan *cari(List L, string namaBarang);

