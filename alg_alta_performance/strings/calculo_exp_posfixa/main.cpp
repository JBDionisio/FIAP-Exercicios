#include <iostream>
#include <locale>
#include <cstring>
//#include <ctype.h>

using namespace std;

#define SIZE 10

int main()
{
    setlocale(LC_ALL, "");
    int topo = 0; 
    char expressao[SIZE];
    float pilha[SIZE];

    cout << "Digite sua expressão Pósfixa: ";
    cin.getline(expressao, SIZE);

    for (int j=0; expressao[j] != '\0'; j++)
    {
        //if(isdigit(expressao[j])) //Não sei se é permitido usar biblioteca ctype
        if( expressao[j] >= '0' && expressao[j] <= '9') 
        {
            pilha[topo] = (float)expressao[j] - 48.0;
            cout << "Digito: " << expressao[j] << "\n";
        }
        else {
            int operacao = (int)expressao[j];
            cout << "Operacao: " << operacao << "\n";

            topo--;
            float dado1 = pilha[topo];
            pilha[topo] = 0;
            topo--;
            float dado2 = pilha[topo];
            pilha[topo] = 0;

            float resultado = 0.0;
            if(operacao == 43) //+
                resultado = dado2 + dado1;
            else if(operacao == 45) //-
                resultado = dado2 - dado1;
            else if(operacao == 42) //*
                resultado = dado2 * dado1;
            else if(operacao == 47) // /
                resultado = dado2 / dado1;

            pilha[topo] = resultado;
        }      

        topo++;
    }

    for (int i=0; pilha[i] != 0; i++)
    {
       cout << "\npilha[" << i << "]: " << pilha[i];
       pilha[i] = 0;
    }    

    //só pra provar que pilha esta vazia
    cout << "\n\nPilha final: ";
    for (int i=0; i<SIZE; i++)
    {
       cout << pilha[i];
    }
    return 0;
}
