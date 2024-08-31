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
    int cont_linhas = 0;
    char nome_arquivo[30] = {""}, frase[TAM] = {""}, palavra_busca[30] = "";
    FILE *arq;

    printf("Digite o nome do arquivo de texto para salvar os dados: ");
    fgets(nome_arquivo, 30, stdin);
    nome_arquivo[strlen(nome_arquivo) - 1] = '\0';

    arq = fopen(nome_arquivo, "w");
    if (!arq)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    do
    {
        printf("Digite uma frase ['FIM' para encerrar]: ");
        fgets(frase, 100, stdin);
        string_maiusculo(frase);

        if (strcmp(frase, "FIM\n"))
        {
            fputs(frase, arq);
            cont_linhas++;
        }
    } while (strcmp(frase, "FIM\n") && cont_linhas != 20);
    fclose(arq);

    arq = fopen(nome_arquivo, "r");
    if (!arq)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    // declaração da matriz
    char **matriz_frases;
    matriz_frases = (char **)malloc(cont_linhas * sizeof(char *));
    if (matriz_frases == NULL)
    {
        printf("Memória insuficiente.\n");
        exit(1);
    }
    for (int i = 0; i < cont_linhas; i++)
    {
        matriz_frases[i] = (char *)malloc(TAM * sizeof(char));
        if (matriz_frases[i] == NULL)
        {
            printf("Memória insuficiente.\n");
            exit(1);
        }
    }
    int i = 0;
    while (fgets(frase, TAM, arq) != NULL)
    {
        matriz_frases[i] = (char *)malloc((strlen(frase) + 1) * sizeof(char));
        if (matriz_frases[i] == NULL)
        {
            printf("Memória insuficiente.\n");
            exit(1);
        }
        strcpy(matriz_frases[i], frase);
        i++;
    }

    printf("\nDigite uma palavra para fazer a busca na matriz: ");
    fgets(palavra_busca, 30, stdin);
    palavra_busca[strlen(palavra_busca) - 1] = '\0';
    string_maiusculo(palavra_busca);

    for (int i = 0; i < cont_linhas; i++)
    {
        for (int j = 0; j < strlen(matriz_frases[i]); j++)
        {
            if (strncmp(&matriz_frases[i][j], palavra_busca, strlen(palavra_busca)) == 0)
            {
                printf("\nLinha %d - %s", i + 1, matriz_frases[i]);
                break;
            }
        }
    }

    for (int i = 0; i < cont_linhas; i++)
    {
        free(matriz_frases[i]);
    }
    free(matriz_frases);

    fclose(arq);
    return 0;
}