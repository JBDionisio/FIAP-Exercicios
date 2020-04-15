#include <iostream>
#include <locale>
using namespace std;
#define NC 15

struct caderno_papelaria
{
    char fabricante[15];
    int numFolhas;
    char tipoDeCapa[15];
    float preco;
};

typedef struct caderno_papelaria TipoCadernoPapelaria;

int main()
{
    setlocale(LC_ALL, 0);
    TipoCadernoPapelaria cadernoCadastro;
    TipoCadernoPapelaria cadernoVenda;

    cout << "Digite o caderno a ser cadastrado: \n";
    cout << "Digite o fabricante: ";
    cin.getline(cadernoCadastro.fabricante, NC);
    cout << "Digite o numero de folhas: ";
    cin >> cadernoCadastro.numFolhas;
    cin.ignore();
    cout << "Digite o tipo de capa (dura/brochura): ";
    cin.getline(cadernoCadastro.tipoDeCapa, NC);
    cout << "Digite o preço: ";
    cin >> cadernoCadastro.preco;

    cadernoVenda = cadernoCadastro;

    cout << "\nApresentação dos dados do caderno vendido: \n";
    cout << "Fabricante: " << cadernoVenda.fabricante << endl;
    cout << "Numero de folhas: " << cadernoVenda.numFolhas << endl;
    cout << "Tipo de capa: " << cadernoVenda.tipoDeCapa << endl;
    cout << "Preço: " << cadernoVenda.preco << endl;

    return 0;
}
