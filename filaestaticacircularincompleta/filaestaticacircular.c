#include "filaestaticacircular.h"

void inicializarFila(TipoFila *fila)
{
    fila->inicio = -1;
    fila->fim = 0;

}

int FilaVazia(TipoFila *fila){ 
return fila->inicio==-1;
}

int filaCheia(TipoFila *fila){
    return fila->inicio==fila->fim;
}


int insereNaFila(TipoFila *fila,TipoItem item){
  if(!filaCheia(fila)){
    if(filaVazia(fila)){
      fila->inicio = 0;
    fila->itens[fila->fim] = item;
    fila->fim = (fila->fim+1)%MAX;
    }
    return 1;
  }
  return 0;
}

int retiraDaFila(TipoFila *fila,TipoItem *item){
  if(!filaVazia(fila)){
    *item = fila->itens[fila->inicio];
    fila->inicio = (fila->inicio+1)%MAX;
    if(fila->inicio==fila->fim){
      fila->inicio = -1;
      fila->fim = 0;
    }
    return 1;
  }
  return 0;
}