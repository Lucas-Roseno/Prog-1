#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cpf = 0, soma_produtos = 0, resultado = 0, dezena_verf = 0, unidade_verf = 0;

    printf("Digite os 9 primeiros dígitos do CPF: ");
    scanf("%d", &cpf);

    int cpf_calulo1 = cpf;

    for (int i = 2; i <= 10; i++)
    {
        resultado = (cpf_calulo1 % 10) * i;
        cpf_calulo1 = cpf_calulo1 / 10;
        soma_produtos += resultado;
    }

    if (soma_produtos % 11 == 0 || soma_produtos % 11 == 1)
    {
        dezena_verf = 0;
    }
    else
    {
        dezena_verf = 11 - (soma_produtos % 11);
    }

    soma_produtos = 0;
    for (int i = 3; i <= 11; i++)
    {
        resultado = (cpf % 10) * i;
        cpf = cpf / 10;
        soma_produtos += resultado;
    }
    soma_produtos += dezena_verf * 2;

    if (soma_produtos % 11 == 0 || soma_produtos % 11 == 1)
    {
        unidade_verf = 0;
    }
    else
    {
        unidade_verf = 11 - (soma_produtos % 11);
    }

    printf("\nDezena do dígito verificador: %d\nUnidade do dígito verificador: %d\n", dezena_verf, unidade_verf);

    return 0;
}