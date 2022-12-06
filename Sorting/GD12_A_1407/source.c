#include "header.h"

void createEmpty(array *a) {
	a->akhir = -1;
}

int isEmpty(array a) {
	return a.akhir == -1;
}

void setArray(array *a, int n) {
	int i;
	createEmpty(&(*a));
	for (i=0; i<n; i++) {
		printf("Masukkan data ke %d : ",i+1);
		scanf("%d",&(*a).t[i]); 
	}
	(*a).akhir=n-1;
}

void printInfo(array a) {
	int i;
	for (i=0; i<=a.akhir; i++) {
 		printf("%d ",a.t[i]);
	}
}

void bubbleSort(array *a) {
	int i,j;

	for (i=0; i<=(*a).akhir-1; i++) {
		for(j=i+1;j<=(*a).akhir;j++) {
			if((*a).t[i] > (*a).t[j]) {
				swap(&(*a).t[i], &(*a).t[j]);
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

void add(array *a, int x) {
	(*a).akhir++;
	(*a).t [(*a).akhir] = x;
}

int length(array a) {
	return(a.akhir+1);
}

array cloneArray(array a) {
	int i;
	array temp;
	
	for (i=0; i<=a.akhir; i++) {
		temp.t[i] = a.t[i];
	}
	temp.akhir = a.akhir;
	return temp;
}

void partInto2(array *a, array *a2) {
	int i, len = length(*a);
	
	(*a).akhir = len / 2 + len % 2 - 1;
	(*a2).akhir = len - length(*a)-1;
	
	for (i=0; i<=(*a2).akhir; i++) {
		(*a2).t[i] = (*a).t[i+length(*a)];
	}
}

void merge(array *a, array t) {
	array temp;
	createEmpty(&temp);
	int i=0, j=0, k;
	
	while (i<=(*a).akhir && j<=t.akhir) {
		if ((*a).t[i] < t.t[j]) {
			add(&temp, (*a).t[i]);
			i++;
		} else {
			add(&temp, t.t[j]);
			j++;
		}
	}
	if(i > (*a).akhir) {
		for (k=j; k<=t.akhir; k++) {
			add(&temp, t.t[k]);
		}
	} else {
		for(k=i; k<=(*a).akhir; k++) {
			add(&temp, (*a).t[k]);
		}
	}
	(*a)=cloneArray(temp);
}

void quickSort(array *a, int awal, int akhir) {
	int i = awal, j = akhir;
	int pivot = (*a).t [(awal + akhir) / 2];

	while (i <= j) {
	while ((*a).t[i] < pivot)
		i++;
	while ((*a).t[j] > pivot)
		j--;
	if (i <= j) {
		swap(&(*a).t[i], &(*a).t[j]);
		i++; 
		j--;
	}
	}
	if (awal < j)
		quickSort(&(*a), awal, j);
	if (i < akhir)
		quickSort(&(*a), i, akhir);
}
