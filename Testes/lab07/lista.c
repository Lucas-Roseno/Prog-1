#include "lista.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void criarLista(lista *pList)
{
    pList->prim = NULL;
}
int estaVazia(lista *pList)
{
    return (pList->prim == NULL);
}

void inserirIni(lista *pList, char n[TAMn], char c[TAMc])
{
    no *novo;
    novo = (no *)malloc(sizeof(no));
    strcpy(novo->nome, n);
    strcpy(novo->cpf, c);
    novo->prox = pList->prim;
    pList->prim = novo;
    return;
}

void mostrarLista(lista *pList)
{
    printf("\n");
    no *pAux;
    for (pAux = pList->prim; pAux != NULL; pAux = pAux->prox)
    {
        printf("\n%s\t%s", pAux->nome, pAux->cpf);
    }
}
int inserirFim(lista *pList, char n[TAMn], char c[TAMc])
{
    int cont = 0;
    if (estaVazia(pList))
    {
        inserirIni(pList, n, c);
        return cont;
    }

    cont = 1;
    no *pAux = pList->prim, *novo;
    while (pAux->prox != NULL)
    {
        cont++;
        pAux = pAux->prox;
    }
    novo = (no *)malloc(sizeof(no));
    strcpy(novo->nome, n);
    strcpy(novo->cpf, c);
    novo->prox = pAux->prox;
    pAux->prox = novo;
    return cont;
}

void removerIni(lista *pList, char n[TAMn])
{
    no *pAux = pList->prim;
    pList->prim = pList->prim->prox;
    free(pAux);
    return;
}

int contarPessoas(lista *pList)
{
    int cont = 0;
    for (no *pAux = pList->prim; pAux != NULL; pAux = pAux->prox)
    {
        cont++;
    }
    return cont;
}

void removerPessoa(lista *pList, char n[TAMn])
{
    no *pAtual = pList->prim, *pAnt = pList->prim, *pAux;
    int cont = 1;

    if (strcmp(pList->prim->nome, n) == 0)
    {
        removerIni(pList, n);
        printf("%s foi removido da lista.\nPermanecem %d na lista", n, contarPessoas(pList));
        return;
    }
    else
    {
        for (pAtual = pList->prim; pAtual != NULL; pAtual = pAtual->prox)
        {
            if (pAtual->prox == NULL && strcmp(pAtual->nome, n) != 0)
            {
                printf("Pessoa não encontrada na lista!\nPermancem %d pessoas.\n",
                       contarPessoas(pList));
                return;
            }
            if (strcmp(pAtual->nome, n) == 0)
            {
                pAnt->prox = pAtual->prox;
                printf("%s foi excluído da lista.\nPermanecem %d na lista.\n",
                       pAtual->nome, contarPessoas(pList));
                free(pAtual);
                return;
            }
            pAnt = pAtual;
        }
    }
    return;
}