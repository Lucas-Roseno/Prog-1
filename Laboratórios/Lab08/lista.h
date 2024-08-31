#ifndef LISTA_H
#define LISTA_H

#define TAMnome 50
#define TAMcpf 11

struct Nodo
{
    char cpf[TAMcpf];
    char nome [TAMnome];
    struct Nodo *prox;
}typedef Nodo;

struct ListaSimplesEnc
{
    struct Nodo *prim;
};

void criarLista(struct ListaSimplesEnc *pList);
void mostrarLista(struct ListaSimplesEnc *pList);
void inserirIni(struct ListaSimplesEnc *pList, char n[TAMnome], char c[TAMcpf]);
int removerIni(struct ListaSimplesEnc *pList);
int estaVazia(struct ListaSimplesEnc *pList);
int inserirFim (struct ListaSimplesEnc *pList, char n[TAMnome], char c[TAMcpf]);

#endif