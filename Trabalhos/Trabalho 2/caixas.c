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
        mostrarFila(pAux->fila);
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
        printf("\nCaixa já está fechado.\n\n");
        return;
    }

    if (pAux->fila->primCliente == NULL)
    { // fila vazia
        pAux->estado = 0;
        printf("\nCaixa %d fechado\nNenhum cliente na fila para ser rediercionado\n\n",
               pAux->numCaixa);
        return;
    }

    caixa *caixaPFechar = pAux;

    int cont = 0;
    caixa *pCont = listaCaixa->primCaixa;
    while (pCont != NULL)
    { // verificando se existe pelo menos outro caixa aberto
        if (cont == 2)
        {
            break;
        }
        if (pCont->estado == 1)
        {
            cont++;
        }
        pCont = pCont->prox;
    }

    if (cont < 2)
    {
        printf("\nCaixa não pode ser fechado pois não há outro aberto!\n\n");
        return;
    }

    pAux = listaCaixa->primCaixa;
    while (pAux != NULL)
    {
        if (pAux->numCaixa == caixaPFechar->numCaixa || pAux->estado == 0)
        {
            pAux = pAux->prox;
        }
        if (pAux->numCaixa != caixaPFechar->numCaixa && pAux->estado == 1)
        {
            break;
        }
    }

    cliente *realocado = caixaPFechar->fila->primCliente;
    while (realocado != NULL)
    {
        inserirOrdFila(listaCaixa, realocado->nome, realocado->cpf, realocado->prioridade,
                       realocado->nitens, pAux->numCaixa);
        realocado = realocado->prox;
        desenfileirar(listaCaixa, numCaixa, -1);
    }

    caixaPFechar->estado = 0;
    caixaPFechar->fila->primCliente = NULL;
    printf("\nCaixa %d fechado", numCaixa);
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
    }
    else
    {
        printf("\nCaixa %d aberto, fila: \n", pAux->numCaixa);
    }

    mostrarFila(pAux->fila);
}

void impressaoDasFilas(listCaixa *listaCaixas)
{
    printf("\n======================================");
    for (caixa *pAux = listaCaixas->primCaixa; pAux != NULL; pAux = pAux->prox)
    {

        if (pAux->estado == 1 && pAux->fila->primCliente != NULL)
        {
            printf("\nCaixa %d:\n", pAux->numCaixa);
            for (cliente *clientes = pAux->fila->primCliente; clientes != NULL; clientes = clientes->prox)
            {
                printf("\n--------------------------------------");
                printf("\nNome: %s\n", clientes->nome);
                printf("CPF: %lld\n", clientes->cpf);
                printf("Prioridade: %d\n", clientes->prioridade);
                printf("Número de itens: %d", clientes->nitens);

                printf("\n--------------------------------------");
            }
            printf("\n======================================\n");
        }
    }
}