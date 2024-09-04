#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LISTA_H
#define LISTA_H

#define TAMn 50

typedef struct contaCorrente
{
    int numConta;
    long long cpf;
    char *nome;
    float limite;
    float saldo;
    struct contaCorrente *prox;
} conta;

typedef struct listaSimples
{
    conta *prim;
}lista;

void criarLista (lista *plist);
void inserirIni (lista *pList, int numConta, long long cpf, char *nome);





#endif