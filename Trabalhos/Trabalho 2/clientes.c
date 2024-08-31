#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criarFila(filaClientes *fila)
{
    fila->primCliente = NULL;
}

void inserirIniFila(listCaixa *lCaixas, char *nome, long long cpf, int prioridade, 
int nItens, int caixaEscolhido)
{
    caixa *pAuxC = lCaixas->primCaixa;
    while (pAuxC->prox != NULL && pAuxC->numCaixa != caixaEscolhido)
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
    

}