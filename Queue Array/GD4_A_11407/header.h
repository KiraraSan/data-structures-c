#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 5

typedef char string[50];

typedef struct {
	string nama, npm;
	float ipk;
} Data;

typedef struct {
	Data D[max];
	int Head;
	int Tail;
} Queue;

Data makeData(string nama, string npm, float ipk);
void createEmpty(Queue *Q);
int isEmpty(Queue Q);
int isFull(Queue Q);
int isOneElmt(Queue Q);
void Enqueue(Queue *Q, Data D);
void Dequeue(Queue *Q);
void print(Queue Q);
int isFound(Queue Q, string target);
