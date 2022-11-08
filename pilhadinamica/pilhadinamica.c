#include "pilhadinamica.h"

void inicilizaPilha(TipoPilha *pilha){
    pilha->topo = NULL;
}

void destroiPilha(TipoPilha *pilha){
    TipoNoh *ptrAux;
    if(!pilhaVazia(pilha))
    {
        ptrAux = pilha->topo;
        while(ptrAux!=NULL)
        {
            pilha -> topo = ptrAux->prox;
            free(ptrAux);
            ptrAux=pilha->topo;
        }
    }
}

int pilhaVazia(TipoPilha *pilha){
    return pilha->topo==NULL;
}

int empilha(TipoPilha *pilha, TipoItem item){
    TipoNoh *novoNoh;

    novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
    if(novoNoh!=NULL)
    {
        novoNoh->item = item;
        novoNoh->prox = pilha->topo;
        pilha->topo = novoNoh;
        return 1;
    }
return 0;
}

int desempilha(TipoPilha *pilha, TipoItem *item){
    TipoNoh *ptrAux;
    if(!pilhaVazia(pilha))
    {
        ptrAux = pilha->topo;
        *item = ptrAux->item;
        pilha->topo = ptrAux->prox;
        free(ptrAux);
        return 1;
    }
    return 0;
}

void imprimeItem(TipoItem item)
{
  printf("%i %s\n",item.chave,item.nome);
}

int imprimePilha(TipoPilha *pilha)
{
    TipoNoh *ptrAux;
    if(!pilhaVazia(pilha))
    {
        ptrAux = pilha->topo;
        while(ptrAux!=NULL)
        {
            imprimeItem(ptrAux->item);
            ptrAux = ptrAux->prox;

        }

    return 1;

    }

    return 0;
}