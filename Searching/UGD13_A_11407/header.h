#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 5

typedef char string[100];
typedef int infoType;
typedef infoType keyType;
typedef infoType arrayType[N];

typedef struct {
	string judul;
	int view;
} Video;

int isEmpty(Video V[]);
int isFull(Video V[]);

void createEmpty(Video V[]);
void swapElement(keyType *first, keyType *second);
void bubbleSort(Video V[]);

int binarySearch(arrayType a, int left, int right, infoType find);
int sequentialSearch(arrayType a, infoType find);

void printArray(arrayType a);
void copyArray(arrayType a, arrayType b);

bool uniqueCheckVideo(Video V[], string judul);
bool uniqueCheckView(Video V[], int view);
int uniqueCheck(arrayType a, infoType input);

void insertRandomView(Video V[], int i);
void insertRandom(arrayType a);

