#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

uint32_t deci_help(char* bina, uint32_t num) {
    if(*bina == '\0') return num;
    assert(*bina == '0' || *bina == '1');
    return deci_help(bina+1, 2*num + (*bina - '0'));
}

uint32_t deci(char* bina) {
    return deci_help(bina, 0);
}

int main() {
    char bina[33];
    printf("Enter the Binary number:");
    scanf("%32s", bina);
    printf("The decimal is %"PRIu32, deci(bina));
    return 0;
}