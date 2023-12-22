#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "read_number.h"
#include "print_number.h"
#include "operation.h"

int main(){
    char input[100];
    char operand1[50], operand2[50], operator;
    int base1, base2;
    printf("Введите выражение:\n");
    fgets(input, 100, stdin);
    bool isUnary = strchr(input, '~') != NULL;
    if (isUnary){
        if (sscanf(input, "~%s", operand1) != 1 || strlen(operand1) == 0){
            fprintf(stderr, "Ошибка:операнд отсутствует\n");
            return EXIT_FAILURE;
        }
        operator = '~';
    }
    else{
        sscanf(input," %s %c %s", operand1, &operator, operand2);
    }
    if ((strlen(operand1)==0) || (strlen(operand2) == 0 && operator != '~')){
        fprintf(stderr, "Ошибка: один из операндов отсутствует\n");
        return EXIT_FAILURE;
    }
    long num1 = readNumber(operand1, &base1);
    long num2 = 0;
    if (!isUnary){
        num2 = readNumber(operand2, &base2);
        if (base1 != base2){
            fprintf(stderr, "Ошибка: системы счисления не совпадают\n");
            return EXIT_FAILURE;
        }
    }
    if (operator == '&' || operator == '|' || operator == '^'){
        if (num1 < 0 || num2 < 0){
            fprintf(stderr, "Ошибка: побитовые операции допустимы только для положительных чисел\n");
            return EXIT_FAILURE;
        }
    }
    long result = operation(num1, num2, operator);
    printNumberInBase(result, base1);
    printf(" (%ld)\n", result);
    return 0;
}
