#ifndef LISTA_H
#define LISTA_H

#define TAMn 50
#define TAMc 11

typedef struct nodo
{
    char nome[TAMn];
    char cpf[TAMc];
    struct nodo *prox;
} no;

typedef struct listaSimplesEnc
{
    no *prim;
} lista;

void criarLista(lista *pList);
int estaVazia(lista *pList);
void inserirIni(lista *pList, char n[TAMn], char c[TAMc]);
void mostrarLista(lista *pList);
int inserirFim (lista *pList, char n[TAMn], char c[TAMc]);
void removerIni(lista *pList, char n[TAMn]);
void removerPessoa (lista *pList, char n[TAMn]);

#endif