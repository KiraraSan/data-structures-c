#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define motorMAX 5

typedef char string[20];

typedef struct {
	string nama;
	string merk;
	int cc;
	string plat;
} Motor;

void inisialisasi(Motor M[]);
void create(Motor M[], string nama, string merk, int cc, string plat, int temp);
void read(Motor M[]);
int isFound(Motor M[], string cari);
// void ubah(Motor M[], string nama, string merk, string cc, string plat, int index);
void hapus(Motor M[], string nama);
void update(Motor M[], string z_plat);
int calculate(Motor M[]);
int isFull(Motor M[]);
int isEmpty(Motor M[]);
int getEmpty(Motor M[]);



