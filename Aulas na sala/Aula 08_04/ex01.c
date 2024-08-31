# include <stdio.h>
int somatorio (int num)
{
    if (num == 1)
    {
        return 1;
    }else
    {
        return num + somatorio(num-1);
    }
}

int main ()
{
    int n = 0;
    printf("Digite um número inteiro: ");
    scanf("%d", &n);

    printf("O resultado = %d ", somatorio(n));
    return 0;
}

