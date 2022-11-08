#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

typedef struct{
    int chave;
    int nome[30];
}TipoItem;

struct noh{
    TipoItem item;
    struct noh *prox;
};

typedef struct noh TipoNoh;

typedef struct{
    TipoNoh *topo;
}TipoPilha;

void inicializaPilha(TipoPilha*);
void destroiPilha(TipoPilha*);
int pilhaVazia(TipoPilha*);
int empilha(TipoPilha*,TipoItem);
int desempilha(TipoPilha*,TipoItem*);
void imprimeItem(TipoItem);
int imprimePilha(TipoPilha*);
