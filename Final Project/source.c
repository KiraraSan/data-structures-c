#include "header.h"

DataParent makeDataParent(string username, string password, int idDokter, string namaDokter, string tanggalBergabung){
	DataParent data;
	
	strcpy(data.username, username);
	strcpy(data.password, password);
	data.idDokter = idDokter;
	strcpy(data.namaDokter, namaDokter);
	strcpy(data.tanggalBergabung, tanggalBergabung);

	return data;
}

void printParent(AddressParent parent){
	
	printf("\n\t\t\t---- Data Dokter ----");
	printf("\n\t\t\t[-] ID Dokter		: %d", parent->dataParent.idDokter);
	printf("\n\t\t\t[-] Nama Dokter		: %s", parent->dataParent.namaDokter);
	printf("\n\t\t\t[-] Tanggal Bergabung	: %s", parent->dataParent.tanggalBergabung);
	printf("\n\t\t\t\t[-] Username		: %s", parent->dataParent.username);
	printf("\n\t\t\t\t[-] Password		: %s\n\n", parent->dataParent.password);

	
}

void printAllParent(Multilist l){
	AddressParent temp = l.firstParent;
	
	while(temp != NULL){
		
		printParent(temp);
		temp = temp->next;
	}
	
}

void printChild(AddressChild child){
	
	printf("\n\t\t\t---- Data Hewan ----");
	printf("\n\t\t\t[-] ID Hewan		: %d", child->dataChild.idHewan);
	printf("\n\t\t\t[-] Nama Hewan		: %s",  child->dataChild.namaHewan);
	printf("\n\t\t\t[-] Tanggal Lahir	: %s", child->dataChild.tanggalLahir);
	printf("\n\t\t\t[-] Jenis Hewan		: %s", child->dataChild.jenisHewan);
	printf("\n\t\t\t[-] Jenis Kelamin	: %s", child->dataChild.jenisKelamin);
			
	printf("\n\t\t\t\t[-] ID Periksa		: %d", child->dataChild.idPeriksa);
	printf("\n\t\t\t\t[-] ID Dokter		: %d", child->dataChild.idDokterBertugas);
	printf("\n\t\t\t\t[-] Tanggal Periksa	: %s\n", child->dataChild.tanggalPeriksa);
			
	if(strcmpi(child->dataChild.diagnosis, "-") != 0){
		printf("\n\t\t\t\t[-] Diagnosis		: %s", child->dataChild.diagnosis);
		printf("\n\t\t\t\t[-] Obat - Obat		: %s\n\n", child->dataChild.obat);
	}else{
		printf("\n");
	}
}

void cekPeriksaHewan(AddressParent parent){
	AddressChild temp = parent->firstChild;
	
	while(temp != NULL){
		if(strcmpi(temp->dataChild.diagnosis, "-") == 0){
			printChild(temp);
		}
		temp = temp->next;
	}
}

void printAllChild(AddressParent parent){
	AddressChild temp = parent->firstChild;
	
	while(temp != NULL){
		printChild(temp);
		temp = temp->next;
	}
}

DataChild makeDataChild(int idHewan, string namaHewan, string tanggalLahir, string jenisHewan, string jenisKelamin, int idPeriksa, 
						int idDokter, string tanggalPeriksa, string diagnosis, string obat){
	DataChild temp;
	
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

bool isUsernameUnik(Multilist l, string username){
	AddressParent temp = l.firstParent;
	
	while(temp != NULL){
		if(strcmpi(temp->dataParent.username, username) == 0){
			return false;
		}
		temp = temp->next;
	}
	return true;
}
