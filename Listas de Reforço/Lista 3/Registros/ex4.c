#include <stdio.h>
#include <stdlib.h>

#define TAM 2

int main () 
{
    int idade = 0, num_filhos = 0;
    char sexo = ' ';
    float renda_familiar = 0;
    FILE *arq;

    if (!(arq = fopen("arq_ex4", "w+")))
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    

    for (int i = 0; i < TAM; i++)
    {
        printf("Digite a idade: ");
        scanf(" %d", &idade);

        printf("Digite o sexo [M/F]: ");
        scanf("  %c", &sexo);

        printf("Digite a renda familiar: ");
        scanf("%f", &renda_familiar);

        printf("Digite o número de filhos: ");
        scanf("%d", &num_filhos);

        fprintf(arq, "%d %c %f %d \n", idade, sexo, renda_familiar, num_filhos);
        printf("\n");
    }

    rewind(arq);
    float soma_salarios = 0;
    int maior_idade = 0, menor_idade = 0, cont_idade = 0, cont_mulheres = 0;
    while (fscanf(arq, "%d %c %f %d \n", &idade, &sexo, &renda_familiar, &num_filhos) == 4)
    {
        soma_salarios += renda_familiar;   
        if (cont_idade == 0)
        {
            maior_idade = idade;
            menor_idade = idade;
        }
        if (maior_idade < idade)
        {
            maior_idade = idade;
        }
        if (menor_idade > idade)
        {
            menor_idade = idade;
        }
        if (sexo == 'f' && num_filhos > 2 && renda_familiar < 600)
        {
            cont_mulheres++;
        }
        cont_idade++;
    }
    
    printf("A média dos salários é R$%.2f\n", soma_salarios / (float)2);
    printf("A maoir idade é %d e a menor %d\n", maior_idade, menor_idade);
    printf("A quantidade de mulheres com mais de dois filhos e renda familiar inferior a 600 é %d\n", cont_mulheres);

    fclose(arq);
    return 0;
}