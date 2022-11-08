#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

typedef struct{
    int chave;
    char nome[30];
}TipoItem;

typedef struct{
    TipoItem itens[MAX];
    int ultimo;
}TipoFila;

void inicializaFila(TipoFila*);
int filaVazia(TipoFila*);
int filaCheia(TipoFila*);
int insereNaFila(TipoFila*,TipoItem);
int retiraDaFila(TipoFila*,TipoItem*);
void destroiFila(TipoFila*);
void imprimeItem(TipoItem);
int imprimeFila(TipoFila*);