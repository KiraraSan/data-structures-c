#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ROW 7
#define COL 4
#define A 4
#define B 4

typedef char string[50];

typedef struct {
	string nama;
	string id;
	int kode;
	string cek;
} Kursi;

typedef struct Index {
	int i;
	int n;
} Index;

void inisialisasi(Kursi K[ROW][COL]);
Kursi create(string nama, string id, int kode, string cek);
Index found(Kursi K[ROW][COL], string id);
Index found2(Kursi K[ROW][COL], string nama);
int isEmpty(Kursi K[ROW][COL]);
bool cekIsi(Kursi K[ROW][COL], Index index);
void read(Kursi K[ROW][COL]);
void enkripsiData(Kursi K[ROW][COL]);
void enkripsiKode(Kursi K[ROW][COL]);
