#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
void criarPilha(struct Pilha *pilha)
{
    pilha->topo = NULL;
}
void empilhar(struct Pilha *pilha, int valor)
{
    struct Nodo *novo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (novo == NULL)
    {
        printf("Memória insuficiente.\n");
        return;
    }
    novo->info = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}
int desempilhar(struct Pilha *pilha)
{
    if (estaVazia(pilha))
    {
        printf("Pilha vazia.\n");
        return -1;
    }
    struct Nodo *temp = pilha->topo;
    int valor = temp->info;
    pilha->topo = temp->prox;
    free(temp);
    return valor;
}
int mostrarTopo(struct Pilha *pilha)
{
    if (estaVazia(pilha))
    {
        printf("Pilha vazia.\n");
        return -1;
    }
    return pilha->topo->info;
}
int estaVazia(struct Pilha *pilha)
{
    return (pilha->topo == NULL);
}

void salvarPilha(struct Pilha *pilha, const char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        perror("Falha ao abrir arquivo");
        return;
    }
    struct Nodo *atual = pilha->topo;
    while (atual != NULL)
    {
        fwrite(&atual->info, sizeof(int), 1, fp);
        atual = atual->prox;
    }
    fclose(fp);
}
void lerPilha(struct Pilha *pilha, const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        perror("Falha ao abrir arquivo");
        return;
    }
    int valor;
    struct Pilha pilhaTemp;
    criarPilha(&pilhaTemp);
    // Ler todos os elementos e empilhá-los na pilha temporária
    while (fread(&valor, sizeof(int), 1, fp) == 1)
    {
        empilhar(&pilhaTemp, valor);
    }
    fclose(fp);
    // Agora, reempilhar os elementos na pilha original e mantera ordem
    while (!estaVazia(&pilhaTemp))
    {
        valor = desempilhar(&pilhaTemp);
        empilhar(pilha, valor);
    }
}