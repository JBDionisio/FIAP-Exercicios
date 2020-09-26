#include <iostream>
#include <stdlib.h>
using namespace std;

struct no {
    char dado;
    struct no *prox;
};

typedef struct no * PilhaChar;

void init (PilhaChar *topo)
{
*topo = NULL;
}

int isEmpty (PilhaChar topo)
{
	if (topo == NULL)
		return(1);
	else
		return(0);
}

void push (PilhaChar *topo, char elem)
{
	PilhaChar novo;
	novo = (PilhaChar) malloc(sizeof(struct no));
	if (novo != NULL)
	{
		novo->dado=elem;
		novo->prox=*topo;
		*topo = novo;
	}
	else
		cout << "Stack overflow \n";
}

int pop(PilhaChar *topo,char *elem)
{
	PilhaChar aux;
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

int top (PilhaChar topo,char *elem)
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
