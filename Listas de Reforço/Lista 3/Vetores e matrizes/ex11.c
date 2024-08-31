#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int matriz [3][5] = {0}, cont = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz[i][j] = (i+6) * 3;
            if (matriz[i][j] > 15 && matriz[i][j] < 20)
            {
                printf("%d\t",matriz[i][j]);
                cont++;   
            }
        }
    }
    
    printf("\nExiste %d números entre 15 e 20\n", cont);

    return 0;
}