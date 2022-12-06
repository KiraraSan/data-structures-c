#include "header.h"

void inisialisasi(Motor M[]) {
	int i, n;
	
	for(i=0; i<motorMAX; i++) {
		strcpy(M[i].nama, "-");
		strcpy(M[i].merk, "-");
		M[i].cc = 0;
		strcpy(M[i].plat, "-");
		
		for(n=0; n<rodaMAX; n++) {
			strcpy(M[i].R[n].jenis, "-");
			M[i].R[n].bobot = 0;
		}
	}
}

Roda createRoda(string jenis, float bobot) {
	Roda R;
	
	strcpy(R.jenis, jenis);
	R.bobot = bobot;
	
	return R;
}

Motor createMotor(string nama, string merk, int cc, string plat) {
	Motor M;
	int i;
	
	strcpy(M.nama, nama);
	strcpy(M.merk, merk);
	M.cc = cc;
	strcpy(M.plat, plat);
	
	return M;
}

void read(Motor M[]) {
	int i, n;
	
	for(i=0; i<motorMAX; i++) {
			printf("\n--- Data %d ---\n", i+1);
			printf("Nama Pemilik : %s\n", M[i].nama);
			printf("Merk Motor   : %s\n", M[i].merk);
			printf("CC           : %d\n", M[i].cc);
			printf("Plat Nomor   : %s\n", M[i].plat);
			
		for(n=0; n<rodaMAX; n++) {
			printf("\n\tRoda %d", n+1);
			printf("\n\tJenis Roda : %s", M[i].R[n].jenis);
			printf("\n\tBobot Roda : %.2f", M[i].R[n].bobot);
			printf("\n");
		}
	} 
}

int isFound(Motor M[], string plat) {
	int i;
	
	for(i=0; i<motorMAX; i++) {
		if(strcmpi(M[i].plat, plat)==0) {
			return i;
		}
	}
	return -1;
}

int isFound2(Motor M[], string nama) {
	int i;
	
	for(i=0; i<motorMAX; i++) {
		if(strcmpi(M[i].nama, nama)==0) {
			return i;
		}
	}
	return -1;
}

void hapus(Motor M[], string nama) {
	int i = isFound2(M, nama);
	
	strcpy(M[i].nama, "-");
	strcpy(M[i].merk, "-");
	M[i].cc = 0;
	strcpy(M[i].plat, "-");	
		
	int n = i;
	for(n=0; n<rodaMAX; n++) {
		strcpy(M[i].R[n].jenis, "-");
		M[i].R[n].bobot = 0;	
	}	
}

void update(Motor M[], string z_plat) {
	string nama, merk, plat, jenis;
	int i, n, cc;
	float bobot;
	
	printf("\nNama   : "); fflush(stdin); gets(nama);
	printf("Merk   : "); fflush(stdin); gets(merk);
	printf("CC     : "); scanf("%d", &cc);
	printf("Plat   : "); fflush(stdin); gets(plat);
	
	i = isFound(M, z_plat);
	
	strcpy(M[i].nama, nama);
	strcpy(M[i].merk, merk);
	M[i].cc = cc;
	strcpy(M[i].plat, plat);
	
	//	n = isFound(M, z_plat);
	
	for(n=0; n<rodaMAX; n++) {
		printf("\n\tJenis roda : "); fflush(stdin); gets(jenis);
		printf("\tBobot roda : "); scanf("%f", &bobot);
			
		strcpy(M[i].R[n].jenis, jenis);
		M[i].R[n].bobot = bobot;
	}
	

}

int isFull(Motor M[]) {
	int i;
	
	for(i=0; i<motorMAX; i++) {
		if(strcmpi(M[i].nama, "-")==0) {
			return i;
		}
	}
	return -1;
}

int isEmpty(Motor M[]) {
	int i;
	
	for(i=0; i<motorMAX; i++) {
		if(strcmpi(M[i].nama, "-")!=0) {
			return i;
		}
	}
	return -1;
}

int getEmpty(Motor M[]) {
	int i;
	
	for(i=0; i<motorMAX; i++) {
		if(strcmpi(M[i].nama, "-")==0) {
			return i;
		}
	}
	return -1;
}

