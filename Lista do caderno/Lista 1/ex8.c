#include <stdio.h>
int main ()
{
    int vetor[4];

    for (int i = 0; i < 4; i++)
    {
        printf("%d número: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    
    for (int i = 0; i < 4; i++)
    {
        if (vetor[i] % 6 == 0)
        {
            printf("%d\t", vetor[i]);
        }
    }    
    printf("são divisíveis por 3 e 2.\n");
    
}