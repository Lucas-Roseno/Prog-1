#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

#define TAMnome 50
#define TAMcpf 11

void criarLista(struct ListaSimplesEnc *pList)
{
    pList->prim = NULL;
}

void mostrarLista(struct ListaSimplesEnc *pList)
{
    printf("\n");
    struct Nodo *p;
    for (p = pList->prim; p != NULL; p = p->prox)
    {
        printf("%s\t%s\n", p->nome, p->cpf);
    }
}

void inserirIni(struct ListaSimplesEnc *pList, char n[50], char c[11])
{
    struct Nodo *novo;
    novo = (struct Nodo *)malloc(sizeof(struct Nodo));
    strcpy(novo->nome, n);
    strcpy(novo->cpf, c);
    novo->prox = NULL;
    pList->prim = novo;
    return;
}

int inserirFim(struct ListaSimplesEnc *pList, char n[TAMnome], char c[TAMcpf])
{
    Nodo *pAtual = pList->prim, *novo;
    novo = (Nodo *)malloc(sizeof(Nodo));
    int cont = 0;

    if (pList->prim == NULL)
    {
        inserirIni(pList, n, c);
        return cont;
    }

    cont = 1;
    while (pAtual->prox != NULL)
    {
        pAtual = pAtual->prox;
        cont++;
    }
    pAtual->prox = novo;
    strcpy(novo->cpf, c);
    strcpy(novo->nome, n);
    novo->prox = NULL;
    return cont;
}

int removerIni(struct ListaSimplesEnc *pList)
{
    struct Nodo *pAux = pList->prim;
    pList->prim = pList->prim->prox;
    free(pAux);
    int cont = 0;
    if (pList->prim == NULL)
    {
        return cont;
    }

    cont = 1;
    for (pAux = pList->prim; pAux->prox != NULL; pAux = pAux->prox)
    {
        cont++;
    }
    return cont;
}
int estaVazia(struct ListaSimplesEnc *pList)
{
    return (pList->prim == NULL);
}
