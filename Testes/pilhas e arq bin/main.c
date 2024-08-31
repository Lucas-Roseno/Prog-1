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
        printf("5 - Salvar Pilha\n");
        printf("6 - Ler Pilha\n");
        printf("7 - Sair\n");
        printf("Opção? ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Valor? ");
            scanf("%d", &valor);
            empilhar(&minhaPilha, valor);
            break;
        case 2:
            valor = desempilhar(&minhaPilha);
            if (valor != -1)
            {
                printf("Desempilhado: %d\n", valor);
            }
            break;
        case 3:
            valor = mostrarTopo(&minhaPilha);
            if (valor != -1)
            {
                printf("Topo: %d\n", valor);
            }
            break;
        case 4:
            if (estaVazia(&minhaPilha))
            {
                printf("Pilha vazia\n");
            }
            else
            {
                printf("Pilha não está vazia\n");
            }
            break;
        case 5:
            salvarPilha(&minhaPilha, "pilha.bin");
            printf("Pilha salva em 'pilha.bin'\n");
            break;
        case 6:
            lerPilha(&minhaPilha, "pilha.bin");
            printf("Pilha lida de 'pilha.bin'\n");
            break;
        case 7:
            exit(0);
        }
    }
    return 0;
}