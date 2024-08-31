#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linha1 = 0, linha2 = 0, coluna1 = 0, coluna2 = 0;
    printf("Número de linhas da primeira matriz: ");
    scanf("%d", &linha1);
    printf("Número de colunas da primeira matriz: ");
    scanf("%d", &coluna1);

    printf("\nNúmero de linhas da segunda matriz: ");
    scanf("%d", &linha2);
    printf("Número de colunas da segunda matriz: ");
    scanf("%d", &coluna2);

    if (coluna1 == linha2)
    {
        // declarando matriz1
        int **matriz1 = (int **)malloc(linha1 * sizeof(int *));
        if (matriz1 == NULL)
        {
            printf("Memoria insuficiente.\n");
            exit(1);
        }

        for (int i = 0; i < linha1; i++)
        {
            matriz1[i] = (int *)malloc(coluna1 * sizeof(int));
            if (matriz1[i] == NULL)
            {
                printf("Memoria insuficiente.\n");
                exit(1);
            }
        }
        // lendo matriz 1
        printf("\n");
        for (int i = 0; i < linha1; i++)
        {
            for (int j = 0; j < coluna1; j++)
            {
                printf("Digite o elemento %d da linha %d, da primeira matriz: ", j + 1, i + 1);
                scanf("%d", &matriz1[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < linha1; i++)
        {
            for (int j = 0; j < coluna1; j++)
            {
                printf("%d\t", matriz1[i][j]);
            }
            printf("\n");
        }

        // declarando matriz2
        int **matriz2 = (int **)malloc(linha2 * sizeof(int *));
        if (matriz2 == NULL)
        {
            printf("Memoria insuficiente.\n");
            exit(1);
        }

        for (int i = 0; i < linha1; i++)
        {
            matriz2[i] = (int *)malloc(coluna2 * sizeof(int));
            if (matriz2[i] == NULL)
            {
                printf("Memoria insuficiente.\n");
                exit(1);
            }
        }
        // lendo matriz 2
        printf("\n");
        for (int i = 0; i < linha2; i++)
        {
            for (int j = 0; j < coluna2; j++)
            {
                printf("Digite o elemento %d da linha %d, da segunda matriz: ", j + 1, i + 1);
                scanf("%d", &matriz2[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < linha2; i++)
        {
            for (int j = 0; j < coluna2; j++)
            {
                printf("%d\t", matriz2[i][j]);
            }
            printf("\n");
        }

        // declarando matriz_resultante
        int **matriz_resultante = (int **)malloc(linha1 * sizeof(int *));
        if (matriz_resultante == NULL)
        {
            printf("Memoria insuficiente.\n");
            exit(1);
        }
        for (int i = 0; i < linha1; i++)
        {
            matriz_resultante[i] = (int *)malloc(coluna2 * sizeof(int));
            if (matriz_resultante[i] == NULL)
            {
                printf("Memoria insuficiente.\n");
                exit(1);
            }
        }
        // Cálculo:
        for (int i = 0; i < linha1; i++)
        {
            for (int j = 0; j < coluna2; j++)
            {
                for (int k = 0; k < linha1; k++)
                {
                    matriz_resultante[i][j] += matriz1[i][k] * matriz2[k][j];
                }
            }
        }
        // imprimindo
        printf("\nA matriz resultante é igual a: \n\n");
        for (int i = 0; i < linha1; i++)
        {
            for (int j = 0; j < coluna2; j++)
            {
                printf("%d\t", matriz_resultante[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    else
    {
        printf("Multiplicação impossível.");
    }

    return 0;
}