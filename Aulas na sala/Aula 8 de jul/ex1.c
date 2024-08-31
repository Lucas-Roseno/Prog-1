#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int main()
{
    int vetor[TAM] = {0};

    for (int i = 0; i < TAM / 2; i++)
    {
        printf("Digite o valor do vetor na posição %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for (int i = 5; i < TAM; i++)
    {
        vetor[i] = vetor[i - 5] * 2;
        
        
        printf("\nValor do vetor na posição  %d: %d", i + 1, vetor[i]);
    }
    return 0;
}