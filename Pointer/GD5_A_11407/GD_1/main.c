#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x;
    int *pointerX;

    printf("\nMasukkan value untuk variabel X: "); scanf("%d", &x);
    pointerX = &x;

    printf("\nAlamat dari variabel X adalah: %d dan valuenya: %d", pointerX, *pointerX);

    return 0;
}

