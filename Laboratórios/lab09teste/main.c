#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main()
{
    int idDoc, idAut, opcao, quantAut;
    char titulo[TAMn], nome[TAMn];

    pilhaDoc pilha;
    criarPilha(&pilha);

    while (1)
    {
        printf("1 - Empilhar documento.\n");
        printf("2 - Desempilhar.\n");
        printf("3 - Mostrar topo.\n");
        printf("4 - Verificar se está vazia.\n");
        printf("5 - Salvar pilha.\n");
        printf("6 - Ler pilha.\n");
        printf("7 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            listAut lista;
            criarLista(&lista);
            printf("\nID documento: ");
            scanf("%d", &idDoc);
            getchar();

            printf("Título do documento: ");
            fgets(titulo, TAMn, stdin);
            titulo[strlen(titulo) - 1] = '\0';

            printf("Quantos autores? ");
            scanf("%d", &quantAut);
            printf("\n");
            getchar();

            for (int i = 0; i < quantAut; i++)
            {
                printf("Nome autor: ");
                fgets(nome, TAMn, stdin);
                nome[strlen(nome) - 1] = '\0';

                printf("Id autor: ");
                scanf("%d", &idAut);
                getchar();

                inserirFim(&lista, nome, idAut);
            }

            empilhar(&pilha, idDoc, titulo, &lista);
            mostrarTopo(&pilha);
            break;
        }
        case 2:
            desemplihar(&pilha);
            break;

        case 3:
            mostrarTopo(&pilha);
            break;
        case 4:
            if (pilhaVazia(&pilha))
            {
                printf("\nPilha vazia!\n\n");
            }else
            {
                printf("\nPilha não está vazia!\n\n");
            }
            break;
        case 5:
            salvarPilha(&pilha);
            printf("\nArquivos salvos!\n\n");
            break;
        case 6:
            printf("\nDados carregados na pilha!\n\n");
            lerPilha(&pilha);
            break;
        case 7:
            exit(0);
        default:
            break;
        }
    }

    return 0;
}