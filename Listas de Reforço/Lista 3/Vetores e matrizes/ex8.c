#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0, b = 0, vet_resultado[5] = {0};
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);

    int *vet_A = (int *)malloc(a * sizeof(int));
    int *vet_B = (int *)malloc(b * sizeof(int));
    if (vet_A == NULL || vet_B == NULL)
    {
        printf("Erro na alocação de memória.");
        exit(0);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Valor da posição %d do vetor A: ", i + 1);
        scanf("%d", &vet_A[i]);
        printf("Valor da posição %d do vetor B: ", i + 1);
        scanf("%d", &vet_B[i]);
        printf("\n");
    }

    int cont_b = b - 1;
    for (int i = 0; i < 5; i++)
    {
        vet_resultado[i] = vet_B[cont_b] - vet_A[i];
        cont_b--;
        printf("%d\t", vet_resultado[i]);
    }

    free(vet_A);
    free(vet_B);
    return 0;
}