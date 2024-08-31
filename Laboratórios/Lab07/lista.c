#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
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
        printf("%s\t%lld\n", p->nome, p->cpf);
    }
}

void inserirIni(struct ListaSimplesEnc *pList, char n[100], long long c)
{
    struct Nodo *novo;
    novo = (struct Nodo *)malloc(sizeof(struct Nodo));
    strcpy(novo->nome, n);
    novo->cpf = c;
    novo->prox = pList->prim;
    pList->prim = novo;
    return;
}
void removerPessoa(struct ListaSimplesEnc *pList, char nome[100])
{
    struct Nodo *pAnt = pList->prim, *pAtual = pList->prim;
    if (strcmp(pAtual->nome, nome) == 0) // caso o nome esteja na primeira posição
    {
        removerIni(pList);
    }
    else
    {
        for (pAtual = pAtual->prox; pAtual != NULL; pAtual = pAtual->prox)
        {
            if (pAtual->prox == NULL && strcmp(pAtual->nome, nome) != 0)
            { // chegou na última pessoa e n achou
                printf("\nNão encontrado na lista!\n");
                return;
            }

            if (strcmp(pAtual->nome, nome) == 0)
            {
                if (pAtual->prox == NULL)
                { // caso o a pesso seja a última da lista
                    pAnt->prox = NULL;
                    free(pAtual);
                    return;
                }
                // encontrou em qualquer parte da lista
                struct Nodo *pAux = pAtual;
                pAtual = pAtual->prox;
                pAnt->prox = pAtual;
                free(pAux);
            }
            pAnt = pAtual; // andando com o ponteiro do anterior
        }
    }
}

int inserirFim (struct ListaSimplesEnc *pList, char n[100], long long c)
{
    Nodo *novo, *pAux;
    novo = (Nodo *)malloc(sizeof(Nodo));
    int cont = 1;

    if (pList->prim == NULL)
    {
        inserirIni(pList, n, c);
        return 0;
    }
    

    for (pAux = pList->prim; pAux != NULL; pAux = pAux->prox)
    {
        if (pAux->prox == NULL)
        {
            strcpy(novo->nome, n);
            novo->cpf = c;
            novo->prox = NULL;
            pAux->prox = novo;
            return cont;
        }
        cont++;
    }
}

void removerIni(struct ListaSimplesEnc *pList)
{
    struct Nodo *pAux = pList->prim;
    pList->prim = pList->prim->prox;
    free(pAux);
}
int estaVazia(struct ListaSimplesEnc *pList)
{
    return (pList->prim == NULL);
}
