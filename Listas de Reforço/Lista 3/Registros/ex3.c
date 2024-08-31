#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    char sexo = ' ', cor_olhos = ' ';
    int idade = 0;
    float altura = 0;
    FILE *arq;

    if (!(arq = fopen("arq_ex3", "w+")))
    {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    for (int i = 0; i < 2; i++)
    {
        printf("Digite o sexo [M/F], do habitante %d: ", i + 1);
        scanf("  %c", &sexo);
        sexo = toupper(sexo);
        printf("Digite altura: ");
        scanf("%f", &altura);
        printf("Digite a idade: ");
        scanf("%d", &idade);
        printf("Digite a cor dos olhos[A - azuis, V - verdes, C - castanhos]: ");
        scanf(" %c", &cor_olhos);
        cor_olhos = toupper(cor_olhos);
        printf("\n");

        fprintf(arq, "%c\n%f\n%d\n%c\n", sexo, altura, idade, cor_olhos);
    }

    rewind(arq);

    float soma_idades = 0, cont_idade = 0;
    int maior_idade = 0, cont_loop = 0, cont_mulheres = 0;
    float cont_homens = 0;
    while (fscanf(arq, "%c\n%f\n%d\n%c\n", &sexo, &altura, &idade, &cor_olhos) == 4)
    {
        if (altura > 1.6 && cor_olhos == 'C')
        {
            soma_idades += idade;
            cont_idade++;
        }

        if (cont_loop == 0)
        {
            maior_idade = idade;
        }
        else if (maior_idade < idade)
        {
            maior_idade = idade;
        }

        if ((sexo == 'F' && idade > 20 && idade < 45) || (cor_olhos == 'V' && altura < 1.7))
        {
            cont_mulheres++;
        }
        
        if (sexo == 'M')
        {
            cont_homens++;
        }
        

        cont_loop++;
    }

    printf("Média das idades dos habitante com mais de 1.6m e olhos castanhos é: %.2f", soma_idades / cont_idade);
    printf("\nA maior idade é: %d", maior_idade);
    printf("\nA quantidade de mulheres que tem idade entre 20 e 45 ou que tem olhos verdes e altura inferior "
            "a 1.7m é %d", cont_mulheres);
    printf("\nO percentual de homens é %.0f por cento.\n", (cont_homens/(float)2) * (float)100);
    fclose(arq);
    return 0;
}