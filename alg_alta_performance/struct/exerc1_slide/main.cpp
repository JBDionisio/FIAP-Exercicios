#include <iostream>
#include <locale>
using namespace std;

#define SIZE 40

struct cliente_banco
{
    char nome[SIZE];
    char endereco[SIZE];
    char cpf[16];
    int conta;
    int anoAbertura;
    float saldo;
};

typedef struct cliente_banco TipoCliente;

int main()
{
    setlocale(LC_ALL, "");
    TipoCliente cliente;
    cout << "Bem vindo(a) cliente. \n";
    cout << "Informe seu nome: ";
    cin.getline(cliente.nome, SIZE);
    cout << "Informe seu endereço: ";
    cin.getline(cliente.endereco, SIZE);
    cout << "Informe seu CPF: ";
    cin.getline(cliente.cpf, 16);
    cout << "Digite o número da sua conta: ";
    cin >> cliente.conta;
    cin.ignore();
    cout << "Digite o ano de abertura: ";
    cin >> cliente.anoAbertura;
    cin.ignore();
    cout << "informe o saldo: ";
    cin >> cliente.saldo;

    // Informações do cliente
    cout << "\n\nExibindo suas informações: \n";
    cout << "************************************************\n";
    cout << "Nome: " << cliente.nome << "\n";
    cout << "Endereço: " << cliente.endereco << "\n";
    cout << "CPF: " << cliente.cpf << "\n";
    cout << "Numero de conta: " << cliente.conta << "\n";
    cout << "Ano de abertura: " << cliente.anoAbertura << "\n";
    cout << "Saldo: " << cliente.saldo << "\n";
    cout << "************************************************\n";

    return 0;
}
