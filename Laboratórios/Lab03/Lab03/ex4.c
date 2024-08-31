#include <stdio.h>
#include <stdlib.h>

int main()
{
    long cnpj = 0;
    int soma_produtos = 0, resultado = 0, dezena_verf = 0, unidade_verf = 0;
    int vet_cnpj1[12] = {2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5};
    int vet_cnpj2[12] = {3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 5, 6};
    printf("Digite os 12 primeiros dígitos do CNPJ: ");
    scanf("%ld", &cnpj);

    long cnpj_calulo1 = cnpj;

    //dezena do digito verificador
    for (int i = 0; i <= 11; i++)
    {
        resultado = (cnpj_calulo1 % 10) * vet_cnpj1[i];
        cnpj_calulo1 = cnpj_calulo1 / 10;
        soma_produtos += resultado;
    }

    if (soma_produtos % 11 < 2)
    {
        dezena_verf = 0;
    }
    else
    {
        dezena_verf = 11 - (soma_produtos % 11);
    }

    //unidade do dígito verificador
    cnpj_calulo1 = cnpj;
    soma_produtos = dezena_verf * 2;
    for (int i = 0; i <= 11; i++)
    {
        resultado = (cnpj_calulo1 % 10) * vet_cnpj2[i];
        cnpj_calulo1 = cnpj_calulo1 / 10;
        soma_produtos += resultado;
    }

    if (soma_produtos % 11 < 2)
    {
        unidade_verf = 0;
    }
    else
    {
        unidade_verf = 11 - (soma_produtos % 11);
    }

    printf("Primeiro dígito verificador: %d\nSegundo dígito verificador %d\n", dezena_verf, unidade_verf);
}