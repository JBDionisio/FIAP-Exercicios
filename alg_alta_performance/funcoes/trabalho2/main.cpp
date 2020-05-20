// ALUNOS - 2ECR
// João Batista Dionísio Neto - RM 83862
// Frederico Costa do Nascimento Dezorzi - RM 82507
// Luccas Guilherme Cordeiro - RM 83515

// Distribuição entre as unidades de atendimento
    //  É feita verificando a unidade que tem mais leitos livres, fazendo a diferença entre
    //o numero de leitos total com os leitos ja ocupados.
    //  Feita na function alocarPacienteEmUnidade() a partir da linha 129.

// Tomada de decisão entre INTERNAÇÃO ou LIBERAÇÃO
    //  É feita com um sistema de "pesos", com base na resposta do paciente.
    //  Se o "peso" das respostas for maior ou igual a 3, esse paciente deve ser internado pois
    //correu um risco de contaminação alto ou apresenta os sintomas.
    //  Leva-se em conta a idade também, sendo maior ou igual a 60 anos soma mais um ao peso.
    //  Feita na function avaliacaoPaciente() a partir da linha 71.

// No final do programa, apenas é printado todas as unidades e pacientes.

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
    int numeroLeitosOcupados; 
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
char avaliacaoPaciente(int idadePaciente)
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

    cin.ignore();

    if(idadePaciente >= 60)
        soma+=1;

    return (soma >= 3) ? 'I' : 'L';
}
int acharPacientePorCPF(tipoPaciente pacientes[SIZE_ARRAYS], int topoPacientes) {
    char cpf[15];
    cout << endl;
    cout << "Digite o CPF no formato xxx.xxx.xxx-xx para consultar: " << endl;
    cout << ">> ";
    cin.getline(cpf, 15);

    int achado=-1;
    for (int i=0; i<topoPacientes; i++)
    {
        if(strcmp(pacientes[i].cpf, cpf) == 0)
            achado = i;
    }

    return achado;
}
int alocarPacienteEmUnidade(tipoUnidadeInternacao unidades[SIZE_ARRAYS], int topoUnidades) {

    int indiceRetorno = -1;
    int maiorQuantidadeDeLeitosLivres = 0;
    for (int i=0; i<topoUnidades; i++)
    {
        bool condicaoBasica = unidades[i].numeroLeitosOcupados < unidades[i].numeroLeitos;
        int leitosLivres = unidades[i].numeroLeitos - unidades[i].numeroLeitosOcupados;
        if((maiorQuantidadeDeLeitosLivres == 0 && condicaoBasica) ||
           (leitosLivres > maiorQuantidadeDeLeitosLivres && condicaoBasica))
        {
            maiorQuantidadeDeLeitosLivres = leitosLivres;
            indiceRetorno = i;
        }
    }

    unidades[indiceRetorno].numeroLeitosOcupados++;
    return indiceRetorno;
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
                cout << "Quantos leitos já estão ocupados? ";
                cin >> unidade.numeroLeitosOcupados;

                if(unidade.numeroLeitosOcupados > unidade.numeroLeitos)
                {                    
                    cout << "Não se pode ocupar mais leitos que existem nesta unidade.";
                    break;
                }

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
                
                cout << "\nIniciando avaliação de sintomas do paciente:" << endl;
                paciente.status = avaliacaoPaciente(2020 - paciente.anoNascimento);                

                cout << "\nCadastro do paciente: '" << paciente.nome << "' feito com sucesso." << endl;
                if(paciente.status == 'L')
                {
                    cout << "Paciente liberado para ir para casa.\n";
                    paciente.localInternacao = -1;
                }
                else
                {
                    cout << "Uma internação é necessaria.\n";
                    paciente.localInternacao = alocarPacienteEmUnidade(unidades, topoUnidades);
                    if(paciente.localInternacao >= 0) 
                    {                        
                        cout << "Paciente foi alocado em: " << unidades[paciente.localInternacao].nome << endl;
                        cout << "Digite o nome do médico responsavel: ";
                        cin.getline(paciente.medicoResponsavel, SIZE_NOME);
                    }
                    else 
                    {
                        cout << "Não foi possível alocar o paciente em nenhum local." << endl;
                    }
                }

                pacientes[topoPacientes] = paciente;
                topoPacientes++;

                cout << "Digite qualquer tecla para voltar ao menu: ";
                char buffer;
                cin >> buffer;
                break;
            }
            case 3:
            {
                int indicePaciente = acharPacientePorCPF(pacientes, topoPacientes);
                if(indicePaciente >= 0)
                {
                    tipoPaciente pacienteAchado = pacientes[indicePaciente];
                    cout << "\nInformações do paciente: " << endl;
                    cout << "Nome: " << pacienteAchado.nome << endl;
                    cout << "CPF: " << pacienteAchado.cpf << endl;
                    cout << "Ano de nascimento: " << pacienteAchado.anoNascimento << endl;

                    if(pacienteAchado.localInternacao >= 0) 
                    {
                        cout << "Local de internação: " << unidades[pacienteAchado.localInternacao].nome << endl;
                        cout << "Médico responsavel: " << pacienteAchado.medicoResponsavel << endl;
                    }
                    else
                        cout << "Paciente não esta alocado em nenhuma unidade." << endl;

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
            {
                cout << endl;
                cout << "Alterar status do paciente:";
                int indicePaciente = acharPacientePorCPF(pacientes, topoPacientes);
                if(indicePaciente >= 0) 
                {
                    int statusAtual;
                    cout << "Paciente '" << pacientes[indicePaciente].nome << "' encontrado" << endl;
                    cout << "Digite o valor correspondente para o status atual do paciente:" << endl;
                    cout << "1 - Alta e liberado para casa\n";
                    cout << "2 - Óbito\n";
                    cout << ">> ";
                    cin >> statusAtual;
                    pacientes[indicePaciente].status = (statusAtual == 1) ? 'A' : 'O';
                    pacientes[indicePaciente].localInternacao = -1;

                    if(statusAtual == 1)
                        cout << "Status alterado para 'ALTA'";
                    else
                        cout << "Status alterado para 'ÓBITO'";                    
                }
                else
                    cout << "Paciente não encontrado";

                cout << "\nDigite qualquer tecla para voltar ao menu: ";
                char buffer;
                cin >> buffer; 
                break;
            }
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
        cout << "Numero de leitos Ocupados: " << unidades[i].numeroLeitosOcupados << endl;
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
