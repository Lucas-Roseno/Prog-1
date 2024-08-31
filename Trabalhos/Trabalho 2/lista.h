#ifndef LISTA_H
#define LISTA_H
#include "clientes.h"

#define TAMn 100

typedef struct Caixa
{
    int numCaixa;
    int estado; // 1 = aberto e 0 = fechado
    struct filaClientes *fila;
    struct Caixa *prox;
}caixa;

typedef struct listaCaixa
{
    caixa *primCaixa;
}listCaixa;

void criarListCaixa(listCaixa *listCaixas);
int listCaixaVazia(listCaixa *listCaixas);
void inserirIniCaixas(listCaixa *listaCaixa);
void inserirFimCaixas(listCaixa *listaCaixa);
void mostrarCaixas(listCaixa *listaCaixa);
void abrirCaixa(listCaixa *listaCaixa, int numCaixa);
void fecharCaixa(listCaixa *listaCaixa, int numCaixa);
void mostrarUmCaixa(listCaixa *listaCaixa, int caixaEscolhido);

#endif
