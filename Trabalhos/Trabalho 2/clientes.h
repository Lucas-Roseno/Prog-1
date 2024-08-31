#ifndef CLIENTES_H
#define CLIENTES_H
#include "lista.h"
#define TAMn 100

typedef struct Cliente
{
    char nome[TAMn];
    long long cpf;
    int prioridade;
    int nitens;
    struct Cliente *prox;
} cliente;

typedef struct filaClientes
{
    cliente *primCliente;
} filaClientes;

void criarFila(filaClientes *fila);
void inserirIniFila(struct listaCaixa *lCaixas, char *nome, long long cpf, int prioridade, 
int nItens, int caixa);

#endif