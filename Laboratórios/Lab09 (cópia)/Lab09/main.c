#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main()
{
    struct PilhaDoc minhaPilha;
    struct ListaAut listaAut;
    int id, opcao;
    char titulo[100];
    criarPilhaDoc(&minhaPilha);

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
            
            criarListaAut(&listaAut);

            printf("Digite um id? ");
            scanf("%d", &id);
            getchar();

            printf("Digite o título: ");
            fgets(titulo, 100, stdin);
            
            int idAutor, control;
            char autor[100];

            printf("\nDeseja adicionar autores? (0 ou 1)\n");
            scanf("%d", &control);
            getchar();

            if(control) {
                while(1) {
                    printf("\nDigite um id para o autor ou 0 para sair e salvar: \n");
                    scanf("%d", &idAutor);
                    getchar();

                    if(idAutor == 0) {
                        Empilhar(&minhaPilha, id, titulo, &listaAut);
                        break;
                    }
                    printf("\nDigite o nome do autor: \n");
                    fgets(autor, 100, stdin);

                    InserirAut(&listaAut, idAutor, autor);
                }   
            } else {
                Empilhar(&minhaPilha, id, titulo, &listaAut);
            }

            break;
        case 2:
            Desempilhar(&minhaPilha);
            break;
        case 3:
            MostrarTopo(&minhaPilha);
            break;
        case 4:
            if(EstaVazia(&minhaPilha)) {
                printf("\nA fila está vazia\n");
            } else {
                printf("\nA fila não está vazia\n");
            };
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