#include "listaDupla.h"

void criarLista(lista_dupla *pList)
{
    pList->prim = NULL;
    pList->ult = NULL;
}

void inserirIni(lista_dupla *pList, char *musica)
{
    nodo *novo = (nodo *)malloc(sizeof(nodo));
    if (novo == NULL)
    {
        perror("Erro na alocação.");
        return;
    }
    strcpy(novo->musica, musica);
    novo->ant = NULL;

    if (pList->prim == NULL) // Lista vazia
    {
        pList->prim = novo;
        pList->ult = novo; // primeiro e último apontam para o novo
        novo->prox = NULL;
    }
    else
    {                             // lista com elementos
        novo->prox = pList->prim; // novo aponta para o primeiro
        pList->prim->ant = novo;  // ant do antigo primeiro aponta para o novo
        pList->prim = novo;       // primeiro da lista aponta para o novo
    }
}

void mostrarLista(lista_dupla *pList)
{
    if (pList->prim == NULL)
    {
        printf("\nLista vazia\n\n");
        return;
    }

    for (nodo *pAux = pList->prim; pAux != NULL; pAux = pAux->prox)
    {
        printf("\n%s\n", pAux->musica);
    }
    printf("\n");
}

void inseririOrd(lista_dupla *pList, char *musica)
{
    struct Nodo *novo, *atual;
    novo = (struct Nodo *)malloc(sizeof(struct Nodo));
    strcpy(novo->musica, musica);

    atual = pList->prim;

    if (pList->prim == NULL)
    {
        inserirIni(pList, musica);
        return;
    }

    while (atual != NULL && strcmp(atual->musica, musica) < 0)
    {
        atual = atual->prox;
    }

    novo->prox = atual;

    if (novo->prox != NULL)
    {
        if (atual->ant == NULL)
        { // o novo vai ser o começo da fila
            inserirIni(pList, musica);
        }
        else
        { // o novo vai ser inserido entre um no e outro
            novo->ant = atual->ant;
            atual->ant = novo;
            novo->ant->prox = novo;
        }
    }
    else
    { // novo vai ser no final da fila
        novo->ant = pList->ult;
        pList->ult->prox = novo;
        pList->ult = novo;
    }
}

void removerIni(lista_dupla *pList)
{
    if (pList->prim == NULL)
    {
        printf("\nLista já está vazia.\n\n");
        return;
    }

    nodo *pAux = pList->prim;

    if (pAux->prox == NULL)
    { // lista tem um elemento
        pList->ult = NULL;
        pList->prim = NULL;
    }
    else
    {
        pList->prim = pAux->prox;
        pList->prim->ant = NULL;
    }

    free(pAux);
}

void removerElemento(lista_dupla *pList, char *musica)
{
    if (pList->prim == NULL)
    {
        printf("\nLista vazia\n\n");
        return;
    }

    nodo *pAux = pList->prim;
    while (strcmp(musica, pAux->musica) != 0 && pAux != NULL)
    {
        pAux = pAux->prox;
    }

    if (pAux == NULL)
    {
        printf("\nElemento não encontrado\n\n");
        return;
    }

    if (pAux->ant == NULL)
    { // elemento no começo da lista
        removerIni(pList);
        mostrarLista(pList);
        return;
    }
    else if (pAux->prox == NULL)
    { // elemento no final
        pList->ult = pAux->ant;
        pAux->ant->prox = NULL;
    }
    else
    {
        pAux->ant->prox = pAux->prox;
        pAux->prox->ant = pAux->ant;
    }
    mostrarLista(pList);
    free(pAux);
}

void inserirAposMusica(lista_dupla *pList, char *nomeMusica, char *novaMusica)
{
    if (pList->prim == NULL)
    {
        printf("\nLista vazia\n\n");
        return;
    }
    
    nodo *novo = (nodo*)malloc(sizeof(nodo));
    if (novo == NULL)
    {
        perror("Erro na alocação");
        return;
    }
    strcpy(novo->musica, novaMusica);

    nodo *pAux = pList->prim;
    while (strcmp(nomeMusica, pAux->musica) != 0 && pAux != NULL)
    {
        pAux = pAux->prox;
    }

    if (pAux == NULL)
    {
        printf("\nMusica não encontrada\n\n");
        return;
    }
    
    if (pAux->prox == NULL)
    {//inserir no final da lista
        novo->prox = NULL;
        pAux->prox = novo;
        novo->ant = pList->ult;
        pList->ult = novo;
    }else
    {
        novo->ant = pAux;
        novo->prox = pAux->prox;
        pAux->prox->ant = novo;
        pAux->prox = novo;
    }
    
    mostrarLista(pList);

    
}