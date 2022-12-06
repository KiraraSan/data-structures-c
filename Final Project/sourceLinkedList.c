#include "headerLinkedList.h"


void createEmptyList(List *L){
	(*L).first = NULL;
}

bool isEmptyList(List L){
	return L.first == NULL;
}

bool isOneElmnt(List L){
	return L.first != NULL && L.first->next == NULL;
}

bool isUnik(List L, int idHewan){
	address temp = L.first;
	
	while(temp != NULL){
		if(temp->P.idHewan == idHewan){
			return false;
		}
		temp = temp->next;
	}
	return true;
}

address alokasiData(Hewan P){
	address a;
	
	a = (tNode *) malloc(sizeof(tNode));
	a->P = P;
	a->next = NULL;
	
	return a;
}

Hewan makeData (int idHewan, string namaHewan, string tanggalLahir, string jenisHewan, string jenisKelamin, int idPeriksa, 
				int idDokter, string tanggalPeriksa, string diagnosis, string obat){
		
	Hewan temp;
	
	temp.idHewan = idHewan;
	strcpy(temp.namaHewan, namaHewan);
	strcpy(temp.tanggalLahir, tanggalLahir);
	strcpy(temp.jenisHewan, jenisHewan);
	strcpy(temp.jenisKelamin, jenisKelamin);
	temp.idPeriksa = idPeriksa;
	temp.idDokterBertugas = idDokter;
	strcpy(temp.tanggalPeriksa, tanggalPeriksa);
	strcpy(temp.diagnosis, diagnosis);
	strcpy(temp.obat, obat);
	
	return temp;
}

void insertFirst(List *L, Hewan P){
	address a;
	
	a = alokasiData(P);
	a->next = L->first;
	
	L->first = a;
}

void insertAt(List *L, Hewan P, string jenisHewan){
	
	address helper = L->first;
	
	if(isEmptyList((*L))){
		insertFirst(&(*L), P);
		
	}else{
		if(isOneElmnt((*L))){
			if(strcmpi(helper->P.jenisHewan, "Anjing") == 0){
				insertLast(&(*L), P);
				
			}else if(strcmpi(helper->P.jenisHewan, "Kucing") == 0){
				insertFirst(&(*L), P);
				
			}else{
				insertLast(&(*L), P);
			}
			
		}else{
			if(strcmpi(helper->P.jenisHewan, "Kucing") == 0){
				insertFirst(&(*L), P);
					
			}else if(strcmpi(helper->P.jenisHewan, "Burung") == 0){
				insertFirst(&(*L), P);
			}else{
				while(helper->next != NULL){
					if(strcmpi(helper->next->P.jenisHewan, "Burung") == 0){
						break;
						
					}else if(strcmpi(helper->next->P.jenisHewan, "Kucing") == 0){
						break;
						
					}
					helper = helper->next;
				}
				address a = alokasiData(P);
				a->next = helper->next;
				helper->next = a;
			}
			
		}
		
	}	
}

void insertLast(List *L, Hewan P){
	address a, last;
	
	if(isEmptyList(*L)){
		insertFirst(&(*L), P);
		
	}else{
		last = L->first;
		a = alokasiData(P);
		
		while(last->next != NULL){
			last = last->next;
		}
		last->next = a;
		
	}
}

void print(List L){
	address a;
	
	if(!isEmptyList(L)){
		a = L.first;
			while(a != NULL){
				printf("\n\t\t\t---- Data Periksa Hewan ----");
				printf("\n\t\t\t[-] ID Hewan		: %d", a->P.idHewan);
				printf("\n\t\t\t[-] Nama Hewan		: %s", a->P.namaHewan);
				printf("\n\t\t\t[-] Tanggal Lahir	: %s", a->P.tanggalLahir);
				printf("\n\t\t\t[-] Jenis Hewan		: %s", a->P.jenisHewan);
				printf("\n\t\t\t[-] Jenis Kelamin	: %s", a->P.jenisKelamin);
				
				printf("\n\t\t\t\t[-] ID Periksa		: %d", a->P.idPeriksa);
				printf("\n\t\t\t\t[-] ID Dokter		: %d", a->P.idDokterBertugas);
				printf("\n\t\t\t\t[-] Tanggal Periksa	: %s\n", a->P.tanggalPeriksa);
				
				if(strcmpi(a->P.diagnosis, "-") != 0){
					printf("\n\t\t\t\t[-] Diagnosis		: %s", a->P.diagnosis);
					printf("\n\t\t\t\t[-] Obat - Obat		: %s\n\n", a->P.obat);
				}else{
					printf("\n");
				}
				
				a = a->next;
			}
	}	
}

address cariHewan(List L, int idHewan){
	address a;
	a = L.first;
	
	while(a != NULL){
		if(a->P.idHewan == idHewan){
			return a;
		}
		a = a->next;
	}
	return NULL;
}

void deleteFirst(List *L){
	address hapus;
	
	if(isOneElmnt((*L))){
		createEmptyList(&(*L));
	}else{
		hapus = L->first;
		L->first = L->first->next;
		free(hapus);
	}	
}

void deleteAt(List *L, address hapus){
	address bantu = L->first;
	
	if(bantu == hapus){
		deleteFirst(&(*L));
	}else{
		while(bantu->next != NULL){
			if(bantu->next == hapus){
				break;
			}
			bantu = bantu->next;
		}
		bantu->next = hapus->next;
		free(hapus);
	}
	
}
