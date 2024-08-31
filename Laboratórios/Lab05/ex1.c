#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100
void string_maiusculo(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        string[i] = toupper(string[i]);
    }
}

int main()
{
    char nome_arquivo[30] = {""}, nome_aluno[TAM] = {""};
    FILE *arq;

    printf("Digite o nome do arquivo para salvar os dados: ");
    fgets(nome_arquivo, 20, stdin);
    nome_arquivo[strlen(nome_arquivo) - 1] = '\0';

    arq = fopen(nome_arquivo, "w+");
    if (!arq)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    do
    {
        printf("Digite o nome do aluno ['sair' para encerrar]: ");
        fgets(nome_aluno, 50, stdin);

        if (strcmp(nome_aluno, "sair\n"))
        {
            fputs(nome_aluno, arq);
        }
    } while (strcmp(nome_aluno, "sair\n"));

    rewind(arq);

    FILE *arq_maiusculo;
    strcat(nome_arquivo, "_MAIUSCULO");
    arq_maiusculo = fopen(nome_arquivo, "w+");
    
    printf("Lendo o arquivo:\n");
    while (fgets(nome_aluno, 100, arq) != NULL)
    {
        string_maiusculo(nome_aluno);
        fputs(nome_aluno, arq_maiusculo);   
        printf("%s", nome_aluno);
    }

    fclose(arq);
    fclose(arq_maiusculo);

    return 0;
}