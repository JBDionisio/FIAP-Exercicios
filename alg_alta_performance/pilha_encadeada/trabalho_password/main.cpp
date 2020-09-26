#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

#include "pilha_encadeada_char.h"
#include "pilha_encadeada_string.h"

int main()
{
    
}

void codifica(char senha[])
{
    char caracterAtual;
    for(int i=0; caracterAtual != '_' || caracterAtual != '#'; i++) 
    {


        if(caracterAtual == '\0')
            break;
    }
}

void inverter() 
{
    char palavra[20], inversao[20];
    PilhaChar topo;
    init(&topo);
    int i;
    for(i=0; palavra[i] != '\0'; i++) 
    {
        push(&topo , palavra[i]);
    }

    for(i=0; !isEmpty(topo); i++)
    {
        pop(&topo, &inversao[i]);
    }

    inversao[i] = '\0';
    cout << inversao << endl;
}