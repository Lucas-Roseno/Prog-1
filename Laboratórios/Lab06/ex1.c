#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq, *arq_tranposta;
    int **matriz, **transposta, linha = 0, coluna = 0;

    if (!(arq = fopen("matriz.txt", "r")))
    {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }
    fscanf(arq, "%d %d", &linha, &coluna);

    // Alocação da matriz e da tranposta
    matriz = (int **)malloc(sizeof(int *) * linha);
    for (int i = 0; i < linha; i++)
    {
        matriz[i] = (int *)malloc(sizeof(int) * coluna);
        if (matriz[i] == NULL)
        {
            printf("Memoria insuficiente.\n");
            exit(1);
        }
    }
    transposta = (int **)malloc(sizeof(int *) * coluna);
    for (int i = 0; i < coluna; i++)
    {
        transposta[i] = (int *)malloc(sizeof(int) * linha);
        if (transposta[i] == NULL)
        {
            printf("Memoria insuficiente.\n");
            exit(1);
        }
    }

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            fscanf(arq, "%d", &matriz[i][j]);
        }
    }
    fclose(arq);

    // calulando a tranposta
    for (int i = 0; i < coluna; i++)
    {
        for (int j = 0; j < linha; j++)
        {
            transposta[i][j] = matriz[j][i];
        }
    }

    //gravando
    if (!(arq_tranposta = fopen("tranposta.txt", "w")))
    {
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }
    for (int i = 0; i < coluna; i++)
    {
        for (int j = 0; j < linha; j++)
        {
            fprintf(arq_tranposta, "%d ", transposta[i][j]);
        }
        fprintf(arq_tranposta, "\n");
    }
    



    printf("\nTranposta:\n");
    for (int i = 0; i < coluna; i++)
    {
        for (int j = 0; j < linha; j++)
        {
            printf("%d\t", transposta[i][j]);
        }
        printf("\n");
    }

    // Liberações
    for (int i = 0; i < linha; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    for (int i = 0; i < coluna; i++)
    {
        free(transposta[i]);
    }
    free(transposta);

    fclose(arq_tranposta);
    return 0;
}