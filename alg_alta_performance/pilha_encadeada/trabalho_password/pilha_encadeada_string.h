#include <iostream>
#include <stdlib.h>
using namespace std;

struct noS {
    char dado[];
    struct noS *prox;
};

typedef struct noS* PilhaString;


void init(PilhaString *topo)
{
    *topo = NULL;
}

int isEmpty(PilhaString topo)
{
	if (topo == NULL)
		return(1);
	else
		return(0);
}

void push(PilhaString *topo, char elem[])
{
	PilhaString novo;
	novo = (PilhaString) malloc(sizeof(struct noS));
	if (novo != NULL)
	{
		strcpy(novo->dado, elem);
		novo->prox=*topo;
		*topo = novo;
	}
	else
		cout << "Stack overflow \n";
}

int pop(PilhaString *topo,char *elem[])
{
	PilhaString aux;
	aux = *topo;
	if (isEmpty(*topo)) 
	{
		strcpy(*elem, aux->dado);
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

int top(PilhaString topo,char *elem[])
{
	if (isEmpty(topo))
	{
        strcpy(*elem, topo->dado);
    	return(1);
    }
	else
	{
    	cout << "pilha vazia \n ";
    	return(0);
    }
}
