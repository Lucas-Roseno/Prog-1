#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autores.h"

void criarLista(listAut *pLisAut)
{
    pLisAut->primAut = NULL;
}

int listaVazia(listAut *pListAut)
{
    return (pListAut->primAut == NULL);
}

void inserirIni(listAut *pListAut, char nome[TAMn], int idAut)
{
    autor *novo;
    novo = (autor *)malloc(sizeof(autor));
    strcpy(novo->nome, nome);
    novo->idAut = idAut;
    novo->prox = NULL;
    pListAut->primAut = novo;
    return;
}

void inserirFim(listAut *pListAut, char nome[TAMn], int idAut)
{
    if (listaVazia(pListAut))
    {
        inserirIni(pListAut, nome, idAut);
        return;
    }

    autor *novo, *pAux = pListAut->primAut;
    novo = (autor *)malloc(sizeof(autor));
    while (pAux->prox != NULL)
    {
        pAux = pAux->prox;
    }
    strcpy(novo->nome, nome);
    novo->idAut = idAut;
    novo->prox = NULL;
    pAux->prox = novo;
    return;
}

void mostrarLista(listAut *pLisAut)
{
    printf("\n");
    for (autor *pAux = pLisAut->primAut; pAux != NULL; pAux = pAux->prox)
    {
        printf("%s\t%d\n", pAux->nome, pAux->idAut);
    }
}