#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 5

typedef char string[50];

typedef struct {
	int id;
	string nama;
	string jenis;
	float uang;
} Bengsin;

typedef struct {
	Bengsin B[max];
	int Head;
	int Tail;
} Queue;

Bengsin makeBengsin(int id, string nama, string jenis, float uang);
void createEmpty(Queue *Q);
int isEmpty(Queue Q);
int isFull(Queue Q);
int isOneElmt(Queue Q);
void Enqueue(Queue *Q, Bengsin B);
void Dequeue(Queue *Q);
void tampil(Queue Q);
int isFound(Queue Q, int cari);
