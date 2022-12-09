#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 5

typedef char string[100];
// typedef int infoType;
// typedef infoType keyType;
// typedef infoType arrayType[N];

typedef struct {
	string judul;
	int view;
} Video;

int isEmpty(Video V[]);
int isFull(Video V[]);

void createEmpty(Video V[]);
// void swapElement(keyType *first, keyType *second);
void bubbleSort(Video V[]);

int binarySearch(Video V[], int left, int right, int find);
int binarySearchJudul(Video V[], int left, int right, string judul);
// int sequentialSearch(arrayType a, infoType find);

void printArray(Video V[]);
// void printArray(arrayType a);
// void copyArray(arrayType a, arrayType b);

bool uniqueCheckVideo(Video V[], string judul);
bool uniqueCheckView(Video V[], int view);
// int uniqueCheck(arrayType a, infoType input);

void insertRandomView(Video V[]);
// void insertRandom(arrayType a);

