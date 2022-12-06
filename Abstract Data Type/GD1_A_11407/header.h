#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[20];

typedef struct {
	string nama;
	string npm;
} Mahasiswa;

void initMahasiswa(Mahasiswa m[]);

Mahasiswa makeMahasiswa(string nama, string npm);

void tampilMahasiswa(Mahasiswa m[]);

void hapusMahasiswa(Mahasiswa m[], string npm);

int isFull(Mahasiswa m[]);
