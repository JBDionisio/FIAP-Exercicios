#include <iostream>
#include <stdlib.h>
using namespace std;

/* declaracao do no */
struct no {
    char dado;
    struct no *prox;
};

/*Definição do tipo de dado pilha */
typedef struct no * TipoPilha;


void init (TipoPilha *topo)
{
*topo = NULL;
}

int isEmpty (TipoPilha topo)
{
	if (topo == NULL)
		return(1);
	else
		return(0);
}

void push (TipoPilha *topo, char elem)
{
	TipoPilha novo;
	novo = (TipoPilha) malloc(sizeof(struct no));
	if (novo != NULL)
	{
		novo->dado=elem;
		novo->prox=*topo;
		*topo = novo;
	}
	else
		cout << "Stack overflow \n";
}

int pop(TipoPilha *topo,char *elem)
{
	TipoPilha aux;
	aux = *topo;
	if (isEmpty(*topo)) 
	{
		*elem=aux->dado;
		*topo=aux->prox;
		free(aux);
		return(1);
	}
	else 
	{
		cout << "pilha vazia \n ";
		return(0);
	}
}

int top (TipoPilha topo,char *elem)
{
	if (isEmpty(topo))
	{
    	*elem=topo->dado;
    	return(1);
    }
	else
	{
    	cout << "pilha vazia \n ";
    	return(0);
    }
}
