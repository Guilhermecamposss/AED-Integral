#include <stdio.h>
#include <stdlib.h>

#define tamanho 1000

typedef struct noarvore{
	char letra;
	struct noarvore *direita;
	struct noarvore *esquerda;
} noarvore;

void posfixa(noarvore *arvore);
noarvore* arvore(char *infixa, char *prefixa, int Inicio, int Fim);
int rgn(char *str, int inicio, int fim, char letra);
noarvore* novoNoh(char letra);


int contt;

void main ()
{

	int Casos;
	int quantidadenos;
    int i;
	char prefixa[tamanho], infixa[tamanho];
	scanf("%i", &Casos);
	while (Casos--)
	{
		scanf("%i %s %s%*c", &quantidadenos, prefixa, infixa);
		contt = 0;
		noarvore *raiz = arvore(infixa, prefixa, 0, quantidadenos - 1);
		posfixa(raiz);
		printf("\n");
	}
}

int rgn(char *str, int inicio, int fim, char letra)
{
	int j;
	for (j = inicio; j <= fim; ++j)
	if (str[j] == letra)
	return j;
	return -1;
}

noarvore* novoNoh(char letra)
{
	noarvore *no = (noarvore *) malloc(sizeof(noarvore));
	no->letra = letra;
	no->esquerda = no->direita = NULL;
	return no;
}


noarvore* arvore(char *infixa, char *prefixa, int Inicio, int Fim)
{

	int indiceinfixa;
	if (Inicio > Fim)
	return NULL;
	noarvore *no = novoNoh(prefixa[contt++]);
	if (Inicio == Fim)
	return no;
	indiceinfixa = rgn(infixa, Inicio, Fim, no->letra);
	no->esquerda = arvore(infixa, prefixa, Inicio, indiceinfixa - 1);
	no->direita = arvore(infixa, prefixa, indiceinfixa + 1, Fim);
	return no;

}

void posfixa(noarvore *no)
{
	if (no == NULL)
	return;
	posfixa(no->esquerda);
	posfixa(no->direita);
	printf("%c", no->letra);

}