#include <iostream>
#include <locale>
#include <cstring>
using namespace std;

#define NC 15
#define N 20

int main()
{
    setlocale(LC_ALL, "");
    /*
    char msg[NC];
    cout << "Digite uma mensagem: ";
    cin.getline(msg, NC);
    cout << "mensagem = " << msg << "\n";
    */

    char nome[N] = "Gal Costa";
    cout << "Nome atribuído na declaração: " << nome << "\n";
    strcpy(nome, "Gilberto Gil");
    cout << "Nome atribuído depois: " << nome << "\n";
    int tamanho = strlen(nome);
    cout << "Tamanho string: " << tamanho << "\n";

    return 0;
}
