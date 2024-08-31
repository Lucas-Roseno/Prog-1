#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet_B[4] = {0}, vet_A[4] = {0};
    char numero[50] = {""};
    FILE *arq;
    if ((arq = fopen("numeros", "w")) == NULL)
    {
        printf("Erro ao abrir o programa.\n");
        exit(1);
    }
    for (int i = 0; i < 4; i++)
    {
        printf("Digite um número:: ");
        scanf("%d", &vet_A[i]);
        fprintf(arq, "%d\n", vet_A[i]);
    }
    fclose(arq);

    if ((arq = fopen("numeros", "r")) == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }
    for (int i = 0; i < 4; i++)
    {
        fscanf(arq, "%d", &vet_B[i]);
        printf("%d\n", vet_B[i]);
    }
    fclose(arq);
    return 0;
}