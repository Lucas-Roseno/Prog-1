#include <stdio.h>
#include <stdlib.h>

void imprimir(char **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("[%c]", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int busca(char **matriz, int lin, int col, int linhas, int colunas)
{
    // Posição inválida
    if (lin < 0 || col < 0 || lin >= linhas || col >= colunas ||
        matriz[lin][col] == 'R' || matriz[lin][col] == '*' || matriz[lin][col] == 'H')
    {
        return 0;
    }

    if (matriz[lin][col] == 'Z')
    {
        return 1;
    }

    if (matriz[lin][col] != 'H')
    {
        matriz[lin][col] = '*';
    }

    // Direita - baixo - cima - esquerda
    if (busca(matriz, lin, col + 1, linhas, colunas) ||
        busca(matriz, lin + 1, col, linhas, colunas) ||
        busca(matriz, lin - 1, col, linhas, colunas) ||
        busca(matriz, lin, col - 1, linhas, colunas))
    {
        return 1;
    }

    if (matriz[lin][col] != 'H')
    {
        matriz[lin][col] = ' ';
    }
    return 0;
}

void fuga_humana(char **matriz, int linhas, int colunas)
{
    int lin = -1, col = -1;

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (matriz[i][j] == 'H')
            {
                lin = i;
                col = j;
                break;
            }
        }
        if (lin != -1 && col != -1)
        {
            break;
        }
    }

    if (lin == -1 || col == -1)
    {
        printf("Humano não encontrado no mapa\n");
        return;
    }

    if (busca(matriz, lin, col + 1, linhas, colunas) ||
        busca(matriz, lin + 1, col, linhas, colunas) ||
        busca(matriz, lin - 1, col, linhas, colunas) ||
        busca(matriz, lin, col - 1, linhas, colunas))
    {
        printf("Caminho encontrado\n");
    }
    else
    {
        printf("Caminho não encontrado\n");
    }
    imprimir(matriz, linhas, colunas);
}

int main()
{
    FILE *arquivo;
    char **matriz;
    int linhas, colunas;

    // Abrir o arquivo para leitura
    arquivo = fopen("matriz.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Loop para ler todas as matrizes
    while (fscanf(arquivo, "%d %d", &linhas, &colunas) == 2)
    {
        // Alocar memória para a matriz
        matriz = (char **)malloc(linhas * sizeof(char *));
        if (matriz == NULL)
        {
            printf("Erro ao alocar memória para a matriz!\n");
            fclose(arquivo);
            return 1;
        }

        for (int i = 0; i < linhas; i++)
        {
            matriz[i] = (char *)malloc(colunas * sizeof(char));
            if (matriz[i] == NULL)
            {
                printf("Erro ao alocar memória para a matriz!\n");
                for (int j = 0; j < i; j++)
                {
                    free(matriz[j]);
                }
                free(matriz);
                fclose(arquivo);
                return 1;
            }
        }

        // Ler a matriz do arquivo
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                fscanf(arquivo, " %c ", &matriz[i][j]);
            }
        }

        // Chamar a função fuga_humana
        fuga_humana(matriz, linhas, colunas);

        // Liberar a memória alocada
        for (int i = 0; i < linhas; i++)
        {
            free(matriz[i]);
        }
        free(matriz);
    }

    fclose(arquivo);

    return 0;
}
