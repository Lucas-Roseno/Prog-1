#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome_aluno[50] = {""};
    FILE *arq;
    if ((arq = fopen("nome_alunos", "w")) == NULL)
    {
        printf("Erro ao abrir o programa.\n");
        exit(1);
    }
    for (int i = 0; i < 4; i++)
    {
        printf("Digite o nome do aluno: ");
        fgets(nome_aluno, 50, stdin);
        fputs(nome_aluno, arq);

    }
    
    fclose(arq);
    return 0;
}