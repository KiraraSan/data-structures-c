#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 5

typedef char string[100];

typedef struct {
	string judul;
	int view;
} Video;

int isEmpty(Video V[]);
int isFull(Video V[]);

void createEmpty(Video V[]);
void bubbleSort(Video V[]);
void bubbleSortJudul(Video V[]);

int binarySearch(Video V[], int left, int right, int find);
int binarySearchJudul(Video V[], int left, int right, string judul);
int sequentialSearch(char randomAlphabet[], char cari);

void printArray(Video V[]);

bool uniqueCheckVideo(Video V[], string judul);
bool uniqueCheckView(Video V[], int view);

void insertRandomView(Video V[]);
void insertRandomAlphabet(char randomAlphabet[]);
