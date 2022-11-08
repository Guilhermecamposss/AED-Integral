#include "filaestatica.h"

void inicializaFila(TipoFila *fila){
    fila->ultimo = -1;
}

int filaVazia(TipoFila *fila){
    return fila->ultimo == -1;
}

int filaCheia(TipoFila *fila){
    return fila->ultimo == MAX-1;
}

int insereNaFila(TipoFila *fila, TipoItem item){
    if(!filaCheia(fila)){
    fila->ultimo++;
    fila->itens[fila->ultimo] = item;
    return 1;
    }

    return 0;

}

int retiraDaFila(TipoFila *fila, TipoItem *item){
    int i;
    if(!filaVazia(fila))
    {
        *item = fila->itens[0];
        for(i=1;i<=fila->ultimo;i++)
        {
            fila->itens[i-1] = fila->itens[i];
        }
    fila->ultimo--;
    return 1;
    }
return 0;
}

void destroiFila(TipoFila *fila)
{
    TipoItem item;
    while(!filaVazia(fila))
    {

        retiraDaFila(fila,&item);

    }
}

void imprimeItem(TipoItem item)
{
  printf("%i %s\n",item.chave,item.nome);
}

int imprimeFila(TipoFila *fila)
{
int i;
if(!listVazia(fila))
{
    for(i=0;i<=fila->ultimo;i++)
    {
        imprimeItem(fila->itens[i]);
    }
return 1;
}
return 0;
}