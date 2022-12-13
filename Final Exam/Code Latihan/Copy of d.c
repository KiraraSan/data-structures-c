#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

typedef int array[MAX];

// Swap berfungsi untuk mengganti dua nilai dari dua variabel berbeda
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble sort untuk mengurutkan data secara ascending ataupun descending
void BubbleSort(array a){
    int i, j;
    for(i = 0; i < MAX - 1; i++){
        for(j = 0; j < MAX - i - 1; j++){
            if(a[j] > a[j + 1]){
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void print(array a, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

void binarySearch(array a, int n, int x){
    int bawah = 0, atas = n - 1, tengah; 
    /* bawah dan atas adalah batas dari array, sedangkan tengah adalah nilai tengah dari array 
    n di kurangi 1 dikarenakan data dalam sebuah array dimulai dari nol bukan satu */

    array temp; /* Array untuk menampung data yang sudah di visit */

    int loop = 0; /* Loop untuk menampung data yang sudah di visit dalam bentuk total loop */

    while(bawah <= atas){ /* Looping akan berhenti jika bawah lebih besar dari atas */

        tengah = (bawah + atas) / 2; /* Menghitung nilai tengah dari array */

        if(a[tengah] == x){ /* Jika nilai tengah sama dengan nilai yang dicari */

            printf("\nFound %d at index %d in the array", x, tengah);

            printf("\nData visit : "); print(temp, loop);

            printf("\nLoop %d times", loop+1);

            return;

        }else if(a[tengah] < x){ /* Jika nilai tengah lebih kecil dari nilai yang dicari */
            
            bawah = tengah + 1; /* Maka nilai bawah akan di tambah 1 */

            temp[loop] = a[tengah]; /* Data yang sudah di visit akan di tampung dalam array temp */

        }else{

            atas = tengah - 1; /* Jika nilai tengah lebih besar dari nilai yang dicari maka nilai atas akan di kurangi 1 */

            temp[loop] = a[tengah]; /* Data yang sudah di visit akan di tampung dalam array temp */

        }

        loop++; /* Loop berfungsi untuk menghitung berapa kalai jumlah perulangan yang terjadi dalam sebuah pencarian */

    }

    printf("Not found %d in the array a ", x); /* data tidak ditemukan */
}

int main(){
//    system("clear");
    array a = {7, 15, 30, 21, 17, 19, 20, 9, 1, 10};
    // BubbleSort(a);
    print(a, MAX);
    printf("\n");
    binarySearch(a, MAX, 1);
    /*
        Dalam binary search, data dalam sebuah array akan diurutkan terlebih dahulu secara ascending ataupun descending.
    */
}
