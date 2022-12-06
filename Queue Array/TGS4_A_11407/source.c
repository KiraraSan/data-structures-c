#include "header.h"

Bengsin makeBengsin(int id, string nama, string jenis, float uang) {
	Bengsin B;
	
	B.id = id;
	strcpy(B.nama, nama);
	strcpy(B.jenis, jenis);
	B.uang = uang;
	
	return B;
}

void createEmpty(Queue *Q) {
	(*Q).Head = (*Q).Tail = -1;
	
	int i;
	for(i=0; i<max; i++) {
		(*Q).B[i].id = 0;
		strcpy((*Q).B[i].nama, "-");
		(*Q).B[i].uang = 0;
	}
}

int isEmpty(Queue Q) {
	return (Q.Head == -1 && Q.Tail == -1);
}

int isFull(Queue Q) {
	return ((Q.Head < Q.Tail && Q.Tail - Q.Head == max-1) || (Q.Tail < Q.Head && Q.Tail + 1 == Q.Head));
}

int isOneElmt(Queue Q) {
	return (Q.Head == Q.Tail && !isEmpty(Q));
}

void Enqueue(Queue *Q, Bengsin B) {
	if(isEmpty(*Q)) {
		(*Q).Head = (*Q).Tail = 0;
	} else {
		if((*Q).Tail == max-1) {
			(*Q).Tail = 0;
		} else {
			(*Q).Tail++;
		}
	}
	(*Q).B[(*Q).Tail] = B;
	printf("\n\t\tBerhasil memasukkan data...");
}

void Dequeue(Queue *Q) {	
	if(isOneElmt(*Q)) {
		createEmpty(&(*Q));
	} else {
		if((*Q).Head == max-1) {
			(*Q).Head = 0;
		} else {
			(*Q).Head++;
		}
	}	
}

void tampil(Queue Q) {
	int i, temp=0;
	
	if(Q.Head <= Q.Tail) {
		for(i=Q.Head; i<=Q.Tail; i++) {
			printf("%d(%s) | ", Q.B[i].id, Q.B[i].nama);
		}
	} else {
		for(i=Q.Head; i<=max-1; i++) {
			printf("%d(%s) | ", Q.B[i].id, Q.B[i].nama);
			temp++;
		}
		for(i=0; i<Q.Tail; i++) {
			printf("%d(%s) | ", Q.B[i].id, Q.B[i].nama);
			temp++;
		}
	}
}

int isFound(Queue Q, int cari) {
	int i;
	if(Q.Head <= Q.Tail) {
		for(i=Q.Head; i<=Q.Tail; i++) {
			if(Q.B[i].id == cari) {
				return i;
			}
		}
	} else {
		for(i=Q.Head; i<max-1; i++) {
			if(Q.B[i].id == cari) {
				return i;
			}
		}
		for(i=0; i<Q.Tail; i++) {
			if(Q.B[i].id == cari) {
				return i;
			}
		}
	}
	return -1;
}
