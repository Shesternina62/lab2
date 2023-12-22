#include "read_number.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
long readNumber(const char* str, int* base){
    long result = 0;
    int i = 0;
    bool isNeg = false;
    if (str[i]== '-'){
        isNeg = true;
        i++;
    }
    if (str[i] == '0' && (str[i+1] == 'x'|| str[i+1] == 'X')){
        *base = 16;
        i += 2;
    }
    else if(str[i] == '0'){
        *base = 8;
        i++;
    }
    else{
        *base = 2;
    }
    for (; str[i] != '\0'; i++){
        if (*base == 2 && (str[i] != '0' && str[i] != '1')) {
            fprintf(stderr, "Ошибка: недопустимое число. В двоичной системе счисления допустимы значения 0 и 1\n");
            exit(EXIT_FAILURE);
        }
        if (*base == 8 && (str[i] < '0' || str[i] > '7')) {
            fprintf(stderr, "Ошибка: недопустимое число.В восьмиричной системе счисления допустимы значения от 0 до 7\n");
            exit(EXIT_FAILURE);
        }
        if (*base == 16 && !((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F'))) {
            fprintf(stderr, "Ошибка: недопустимое число. В шестнадцаричной системе счисления допутимы значения от 0 до 9 и от A до F\n");
            exit(EXIT_FAILURE);
        }
        result *= *base;
        if (str[i] >= '0' && str[i] <= '9') {
            result += str[i] - '0';
        }
        else if (*base == 16 && ((str[i] >= 'A' && str[i] <= 'F') || (str[i] >= 'a' && str[i] <= 'f'))) {
            result += (str[i] >= 'a') ? (10 + str[i] - 'a') : (10 + str[i] - 'A');
        }
        else {
            break;
        }
    }

    return isNeg ? -result : result;
}