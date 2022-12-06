#include "header.h"

void inisialisasi(Kursi K[ROW][COL]) {
	int i;
	int n;
	
	for(i=0; i<ROW; i++) {
		for(n=0; n<COL; n++) {
			strcpy(K[i][n].nama, "-");
			strcpy(K[i][n].id, "-");
			K[i][n].kode = 0;
			strcpy(K[i][n].cek, "-");
		}
	}
}

Kursi create(string nama, string id, int kode, string cek) {
	Kursi temp;
	
	strcpy(temp.nama, nama);
	strcpy(temp.id, id);
	temp.kode = kode;
	strcpy(temp.cek, cek);
	
	return temp;
}

Index found(Kursi K[ROW][COL], string cari) {
	int i;
	int n;
	Index index;
	
	index.i = -1;
	
	for(i=0; i<ROW; i++) {
		for(n=0; n<COL; n++) {
			if(strcmpi(K[i][n].id, cari)==0) {
				index.i = i;
				index.n = n;
				
				return index;
			}
		}
	}
	return index;
}

Index found2(Kursi K[ROW][COL], string cari) {
	int i;
	int n;
	Index index2;
	
	index2.i = -1;
	
	for(i=0; i<ROW; i++) {
		for(n=0; n<COL; n++) {
			if(strcmpi(K[i][n].nama, cari)==0) {
				index2.i = i;
				index2.n = n;
				
				return index2;
			}
		}
	}
	return index2;
}

int isEmpty(Kursi K[ROW][COL]) {
	int i, n;
	
	for(i=0; i<ROW; i++) {
		for(n=0; n<COL; n++) {
			if(strcmpi(K[i][n].nama, "-")!=0) {
				return i;
			}	
		}	
	}
	return -1;
}

bool cekIsi(Kursi K[ROW][COL], Index index) {
	if(strcmpi(K[index.i][index.n].cek, "-")) {
		return true;
	} else {
		return false;
	}
}

void read(Kursi K[ROW][COL]) {
	int i;
	int n;
	
	for(i=0; i<ROW; i++) {
		printf("\t");
		for(n=0; n<COL; n++) {
			printf("[%s]\t\t", K[i][n].id);
		}
		printf("\n");
	}
}

void enkripsiData(Kursi K[ROW][COL]) {
	int i;
	int n;
	
	for(i=0; i<COL; i++) {
		printf("\t");
		for(n=ROW-1; n>=0; n--) {
			printf("[%s]\t\t", K[n][i].id);
		}
		printf("\n");
	}
}

void enkripsiKode(Kursi K[ROW][COL]) {
	int i, n;
	int z;
	int jumlah;
	int kali[A][B];
	int enkKode[ROW][COL];
	
	for(i=0; i<ROW; i++) {
		for(n=0; n<COL; n++) {
			enkKode[i][n] = K[i][n].kode;  
		}
	}
	printf("\n\tInput Matrix Kode (4x4) :\n");
	for(i=0; i<A; i++) {
		printf("\t");
		for(n=0; n<B; n++) {
			scanf("%d", &kali[i][n]);
		}
	}
    printf("\n\tMatrix Sebelum :\n");
    for(i=0; i<ROW; i++) {
    	printf("\t");
  		for(n=0; n<COL; n++) {
        	printf("[ %d ]\t\t", K[i][n].kode);
      	}
      	printf("\n");
    }
    for(i=0; i<ROW; i++) {
    	for(n=0; n<B; n++) {
    		if(enkKode[i][n] != 0) {
    			jumlah = 0;
    			for(z=0; z<A; z++) {
        			jumlah += enkKode[i][z] * kali[z][n];
        			K[i][n].kode = jumlah;
        		}
			}	
      	}
    }
    printf("\n\tMatrix Sesudah :\n");
    for(i=0; i<ROW; i++) {
    	printf("\t");
      	for(n=0; n<B; n++) {
        	printf("[ %d ]\t\t", K[i][n].kode);
      	}
      	printf("\n");
    }
    printf("\n\t\t[*] Berhasil update kode");
}
