#include "pilhaestatica.h"

void inicializapilha(TipoPilha *pilha){
    pilha->topo = -1;
}

void destroiPilha(TipoPilha *pilha){
    pilha->topo = -1;
}

int pilhaVazia(TipoPilha *pilha){
    return pilha->topo==-1;
}

int pilhaCheia(TipoPilha *pilha){
    return pilha->topo==MAX-1;
}

int empilha(TipoPilha *pilha, TipoItem item){
    if(!pilhaCheia(pilha))
    {
        pilha->topo++;
        pilha->itens[pilha->topo] = item;
        return 1;
    }
    else
    {
        return 0;
    }
}

int desempilha(TipoPilha *pilha, TipoItem *item){
    if(!pilhaVazia(pilha))
    {
    *item = pilha->itens[pilha->topo];
    pilha->topo--;
    return 1;
    }

    return 0;

}

int consultaTopo(TipoPilha *pilha, TipoItem *item){
    if(!pilhaVazia(pilha))
    {
    *item = pilha->itens[pilha->topo];
    return 1;
    }
return 0;
}

void imprimeItem(TipoItem item)
{
    printf("%i %s\n",item.chave,item.nome);
}

int imprimePilha(TipoPilha *pilha){
int i;
if(!pilhaVazia(pilha))
{
    for(i=pilha->topo;i>=0;i--)
    {
    imprimeItem(pilha->itens[i]);
    }
}
return 0;
}

