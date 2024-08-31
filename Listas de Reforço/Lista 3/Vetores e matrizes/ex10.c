#include <stdio.h>
#include <stdlib.h>

int main () 
{
    int tam_vet = 0;
    float maior = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam_vet);

    float *vet = (float *)malloc(tam_vet * sizeof(float));

    for (int i = 0; i < tam_vet; i++)
    {
        printf("Digite o valor da posição %d: ", i + 1);
        scanf("%f", &vet[i]);
        if (i == 0)
        {
            maior = vet[i];
        } else if(maior < vet[i])
        {
            maior = vet[i];
        }
    }
    
    printf("\nNúmeros do vetor divido pelo maior %.2f: \n", maior);
    for (int i = 0; i < tam_vet; i++)
    {
        vet[i] = vet[i] / maior;
        printf("%.2f\t", vet[i]);
    }
    

    free(vet);
    return 0;
}