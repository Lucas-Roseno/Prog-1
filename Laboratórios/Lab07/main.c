#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "lista.c"

#define TAM 100

int main()
{
    struct ListaSimplesEnc minhaLista;
    int op;
    long long cpf;
    char nome[TAM] = {""};
    char preferencial;
    criarLista(&minhaLista);
    while (1)
    {
        printf("\n");
        printf("1 -Inserir pessoa\n");
        printf("2 -Remover pessoa\n");
        printf("3 -Mostrar lista\n");
        printf("4 -Verificar se está vazia\n");
        printf("5 -Sair\n");
        printf("Opcao? ");
        scanf("%d", &op);
        getchar();
        switch (op)
        {
        case 1: // inserir elemento no inicio
            printf("\nAtendimento prioritário [s/n]? ");
            scanf(" %c", &preferencial);
            getchar();

            printf("Nome: ");
            fgets(nome, 100, stdin);
            nome[strlen(nome) - 1] = '\0';

            printf("Digite o CPF: ");
            scanf("%lld", &cpf);

            if (preferencial == 's')
            {
                inserirIni(&minhaLista, nome, cpf);
                printf("Dados inseridos no ínicio da lista\n");
                break;
            }
            else if (preferencial == 'n')
            {
                printf("Dados inseridos. Tem %d pessoas na frente.\n",inserirFim(&minhaLista, nome, cpf));
            }

            break;
        case 2: // remover determinado elemento
            printf("\nDigite o nome da pessoa que deseja remover: ");
            fgets(nome, 50, stdin);
            nome[strlen(nome) - 1] = '\0';
            removerPessoa(&minhaLista, nome);
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
                printf("Lista vazia\n.");
            }else
            {
                printf("Lista não esta vazia.\n");
            }
            
            break;
        case 5: // abandonar o programa
            exit(0);
        }
    }
    return 0;
}
