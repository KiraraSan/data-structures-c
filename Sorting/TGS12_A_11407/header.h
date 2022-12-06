#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef char string[50];
typedef int address;

typedef struct {
	string namaRoket;
	int status;
	int kapasitas;
	int kodeRoket;
} Roket;

typedef struct {
	address akhir;
	Roket D[MAX];
} array;

//==Fungsi Array==//
void createEmpty(array *a);
int isEmpty(array a);
void setArray(array *a, int n);
void printArray(array a);
void printArray_two(array a);
//===//

int findArray(array a, int find);

//==Bubble Sort==//
void bubbleSort(array *a);
void swap(int *a, int *b);
//===//

//==Merge Sort==//
void mergeSort(array *a);
void add(array *a, Roket x);
int length(array a);
array cloneArray(array a);
void partInto2(array *a, array *a2);
void merge(array *a, array t);
//===//

//==Quick Sort==//
void quickSort (array *a, int awal, int akhir);
//===//
