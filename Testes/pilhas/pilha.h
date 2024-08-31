#ifndef PILHA_H
#define PILHA_H

typedef struct Nodo
{
    int info;
    struct Nodo *prox;
}no;

typedef struct Pilha
{
    no *topo;
}Pilha;

void criarPilha(Pilha *pilha);
void empilhar(Pilha *pilha, int valor);
int estaVazia(Pilha *pilha);
void mostrarTopo(Pilha *pilha);
void desempilhar(Pilha *pilha);
#endif