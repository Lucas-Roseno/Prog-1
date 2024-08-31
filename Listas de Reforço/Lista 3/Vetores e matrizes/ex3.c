#include <stdio.h>

#define TAM 15

int main () 
{
    int vet[TAM] = {0}, maior = 0, menor = 0;
    for (int i = 0; i < TAM; i++)
    {
        printf("Digite o valor da posição %d: ", i+1);
        scanf("%d", &vet[i]);
        if (i == 0)
        {
            maior = vet[i];
            menor = vet[i];
        }else if (vet[i] > maior)
        {
            maior = vet[i];
        }else if (vet[i] < menor)
        {
            menor = vet[i];
        }
    }
    printf("\nMaior = %d\nMenor = %d\n", maior, menor);

    return 0;
}