#include <stdio.h>
#include "calculadora.h"
int main()
{
    int num1, num2;
    printf("Digite dois números: ");
    scanf("%d %d", &num1, &num2);
    printf("Soma: %d\n", soma(num1, num2));
    printf("Subtração: %d\n", subtracao(num1, num2));
    printf("Multiplicação: %d\n", multiplicacao(num1, num2));
    printf("Divisão: %.2f\n", divisao(num1, num2));
    return 0;
}