#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10

typedef int infoType;
typedef infoType keyType;
typedef infoType arrayType[N];

int isEmpty(arrayType a);
int isFull(arrayType a);

void createEmpty(arrayType a);
void swapElement(keyType *first, keyType *second);
void bubbleSort(arrayType a);

int binarySearch(arrayType a, int left, int right, infoType find);
int sequentialSearch(arrayType a, infoType find);

void printArray(arrayType a);
void copyArray(arrayType a, arrayType b);

int uniqueCheck(arrayType a, infoType input);

void insertRandom(arrayType a);

