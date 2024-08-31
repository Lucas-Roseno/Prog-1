#include <stdio.h>
#include <stdlib.h>

#define num_habitantes 2
struct habitantes
{
    char sexo;
    float altura;
    int idade;
    char cor_olhos;
};
typedef struct habitantes modHabitantes;

int main()
{
    FILE *arq;
    struct habitantes vet_habitantes[num_habitantes];

    for (int i = 0; i < num_habitantes; i++)
    {
        printf("Digite o sexo [M/F]: ");
        scanf(" %c", &vet_habitantes[i].sexo);
        printf("Digite a altura: ");
        scanf("%f", &vet_habitantes[i].altura);
        printf("Digite a idade: ");
        scanf("%d", &vet_habitantes[i].idade);
        getchar();
        printf("Digite a cor dos olhos [A - azuis, V - verdes, C - castanhos]: ");
        scanf("%c", &vet_habitantes[i].cor_olhos);
    }

    arq = fopen("ex3_bin.dat", "wb");
    if (arq != NULL)
    {
        fwrite(vet_habitantes, sizeof(struct habitantes), num_habitantes, arq);
    }
    fclose(arq);

    arq = fopen("ex3_bin.dat", "rb");
    if (arq != NULL)
    {
        fread(vet_habitantes, sizeof(struct habitantes), num_habitantes, arq);
    }

    float media_idades = 0, cont_idade = 0;
    int maior_idade = 0, cont_mulher = 0, cont_homens = 0;
    for (int i = 0; i < num_habitantes; i++)
    {
        if (vet_habitantes[i].cor_olhos == 'c' && vet_habitantes[i].altura > 1.6)
        {
            media_idades += vet_habitantes[i].idade;
            cont_idade++;
        }

        if (i == 0)
        {
            maior_idade = vet_habitantes[i].idade;
        }
        else if (maior_idade < vet_habitantes[i].idade)
        {
            maior_idade = vet_habitantes[i].idade;
        }

        if ((vet_habitantes[i].sexo == 'f' && vet_habitantes[i].idade > 20 && vet_habitantes[i].idade < 45) ||
            (vet_habitantes[i].cor_olhos == 'v' && vet_habitantes[i].altura < 1.7))
        {
            cont_mulher++;
        }

        if (vet_habitantes[i].sexo == 'm')
        {
            cont_homens++;
        }
    }

    printf("\nA média da idade de pessoas com olhos castanhos e altura superior a 1.6m é %.0f.\n", media_idades / cont_idade);
    printf("A maior idade é %d.\n", maior_idade);
    printf("A quantidade de mulheres que tem idade entre 20 e 45, ou que tem olhos verdes e altura inferior a 1.70 é %d\n", cont_mulher);
    printf("O percentual de homens é de %.0f por cento.\n", ((float)cont_homens / 2) * 100);
    fclose(arq);

    return 0;
}