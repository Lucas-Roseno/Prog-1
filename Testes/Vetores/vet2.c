#include <stdio.h>
#include <stdlib.h>
int main () 
{
    int vet[10] = {0};

    for (int i = 0; i < 5; i++)
    {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vet[i]);
        vet[i + 5] = vet[i] * (i+2);
    }
    for (int i = 5; i < 10; i++)
    {
        printf("\nValor da posição %d: %d\n", i + 1, vet[i]);
    }
    

    return 0;
}