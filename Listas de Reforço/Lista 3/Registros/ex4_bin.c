#include <stdio.h>
#include <stdlib.h>

#define TAM 2

struct habitantes
{
    int idade;
    char sexo;
    float renda_familiar;
    int num_filhos;
};
typedef struct habitantes modHabitantes;

int main()
{
    FILE *arq;
    struct habitantes vet_habitantes[TAM], vet2[TAM]; 

    for (int i = 0; i < TAM; i++)
    {
        printf("Digite a idade: ");
        scanf("%d", &vet_habitantes[i].idade);
        getchar();
        printf("Digite o sexo [M/F]: ");
        scanf("%c", &vet_habitantes[i].sexo);
        printf("Digite a renda familiar: ");
        scanf("%f", &vet_habitantes[i].renda_familiar);
        printf("Digite o número de filhos: ");
        scanf("%d", &vet_habitantes[i].num_filhos);
        printf("\n");
    }

    if (!(arq = fopen("ex4_bin.dat", "wb")))
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    fwrite(vet_habitantes, sizeof(struct habitantes), TAM, arq);
    fclose(arq);

    if (!(arq = fopen("ex4_bin.dat", "rb")))
    {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    fread(vet2, sizeof(struct habitantes), TAM, arq);

    float media_salarios = 0;
    int menor_idade = 0, cont_mulheres = 0;
    for (int i = 0; i < TAM; i++)
    {
        media_salarios += vet2[i].renda_familiar;

        if (i == 0)
        {
            menor_idade = vet2[i].idade;
        }
        else if (menor_idade > vet2[i].idade)
        {
            menor_idade = vet2[i].idade;
        }

        if (vet2[i].num_filhos > 2 && vet2[i].renda_familiar < 600 && vet_habitantes[i].sexo == 'f')
        {
            cont_mulheres++;
        }
    }
    fclose(arq);

    printf("\nA média dos salários é de R$%.2f\n", media_salarios / TAM);
    printf("A menor idade é %d.\n", menor_idade);
    printf("A quantidade de mulheres com mais de dois filhos e renda familiar inferior a R$600.00 é %d\n.", cont_mulheres);

    return 0;
}