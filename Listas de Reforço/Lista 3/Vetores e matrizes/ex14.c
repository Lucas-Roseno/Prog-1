#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define num_nomes 3
#define tam_nomes 100

int main () 
{
    float matriz_notas[3][2] = {0}, media_notas[num_nomes] = {0}, media_classe = 0;
    char *vet_nomes[num_nomes];
    char nome[tam_nomes];
    for (int i = 0; i < num_nomes; i++)
    {
        printf("Digite o nome do aluno %d: ", i + 1);
        if (fgets(nome, tam_nomes, stdin) != NULL)
        {
            nome[strlen(nome) - 1] = '\0';
            vet_nomes[i] = malloc(strlen(nome) + 1);
            if (vet_nomes[i] == NULL)
            {
                printf("Erro na alocação de memória.");
                exit(1);
            }
            strcpy(vet_nomes[i], nome);
        }
        for (int j = 0; j < 2; j++)
        {
            printf("Digite a %d nota do(a) %s: ",j + 1, vet_nomes[i]);
            scanf("%f", &matriz_notas[i][j]);
        }
        getchar();
    }
    
    for (int i = 0; i < num_nomes; i++)
    {
        char situacao_aluno[30] = {""};
        media_notas[i] = (matriz_notas[i][0] + matriz_notas[i][1]) / 2;
        if (media_notas[i] < 4)
        {
            strcat(situacao_aluno, "REPROVADO"); 
        }else if (media_notas[i] > 4 && media_notas[i] < 6)
        {
            strcat(situacao_aluno, "EXAME");
        }else if(media_notas[i] > 6)
        {
            strcat(situacao_aluno, "APROVADO");
        }

        printf("A média do aluno %s é %.2f e a situção é: %s\n", vet_nomes[i], media_notas[i], situacao_aluno);
        free(vet_nomes[i]);
        media_classe += media_notas[i];
    }
    printf("A média da classe é %.2f.\n", media_classe/num_nomes);
    

    return 0;
}