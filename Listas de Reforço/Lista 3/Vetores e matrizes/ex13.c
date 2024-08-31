#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matriz[6][3] = {0}, maior = 0, menor = 0;
    int i_maior = 0, j_maior = 0, i_menor = 0, j_menor = 0;

    for (int i = 0; i < 6; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            matriz[i][j] = (j + 5) * 3;

            if (i == 0 && j == 0)
            {
                maior = matriz[i][j];
                i_maior = i;
                j_maior = j;
                menor = matriz[i][j];
                i_menor = i;
                j_menor = j;
            }
            else if (maior < matriz[i][j])
            {
                maior = matriz[i][j];
                i_maior = i;
                j_maior = j;
            }
            else if (menor > matriz[i][j])
            {
                menor = matriz[i][j];
                i_menor = i;
                j_menor = j;
            }
        }
    }

    printf("O maior é %d na posição [%d][%d]\nO menor é %d na posição [%d][%d]\nConsiderando a primeira aparição\n"
    , maior, i_maior, j_maior, menor, i_menor, j_menor);

    return 0;
}