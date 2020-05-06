// ALUNOS - 2ECR
// João Batista Dionísio Neto - RM 83862

#include <iostream>
#include <locale>
using namespace std;

#define SIZE_NOME 30

struct registro_paciente
{
    char nome[SIZE_NOME];
    char cpf[15];
    int anoNascimento;
    char localInternacao[SIZE_NOME];
    char medicoResponsavel[SIZE_NOME];
    char status;
};

struct registro_unidade_internacao
{
    char nome[SIZE_NOME];
    char telefone[9];
    int numeroLeitos;    
};

typedef struct registro_paciente tipoPaciente;
typedef struct registro_unidade_internacao tipoUnidadeInternacao;

void limparTela()
{
    for (int i=0; i<20; i++)
    {
        cout << "\n"; 
    }  
}
int menu() 
{
    int opcao = 0;
    cout << "Digite a opção correspondente: " << endl; 
    cout << "*********************************************" << endl; 
    cout << "**| 1 - Cadastrar unidade de internação" << endl; 
    cout << "**| 2 - Cadastrar novo paciente" << endl; 
    cout << "**| 3 - Consultar paciente (CPF)" << endl; 
    cout << "**| 4 - Alterar status de paciente" << endl; 
    cout << "**| 5 - Sair do programa" << endl;
    cout << "*********************************************" << endl; 
    cout << ">> ";
    cin >> opcao;
    return opcao;
}
tipoUnidadeInternacao cadastroUnidadeInternacao() {
    tipoUnidadeInternacao unidade;
    cout << endl;
    cin.ignore();
    cout << "Cadastrando nova unidade:" << endl;
    cout << "Digite o nome: ";
    cin.getline(unidade.nome, SIZE_NOME);
    cout << "Digite o telefone (xxxx-xxxx): ";
    cin.getline(unidade.telefone, 10);
    cout << "Digite o número de leitos: ";
    cin >> unidade.numeroLeitos;

    return unidade;
}

int main()
{
    int opcao = 0;
    tipoUnidadeInternacao bufferUnidade;
    do
    {
        limparTela();
        opcao = menu();
        switch (opcao)
        {
            case 1:
                bufferUnidade = cadastroUnidadeInternacao();
                cout << bufferUnidade.nome;
                while(1);
                break;
            case 2:
                cout << "2";
                break;
            case 3:
                cout << "3";
                break;
            case 4:
                cout << "4";
                break;
            case 5:
                cout << "goodbye";
                break;
        }
    } while (opcao != 5);
    
    return 0;

}
