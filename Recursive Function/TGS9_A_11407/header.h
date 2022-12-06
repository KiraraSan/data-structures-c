#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 12
#define MAX_P 5

typedef char string[100];

typedef struct {
    string nama;
    string bidangKeahlian;
    float gajiPokok;
    int jmlPenelitianBln[MAX];
} Peneliti;

void inisialisasi(Peneliti P[], int index);
int getEmptyIndex(Peneliti P[], int index);
void printPenelitian(Peneliti P[], int index, int value);
void printAll(Peneliti P[], int index);
int isEmpty(Peneliti P[], int index);
int isPenelitiUnik(Peneliti P[], int index, string nama);
void inputPenelitian(Peneliti temp[], int index, int value);
void edit(Peneliti temp[], Peneliti temp_two, int index);
int maximum(Peneliti P[], int index, int value);
int minimum(Peneliti P[], int index, int value);
