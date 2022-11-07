#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct{
    int chave;
    char nome[30];
}TipoItem;

typedef struct{
    TipoItem itens[MAX];
    int topo;
}TipoPilha;

void inicializaPilha(TipoPilha*);
void destroiPilha(TipoPilha*);
int pilhaVazia(TipoPilha*);
int pilhaCheia(TipoPilha*);
int empilha(TipoPilha*,TipoItem);
int desempilha(TipoPilha*,TipoItem*);
int consultaTopo(TipoPilha*,TipoItem*);
void imprimeItem(TipoItem);
int imprimePilha(TipoPilha*);