#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define motorMAX 5
#define rodaMAX 2

typedef char string[20];

typedef struct {
	string jenis;
	float bobot;
} Roda;

typedef struct {
	string nama;
	string merk;
	int cc;
	string plat;
	Roda R[rodaMAX];
} Motor;

void inisialisasi(Motor M[]);
Roda createRoda(string jenis, float bobot);
Motor createMotor(string nama, string merk, int cc, string plat);
void read(Motor M[]);
int isFound(Motor M[], string cari);
void hapus(Motor M[], string nama);
void update(Motor M[], string z_plat);
int calculate(Motor M[]);
int isFull(Motor M[]);
int isEmpty(Motor M[]);
int getEmpty(Motor M[]);



