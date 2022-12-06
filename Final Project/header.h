#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

/* Anggota Kelompok:
	1. Alexis Divasonda Sigat Ngaing	/ 210711407
	2. I Nyoman Gede Giri Mulyawan		/ 210711412
	3. romanus NDRURU					/ 210711449
	4. Devin Ganiputra Hernando			/ 210711453
*/


typedef char string[100];
typedef struct Child* AddressChild;
typedef struct Parent* AddressParent;


typedef struct DataChild{
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
	
} DataChild;


typedef struct DataParent{
	string username;
	string password;
	int idDokter;
	string namaDokter;
	string tanggalBergabung;
	
} DataParent;


typedef struct Child{
	DataChild dataChild;
	AddressChild next;
} NodeChild;


typedef struct Parent{
	DataParent dataParent;
	AddressParent next;
	
	AddressChild firstChild;
} NodeParent;


typedef struct{
	AddressParent firstParent;
} Multilist;


//source Parent;
void createEmpty(Multilist *l);
bool isEmpty(Multilist l);
bool haveChild(AddressParent ap);
bool isParentUnik(Multilist l, int idDokter);
bool isChildUnik(Multilist, int idPeriksa);

void insertFirstParent(Multilist *l, DataParent data);
void insertLastParent(Multilist *l, DataParent data);

void deleteFirstParent(Multilist *l);
void deleteAtParent(Multilist *l, int idParent);
void deleteAllChild(AddressParent parent);

AddressParent alokasiParent(DataParent data);
AddressParent findParent(Multilist l, int cariId);
AddressParent cekUserDokter(Multilist l, string username, string password);


//sourceChild
void insertFirstChild(Multilist l, AddressParent parent, DataChild data);
AddressChild alokasiChild(DataChild data);
AddressChild findChild(Multilist l, AddressParent parent, int idPeriksa);
void deleteAtChild(AddressParent parent, int idHewan);


//source
DataParent makeDataParent(string username, string password, int idDokter, string namaDokter, string tanggalBergabung);
DataChild makeDataChild(int idHewan, string namaHewan, string tanggalLahir, string jenisHewan, string jenisKelamin, int idPeriksa, 
						int idDokter, string tanggalPeriksa, string diagnosis, string obat);
						
void printParent(AddressParent parent);
void printAllParent(Multilist l);

void printAllChild(AddressParent parent);
void printChild(AddressChild child);
void cekPeriksaHewan(AddressParent parent);

bool isUsernameUnik(Multilist l, string username);
