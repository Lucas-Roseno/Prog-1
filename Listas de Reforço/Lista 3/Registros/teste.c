#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int soma_num(int n)
{
    int cont;
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return 1 + soma_num(n / 10);
    }
}

int main()
{
    int num = 0;
    printf("Digite um número: ");
    scanf("%d", &num);
    printf("O número é %d\n", soma_num(num));

    return 0;
}