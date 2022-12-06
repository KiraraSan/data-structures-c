#include "header.h"

Bengsin makeBengsin(int id, string nama, string jenis, float uang) {
	Bengsin bengsin;
	
	bengsin.id = id;
	strcpy(bengsin.nama, nama);
	strcpy(bengsin.jenis, jenis);
	bengsin.uang = uang;
	
	return bengsin;
}

void createEmpty(Queue *Q) {
	(*Q).Head = (*Q).Tail = -1;
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
	printf("\n\tBerhasil memasukkan data...");
}

void Dequeue(Queue *Q) {
	int temp_one;
	string temp_two;
	
	temp_one = (*Q).B[(*Q).Head].id;
	strcpy(temp_two, (*Q).B[(*Q).Head].nama);
	
	if(isOneElmt(*Q)) {
		createEmpty(&(*Q));
	} else {
		if((*Q).Head == max-1) {
			(*Q).Head = 0;
		} else {
			(*Q).Head++;
		}
	}
	printf("\n\t ID | &d | dengan nama | %s | berhasil melakukan pembayaran...", temp_one, temp_two);
}

void tampil(Queue Q) {
	Queue pertamax, pertalite;
	int i, temp=1000;
	
	if(Q.Head <= Q.Tail) {
		for(i=0; i<=Q.Tail; i++) {
			printf("%d(%s) | ", temp+1, Q.B[i].nama);
		}
	} else {
		for(i=Q.Head; i<=max-1; i++) {
			printf("%d(%s) | ", temp, Q.B[i].nama);
			temp++;
		}
		for(i=0; i<Q.Tail; i++) {
			printf("%d(%s) | ", temp, Q.B[i].nama);
			temp++;
		}
	}
	
	if(Q.Head <= Q.Tail) {
		for(i=0; i<=Q.Tail; i++) {
			printf("%d(%s) | ", 1000+1, Q.B[i].nama);
		}
	} else {
		for(i=Q.Head; i<=max-1; i++) {
			printf("%d(%s) | ", temp, Q.B[i].nama);
			temp++;
		}
		for(i=0; i<Q.Tail; i++) {
			printf("%d(%s) | ", temp, Q.B[i].nama);
			temp++;
		}
	}
}

int isFound(Queue Q, int cari) {
	int i;
	if(Q.Head <= Q.Tail) {
		for(i=0; i<=Q.Tail; i++) {
			if(Q.B[i].id = cari) {
				return i;
			}
		}
	} else {
		for(i=Q.Head; i<=max-1; i++) {
			if(Q.B[i].id = cari) {
				return i;
			}
		}
		for(i=0; i<Q.Tail; i++) {
			if(Q.B[i].id = cari) {
				return i;
			}
		}
	}
	return -1;
}
