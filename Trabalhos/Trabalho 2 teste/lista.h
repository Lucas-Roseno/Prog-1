#ifndef LISTA_H
#define LISTA_H

#define TAMn 100

//=============FILA================
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



//=============CAIXA===============
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

//=============FILA================

void criarFila(filaClientes *fila);
void inserirIniFila(listCaixa *lCaixas, char *nome, long long cpf, int prioridade, 
int nItens, int caixaEscolhido);
void mostrarFila(filaClientes *fila);
void inserirOrdFila(listCaixa *lCaixas, char *nome, long long cpf, int prioridade, 
int nItens, int caixaEscolhido);
void desenfileirar(listCaixa *listaCaixas, int caixaEscolhido);

#endif
