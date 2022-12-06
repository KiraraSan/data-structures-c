#include "header.h"

void initMatriks(Data data[ROW][COL]) {
	int i;
	int j;
	
	for(i=0; i<ROW; i++) {
		for(j=0; j<COL; j++) {
			data[i][j].value = -1;
			strcpy(data[i][j].status, "-");
		}
	}
}

void printData(Data data[ROW][COL]) {
	int i;
	int j;
	
	for(i=0; i<ROW; i++) {
		printf("\t");
		for(j=0; j<COL; j++) {
			printf("%d\t", data[i][j].value);
		}
		printf("\n");
	}
}

Data buatData(int value, string status) {
	Data temp;
	
	temp.value = value;
	strcpy(temp.status, status);
	
	return temp;
}

Index cariData(Data data[ROW][COL], int cari) {
	int i;
	int j;
	Index index;
	
	index.i = -1;
	
	for(i=0; i<ROW; i++) {
		for(j=0; j<COL; j++) {
			if(data[i][j].value == cari) {
				index.i = i;
				index.j = j;
				
				return index;
			}
		}
	}
	return index;
}

bool sudahIsi(Data data[ROW][COL], Index index) {
	if(strcmpi(data[index.i][index.j].status, "-")) {
		return true;
	} else {
		return false;
	}
}
