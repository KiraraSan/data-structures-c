#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>


typedef struct Node *address;
typedef char string[100];

typedef struct{
	int idHewan;
	string namaHewan;
	string tanggalLahir;
	string jenisHewan;
	string jenisKelamin;
	int idPeriksa;
	int idDokterBertugas;
	string tanggalPeriksa;
	string diagnosis;
	string obat;
} Hewan;

typedef struct Node{
	Hewan P;
	address next;
} tNode;

typedef struct{
	address first;
} List;


void createEmptyList(List *L);
bool isEmptyList(List L);
bool isOneElmnt(List L);
bool isUnik(List L, int idHewan);

address alokasiData(Hewan P);
Hewan makeData (int idHewan, string namaHewan, string tanggalLahir, string jenisHewan, string jenisKelamin, int idPeriksa, 
				int idDokter, string tanggalPeriksa, string diagnosis, string obat);
				
void insertFirst(List *L, Hewan P);
void insertLast(List *L, Hewan P);
void insertAt(List *L, Hewan P, string jenisHewan);

void deleteFirst(List *L);
void deleteLast(List *L);
void deleteAt(List *L, address hapus);

void print(List L);
address cariHewan(List L, int idHewan);
