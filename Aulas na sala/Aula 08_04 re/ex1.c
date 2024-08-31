#include <stdio.h>
int calculo_fatorial (int num)
{
    if(num == 1)
    {
        return 1;
    }else
    {
        return num * calculo_fatorial(num - 1);
    }
}

int main () 
{
    int num = 0;
    printf("Digite um valor: ");
    scanf("%d", &num);
    printf("O fatorial de %d é %d\n", num, calculo_fatorial(num));
    return 0;
}