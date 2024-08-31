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
    novo->fila = (filaClientes *)malloc(sizeof(filaClientes));
    criarFila(novo->fila);
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
        criarFila(novo->fila);
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
        printf("\nCaixa %d ", pAux->numCaixa);
        if (pAux->estado == 1)
        {
            printf("aberto\n");
        }
        else
        {
            printf("fechado\n");
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
        printf("\nCaixa %d aberto!\n\n", numCaixa);
    }
}

void fecharCaixa(listCaixa *listaCaixa, int numCaixa)
{
    caixa *pAux = listaCaixa->primCaixa;
    while (pAux->prox != NULL && pAux->numCaixa != numCaixa)
    { // busca
        pAux = pAux->prox;
    }

    if (pAux->estado == 0)
    {
        printf("\nCaixa já está fechado.\n");
        return;
    }

    if (pAux->fila->primCliente == NULL)
    { // fila vazia
        pAux->estado = 0;
        printf("\nCaixa fechado!\nNenhum cliente na fila para ser rediercionado\n\n");
        return;
    }

    caixa *caixaPFechar = pAux;

    int cont = 0;
    caixa *pCont = listaCaixa->primCaixa;
    while (pCont != NULL)
    { // verificando se existe pelo menos outro caixa aberto
        if (cont == 2)
            break;
        
        if (pCont->estado == 1)
        {
            cont++;
        }
        
        pAux = pCont;
        pCont = pCont->prox;
    }

    if (cont < 2)
    {
        printf("\nCaixa não pode ser fechado pois não há outro aberto!\n\n");
        return;
    }

    cliente *realocado = caixaPFechar->fila->primCliente;
    while (realocado != NULL)
    {
        inserirOrdFila(listaCaixa, realocado->nome, realocado->cpf, realocado->prioridade,
                       realocado->nitens, pAux->numCaixa);
        desenfileirar(listaCaixa, numCaixa);
        realocado = realocado->prox;
    }
    caixaPFechar->estado = 0;
    caixaPFechar->fila->primCliente = NULL;

    mostrarUmCaixa(listaCaixa, pAux->numCaixa);
}

void mostrarUmCaixa(listCaixa *listaCaixa, int caixaEscolhido)
{
    caixa *pAux = listaCaixa->primCaixa;
    while (pAux->numCaixa != caixaEscolhido)
    {
        pAux = pAux->prox;
    }
    if (pAux->estado == 0)
    {
        printf("\nCaixa %d fechado!\n\n", pAux->numCaixa);
        return;
    }else
    {
        printf("\nCaixa %d aberto, fila: \n", pAux->numCaixa);
    }

    mostrarFila(pAux->fila);
}

//=============FILA================

void criarFila(filaClientes *fila)
{
    fila->primCliente = NULL;
}

void inserirIniFila(listCaixa *lCaixas, char *nome, long long cpf, int prioridade,
                    int nItens, int caixaEscolhido)
{
    caixa *pAuxC = lCaixas->primCaixa;
    while (pAuxC->numCaixa != caixaEscolhido)
    {
        pAuxC = pAuxC->prox;
    }
    cliente *novo = (cliente *)malloc(sizeof(cliente));
    if (novo == NULL)
    {
        perror("\nErro ao alocar memória!\n\n");
        return;
    }
    strcpy(novo->nome, nome);
    novo->cpf = cpf;
    novo->prioridade = prioridade;
    novo->nitens = nItens;
    novo->prox = pAuxC->fila->primCliente;
    pAuxC->fila->primCliente = novo;
}

void mostrarFila(filaClientes *fila)
{
    cliente *pAux = fila->primCliente;
    if (pAux == NULL)
    {
        printf("\nFila vazia\n\n");
    }

    while (pAux != NULL)
    {
        printf("%s\tPrioridade: %d\n", pAux->nome, pAux->prioridade);
        pAux = pAux->prox;
    }
    printf("\n");
}

void inserirOrdFila(listCaixa *lCaixas, char *nome, long long cpf, int prioridade,
                    int nItens, int caixaEscolhido)
{
    caixa *pAuxC = lCaixas->primCaixa;
    while (pAuxC->numCaixa != caixaEscolhido)
    {
        pAuxC = pAuxC->prox;
    }

    if (pAuxC->estado == 0)
    {
        printf("\nCaixa fechado!\nCadastre o cliente em outro caixa.\n\n");
        return;
    }

    // caso a fila esteja vazia ou o pirmeiro da fila n tenha prioridade igual a 1
    // ou o primeiro da fila tem prioridade igual a 3
    if (pAuxC->fila->primCliente == NULL ||
        (pAuxC->fila->primCliente->prioridade > 1 && prioridade == 1) || 
        (pAuxC->fila->primCliente->prioridade > 2 && prioridade == 2))
    {
        inserirIniFila(lCaixas, nome, cpf, prioridade, nItens, caixaEscolhido);
        return;
    }

    cliente *clienteAtual = pAuxC->fila->primCliente, *novo;
    cliente *clienteAnt = clienteAtual;
    switch (prioridade)
    {
    case 1:
        while (clienteAtual != NULL && clienteAtual->prioridade == 1)
        {
            clienteAnt = clienteAtual;
            clienteAtual = clienteAtual->prox;
        }

        break;
    case 2:
        while (clienteAtual != NULL && clienteAtual->prioridade <= 2)
        {
            clienteAnt = clienteAtual;
            clienteAtual = clienteAtual->prox;
        }

        break;
    case 3:
        while (clienteAtual != NULL && clienteAtual->prioridade <= 3)
        {
            clienteAnt = clienteAtual;
            clienteAtual = clienteAtual->prox;
        }

        break;

    default:
        break;
    }

    novo = (cliente *)malloc(sizeof(cliente));
    if (novo == NULL)
    {
        perror("\nErro ao alocar memória!\n\n");
        return;
    }
    strcpy(novo->nome, nome);
    novo->cpf = cpf;
    novo->prioridade = prioridade;
    novo->nitens = nItens;
    novo->prox = clienteAnt->prox;
    clienteAnt->prox = novo;
}

void desenfileirar(listCaixa *listaCaixas, int caixaEscolhido)
{
    caixa *pAux = listaCaixas->primCaixa;
    while (pAux->prox != NULL && pAux->numCaixa != caixaEscolhido)
    { // achando o caixa certo
        pAux = pAux->prox;
    }
    if (pAux->estado == 0) // caixa fechado
    {
        printf("\nCaixa fechado!\n\n");
        return;
    }
    if (pAux->fila->primCliente == NULL) // fila vazia
    {
        printf("\nFila vazia!\n\n");
        return;
    }

    cliente *clienteAux = pAux->fila->primCliente;
    pAux->fila->primCliente = clienteAux->prox;
    printf("\nCliente %s atendido!\n\n", clienteAux->nome);
    free(clienteAux);
}