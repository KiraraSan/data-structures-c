// NO 6

#include <stdio.h>

#define N 10

void tampilRekursif1(int A[], int i){ // Cara 1
	if(i < 0){
		return;
	}
	else{
		printf("%d ", A[i]);
		tampilRekursif1(A, i - 1);
	}
}

void tampilRekursif2(int A[], int i){ // Cara 2
	if(i == N){
		return;
	}
	else{
		tampilRekursif2(A, i + 1);
		printf("%d ", A[i]);
	}
}

int main(){
	int A[N] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};
	
	printf("Tampil Rekursif 1 : \n");
	tampilRekursif1(A, N - 1);
	printf("\n\nTampil Rekursif 2 : \n");
	tampilRekursif2(A, 0);
	printf("\n\nTampil Rekursif 3 : \n");
	
	return 0;
}
