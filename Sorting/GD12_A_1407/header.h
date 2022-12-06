#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int infotype;
typedef int address;

typedef struct {
	address akhir;
	infotype t[MAX];
} array;

//==Fungsi Array==//
void createEmpty(array *a);
int isEmpty(array a);
void setArray(array *a, int n);
void printInfo(array a);
//===//

//==Bubble Sort==//
void bubbleSort(array *a);
void swap(int *a, int *b);
//===//

//==Merge Sort==//
void mergeSort(array *a);
void add(array *a, int x);
int length(array a);
array cloneArray(array a);
void partInto2(array *a, array *a2);
void merge(array *a, array t);
//===//

//==Quick Sort==//
void quickSort (array *a, int awal, int akhir);
//===//
