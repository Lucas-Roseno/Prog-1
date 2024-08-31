#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq;
    int idade = 0, num_filhos = 0, cont_medias = 0, soma_filhos = 0, mais_dezmil = 0;
    float salario = 0, soma_salarios = 0, maior_salario = 0;
    arq = fopen("arq_ex2", "w");
    for (int i = 0; i < 2; i++)
    {
        printf("Digite o salário: ");
        scanf("%f", &salario);
        fprintf(arq, "%f\n", salario);

        printf("Digite a idade: ");
        scanf("%d", &idade);
        fprintf(arq, "%d\n", idade);

        printf("Digite o número de filhos: ");
        scanf("%d", &num_filhos);
        fprintf(arq, "%d\n", num_filhos);

        fprintf(arq, "\n");
        printf("\n");
    }
    fclose(arq);

    if (!(arq = fopen("arq_ex2", "r")))
    {
        printf("Erro na arbetura do código!");
        exit(1);
    }
    while (fscanf(arq, "%f\n%d\n%d\n", &salario, &idade, &num_filhos) == 3)
    {
        soma_salarios += salario;
        soma_filhos += num_filhos;
        if (cont_medias == 0)
        {
            maior_salario = salario;
        }
        else if (maior_salario < salario)
        {
            maior_salario = salario;
        }
        if (salario > 10000)
        {
            mais_dezmil++;
        }
        cont_medias++;
    }
    printf("A média dos salários: %.2f\n", soma_salarios / (float)cont_medias);
    printf("A média do número de filhos é: %.2f\n", (float)soma_filhos / (float)cont_medias);
    printf("O maior salário é: R$%.2f\n", maior_salario);
    printf("O número de mulheres com salário superior a dez mil: %d\n", mais_dezmil);

    fclose(arq);
    return 0;
}