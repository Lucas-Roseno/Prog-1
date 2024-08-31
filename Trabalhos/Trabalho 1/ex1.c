// Exercício 1: Última Esperança Contra a Skynet
#include <stdio.h>
#include <stdlib.h>

#define linhas 7
#define colunas 9

void imprimir(char matriz[linhas][colunas])
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

int busca(char matriz[linhas][colunas], int lin, int col)
{
    // posição inválida
    if (lin < 0 || col < 0 || lin >= linhas || col >= colunas ||
        matriz[lin][col] == 'R' || matriz[lin][col] == '*' 
        || matriz[lin][col] == 'H')
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
        imprimir(matriz);
    }

    // direita - baixo - cima - esquerda
    if (busca(matriz, lin, col + 1) || busca(matriz, lin + 1, col) ||
        busca(matriz, lin - 1, col) || busca(matriz, lin, col - 1))
    {
        return 1;
    }

    if (matriz[lin][col] != 'H')
    {
        matriz[lin][col] = ' ';
        imprimir(matriz);
    }
    return 0;
}

void fuga_humana(char matriz[linhas][colunas])
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
    if (busca(matriz, lin, col + 1)|| busca(matriz, lin + 1, col)
        || busca(matriz, lin - 1, col) || busca(matriz, lin, col - 1))
    {
        printf("Caminho encontrado\n");
    }
    else
    {
        printf("Caminho não encontrado\n");
    }
    imprimir(matriz);
}

int main()
{
    char matriz[linhas][colunas] =
        {
            {'H', ' ', 'R', 'R', ' ', ' ', 'R', ' ', ' '},
            {' ', 'R', 'R', ' ', 'R', 'R', ' ', ' ', 'R'},
            {' ', 'R', ' ', 'R', ' ', 'R', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', 'R', ' ', ' ', 'R'},
            {' ', ' ', 'R', ' ', ' ', ' ', ' ', 'R', ' '},
            {' ', ' ', ' ', ' ', 'R', ' ', ' ', ' ', ' '},
            {'Z', ' ', 'R', ' ', ' ', ' ', 'R', ' ', ' '}};

    fuga_humana(matriz);
    return 0;
}
