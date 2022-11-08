#include "FilaEstatica.h"

void imprimeMenu();
void leDadosItem(TipoItem*);

int main(){
  TipoFila fila;
  TipoItem item;
  int op = 0, i;

  inicializaFila(&fila);

  while(op != 4){
    imprimeMenu();
    printf("\nOpção: ");
    scanf("%i",&op);
    switch(op){
      case 1:
        leDadosItem(&item);
        if(insereNaFila(&fila,item))
          printf("\nItem inserido com sucesso!\n");
        else
          printf("\nErro! Não foi possível inserir o item!\n");
        break;
      case 2:
        if(retiraDaFila(&fila,&item)){
          printf("\nItem retirado com sucesso!");
          printf("\nItem: %i %s\n",item.chave,item.nome);
        }
        else{
          printf("\nErro! Não foi possível retirar da fila!\n");
        }
        break;
      case 3:
        if(!filaVazia(&fila)){
          printf("\nFila:\n");
          imprimeFila(&fila);
        }
        else{
          printf("\nFila Vazia!\n");
        }
        break;
      case 4:
        destroiFila(&fila);
        printf("\nAté logo!\n");
        break;
      default:
        break;
    }
  }

  return 0;
}

void imprimeMenu(){
  printf("\nMenu");
  printf("\n1 - Insere na fila");
  printf("\n2 - Retira da fila");
  printf("\n3 - Imprime fila");
  printf("\n4 - Sair");
}

void leDadosItem(TipoItem *item){
  printf("\nDados do Item");
  printf("\nChave: ");
  scanf("%i",&item->chave);
  getchar();
  printf("Nome: ");
  fgets(item->nome,sizeof(item->nome),stdin);
}