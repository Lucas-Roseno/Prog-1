#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void criarPilhaDoc(struct PilhaDoc *pilha)
{
    pilha->topo = NULL;
}

void criarListaAut(struct ListaAut *lista)
{
    lista->prim = NULL;
}

void Empilhar(struct PilhaDoc *pilha, int id, char titulo[100], struct ListaAut *lista)
{
    struct NodoDoc *novo = (struct NodoDoc *)malloc(sizeof(struct NodoDoc));
    novo->id = id;
    strcpy(novo->titulo, titulo);
    novo->autores = lista->prim;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

void InserirAut(struct ListaAut *lista, int id, char nome[100])
{
    struct NodoAut *novo;
    novo = (struct NodoAut *)malloc(sizeof(struct NodoAut));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->prox = lista->prim;
    lista->prim = novo;
}

void mostrarLista(struct NodoAut *p)
{
    while (p != NULL)
    {
        printf("\n%s\n", p->nome);
        p = p->prox;
    }
    printf("\n");
}

void MostrarTopo(struct PilhaDoc *pilha)
{
    if (EstaVazia(pilha))
    {
        printf("Pilha vazia.\n");
    }
    else
    {
        printf("\nId: %d", pilha->topo->id);
        printf("\nTítulo: %s", pilha->topo->titulo);
        printf("\nAutores: ");
        mostrarLista(pilha->topo->autores);
    }
}

int EstaVazia(struct PilhaDoc *pilha)
{
    return (pilha->topo == NULL);
}

void Desempilhar(struct PilhaDoc *pilha)
{
    if (EstaVazia(pilha))
    {
        printf("Pilha vazia.\n");
    }

    char titulo[100];

    struct NodoDoc *temp = pilha->topo;
    int valor = temp->id;
    strcpy(titulo, temp->titulo);
    pilha->topo = temp->prox;
    free(temp);

    printf("\nSucesso ao desempilhar o documento de id: %d e título: %s \n", valor, titulo);
}

void salvarPilha(struct PilhaDoc *pilha, const char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "wb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    struct NodoDoc *docAtual = pilha->topo;

    while (docAtual != NULL) {
        fwrite(&docAtual->id, sizeof(int), 1, fp);
        fwrite(docAtual->titulo, sizeof(char), 100, fp);

        struct NodoAut *autorAtual = docAtual->autores;
        while (autorAtual != NULL) {
            fwrite(&autorAtual->id, sizeof(int), 1, fp);
            fwrite(autorAtual->nome, sizeof(char), 100, fp);

            autorAtual = autorAtual->prox;
        }

        int fimAutores = -1;
        fwrite(&fimAutores, sizeof(int), 1, fp);

        docAtual = docAtual->prox;
    }

    fclose(fp);
}


void lerPilha(struct PilhaDoc *pilha, const char *nomeArquivo) {
    FILE *fp = fopen(nomeArquivo, "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    struct NodoDoc *docAtual = NULL;
    while (!feof(fp)) {
        struct NodoDoc *novoDoc = (struct NodoDoc *)malloc(sizeof(struct NodoDoc));
        if (novoDoc == NULL) {
            perror("Erro de alocação de memória");
            return;
        }

        if (fread(&novoDoc->id, sizeof(int), 1, fp) != 1) break;

        fread(novoDoc->titulo, sizeof(char), 100, fp);

        novoDoc->autores = NULL;
        struct NodoAut *autorAtual = NULL;

        while (1) {
            int autorId;
            if (fread(&autorId, sizeof(int), 1, fp) != 1) break;

            if (autorId == -1) break;

            struct NodoAut *novoAutor = (struct NodoAut *)malloc(sizeof(struct NodoAut));

            novoAutor->id = autorId;
            fread(novoAutor->nome, sizeof(char), 100, fp);
            novoAutor->prox = NULL;

            if (novoDoc->autores == NULL) {
                novoDoc->autores = novoAutor;
            } else {
                autorAtual->prox = novoAutor;
            }
            autorAtual = novoAutor;
        }
        novoDoc->prox = pilha->topo;
        pilha->topo = novoDoc;
    }

    fclose(fp);
}
