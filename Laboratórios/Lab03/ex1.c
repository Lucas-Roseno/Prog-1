#include <stdio.h>
#include <math.h>
void main () 
{
    int a = 0, b = 0, maior = 0, menor = 0;

    do
    {
        int somatorio = 0;
        printf("Digite o valor de a: ");
        scanf("%d", &a);
        printf("Digite o valor de b: ");
        scanf("%d", &b);
        
        if (a>b)
        {
            maior = a;
            menor = b;
        }else if(b>a)
        {
            maior = b;
            menor = a;
        }else
        {
            if (a == 0 && b == 0)
            {
                printf("\nFim do programa!\n\n");
                break;
            }
        }

        for (int i = menor + 1; i < maior; i++)
        {
            if (i % 2 == 0)
            {
                somatorio += pow(i, 2);
            }
        }
        printf("\nSomatório dos números pares, ao quadrado, entre %d e %d = %d\n\n",a, b, somatorio);
    } while (a != 0 || b != 0);
}