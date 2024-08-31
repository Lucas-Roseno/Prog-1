#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int matriz [2][4] = {0}, cont = 0, soma_pares = 0, cont_pares = 0;

    for (int i = 0; i < 2; i++)
    {
        printf("\nLinha %d:\t", i + 1);
        for (int j = 0; j < 4; j++)
        {
            matriz[i][j] = (j+5) * 3;
            if (matriz[i][j] > 12 && matriz[i][j] < 20)
            {
                printf("%d\t",matriz[i][j]);
                cont++;   
            }
            if (matriz[i][j] % 2 == 0)
            {
                soma_pares += matriz[i][j];
                cont_pares++;
            }
            
        }
    }
    
    printf("\n\nA média entre os números pares é %.2f\n", (float)soma_pares/(float)cont_pares);

    return 0;
}