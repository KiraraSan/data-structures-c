#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

typedef int infotype;
typedef struct node *address;

typedef struct node {
    infotype data;
    address next;
} node;

typedef struct {
    address first;
} List;

void createEmpty(List *L);
bool isEmpty(List L);
bool isOneElement(List L);
address alokasi(infotype X);
void insertFirst(List *L, address newNode);
void insertAfter(address before, address newNode);
void insertLast(List *L, address newNode);
void deleteFirst(List *L);
void deleteAt(List *L, address del);
void deleteLast(List *L);
void printData(List L);
address findNode(List L, infotype x);

