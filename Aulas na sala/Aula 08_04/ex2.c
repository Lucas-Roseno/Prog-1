# include <stdio.h>
int sequencia_fibonnaci (int num)
{
    if (num == 0)
    {
        return 0;
    }else if (num == 1)
    {
        return 1;
    }else
    {
        return sequencia_fibonnaci(num - 1) + sequencia_fibonnaci(num - 2);
    }
}

int main ()
{
    int num = 0;
    printf("Digite o número da seguência fibonnaci que deseja ver: ");
    scanf("%d", &num);

    printf("O número é %d", sequencia_fibonnaci(num));

    return 0;
}