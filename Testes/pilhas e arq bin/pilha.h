#ifndef PILHA_H
#define PILHA_H
struct Nodo
{
    int info;
    struct Nodo *prox;
};
struct Pilha
{
    struct Nodo *topo;
};
void criarPilha(struct Pilha *pilha);
void empilhar(struct Pilha *pilha, int valor);
int desempilhar(struct Pilha *pilha);
int mostrarTopo(struct Pilha *pilha);
int estaVazia(struct Pilha *pilha);
void salvarPilha(struct Pilha *pilha, const char *filename);
void lerPilha(struct Pilha *pilha, const char *filename);
#endif