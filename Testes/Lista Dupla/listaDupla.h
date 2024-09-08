#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef LISTADUPLA_H
#define LISTADUPLA_H


#define TAM 50

typedef struct Nodo
{
    char musica[TAM];
    struct Nodo *prox;
    struct Nodo *ant;
}nodo;

typedef struct lista_dupla
{
    nodo *prim;
    nodo *ult;
}lista_dupla;

void criarLista (lista_dupla *pList);
void inserirIni (lista_dupla *pList, char *musica);
void mostrarLista (lista_dupla *pList);
void inseririOrd (lista_dupla *pList, char *musica);
void removerIni (lista_dupla *pList);
void removerElemento (lista_dupla *pList, char *musica);
void inserirAposMusica(lista_dupla *pList, char *nomeMusica, char *novaMusica);



#endif