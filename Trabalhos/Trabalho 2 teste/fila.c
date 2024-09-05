#include "lista.h"

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
        //printf("\nCaixa fechado!\nCadastre o cliente em outro caixa.\n\n");
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

void desenfileirar(listCaixa *listaCaixas, int caixaEscolhido, int impressao)
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
    if (impressao == -1)
    {
        return;
    }else
    {
        printf("\nCliente %s atendido!\n\n", clienteAux->nome);
    }
    
    free(clienteAux);
}