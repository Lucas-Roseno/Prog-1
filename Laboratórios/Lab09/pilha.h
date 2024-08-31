#ifndef PILHA_H
#define PILHA_H
#include "autores.h"

typedef struct documento
{
    int idDoc;
    char titulo[TAMn];
    listAut *list_aut;
    struct documento *prox;
}doc;
typedef struct pilhaDocumento
{
    doc *topo;
}pilhaDoc;

void criarPilha(pilhaDoc *pPilha);
int pilhaVazia(pilhaDoc *pPilha);
void empilhar(pilhaDoc *pPilha, int idDoc, char titulo[TAMn], listAut *autores);
void mostrarTopo(pilhaDoc *pPilha);
doc desemplihar(pilhaDoc *pPilha);
void salvarPilha(pilhaDoc *pPilha);
void lerPilha(pilhaDoc *pPilha);

#endif