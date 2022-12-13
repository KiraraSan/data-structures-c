#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 5

typedef char string[100];

typedef struct {
    int no;
} Mahasiswa;

void inisialisasi(Mahasiswa M[], int index);
int getEmptyIndex(Mahasiswa M[], int index);
void printAll(Mahasiswa M[], int index);
void printAllDesc(Mahasiswa M[], int index);
int isEmpty(Mahasiswa M[], int index);

