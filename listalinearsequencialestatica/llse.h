#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct 
{
    int chave;
    char nome[50];

}TipoItem;

typedef struct
{
    TipoItem itens[MAX];
    int ultimo;

}ListaLinearSequencial;

int listaVazia(ListaLinearSequencial*);
int listaCheia(ListaLinearSequencial*);

void inicializaLista(ListaLinearSequencial*);
void destroiLista(ListaLinearSequencial*);

void imprimimeItem(TipoItem);
void imprimeLista(ListaLinearSequencial*);

int insereNoFinal(ListaLinearSequencial*,TipoItem);
int insereNoInicio(ListaLinearSequencial*,TipoItem);

int removeDoFinal(ListaLinearSequencial*,TipoItem*);
int removeDoInicio(ListaLinearSequencial*, TipoItem*);

