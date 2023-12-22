#include "operation.h"
#include <stdio.h>
#include <stdlib.h>
long operation( long num1, long num2, char operator){
    switch(operator){
        case '+' :return num1 + num2;
        case '-' :return num1 - num2;
        case '*' :return num1 * num2;
        case '%' :
        if (num2 == 0){
            fprintf(stderr,"Ошибка: нельзя делить на ноль!\n");
            exit(EXIT_FAILURE);
        }
        else{
            return num1 % num2;
        }
        case '~': return (~num1);
        case '&':
        if (num1 >= 0 && num2 >= 0) {
            return (num1 & num2); 
        } 
        else {
        fprintf(stderr, "Ошибка: Для битовых операций требуется неотрицательное число.\n"); 
        exit(EXIT_FAILURE);
        }
        case '|':
        if (num1 >= 0 && num2 >= 0) {
        return (num1 | num2); 
        } 
        else {
        fprintf(stderr, "Ошибка: Для битовых операций требуется неотрицательное число.\n"); 
        exit(EXIT_FAILURE);
        }
        case '^':
        if (num1 >= 0 && num2 >= 0) {
            return (num1 ^ num2); 
        } 
        else {
        fprintf(stderr, "Ошибка: Для битовых операций требуется неотрицательное число.\n"); 
        exit(EXIT_FAILURE);
        }
    default:
    fprintf(stderr,"Ошибка: недопустимая операция!\n");
    exit(EXIT_FAILURE);
    }
}

