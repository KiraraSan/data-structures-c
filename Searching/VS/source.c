#include "header.h"

int isEmpty(arrayType a) {
    return (a[0] == 0);
}

int isFull(arrayType a) {
    return (a[N-1] != 0);
}

void createEmpty(arrayType a) {
    int i;

    for (i=0; i<N; i++) {
        (a)[i] = 0;
    }
}

void swapElement(keyType *first, keyType *second) {
    keyType temp;
    temp = (*first);
    (*first) = (*second);
    (*second) = temp;
}

void bubbleSort(arrayType a) {
    int i, j;

    for (i=0; i<N; i++) {
        for (j=i+1; j<N; j++) {
            if((a)[i] > (a)[j]) {
                swapElement(&(a)[i], &(a)[j]);
            }
        }
    }
}

int binarySearch(arrayType a, int left, int right, infoType find) {
    if (right >= left) {
        int mid = (left + right)/2;
        if (find == a[mid]) {
            return mid;
        }
        if (find < a[mid]) {
            return binarySearch(a, left, mid-1, find);
        }
        return binarySearch(a, mid+1, right, find);
    }
    return -1;
}

int sequentialSearch(arrayType a, infoType find) {
    int i;
    
    for (i=0; i<N; i++) {
        if(a[i] == find) {
            return i;
        }
    }
    return -1;
}

void printArray(arrayType a) {
    int i;

    for (i=0; i<N; i++) {
        printf("%d ", a[i]);
    }
}

int uniqueCheck(arrayType a, infoType input) {
    int i;

    for (i=0; i<N; i++) {
        if(a[i] == input) {
            return 0;
        }
    }
    return 1;
}

void copyArray(arrayType a, arrayType b) {
    int i;

    for (i=0; i<N; i++) {
        b[i] = a[i];
    }
}

void insertRandom(arrayType a) {
    int i, num;

    srand((unsigned) time(NULL));
    for (i=0; i<N; i++) {
        num = rand() % 70 + 1;
        if (uniqueCheck(a, num)) {
            (a)[i] = num;
        } else {
            i--;
        }
    }
}