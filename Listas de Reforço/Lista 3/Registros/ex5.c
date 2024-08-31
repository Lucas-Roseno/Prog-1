#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2
struct produtos
{
    int codigo;
    char descricao[50];
    float valor_uni;
    int quant_estoque;
};
typedef struct produtos modProdutos;

int main()
{
    struct produtos vet_gravacao[TAM], vet_leitura[TAM], vet_aux[1];
    FILE *arq;
    for (int i = 0; i < TAM; i++)
    {
        printf("Digite o código do produto: ");
        scanf("%d", &vet_gravacao[i].codigo);
        getchar();
        printf("Digite a descrição: ");
        fgets(vet_gravacao[i].descricao, 50, stdin);
        vet_gravacao[i].descricao[strlen(vet_gravacao[i].descricao) - 1] = '\0';

        printf("Digite o valor unitário: ");
        scanf("%f", &vet_gravacao[i].valor_uni);
        printf("Digite a quantidade em estoque do produto: ");
        scanf("%d", &vet_gravacao[i].quant_estoque);
        printf("\n");
    }

    // ordenando o vetor em ordem crescente
    for (int i = 0; i < TAM; i++)
    {
        for (int j = i + 1; j < TAM; j++)
        {
            if (vet_gravacao[i].codigo > vet_gravacao[j].codigo)
            {
                vet_aux[0] = vet_gravacao[i];
                vet_gravacao[i] = vet_gravacao[j];
                vet_gravacao[j] = vet_aux[0];
            }
        }
    }

    if (!(arq = fopen("ex5.dat", "wb")))
    {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }
    fwrite(vet_gravacao, sizeof(struct produtos), TAM, arq);
    fclose(arq);

    if (!(arq = fopen("ex5.dat", "rb")))
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    
    fread(vet_leitura, sizeof(struct produtos), TAM, arq);

    
    fclose(arq);
    return 0;
}