#include "header.h"

int isFull(Video V[]) {
	int i;
	
	for (i=0; i<5; i++) {
		if (strcmpi(V[i].judul, "-") == 0) {
			return i;
		}
	}
	return -1;
}

int isEmpty(Video V[]) {
	int i;
	
	for (i=0; i<N; i++) {
		if (strcmpi(V[i].judul, "-") != 0) {
			return i;
		}
	}
	return -1;
}

void createEmpty(Video V[]) {
    int i;

    for (i=0; i<N; i++) {
    	strcpy(V[i].judul, "-");
    	V[i].view = 0;
    }
}

void bubbleSort(Video V[]) {
    Video v;
    int i, j;

    for (i=0; i<N; i++) {
        for (j=i+1; j<N; j++) {
            if ((V)[i].view > (V)[j].view) {
                v = V[i];
                V[i] = V[j];
                V[j] = v;
            }
        }
    }
}

void bubbleSortJudul(Video V[]) {
    Video v;
    int i, j;

    for (i=0; i<N; i++) {
        for (j=i+1; j<N; j++) {
            if (strcmpi((V)[i].judul, (V)[j].judul) > 0) {
                v = V[i];
                V[i] = V[j];
                V[j] = v;
            }
        }
    }
}

int binarySearch(Video V[], int left, int right, int find) {
    if (right >= left) {
        int mid = (left + right)/2;
        if (find == V[mid].view) {
            return mid;
        }
        if (find < V[mid].view) {
            return binarySearch(V, left, mid-1, find);
        }
        return binarySearch(V, mid+1, right, find);
    }
    return -1;
}

int binarySearchJudul(Video V[], int left, int right, string carijd) {
    if (right >= left) {
        int mid = (left + right)/2;
        if (strcmp(carijd, V[mid].judul) == 0) {
            return mid;
        }
        if (strcmp(carijd, V[mid].judul) < 0) {
            return binarySearchJudul(V, left, mid-1, carijd);
        }
        return binarySearchJudul(V, mid+1, right, carijd);
    }
    return -1;
}

int sequentialSearch(char randomAlphabet[], char cari) {
    int i;
    
    for (i=0; i<10; i++) {
        if (randomAlphabet[i] == cari) {
            return i;
        }
    }
    return -1;
}

void printArray(Video V[]) {
    int i;

    for (i=0; i<N; i++) {
		printf("\n\t| %s - %d |", V[i].judul, V[i].view);
	}
}

bool uniqueCheckVideo(Video V[], string judul) {
    int i;

    for (i=0; i<N; i++) {
        if (strcmpi(V[i].judul, judul) == 0) {
            return false;
        }
    }
    return true;
}

bool uniqueCheckView(Video V[], int view) {
    int i;

    for (i=0; i<N; i++) {
        if(V[i].view == view) {
            return false;
        }
    }
    return true;
}

int uniqueCheckAplhabet(char randomAlphabet[], char randomNumber) {
    int i;

    for (i=0; i<10; i++) {
        if (randomAlphabet[i] == randomNumber) {
            return 0;
        }
    }
    return 1;
}

// void insertRandomAlphabet(char randomAlphabet[]) {
//     char randAlpha[10], alpha;
// 	int counter = 0, randomNumber = 0;
// 	srand(time(NULL));

// 	for (counter = 0; counter < 10; counter++) {
// 		randomNumber = 26 * (rand() / (RAND_MAX + 1.0));

// 		randomNumber += 65;
// 		alpha = (char) randomNumber;

//         if (uniqueCheckAplhabet(randomAlphabet, alpha)) {
//             randomAlphabet[counter] = alpha;
//         } else {
//             counter--;
//         }
// 	}
// }

void insertRandomAlphabet(char randomAlphabet[]) {
    char alphabet[] = {'A', 'B', 'C', 'D', 'E',
					   'F', 'G', 'H', 'I', 'J',
					   'K', 'L', 'M', 'N', 'O',
					   'P', 'Q', 'R', 'S', 'T',
					   'U', 'V', 'W', 'X', 'Y',
					   'Z'};
    char alpha;
	int counter = 0, randomNumber = 0;
	srand(time(NULL));

	for (counter = 0; counter < 10; counter++) {
        alpha = alphabet[rand() % 26];

        if (uniqueCheckAplhabet(randomAlphabet, alpha) && alpha != 'A' && alpha != 'I' && alpha != 'U' && alpha != 'E' && alpha != 'O') {
            randomAlphabet[counter] = alpha;
        } else {
            counter--;
        }
	}
}

void insertRandomView(Video V[]) {
    int num, i;

    for (i=0; i<N; i++) {
        num = rand() % 1000 + 1;
        if (uniqueCheckView(V, num)) {
            V[i].view = num;
        } else {
            i--;
        }
    }
}
