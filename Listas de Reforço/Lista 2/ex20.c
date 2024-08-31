#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    char continuar = ' ';
    do
    {
        int n1 = 0, n2 = 0;

        printf("Digite o primeiro número: ");
        scanf("%d", &n1);
        printf("Digite o segundo número: ");
        scanf("%d", &n2);

        while (n2 == 0){
            printf("Inválido!\nDigite o segundo número: ");
            scanf("%d", &n2);
        }
        
        printf("\nA divisão de %d por %d é igual a %.2f\n", n1, n2, (float)n1 / (float)n2);
        printf("Deseja continuar o programa? [S/N] ");
        scanf(" %c", &continuar);
        while (continuar != 'S' & continuar != 's'
        &continuar != 'N' & continuar != 'n')
        {
            printf("\nInválido!\nDigite [N/S]: ");
            scanf(" %c", &continuar);
        }
        
    } while (continuar == 'S' || continuar == 's');

    return 0;
}