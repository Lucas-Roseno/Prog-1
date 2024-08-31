# include <stdio.h>
int calculo_potencia (int base, int expoente)
{
    if (expoente == 0)
    {
        return 1;
    }else if (expoente == 1)
    {
        return base;
    }else
    {
        return base * calculo_potencia(base, expoente -1);
    }
    
}

int main ()
{
    int base = 0, expoente = 0;
    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o expoente: ");
    scanf("%d", &expoente);
    
    printf("%d elevado a %d = %d\n", base, expoente, calculo_potencia(base, expoente));

    return 0;
}