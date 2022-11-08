#include <stdio.h>
#include <stdlib.h>
#include "pilhadinamica.h"

int main(){
  TipoPilha pilha;
  TipoItem item;
  int n, i;

  inicializaPilha(&pilha);

  printf("Número de itens a empilhar: ");
  scanf("%i",&n);
  for(i=0;i<n;i++)
  {
    printf("Item:\n");
    printf("Chave: ");
    scanf("%i",&item.chave);
    getchar();
    printf("Nome: ");
    fgets(item.nome,sizeof(item.nome),stdin);
    if(!empilha(&pilha,item))
    {
    printf("Não foi possível empilhar! Pilha Cheia!\n");
    break;
    }
  }

  imprimePilha(&pilha);

  while(!pilhaVazia(&pilha))
  {
    if(!desempilha(&pilha,&item))
    {
      printf("Não foi possível desempilhar! Pilha Vazia!\n");
    }
    else
    {
      printf("Item desempilhado: %i %s\n",item.chave,item.nome);
    }
  }

  destroiPilha(&pilha);

  return 0;
}