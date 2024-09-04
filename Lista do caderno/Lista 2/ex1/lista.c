#include "lista.h"

void criarLista (lista *plist)
{
    plist->prim = NULL;
}

void inserirIni (lista *pList, int numConta, long long cpf, char *nome)
{
    conta *novo = (conta *)malloc(sizeof(conta));
    if (novo == NULL)
    {
        perror("\nErro na alocação\n\n");
        return;
    }

    novo->numConta = numConta;
    novo->cpf = cpf;
    novo->nome = nome;
    novo->prox = pList->prim;
    pList->prim = novo;
}