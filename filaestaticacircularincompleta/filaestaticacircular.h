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
    int inicio;
    int fim;
}TipoFila;

void inicializaFila(TipoFila*);
int filaVazia(TipoFila*);
int filaCheia(TipoFila*);
int insereNaFila(TipoFila*,TipoItem);
int retiraDaFila(TipoFila*,TipoItem*);