#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define tamanho 1000


struct rgn{   
    struct rgn *esquerda;
    int num;
    struct rgn *direita;

};
typedef struct rgn tipoarvore;

tipoarvore * funcaopai(tipoarvore *r, int n){  
    if(r == NULL)
    return NULL;
    else if (n == r->num)
    {
    return r;
    }
    else if(n < r->num)
    {       
    if(r->esquerda == NULL)
    return r;
    else
    return funcaopai(r->esquerda, n);
    }
    else
    {
    if(r->direita == NULL)
    return r;
    else
    return funcaopai(r->direita, n);
    }
}


int main()
{  
    tipoarvore *raiz, *pai, *j, *h[tamanho];
    int valor;
    int casos;
    int k;
    int i;
    int no;
    int contadora;
    int contadorb;

    scanf("%d", &casos);
         for(k=1; k<=casos; k++)
    {
	    for(i=0;i<tamanho;i++)
	h[i] = NULL;
    raiz = NULL;

    scanf("%d", &valor);
        for(i=0; i<valor; i++)
        {
            scanf("%d", &no);
            j = (tipoarvore *) malloc(sizeof(tipoarvore));
            j->num = no;
            j->esquerda = j->direita = NULL;

        pai = funcaopai(raiz, no);
            if(pai == NULL)
                raiz = j;
              else if (pai->num != no){
                     if (no < pai->num)
            pai->esquerda = j;
                else
     pai->direita = j;
            }
        }
        printf("Case %d:\n", k);
                j = raiz;
             contadora = 1;
             contadorb  = 1;
                h[0] = j;
        while(j != NULL){
         printf("%d", j->num);

                 if(j->esquerda != NULL){
                      h[contadora] = j->esquerda;
                     contadora++;
                 }

         if(j->direita != NULL){
                h[contadora] = j->direita;
                contadora++;
            }

                        if(h[contadorb]!=NULL)
                            printf(" ");

                  j = h[contadorb];
              contadorb++;
        }

        printf("\n\n");
    }
 return 0;
}