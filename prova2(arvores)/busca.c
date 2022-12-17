#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct rgn
{
    struct rgn *esquerda;
    int valor;
    struct rgn *dir;
    };

typedef struct rgn arvore;
int tipo;

arvore * AchaPai(arvore *r, int v)
{	if(r == NULL)
	return NULL;
	else
		if(v <= r->valor)
			if(r->esquerda == NULL)
			return r;
			else
			return AchaPai(r->esquerda, v);
		    else

			if(r->dir == NULL)
			return r;
			else
			return AchaPai(r->dir, v);
}

int ImprimeArvore(arvore *r)
{
	if(r != NULL)
	{
		if(tipo == 1){
			printf(" %d", r->valor);
			ImprimeArvore(r->esquerda);
			ImprimeArvore(r->dir);
		}
		if(tipo == 2){
			ImprimeArvore(r->esquerda);
			printf(" %d", r->valor);
			ImprimeArvore(r->dir);
		}
		if(tipo == 3){
			ImprimeArvore(r->esquerda);
			ImprimeArvore(r->dir);
			printf(" %d", r->valor);
		}
	}

	return 0;
}

int main()
{	arvore *raiz, *pai, *aux;
	int tamanho, Ncasos, c, d, noh;

	raiz = NULL;
	scanf("%d", &Ncasos);

	for(c=1; c<=Ncasos; c++)
	{
		raiz = NULL;

		scanf("%d", &tamanho);
		for(d=0; d<tamanho; d++)
		{
			scanf("%d", &noh);

			aux = (arvore *) malloc(sizeof(arvore));
			aux->valor = noh;
			aux->esquerda = NULL;
			aux->dir = NULL;

			pai = AchaPai(raiz, noh);
			if(pai == NULL)
				raiz = aux;
			else
				if(noh <= pai->valor)
					pai->esquerda = aux;
				else
					pai->dir = aux;
		}
		printf("Case %d:", c);
		printf("\nPre.:");
		tipo = 1;
		ImprimeArvore(raiz);
		printf("\nIn..:");
		tipo = 2;
		ImprimeArvore(raiz);
		printf("\nPost:");
		tipo = 3;
		ImprimeArvore(raiz);
		printf("\n\n");
	}
	return 0;
}