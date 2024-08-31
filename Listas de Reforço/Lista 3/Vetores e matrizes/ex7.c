#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main()
{
    int vet_principal[TAM] = {0}, cont = 0;
    for (int i = 0; i < TAM; i++)
    {
        printf("Digite o valor da posição %d: ", i + 1);
        scanf("%d", &vet_principal[i]);
        if (vet_principal[i] == 0)
        {
            cont++;
        }
    }

    int *vet_reduzido = (int *)malloc((TAM - cont) * sizeof(int));
    if (vet_reduzido == NULL)
    {
        printf("Erro na alocação de memória.\n");
        exit(0);
    }
    
    int cont_vet_reduzido = 0;
    for (int j = 0; j < TAM; j++)
    {
        if (vet_principal[j] != 0)
        {
            vet_reduzido[cont_vet_reduzido] = vet_principal[j];
            printf("%d\t", vet_reduzido[cont_vet_reduzido]);
            cont_vet_reduzido++;
        }
        
    }
    printf("\n");
    free(vet_reduzido);
    return 0;
}