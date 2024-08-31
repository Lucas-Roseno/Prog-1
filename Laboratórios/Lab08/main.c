#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "lista.c"

#define TAMnome 50
#define TAMcpf 11

int main()
{
    struct ListaSimplesEnc minhaLista;
    int op;
    char cpf[TAMcpf];
    char nome[TAMnome] = {""};
    char preferencial;
    criarLista(&minhaLista);
    while (1)
    {
        printf("\n");
        printf("0 -Sair\n");
        printf("1 -Inserir pessoa\n");
        printf("2 -Atender o primeiro\n");
        printf("3 -Mostrar fila\n");
        printf("4 -Verificar se está vazia\n");
        printf("Opcao? ");
        scanf("%d", &op);
        getchar();
        switch (op)
        {
        case 1:
            // printf("\nAtendimento prioritário [s/n]? ");
            // scanf(" %c", &preferencial);
            // getchar();

            printf("\nNome: ");
            fgets(nome, TAMnome, stdin);
            nome[strlen(nome) - 1] = '\0';

            printf("Digite o CPF: ");
            fgets(cpf, TAMcpf, stdin);

            printf("Dados inseridos. Tem %d pessoas na frente.\n",
                   inserirFim(&minhaLista, nome, cpf));
            // if (preferencial == 's')
            // {
            //     inserirIni(&minhaLista, nome, cpf);
            //     printf("Dados inseridos no ínicio da lista\n");
            //     break;
            // }

            break;
        case 2: // remover determinado elemento
            if (estaVazia(&minhaLista))
            {
                printf("\nA fila esá vazia!\n");
                break;
            }
            
            printf("\nPrimeiro da fila atendido!\nFaltam: %d\n",removerIni(&minhaLista));
            
            break;
        case 3: // mostrar lista
            if (estaVazia(&minhaLista))
            {
                printf("Lista vazia\n");
            }
            else
            {
                mostrarLista(&minhaLista);
            }
            break;
        case 4:
            if (estaVazia(&minhaLista))
            {
                printf("Lista vazia.\n");
            }
            else
            {
                printf("Lista não esta vazia.\n");
            }

            break;
        case 0: // abandonar o programa
            exit(0);
        }
    }
    return 0;
}
