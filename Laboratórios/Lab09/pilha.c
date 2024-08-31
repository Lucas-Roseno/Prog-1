#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void criarPilha(pilhaDoc *pPilha)
{
    pPilha->topo = NULL;
}

int pilhaVazia(pilhaDoc *pPilha)
{
    return (pPilha->topo == NULL);
}

void empilhar(pilhaDoc *pPilha, int idDoc, char titulo[TAMn], listAut *autores)
{
    doc *novo = (doc *)malloc(sizeof(doc));//cria o no do documento
    if (novo == NULL)
    {
        printf("Erro ao alocar memória\n");
        return;
    }

    novo->idDoc = idDoc;
    strcpy(novo->titulo, titulo);

    novo->list_aut = (listAut *)malloc(sizeof(listAut));//Aloca espaço para criar a lista
    if (novo->list_aut == NULL)
    {
        perror("Erro ao alocar memória\n");
        free(novo);
        return;
    }
    criarLista(novo->list_aut);//cria a novo lista
    autor *atual = autores->primAut;

    while (atual != NULL)
    {//insere os autores na lista 
        inserirFim(novo->list_aut, atual->nome, atual->idAut);
        atual = atual->prox;
    }

    novo->prox = pPilha->topo;
    pPilha->topo = novo;
}

void mostrarTopo(pilhaDoc *pPilha)
{
    if (pilhaVazia(pPilha))
    {
        printf("\nPilha vazia!\n\n");
        return;
    }

    printf("\n%d\t%s", pPilha->topo->idDoc, pPilha->topo->titulo);
    mostrarLista(pPilha->topo->list_aut);
    printf("\n");
}

doc desemplihar(pilhaDoc *pPilha)
{
    doc retorno;
    if (pilhaVazia(pPilha))
    {
        printf("\nPilha vazia!\n\n");
        return retorno;
    }
    doc *temp = pPilha->topo;
    pPilha->topo = temp->prox;
    printf("\nDocumento excluído:\n");
    printf("%d\t%s\n", temp->idDoc, temp->titulo);
    retorno = *temp;
    free(temp);
    printf("\n");
    return retorno;
}

void salvarPilha(pilhaDoc *pPilha)
{
    FILE *arq = fopen("arquivo.bin", "wb");
    if (arq == NULL)
    {
        perror("\nErro ao abrir o arquivo!\n");
        return;
    }

    doc *atual = pPilha->topo;
    while (atual != NULL)
    {
        fwrite(&atual->idDoc, sizeof(int), 1, arq);
        fwrite(atual->titulo, sizeof(char), TAMn, arq);

        // Gravando a lista
        autor *auxAutor = atual->list_aut->primAut;
        while (auxAutor != NULL)
        {
            fwrite(&auxAutor->idAut, sizeof(int), 1, arq);
            fwrite(auxAutor->nome, sizeof(char), TAMn, arq);
            auxAutor = auxAutor->prox;
        }
        // Flag para saber o fim da lista
        int fimLista = -1;
        fwrite(&fimLista, sizeof(int), 1, arq);

        atual = atual->prox;
    }
    fclose(arq);
}

void lerPilha(pilhaDoc *pPilha)
{
    FILE *arq = fopen("arquivo.bin", "rb");
    if (arq == NULL)
    {
        perror("\nErro ao abrir o arquivo!\n");
        return;
    }

    pilhaDoc pilhaTemp;
    criarPilha(&pilhaTemp);

    while (!feof(arq))
    {
        doc novoDoc;
        listAut *novaLista = (listAut *)malloc(sizeof(listAut));
        criarLista(novaLista);

        if (fread(&novoDoc.idDoc, sizeof(int), 1, arq) != 1)
        {
            break;
        }
        fread(novoDoc.titulo, sizeof(char), TAMn, arq);

        while (1) // Lendo a lista
        {
            int idAut;
            fread(&idAut, sizeof(int), 1, arq);
            if (idAut == -1) // Flag do fim da lista
            {
                break;
            }
            char nome[TAMn];
            fread(nome, sizeof(char), TAMn, arq);
            inserirFim(novaLista, nome, idAut);
        }

        empilhar(&pilhaTemp, novoDoc.idDoc, novoDoc.titulo, novaLista);
        //mostrarTopo(&pilhaTemp);
    }

    // colando a pilha na ordem certa
    doc *aux = pilhaTemp.topo;
    while (aux != NULL)
    {
        empilhar(pPilha, aux->idDoc, aux->titulo, aux->list_aut);
        aux = aux->prox;
        mostrarTopo(pPilha);
    }
}
