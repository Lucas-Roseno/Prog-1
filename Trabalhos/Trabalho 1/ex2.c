// Exercício 2: O Código Esquecido do Dr. Emmett Brown
#include <stdio.h>
#include <stdlib.h>
int busca_fibonacci(int n, int x)
{
    int num = 0, num_anterior = 0, aux = 0, valor_x = 0;
    int *vet_fibonacci = (int *)malloc(n * sizeof(int));
    //cálculo de fibonacci
    for (int i = 0; i < n; i++)
    {
        aux = num;
        num += num_anterior;
        num_anterior = aux;
        vet_fibonacci[i] = num;
        if (i == 0)
        {
            num++;
        }
        else if (i == 1)
        {
            num_anterior = 0;
        }
        printf("%d\t", vet_fibonacci[i]);
    }

    //busca binária
    int inicio = 0, fim = n - 1;
    do
    {
        int meio = inicio + (fim - inicio) / 2;
        if (vet_fibonacci[meio] == x)
        {
            free(vet_fibonacci); 
            return meio;         
        }
        if (vet_fibonacci[meio] < x)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }while (inicio <= fim);

    free(vet_fibonacci); 
    return -1;
}
    int main()
    {
        int n = 0, x = 0;
        printf("Digite o número de iterações da sequência de Fibonacci: ");
        scanf("%d", &n);

        printf("Digite o número que deseja ver se está na sequência: ");
        scanf("%d", &x);

        printf("\nÍndice: %d\n", busca_fibonacci(n, x));

        return 0;
    }