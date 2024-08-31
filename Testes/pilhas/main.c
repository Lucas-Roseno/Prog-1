#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
int main()
{
    struct Pilha minhaPilha;
    int valor, opcao;
    criarPilha(&minhaPilha);
    while (1)
    {
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Mostrar topo\n");
        printf("4 - Verificar se está vazia\n");
        printf("5 - Sair\n");
        printf("Opção? ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o valor: ");
            scanf("%d", &valor);
            empilhar(&minhaPilha, valor);
            break;
        case 2:
            desempilhar(&minhaPilha);
            break;
        case 3:
            mostrarTopo(&minhaPilha);
            break;
        case 4:
            if (estaVazia(&minhaPilha))
            {
                printf("Pilha vazia.\n");
            }
            else
            {
                printf("Pilha não está vazia.\n");
            }

            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}