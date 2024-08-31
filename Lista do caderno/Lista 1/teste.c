#include <stdio.h>
//função que soma 10 ao valor recebido
void soma10(int x)
{
    x = x + 10;
    printf("X dentro da função por valor = %d \n",x);
    return;
}
void soma10p(int *x)
{
    *x = *x + 10;
    printf("X dentro da função por referência = %d \n",*x);
    return;
}
int main(void)
{
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    printf("O numero digitado foi: %d \n",numero);
    soma10(numero); //chamada da função
    printf("Valor do número após soma10: %d \n",numero);
    soma10p(&numero); //chamada da função por referência
    printf("Valor do número após soma10p: %d \n",numero);
    return 0;
}