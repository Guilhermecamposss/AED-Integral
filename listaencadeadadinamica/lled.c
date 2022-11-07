#include "lled.h"

int listaVazia(ListaLinearED *lista){
    return lista->ultimo==0;
}

void inicializaLista(ListaLinearED *lista){
    lista->inicioLista = NULL;
    lista->ultimo = 0;
}

void destroiLista(ListaLinearED *lista){
    TipoNoh *ptrAux1, *ptrAux2;
    if(!listaVazia(lista))
    {
        ptrAux1 = lista->inicioLista;
        ptrAux2 = ptrAux1->prox;
        while(ptrAux1->prox != NULL)
        {
            free(ptrAux1);
            ptrAux1 = ptrAux2;
            ptrAux2 = ptrAux1->prox;
        }
        free(ptrAux1);

    }
    lista->inicioLista=NULL;
    lista->ultimo = 0;


}

void imprimeItem(TipoItem item){
    printf("%i %s\n",item.chave,item.nome);
}

void imprimeLista(ListaLinearED *lista){
    TipoNoh *ptrAux;
    if(!listaVazia(lista))
    {
        ptrAux = lista->inicioLista;
        while(ptrAux != NULL)
        {
            imprimeItem(ptrAux->item);
            ptrAux = ptrAux->prox;
        }

    }

}

int insereNoFinal(ListaLinearED *lista,TipoItem item){
    TipoNoh *novoNoh, *ptrAux;
    novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
    if(novoNoh != NULL)
    {
    ptrAux = lista->inicioLista;
    if(listaVazia(lista))
    {
        while(ptrAux->prox != NULL)
        {
            ptrAux = ptrAux->prox;
            ptrAux->prox = novoNoh;
        }

    }
    else{
        lista->inicioLista = novoNoh;
    }
    novoNoh-> item = item;
    novoNoh-> prox = NULL;
    lista->ultimo++;
    return 1;

    }

    return 0;

}

int insereNoInicio(ListaLinearED *lista, TipoItem item)
{
    TipoNoh *novoNoh;
    novoNoh = (TipoNoh*) malloc(sizeof(TipoNoh));
    if(novoNoh != NULL)
    {
        novoNoh->item = item;
        novoNoh->prox = lista->inicioLista;
        lista->inicioLista = novoNoh;
        lista->ultimo++;
        return 1;
    }
    else{
    return 0;
    }

} 

int removeDoFinal(ListaLinearED* lista, TipoItem *item){
    TipoNoh *ptrAux1, *ptrAux2;
    if(!listaVazia(lista))
    {
        ptrAux1 = lista->inicioLista;
        ptrAux2 = ptrAux1->prox;
        if(ptrAux2 == NULL)
        {
            lista->inicioLista = NULL;
            *item = ptrAux1->item;
            free(ptrAux1);
        }
        else
        {
        while(ptrAux2->prox != NULL)
        {
            ptrAux1 = ptrAux2;
            ptrAux2 = ptrAux2->prox;

        }
        ptrAux1->prox=NULL;
        *item = ptrAux2->item;
        free(ptrAux2);


        }
        lista->ultimo--;
        return 1;

    }
    else{

return 0;

    }

}
