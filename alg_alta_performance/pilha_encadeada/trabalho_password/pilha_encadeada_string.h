#include <iostream>
#include <stdlib.h>
using namespace std;

struct noS {
    char dado[20];
    struct noS *prox;
};

typedef struct noS* PilhaString;


void initS(PilhaString *topo)
{
    *topo = NULL;
}

int isEmptyS(PilhaString topo)
{
	if (topo == NULL)
		return(1);
	else
		return(0);
}

void pushS(PilhaString *topo, char elem[])
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

int popS(PilhaString *topo,char elem[])
{
	PilhaString aux;
	aux = *topo;
	if (!isEmptyS(*topo)) 
	{
		strcpy(elem, aux->dado);
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

int topS(PilhaString topo,char *elem[])
{
	if (!isEmptyS(topo))
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
