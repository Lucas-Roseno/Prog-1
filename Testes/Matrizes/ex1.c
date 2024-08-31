// Faça um programa que carregue uma matriz 3 x 5 com números inteiros, calcule e
// mostre a quantidade de elementos entre 15 e 20.

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int matriz[3][5] = {0}, cont = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz[i][j] = (j + 2) * 3;
            printf("%d\t", matriz[i][j]);
            if (matriz[i][j] >= 15 && matriz[i][j] <= 20)
            {
                cont++;
            }
        }
        printf("\n");
    }
    printf("\nA quantidade de elementos ente 15 e 20 é %d\nE os elementos são:\n", cont);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matriz[i][j] >= 15 && matriz[i][j] <= 20)
            {
                printf("%d\t", matriz[i][j]);
            }
        }
    }
    return 0;
}