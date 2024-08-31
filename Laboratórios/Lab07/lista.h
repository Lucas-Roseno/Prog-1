#ifndef LISTA_H
#define LISTA_H

struct Nodo
{
    long long cpf;
    char nome [100];
    struct Nodo *prox;
}typedef Nodo;

struct ListaSimplesEnc
{
    struct Nodo *prim;
};

void criarLista(struct ListaSimplesEnc *pList);
void mostrarLista(struct ListaSimplesEnc *pList);
void inserirIni(struct ListaSimplesEnc *pList, char n[100], long long c);
void removerIni(struct ListaSimplesEnc *pList);
int estaVazia(struct ListaSimplesEnc *pList);
void removerPessoa (struct ListaSimplesEnc *plist, char nome[100]);
int inserirFim (struct ListaSimplesEnc *pList, char n[100], long long c);

#endif