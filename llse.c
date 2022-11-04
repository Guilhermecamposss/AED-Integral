#include "llse.h"

int listaVazia(ListaLinearSequencial* lista)
{

    return lista->ultimo == 0;

}

int listaCheia(ListaLinearSequencial* lista)
{

    return lista->ultimo == MAX;

}

void inicializaLista(ListaLinearSequencial* lista)
{

    lista->ultimo = 0;

}

void destroiLista(ListaLinearSequencial* lista)
{

    lista->ultimo = 0;

}

void imprimimeItem(TipoItem item)
{

    printf("%i %s",item.chave,item.nome);

}

void imprimeLista(ListaLinearSequencial*lista){
    int i;

    for(i=0;i<lista->ultimo;i++)
    {
    imprimeItem(lista->itens[i]);
    }
}


int insereNoFinal(ListaLinearSequencial* lista,TipoItem novoItem)
{
    int pos = lista->ultimo;

    if(!listaCheia(lista))
    {
    lista->itens[pos]=novoItem;
    lista->ultimo++;
    return 1;
    }
    else
    {
    return 0;
    }
}

int insereNoInicio(ListaLinearSequencial* lista, TipoItem novoItem)
{
    int pos = lista->ultimo;
    int i;

    if(!listaCheia(lista))
    {
        for(i=pos;i>0;i--)
        {
        lista->itens[i] = lista->itens[i-1];
        lista->itens[0] = novoItem;
        lista->ultimo++;
        return 1;
        }
    }
    else
    {
    return 0;
    }
}

int removeDoFinal(ListaLinearSequencial* lista, TipoItem *item)
{
    int pos=lista->ultimo;

    if(!listaVazia(lista))
    {
        *item = lista->itens[pos-1];
        lista->ultimo--;
        return 1;
    }
    else
    {
    return 0;
    }
}

int removeDoInicio(ListaLinearSequencial *lista, TipoItem *item)
{
    int pos=lista->ultimo;
    int i;

    if(!listaVazia(lista))
    {
    *item = lista->itens[0];
    for(i=1;i<pos;i++)
    {

        lista->itens[i-1] = lista->itens[i];

    }
    lista->ultimo--;
    return 1;
    }
    else
    {
    return 0;
    }
}