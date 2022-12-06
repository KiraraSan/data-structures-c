#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef char string[50];

typedef struct Data {
	string name;
	int quantity;
	int total;
} Data;

typedef struct Node *address;

typedef struct Node {
    Data data;
    address next;
} Node;

typedef struct List {
    address first;
} List;

void createEmpty(List *L);
bool isEmpty(List L);
bool isOneElement(List L);
address alokasiData(Data D);
void insertFirst(List *L, address newNode);
void insertAfter(address before, address newNode);
void insertLast(List *L, address newNode);
void deleteFirst(List *L);
void deleteAt(List *L, address del);
void deleteLast(List *L);
void printData(List L);
address findNode(List L, Data D);
void sortName(List *L);
void sortTotal(List *L);
