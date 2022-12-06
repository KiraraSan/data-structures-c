#include "header.h"

Data makeData(string nama, string npm, float ipk) {
	Data data;
	
	strcpy(data.nama, nama);
	strcpy(data.npm, npm);
	data.ipk = ipk;
	
	return data;
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

void Enqueue(Queue *Q, Data D) {
	if(isEmpty(*Q)) {
		(*Q).Head = (*Q).Tail = 0;
	} else {
		if((*Q).Tail == max-1) {
			(*Q).Tail = 0;
		} else {
			(*Q).Tail++;
		}
	}
	(*Q).D[(*Q).Tail] = D;
	printf("\n\tBerhasil memasukkan data...");
}

void Dequeue(Queue *Q) {
	string temp;
	
	strcpy(temp, (*Q).D[(*Q).Head].npm);
	
	if(isOneElmt(*Q)) {
		createEmpty(&(*Q));
	} else {
		if((*Q).Head == max-1) {
			(*Q).Head = 0;
		} else {
			(*Q).Head++;
		}
	}
	printf("\n\tData dengan NPM %s berhasil dihapus...", temp);
}

void print(Queue Q) {
	int i, temp=1;
	
	if(Q.Head <= Q.Tail) {
		for(i=0; i<=Q.Tail; i++) {
			printf("%d. %s(%.2f); ", i+1, Q.D[i].nama, Q.D[i].ipk);
		}
	} else {
		for(i=Q.Head; i<=max-1; i++) {
			printf("%d. %s(%.2f); ", temp, Q.D[i].nama, Q.D[i].ipk);
			temp++;
		}
		for(i=0; i<Q.Tail; i++) {
			printf("%d. %s(%.2f); ", temp, Q.D[i].nama, Q.D[i].ipk);
			temp++;
		}
	}
}

int isFound(Queue Q, string target) {
	int i;
	if(Q.Head <= Q.Tail) {
		for(i=0; i<=Q.Tail; i++) {
			if(strcmp(Q.D[i].npm, target)==0) {
				return i;
			}
		}
	} else {
		for(i=Q.Head; i<=max-1; i++) {
			if(strcmp(Q.D[i].npm, target)==0) {
				return i;
			}
		}
		for(i=0; i<Q.Tail; i++) {
			if(strcmp(Q.D[i].npm, target)==0) {
				return i;
			}
		}
	}
	return -1;
}
