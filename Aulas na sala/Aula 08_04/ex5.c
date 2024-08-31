# include <stdio.h>
int calculo_digitos (int num)
{
    if (num == 0)
    {
        return 0;
    }else
    {
        return 1 + calculo_digitos(num/10);
    }
}

int main ()
{
    int num = 0;
    printf("Digite um número: ");
    scanf("%d", &num);
    printf("O número %d tem %d dígitos.\n",num, calculo_digitos(num));
    return 0;
}