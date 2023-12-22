#include "print_number.h"
#include <stdio.h>

void printNumberInBase(long num, int base) {
    if (num < 0 && base != 2){
        printf("-");
        num = -num;
    }
    if (base == 16){
        printf("0x%lx", num);
    }
    else if (base == 8){
        printf("0%lo", num);
    }
    else if (base == 2) {
        char bin[65];
        long n;
        if (num < 0) {
            n = -num;
        }
        else {
            n = num;
        }
        int i = 0;
        while (n > 0) {
            bin[i++] = (n % 2) + '0';
            n /= 2;
        }
        if (i == 0) {
            printf("0");
        }
        else {
            if (num < 0) {
                printf("-");
            }
            for (int j = i - 1; j >= 0; j--) {
                printf("%c", bin[j]);
            }
        }
    }
    else{
        printf("%ld", num);
    }
}