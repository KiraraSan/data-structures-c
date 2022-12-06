#include "header.h"

void createEmpty(array *a) {
	a->akhir = -1;
}

int isEmpty(array a) {
	return a.akhir == -1;
}

void printArray(array a) {
	int i;
	
	for (i=0; i<=a.akhir; i++) {
		if (a.D[i].status == 0) {
			printf("\n\tNama      : %s", a.D[i].namaRoket); 
			printf("\n\tKode      : %d", a.D[i].kodeRoket);
			printf("\n\tKapasitas : %d\n", a.D[i].kapasitas);	
		}	
	}	
}

void printArray_two(array a) {
	int i;
	
	for (i=0; i<=a.akhir; i++) {
		if (a.D[i].status == 1) {
			printf("\n\tNama      : %s", a.D[i].namaRoket); 
			printf("\n\tKode      : %d", a.D[i].kodeRoket);
			printf("\n\tKapasitas : %d\n", a.D[i].kapasitas);	
		}
	}	
}

int findArray(array a, int find) {
	int i;
	
	for (i=0; i<=a.akhir; i++) {
		if (a.D[i].kodeRoket == find) {
			return i;
		}		
	}
	return -1;
}

void bubbleSort(array *a) {
	int i, j;

	for (i=0; i<=(*a).akhir-1; i++) {
		for (j=i+1; j<=(*a).akhir; j++) {
			if ((*a).D[i].kapasitas > (*a).D[j].kapasitas) {
				swap(&(*a).D[i].kapasitas, &(*a).D[j].kapasitas);
			}
		}
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void mergeSort(array *a) {
	array t;
	
	if (length(*a) > 1) {
		partInto2(&(*a), &t);
		mergeSort(&(*a));
		mergeSort(&t);
		merge(&(*a), t);
	}
}

void add(array *a, Roket x) {
	(*a).akhir++;
	(*a).D [(*a).akhir] = x;
}

int length(array a) {
	return (a.akhir+1);
}

array cloneArray(array a) {
	int i;
	array temp;
	
	for (i=0; i<=a.akhir; i++) {
		temp.D[i] = a.D[i];
	}
	temp.akhir = a.akhir;
	return temp;
}

void partInto2(array *a, array *a2) {
	int i, len = length(*a);
	
	(*a).akhir = len / 2 + len % 2 - 1;
	(*a2).akhir = len - length(*a)-1;
	
	for (i=0; i<=(*a2).akhir; i++) {
		(*a2).D[i] = (*a).D[i+length(*a)];
	}
}

void merge(array *a, array D) {
	array temp;
	createEmpty(&temp);
	int i=0, j=0, k;
	
	while (i<=(*a).akhir && j<=D.akhir) {
		if ((*a).D[i].namaRoket < D.D[j].namaRoket) {
			add(&temp, (*a).D[i]);
			i++;
		} else {
			add(&temp, D.D[j]);
			j++;
		}
	}
	if (i > (*a).akhir) {
		for (k=j; k<=D.akhir; k++) {
			add(&temp, D.D[k]);
		}
	} else {
		for(k=i; k<=(*a).akhir; k++) {
			add(&temp, (*a).D[k]);
		}
	}
	(*a)=cloneArray(temp);
}

void quickSort(array *a, int awal, int akhir) {
	int i = awal, j = akhir;
	int pivot = (*a).D [(awal + akhir) / 2].kodeRoket;

	while (i <= j) {
	while ((*a).D[i].kodeRoket < pivot)
		i++;
	while ((*a).D[j].kodeRoket > pivot)
		j--;
	if (i <= j) {
		swap(&(*a).D[i].kodeRoket, &(*a).D[j].kodeRoket);
		i++; 
		j--;
	}
	}
	if (awal < j)
		quickSort(&(*a), awal, j);
	if (i < akhir)
		quickSort(&(*a), i, akhir);
}
