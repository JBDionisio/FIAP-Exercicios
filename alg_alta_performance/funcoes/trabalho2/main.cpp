// ALUNOS - 2ECR
// João Batista Dionísio Neto - RM 83862

#include <iostream>
#include <locale>
using namespace std;

#define SIZE_NOME 30
#define SIZE_ARRAYS 15

struct registro_paciente
{
    char nome[SIZE_NOME];
    char cpf[15];
    int anoNascimento;
    int localInternacao;
    char medicoResponsavel[SIZE_NOME];
    char status;
};

struct registro_unidade_internacao
{
    char nome[SIZE_NOME];
    char telefone[10];
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

int main()
{
    int opcao = 0;
    int topoUnidades = 0;
    tipoUnidadeInternacao unidades[SIZE_ARRAYS];

    cout << "BEM VINDO!";
    do
    {
        limparTela();
        opcao = menu();
        switch (opcao)
        {
            case 1:
            {
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

                unidades[topoUnidades] = unidade;
                topoUnidades++;

                cout << "\nCadastro da unidade: '" << unidade.nome << "' feito com sucesso." << endl;
                cout << "Digite qualquer tecla para voltar ao menu: ";
                char buffer;
                cin >> buffer;
                break;
            }
            case 2:
            {
                tipoPaciente paciente;
                cout << endl;
                cin.ignore();
                cout << "Cadastrando novo paciente:" << endl;
                cout << "Digite o nome: ";
                cin.getline(paciente.nome, SIZE_NOME);
                cout << "Digite o CPF (xxx.xxx.xxx-xx): ";
                cin.getline(paciente.cpf, 15);
                cout << "Digite o ano de nascimento: ";
                cin >> paciente.anoNascimento;
                cout << "Digite o número conforme o local de internação" << endl;
                for (int i=0; i<topoUnidades; i++)
                {
                    cout << i+1 << " - " << unidades[i].nome << endl;
                }
                cout << ">> ";
                cin >> paciente.localInternacao;
                cin.ignore();
                cout << "Digite o nome do médico responsavel: ";
                cin.getline(paciente.medicoResponsavel, SIZE_NOME);
                

                // unidades[topoUnidades] = unidade;
                // topoUnidades++;

                // cout << "\nCadastro da unidade: '" << unidade.nome << "' feito com sucesso." << endl;
                cout << "Digite qualquer tecla para voltar ao menu: ";
                char buffer;
                cin >> buffer;
                break;
            }
            case 3:
                cout << "3";
                break;
            case 4:
                cout << "4";
                break;
            case 5:
                break;
            default:
                cout << "Opção invalida";
                break;
        }
    } while (opcao != 5);

    cout << "\n*****UNIDADES*****";
    for (int i=0; i<topoUnidades; i++)
    {
        cout << endl;
        cout << "Nome: " << unidades[i].nome << endl;
        cout << "Telefone: " << unidades[i].telefone << endl;
        cout << "Numero de leitos: " << unidades[i].numeroLeitos << endl;
    }
    
    
    return 0;

}
