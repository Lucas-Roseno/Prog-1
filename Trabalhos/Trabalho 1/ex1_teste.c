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
    // posição inválida
    if (lin < 0 || col < 0 || lin >= linhas || col >= colunas ||
        matriz[lin][col] == 'R' || matriz[lin][col] == '*' || matriz[lin][col] == 'H')
    {
        return 0;
    }

    if (matriz[lin][col] == 'Z')
    {
        return 1;
    }
    if (matriz[lin + 1][col] == 'Z' && lin < linhas)
    {
        matriz[lin][col] = '*';
        return 1;
    }

    if (matriz[lin][col] != 'H')
    {
        matriz[lin][col] = '*';
        // imprimir(matriz);
    }

    // direita - baixo - cima - esquerda
    if (busca(matriz, lin, col + 1, linhas, colunas) || busca(matriz, lin + 1, col, linhas, colunas) ||
        busca(matriz, lin - 1, col, linhas, colunas) || busca(matriz, lin, col - 1, linhas, colunas))
    {
        return 1;
    }

    if (matriz[lin][col] != 'H')
    {
        matriz[lin][col] = ' ';
        // imprimir(matriz);
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

    // direita - baixo - cima - esquerda
    if (busca(matriz, lin, col + 1, linhas, colunas) || busca(matriz, lin + 1, col, linhas, colunas) || busca(matriz, lin - 1, col, linhas, colunas) || busca(matriz, lin, col - 1, linhas, colunas))
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
    arquivo = fopen("matriz.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    while (!feof(arquivo))
    {
        int linhas = 0, colunas = 0;
        char **matriz;

        // Ler o número de linhas e colunas
        fscanf(arquivo, "%d %d", &linhas, &colunas);

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
        }

        // Ler a matriz do arquivo
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                fscanf(arquivo, " %c", &matriz[i][j]);
            }
        }

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