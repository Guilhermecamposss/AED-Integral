#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int chave;
    char nome[30];
}TipoItem;

struct noh{
    TipoItem item;
    struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct{
    TipoNoh *inicioLista;
    int ultimo;
}ListaLinearED;

int listaVazia(ListaLinearED*);
void inicializaLista(ListaLinearED*);
void destroiLista(ListaLinearED*);
void imprimeItem(TipoItem);
void imprimeLista(ListaLinearED*);
int insereNoFinal(ListaLinearED*,TipoItem);
int insereNoInicio(ListaLinearED*,TipoItem);
int removeDoFinal(ListaLinearED*, TipoItem*);
int removeDoInicio(ListaLinearED*,TipoItem*);






