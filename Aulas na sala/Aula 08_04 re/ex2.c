/*
Escreva um programa em C que calcule a soma dos primeiros n números
naturais de forma recursiva:
*/
#include <stdio.h>
int somatorio (int num)
{
    if(num == 0)
    {
        return 0;
    }else
    {
        return num + somatorio(num -1);
    }
}
int main ()
{
    int num = 0;
    printf("Digite um número: ");
    scanf("%d", &num);
    printf("O somatório dos primeiros número é igual a %d\n", somatorio(num));
}