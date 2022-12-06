#ifndef HEADER
#define HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 3
#define COL 5

typedef char string[50];

typedef struct Data {
	int value;
	string status;
} Data;

typedef struct Index {
	int i;
	int j;
} Index;

void initMatriks(Data data[ROW][COL]);
void printData(Data data[ROW][COL]);
Data buatData(int value, string status);
Index cariData(Data[ROW][COL], int value);
bool sudahIsi(Data data[ROW][COL], Index index);

#endif
