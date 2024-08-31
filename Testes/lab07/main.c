#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

#define TAMnome 50
#define TAMcpf 11

int main()
{
    int op;
    char nome[TAMnome], cpf[TAMcpf], pessoa_remover[TAMn];
    lista minhaLista;
    criarLista(&minhaLista);
    while (1)
    {
        printf("\n1 - Inserir pessoa.");
        printf("\n2 - Mostrar lista.");
        printf("\n3 - Remover pessoa.");
        printf("\n5 - sair");
        printf("\nOpção: ");
        scanf("%d", &op);
        getchar();
        switch (op)
        {
        case 1:
            printf("\nDigite o nome: ");
            fgets(nome, 50, stdin);
            nome[strlen(nome) - 1] = '\0';

            printf("Digite o CPF: ");
            fgets(cpf, 11, stdin);

            printf("Pessoa inserida na lista. Tem %d na frente.\n",
            inserirFim(&minhaLista, nome, cpf));
            break;

        case 2:
            if (estaVazia(&minhaLista))
            {
                printf("Lista vazia!\n");
            }
            else
            {
                mostrarLista(&minhaLista);
            }
            break;
        case 3:
            if (estaVazia(&minhaLista))
            {
                printf("Lista vazia!\n");
            }else
            {
                printf("\nDigite o nome da pessoa que deseja remover: ");
                fgets(pessoa_remover, 50, stdin);
                pessoa_remover[strlen(pessoa_remover) - 1] = '\0';
                removerPessoa(&minhaLista, pessoa_remover);
            }
            break;
        case 5:
            exit(0);

        default:
            break;
        }
    }

    return 0;
}