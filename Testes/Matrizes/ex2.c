#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define linhas 3
#define colunas 3

int main()
{
    int notas[linhas][colunas] = {0};
    char nome_alunos[3][20] = {""};

    for (int i = 0; i < linhas; i++)
    {
        printf("\nDigite o nome do aluno %d: ", i + 1);
        fgets(nome_alunos[i], 15, stdin);
        nome_alunos[i][strlen(nome_alunos[i]) - 1] = '\0';
        for (int j = 0; j < colunas; j++)
        {
            printf("Digite a nota: ");
            scanf("%d", &notas[i][j]);
            getchar();//limpando o buffer para o fgets
        }
        printf("\n");
    }

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d\t", notas[i][j]);
        }
        printf("\n");
    }

    return 0;
}