#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

#include "pilha_encadeada_char.h"

int main()
{
    TipoPilha topo;
    char palavra[20], inversao[20];

    init(&topo);

    cout << "Digite a palavra a ser verificada: " << endl ;
    cin.getline(palavra, 20) ;

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