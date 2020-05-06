// ALUNOS - 2ECR
// João Batista Dionísio Neto - RM 83862

#include <iostream>
#include <cstring>
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
    cout << "**| 3 - Consultar informações de paciente (CPF)" << endl; 
    cout << "**| 4 - Alterar status de paciente" << endl; 
    cout << "**| 5 - Sair do programa" << endl;
    cout << "*********************************************" << endl; 
    cout << ">> ";
    cin >> opcao;
    return opcao;
}
char avaliacaoPaciente()
{
    int buffer = 0, soma = 0;
    cout << "Responda as perguntas com 0 p/ NÃO e 1 p/ SIM:" << endl;
    cout << "Você está com tosse?" << endl << ">> ";
    cin >> buffer;
    (buffer == 1) ? soma++ : soma;
    buffer = 0;

    cout << "Você está com febre?" << endl << ">> ";
    cin >> buffer;
    (buffer == 1) ? soma++ : soma;
    buffer = 0;

    cout << "Você está se sentindo cansado?" << endl << ">> ";
    cin >> buffer;
    (buffer == 1 && soma >= 1) ? soma++ : soma;
    buffer = 0;

    cout << "Você está sentindo dificuldades para respirar?" << endl << ">> ";
    cin >> buffer;
    (buffer == 1 && soma >= 1) ? soma+=3 : soma;
    buffer = 0;

    cout << "Você tem contato com pessoas que apresentam os sintomas?" << endl << ">> ";
    cin >> buffer;
    (buffer == 1) ? soma+=1 : soma;
    buffer = 0;
    
    cout << "Você teve contato com pessoas diagnosticadas com COVID-19?" << endl << ">> ";
    cin >> buffer;
    (buffer == 1) ? soma+=3 : soma;
    buffer = 0;

    return (soma >= 3) ? 'I' : 'L';
}

int main()
{
    int opcao = 0;
    int topoUnidades = 0;
    int topoPacientes = 0;
    tipoUnidadeInternacao unidades[SIZE_ARRAYS];
    tipoPaciente pacientes[SIZE_ARRAYS];

    do
    {
        limparTela();
        opcao = menu();
        cin.ignore();
        switch (opcao)
        {
            case 1:
            {
                tipoUnidadeInternacao unidade;
                cout << endl;                
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
                cout << "Cadastrando novo paciente:" << endl;
                cout << "Digite o nome: ";
                cin.getline(paciente.nome, SIZE_NOME);
                cout << "Digite o CPF (xxx.xxx.xxx-xx): ";
                cin.getline(paciente.cpf, 15);
                cout << "Digite o ano de nascimento: ";
                cin >> paciente.anoNascimento;
                cout << "Digite o número conforme o local de internação" << endl;

                for (int i=0; i<topoUnidades; i++)
                    cout << i+1 << " - " << unidades[i].nome << endl;
                cout << ">> ";
                cin >> paciente.localInternacao;
                paciente.localInternacao-=1;
                cin.ignore();
                cout << "Digite o nome do médico responsavel: ";
                cin.getline(paciente.medicoResponsavel, SIZE_NOME);
                cout << "\nIniciando avaliação de sintomas do paciente:" << endl;
                paciente.status = avaliacaoPaciente();

                pacientes[topoPacientes] = paciente;
                topoPacientes++;

                cout << "\nCadastro do paciente: '" << paciente.nome << "' feito com sucesso." << endl;
                if(paciente.status == 'L')
                    cout << "Paciente liberado para ir para casa.\n";
                else
                    cout << "Uma internação é necessaria.\n";

                cout << "Digite qualquer tecla para voltar ao menu: ";
                char buffer;
                cin >> buffer;
                break;
            }
            case 3:
            {
                char cpf[15];
                cout << endl;
                cout << "Digite o CPF no formato xxx.xxx.xxx-xx para consultar: " << endl;
                cout << ">> ";
                cin.getline(cpf, 15);

                tipoPaciente pacienteAchado;
                int achado=0;
                for (int i=0; i<topoPacientes; i++)
                {
                    if(strcmp(pacientes[i].cpf, cpf) == 0)
                    {
                        pacienteAchado = pacientes[i];
                        achado++;
                    }
                }

                if(achado > 0)
                {
                    cout << "\nInformações do paciente: " << endl;
                    cout << "Nome: " << pacienteAchado.nome << endl;
                    cout << "CPF: " << pacienteAchado.cpf << endl;
                    cout << "Ano de nascimento: " << pacienteAchado.anoNascimento << endl;
                    cout << "Local de internação: " << unidades[pacienteAchado.localInternacao].nome << endl;
                    cout << "Médico responsavel: " << pacienteAchado.medicoResponsavel << endl;

                    if(pacienteAchado.status == 'L')
                        cout << "Status: liberado para ir para casa" << endl;
                    else if(pacienteAchado.status == 'I')
                        cout << "Status: Internação necessaria" << endl;
                    else if(pacienteAchado.status == 'A')
                        cout << "Status: Alta e liberado para casa" << endl;
                    else if(pacienteAchado.status == 'O')
                        cout << "Status: Óbito" << endl;
                }
                else 
                    cout << "Paciente não encontrado" << endl;

                cout << "\nDigite qualquer tecla para voltar ao menu: ";
                char buffer;
                cin >> buffer;                
                break;
            }
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

    cout << "\n*****PACIENTES*****";
    for (int i=0; i<topoPacientes; i++)
    {
        cout << endl;
        cout << "Nome: " << pacientes[i].nome << endl;
        cout << "Local de internação: " << unidades[pacientes[i].localInternacao].nome << endl;
        cout << "Status: " << pacientes[i].status << endl;
    }
    
    
    return 0;

}
