#include <stdio.h>
#include <stdlib.h>
int main()
{
    int vet[5] = {0}, maior = 0, aux = 0;
    for (int i = 0; i < 5; i++)
    {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        maior = vet[i];
        for (int j = i; j < 5; j++)
        {
            if (vet[j] > maior)
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
    printf("Vetor ordenado: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", vet[i]);
    }

    return 0;
}