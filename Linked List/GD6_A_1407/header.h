#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char string[50];

typedef struct Node *address;

typedef struct {
    string nama;
    int NPP;
} Data;

typedef struct Node {
    Data D;
    address next;
} tNode;

typedef struct {
    address first;
} List;

void createEmpty(List *L);
bool isEmpty(List L);

address alokasiData(Data D);
Data makeData(string nama, int NPP);

void dealokasiData(address P);

void insertFirst(List *L, Data D);
void insertLast(List *L, Data D);

void deleteFirst(List *L);
void deleteLast(List *L);

void showList(List L);

