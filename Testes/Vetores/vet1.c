// Ler 30 valores, calcular a média aritmética dos mesmos e imprimir a média e os
// valores iguais ou superiores à média.
#include <stdio.h>
#include <stdlib.h>
#define TAM 3
int main()
{
    int vet_alunos[TAM] = {0}, soma_notas = 0;
    float media = 0;
    for (int i = 0; i < TAM; i++)
    {
        printf("Digite a nota %d: ", i + 1);
        scanf("%d", &vet_alunos[i]);
        soma_notas += vet_alunos[i];
    }
    media = (float)soma_notas / (float)TAM;
    printf("\nA média aritmétrica das notas é = %.2f\n\n", media);

    for (int i = 0; i < TAM; i++)
    {
        if (vet_alunos[i] >= media)
        {
            printf("A nota %d é igual, ou superior a média.\n",vet_alunos[i]);
        }
        
    }

    return 0;
}
