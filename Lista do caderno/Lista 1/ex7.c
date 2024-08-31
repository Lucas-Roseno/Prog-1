/*
7. Escreva um programa em C que calcule a potência de um número de forma
recursiva. O programa deve possuir uma função com a assinatura int potencia(int
x, int n) que retorna a x elevado a n.
*/
#include <stdio.h>
int potencia(int base, int expoente)
{
    if (expoente == 1)
    {
        return base;
    } else
    {
        return base * potencia(base, expoente - 1);
    }
}

int main () 
{
    int base = 0, expoente = 0;
    printf("Digite o valor da base: ");
    scanf("%d", &base);
    printf("Digite o valor do expoente: ");
    scanf("%d", &expoente);
    printf("%d elevado a %d = %d\n", base, expoente, potencia(base, expoente));

    return 0;
}