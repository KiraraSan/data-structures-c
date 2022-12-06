#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#define dataMAX 20
#define ROW 4
#define COL 5

typedef char string[20];

typedef struct {
    int id;
    string no_urut;
    string nama;
    string daftar;
    string gender;
    string status;
} Peserta;

Peserta makePeserta(int id, string no_urut, string nama, string daftar, string gender, string status);
void inisialisasi(Peserta peserta[ROW][COL]);
void print(Peserta peserta[ROW][COL]);
void input(Peserta *ptrDisplay);
Peserta* cariID(Peserta *ptrDisplay, Peserta peserta[ROW][COL], int id);
