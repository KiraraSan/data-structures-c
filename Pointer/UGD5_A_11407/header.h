#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#define dataMAX 20

typedef char string[10];

typedef struct {
    int id;
    string no_urut;
    string nama;
    string daftar;
    string gender;
    string status;
} Peserta;

Peserta makePeserta(int id, string no_urut, string nama, string daftar, string gender, string status);
void inisialisasi(Peserta peserta[]);
void print(Peserta peserta[]);
void input(Peserta *ptrDisplay);
Peserta* cariID(Peserta *ptrDisplay, Peserta peserta[], int id);
