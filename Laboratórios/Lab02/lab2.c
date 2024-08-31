#include <stdio.h>
#include <math.h>
int main () 
{
    int opcao = 0, n = 0;
    do
    {
        printf("\nExecutar qual exercicio?[0 para sair] ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            break;
        case 1:
        
            printf("Digite um número inteiro: ");
            scanf("%d", &n);
            for (int i = 1; i < 11; i++)
            {
                printf("\n%d x %d = %d", i, n, i*n);
            }
            break;
        case 2: 
            printf("Digite um número inteiro: ");
            scanf("%d", &n);
            int resultado = 1;
            do
            {
                resultado = resultado * n;
                n --;
            } while (n >= 1);
            printf("\nO fatorial eh %d.\n", resultado);
            break;

        case 3:
            resultado = 0;
            printf("Digite um número inteiro: ");
            scanf("%d", &n);
            while (n>0)
            {
                resultado = resultado*10 + n % 10;
                n = n/10;
            }
            printf("\n%d", resultado);
            break;
        case 4:
            printf("Digite um número inteiro: ");
            scanf("%d", &n);
            int primo = 0;
            for (int i = 1; i < n; i++)
            {
                if (n % i == 0)
                {
                    primo++;
                } else if (primo > 1)
                {
                    break;
                }
            }
            if (primo == 1)
            {
                printf("\nNumero primo.\n");
            } else
            {
                printf("\nNumero nao eh primo.\n");
            }
            break;
        default:
            printf("\nINVALIDO!\n");
            break;
        }
    } while (opcao != 0);
    return 0;
}