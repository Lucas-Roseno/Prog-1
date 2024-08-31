#include <stdio.h>
#include <stdlib.h>

int main () 
{
    int tam_vet = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam_vet);

    int *vet = (int *)malloc(tam_vet * sizeof(int));
    int *vet_primos = (int *)malloc(tam_vet * sizeof(int));

    int cont_primos = 0;
    for (int i = 0; i < tam_vet; i++)
    {
        int cont_divisor = 0;
        printf("Digite a posição %d do vetor: " , i + 1);
        scanf("%d", &vet[i]);

        for (int j = 1; j <= vet[i]; j++)
        {
            if (vet[i] % j == 0)
            {
                cont_divisor++;
            }
        }
        if (cont_divisor == 2)
        {
            vet_primos[cont_primos] = vet[i];
            cont_primos++;
        }        
    }
    
    printf("Vetor com os número primos digitados: \n");
    for (int i = 0; i < cont_primos; i++)
    {
        printf("%d\t", vet_primos[i]);
    }
    

    free(vet);
    free(vet_primos);
    return 0;
}