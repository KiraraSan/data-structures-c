#include <stdio.h>
#include <stdlib.h>

typedef struct node *addr;
typedef struct node *List;

typedef struct node {
    int data;
    addr next;
} Node;

void createEmpty(List *L);
int isOneElm(List L);
int isEmpty(List L);
addr findNode(List L, int data);
addr alokasi(int data);
void insertFirst(List *L, addr newNode);
void insertAfter(List *L, addr newNode, int prevData);
void insertLast(List *L, addr newNode);
void deleteFirst(List *L);
void deleteAt(List *L, addr delNode);
void deleteLast(List *L);
void printAll(List L);

