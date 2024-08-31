#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void criarPilha(Pilha *pilha)
{
    pilha->topo = NULL;
}
void empilhar(Pilha *pilha, int valor)
{
    no *pAux = (no *)malloc(sizeof(no));
    if (pAux == NULL)
    {
        printf("Erro ao alocar memória\n");
        return;
    }

    pAux->info = valor;
    pAux->prox = pilha->topo;
    pilha->topo = pAux;
}
int estaVazia(Pilha *pilha)
{
    return (pilha->topo == NULL);
}
void mostrarTopo(Pilha *pilha)
{
    printf("%d\n", pilha->topo->info);
}
void desempilhar(Pilha *pilha)
{
    if (estaVazia(pilha))
    {
        printf("Lista vazia.\n");
        return;
    }
    int valor = pilha->topo->info;
    no *temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);
    printf("%d\n", valor);
}