#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LLSEMV.h"

int main()
{
    ListaLinearSequencial lista;
    TipoItem item;
    int i, n;

    inicializaLista(&lista);

    printf("num a serem inseridos: ");
    scanf("%i",&n);

    for(i=0;i<n;i++)
    {
    printf("item %i\n",i+1);
    printf("chave: ");
    scanf("%i",&item.chave);
    getchar();
    printf("nome: ");
    fgets(item.nome,sizeof(item.nome),stdin);
    if(!insereNoInicio(&lista,item))
    {
        printf("ERRO!\n");
        break;
    }
    }


    if(!listaVazia(&lista))
    {
    printf("\nItens na lista:\n");
    imprimeLista(&lista);  
    }
    else
    {
    printf("\nLista Vazia.\n");
    }

    if(!removeDoFinal(&lista,&item))
    {
        printf("VAZIA!");
    }
    else{
        printf("Item removido: %i %s",item.chave,item.nome);
    }

    if(!listaVazia(&lista))
    {
    printf("\nitens na lista:\n");
    imprimeLista(&lista);
    }
    else{
        printf("lista Vazia!");
    }

    if(!removeDoInicio(&lista,&item))
    {
    printf("erro!Lista VAZIA!\n");
    }
    else
    {
        printf("item removido: %i %s,item.chave,item.nome");
    }

return 0;

}