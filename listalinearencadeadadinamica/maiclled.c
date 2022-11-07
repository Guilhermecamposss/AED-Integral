#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lled.h"

int main()
{
    ListaLinearED lista;
    TipoItem item;
    int n, i;
    inicializaLista(&lista);
    printf("nums de itens a serem inseridos: ");
    scanf("%i",&n);
    for(i=0;i<n;i++)
    {
        printf("Item %i\n",i+1);
        printf("Chave: ");
        scanf("&i",item.chave);
        getchar();
        prinf("nome: ");
        fgets(item.nome,sizeof(item.nome),stdin);
        if(!insereNoFinal(&lista,item))
        {
            printf("ERRO!");
            break;
        }
    }


    if(!listaVazia(&lista))
    {
    printf("\nLista: \n");
    imprimeLista(&lista);
    }
    else{
    printf("\nLista Vazia!\n");



if(removeDoFinal(&lista,&item))
{
    printf("Item removido: %i %s\n",item.chave,item.nome);
}
else
{
printf("lista vazia");
}

destroiLista(&lista);

return 0;

}
}
