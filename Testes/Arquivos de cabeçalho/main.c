#include <stdio.h>
#include "matematica.h"
int main()
{
    int num;
    printf("Digite um número para calcular o fatorial: ");
    scanf("%d", &num);
    printf("O fatorial de %d é: %d\n", num, fatorial(num));
    printf("Digite um número para calcular a sequência de Fibonacci: ");
    scanf("%d", &num);
    printf("A sequência de Fibonacci até %d termos é:\n", num);
    for (int i = 0; i < num; i++)
    {
        printf("%d ", fibonacci(i));
    }
    return 0;
}