#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void criarListCaixa(listCaixa *listCaixas)
{
    listCaixas->primCaixa = NULL;
}
int listCaixaVazia(listCaixa *listCaixas)
{
    return (listCaixas->primCaixa == NULL);
}

void inserirIniCaixas(listCaixa *listaCaixa)
{
    caixa *novo = (caixa *)malloc(sizeof(caixa));
    if (novo == NULL)
    {
        perror("\nErro ao alocar memória!\n");
        return;
    }
    novo->fila = (filaClientes*)malloc(sizeof(filaClientes));
    if (novo->fila == NULL)
    {
        perror("\nErro na alocação de memória.\n\n");
        return;
    }
    
    novo->numCaixa = 1;
    novo->estado = 1;
    novo->prox = listaCaixa->primCaixa;
    listaCaixa->primCaixa = novo;
    return;
}

void inserirFimCaixas(listCaixa *listaCaixa)
{
    if (listaCaixa->primCaixa == NULL)
    {
        inserirIniCaixas(listaCaixa);
        return;
    }
    else
    {
        caixa *pAux = listaCaixa->primCaixa, *novo = (caixa *)malloc(sizeof(caixa));
        int contCaixa = 2;
        while (pAux->prox != NULL)
        {
            pAux = pAux->prox;
            contCaixa++;
        }
        novo->fila = (filaClientes *)malloc(sizeof(filaClientes));
        if (novo->fila == NULL)
        {
            perror("\nErro na alocação.\n\n");
            return;
        }
        
        novo->numCaixa = contCaixa;
        novo->estado = 1;
        novo->prox = NULL;
        pAux->prox = novo;
    }
}

void mostrarCaixas(listCaixa *listaCaixa)
{
    for (caixa *pAux = listaCaixa->primCaixa; pAux != NULL; pAux = pAux->prox)
    {
        printf("\nCaixa %d\n", pAux->numCaixa);
        if (pAux->estado == 1)
        {
            printf("Estado: aberto\n");
        }
        else
        {
            printf("Estado: fechado\n");
        }
    }
}

void abrirCaixa(listCaixa *listaCaixa, int numCaixa)
{
    caixa *pAux = listaCaixa->primCaixa;
    while (pAux->prox != NULL && pAux->numCaixa != numCaixa)
    {
        pAux = pAux->prox;
    }
    if (pAux->numCaixa != numCaixa && pAux->prox == NULL)
    {
        printf("\nCaixa não encontrado!\n\n");
        return;
    }
    if (pAux->numCaixa == numCaixa)
    {
        pAux->estado = 1;
        printf("\nCaixa aberto!\n\n");
    }
}

void fecharCaixa(listCaixa *listaCaixa, int numCaixa)
{
    caixa *pAux = listaCaixa->primCaixa;
    while (pAux->prox != NULL && pAux->numCaixa != numCaixa)
    {
        pAux = pAux->prox;
    }
    if (pAux->numCaixa != numCaixa && pAux->prox == NULL)
    {
        printf("\nCaixa não encontrado!\n\n");
        return;
    }
    if (pAux->numCaixa == numCaixa)
    {
        pAux->estado = 0;
        printf("\nCaixa fechado!\n\n");
    }
}

void mostrarUmCaixa(listCaixa *listaCaixa, int caixaEscolhido)
{
    caixa *pAux = listaCaixa->primCaixa;
    while (pAux->numCaixa != caixaEscolhido )
    {
        pAux = pAux->prox;
    }
    printf("\nCaixa %d: ", pAux->numCaixa);
    if (pAux->estado == 1)
    {
        printf("aberto\n");
    }else
    {
        printf("fechado\n");
    }

    cliente *pCliente = pAux->fila->primCliente;
    while (pCliente != NULL)
    {
        printf("Cliente: %s", pCliente->nome);
    }
    
    
}