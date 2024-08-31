#ifndef PILHA_H
#define PILHA_H

struct NodoAut
{
   int id;
   char nome [100];
   struct NodoAut *prox;
};

struct ListaAut
{
    struct NodoAut *prim;
};

//------------------------------------------------//

struct NodoDoc
{
    int id;
    char titulo [100];
    struct NodoDoc *prox;
    struct NodoAut *autores;
};

struct PilhaDoc
{
    struct NodoDoc *topo;
};

void criarPilhaDoc(struct PilhaDoc *pilha);
void Empilhar(struct PilhaDoc *pilha, int id, char titulo[100], struct ListaAut *lista);
void MostrarTopo(struct PilhaDoc *pilha);
int EstaVazia(struct PilhaDoc *pilha);
void Desempilhar(struct PilhaDoc *pilha);

void mostrarLista(struct NodoAut *p);
void criarListaAut(struct ListaAut *lista);
void InserirAut(struct ListaAut *lista, int id, char nome[100]);

void salvarPilha(struct PilhaDoc *pilha, const char *nomeArquivo);
void lerPilha(struct PilhaDoc *pilha, const char *nomeArquivo);
#endif