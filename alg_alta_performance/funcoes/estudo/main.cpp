#include <iostream>
#include <cstring>
#include <locale>
#include <stdlib.h>
#include <cstring>
using namespace std;

#define TAM_NOME 40
#define MAX_CIDADES 50

struct cidade
{
    char nome[TAM_NOME];
    int numeroHabitantes;
    float temperaturaMediaAnual;
};
struct reg_menor
{
    char nome[TAM_NOME];
    float temperaturaMediaAnual;
};

typedef struct cidade TipoCidade;
typedef struct reg_menor TipoRegMenorTemp;

int mais_fria(TipoCidade cidades[], int numCidades)
{
    int temp=cidades[0].temperaturaMediaAnual, indMenorTemperatura=0;
    for(int i=0; i<numCidades; i++) 
    {
        if(temp>cidades[i].temperaturaMediaAnual)
        {
            temp=cidades[i].temperaturaMediaAnual;
            indMenorTemperatura = i;
        }            
    }

    return indMenorTemperatura;
}

void ordenacao_insercao(TipoCidade cidades[], int numCidades)
{
    int j, i;
    TipoCidade eleita;
    for(i=1; i<numCidades; i++) {
        eleita = cidades[i];
        j = i-1;
        while(j >= 0 && cidades[j].numeroHabitantes > eleita.numeroHabitantes) {
        cidades[j+1] = cidades[j];
        j = j-1;
        }
        cidades[j+1] = eleita;
    }
}

void busca_cidade(TipoCidade cidades[], int numCidades, char cidadeProcurada[TAM_NOME])
{
    int pos=-1, achado=0;
    for (int i=0; i<numCidades && achado==0; i++)
    {
        if(strcmp(cidades[i].nome, cidadeProcurada) == 0) 
        {
            pos = i;
            achado=1;
        }
    }
    
    if(pos!=-1) 
    {
        cout << "Cidade encontrada\n";
        cout << "Nome: " << cidades[pos].nome << endl;
        cout << "Numero de habitantes: " << cidades[pos].numeroHabitantes << endl;
        cout << "Temperatura média no ano de 2019: " << cidades[pos].temperaturaMediaAnual << endl;
    }
    else
        cout << "A cidade não foi encontrada.\n";
}

int main()
{
    setlocale(LC_ALL, "");
    TipoCidade cidades[MAX_CIDADES]; 
    int resp, nCidades=0;

    do {
        system("cls");
        cout << "1) Cadastrar nova cidade.\n" ;
        cout << "2) Buscar cidade com média mais fria.\n";
        cout << "3) Buscar cidade por nome.\n";
        cout << "4) Ordenar em ordem crescente do número de habitantes.\n";
        cout << "5) Encerrar programa.\n";
        cout << "Digite sua opção: ";
        cin >> resp;
        cin.ignore();

        switch (resp)
        {
            case 1:
            {
                TipoCidade cidadeAux;
                cout << "\nDigite o nome da cidade: ";
                cin.getline(cidadeAux.nome, TAM_NOME);
                cout << "Digite o numero de habitantes: ";
                cin >> cidadeAux.numeroHabitantes;
                cout << "Digite a temperatura média em 2019: ";
                cin >> cidadeAux.temperaturaMediaAnual;

                cidades[nCidades] = cidadeAux;
                nCidades++;

                cout << "A cidade " << cidadeAux.nome << " foi cadastrada com sucesso." << endl;
                system("pause");
                break;
            }
            case 2:
            {
                int indMenor = mais_fria(cidades, nCidades);
                TipoRegMenorTemp cidadeMenorTemperatura;
                strcpy(cidadeMenorTemperatura.nome, cidades[indMenor].nome);
                cidadeMenorTemperatura.temperaturaMediaAnual = cidades[indMenor].temperaturaMediaAnual;

                cout << "A cidade com menor temperatura média é: " << cidadeMenorTemperatura.nome << endl;
                cout << "e sua temperatura média no ano de 2019 foi: " << cidadeMenorTemperatura.temperaturaMediaAnual << " graus" << endl;
                system("pause");
                break;
            }
            case 3:
            {
                char respCidade[TAM_NOME];
                cout << "Digite o nome da cidade que deseja procurar: ";
                cin.getline(respCidade, TAM_NOME);
                busca_cidade(cidades, nCidades, respCidade);
                system("pause");  
                break;       
            }
            case 4:
            {
                ordenacao_insercao(cidades, nCidades);
                cout << "As cidades ordenadas por ordem crescente de habitantes são: \n" ;
                for(int i=0; i<nCidades && i<10; i++) 
                    cout << cidades[i].nome << " | " << cidades[i].numeroHabitantes << " | " << cidades[i].temperaturaMediaAnual << endl;
                system("pause");
                break;
            }
            case 5:
                cout << "Encerrando programa.\n";
                break;
            default: 
                cout << "Opção inválida.\n";
        }
    } while (resp!=5);

    return 0;
}