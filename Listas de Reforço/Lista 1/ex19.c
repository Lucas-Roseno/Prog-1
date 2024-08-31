#include <stdio.h>
void main () 
{
    char turma = ' ', presenca = ' ';
    int num_alunos = 0, num_matricula = 0, num_turma = 0;

    do
    {
        printf("\nDigite o número de turmas que será cadastrado\n[O valor deve estar entre 0 e 14]: ");
        scanf("%d", &num_turma);
    } while (num_turma > 14 || num_turma < 0);
    
    for (int i = 0; i < num_turma; i++)
    {
        printf("\nDigite a identificação da turma: ");
        scanf(" %c", &turma);
        printf("Digite a quantidade de alunos matriculados: ");
        scanf("%d", &num_alunos);

        for (int i = 0; i < num_alunos; i++)
        {
            printf("\nDigite o número de matricula do aluno: ");
            scanf("%d", &num_matricula);
            printf("Digite se o aluno estava presente ou ausente\n['A' ou 'P']: ");
            scanf(" %c", &presenca);
        }
        
    }
    

}