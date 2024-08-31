#ifndef AUTORES_H
#define AUTORES_H

#define TAMn 100

typedef struct autor
{
    char nome[TAMn];
    int idAut;
    struct autor *prox;
} autor;

typedef struct listaAutores
{
    autor *primAut;
} listAut;

void criarLista(listAut *pLisAut);
int listaVazia(listAut *pListAut);
void inserirIni(listAut *pListAut, char nome[TAMn], int idAut);
void inserirFim(listAut *pListAut, char nome[TAMn], int idAut);
void mostrarLista(listAut *pLisAut);
#endif