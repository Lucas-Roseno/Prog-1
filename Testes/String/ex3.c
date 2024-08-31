#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cargo[30] = "";
    float salario = 0, novo_salario = 0;

    printf("Digite o cargo do funcionário: ");
    fgets(cargo, 30, stdin);
    cargo[strlen(cargo) - 1] = '\0';

    printf("Digite o salário: ");
    scanf(" %f", &salario);

    if (strcmp(cargo, "gerente") == 0)
    {
        novo_salario = salario * 1.1;
    }else if (strcmp(cargo, "engenheiro") == 0)
    {
        novo_salario = salario * 1.2;
    }else if (strcmp(cargo, "tecnico") == 0)
    {
        novo_salario = salario * 1.3;
    }else
    {
        novo_salario = salario * 1.4;
    }

    printf("\nSalário antigo: R$%.2f\nNovo salário: R$%.2f\nDiferença entre os salários: R$%.2f\n", salario,
           novo_salario, novo_salario - salario);

    return 0;
}