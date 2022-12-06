#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef char string[50];

typedef struct node *addr;
typedef struct node *List;

typedef struct {
	int hari;
	int bulan;
	string tahun;
} Date;

typedef struct Data {
	int id;
	string jenisMotor;
	string namaPeminjam;
	string tanggalPinjam;
	Date date;
	string status;
	float hargaPinjam;
} Data;

typedef struct node {
    Data data;
    addr next;
} Node;

void createEmpty(List *L);

int isOneElm(List L);
int isEmpty(List L);

addr findNode(List L, int id);
addr findPeminjam(List L, string namaPeminjam);
addr alokasi(Data data);

void insertFirst(List *L, addr newNode);
void insertAfter(List *L, addr newNode, int prevData);
void insertLast(List *L, addr newNode);

void deleteFirst(List *L);
void deleteAt(List *L, addr delNode);
void deleteLast(List *L);

void printAll(List L);
void printRiwayat(List Lr, float pendapatan);

