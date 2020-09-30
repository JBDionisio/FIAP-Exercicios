#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

#include "pilha_encadeada_char.h"
#include "pilha_encadeada_string.h"

#define SIZE_NOME 20
#define SIZE_SENHA 30
#define SIZE_MAQUINAS 3

int tamanho(char palavra[SIZE_NOME])
{
    int tamanho = 0;
    for (int i = 0; palavra[i] != '\0'; i++)
        tamanho++;

    return tamanho;
}

void inverterMaquinas(char maquina[3][SIZE_NOME], int tamanho)
{
    PilhaString topo;
    initS(&topo);
    int i;
    for (i = 0; i < tamanho; i++)
    {
        pushS(&topo, maquina[i]);
    }

    for (i = 0; !isEmptyS(topo); i++)
    {
        popS(&topo, maquina[i]);
    }
}

void inverterPalavra(char palavra[SIZE_NOME], char inversao[SIZE_NOME])
{
    PilhaChar topo;
    init(&topo);
    int i;
    for (i = 0; palavra[i] != '\0'; i++)
    {
        push(&topo, palavra[i]);
    }

    for (i = 0; !isEmpty(topo); i++)
    {
        pop(&topo, &inversao[i]);
    }

    inversao[i] = '\0';
}

void codifica(char senha[])
{
    int topoGuardaCaracteres = 0;
    char caracterAtual;
    char caracteresGuardados[10], senhaInvertida[SIZE_SENHA];
    memset(senhaInvertida, 0, sizeof senhaInvertida);
    memset(caracteresGuardados, 0, sizeof caracteresGuardados);
    for (int i = 0; senha[i] != '\0'; i++)
    {
        caracterAtual = senha[i];
        if (caracterAtual != '_' && caracterAtual != '#')
        {
            caracteresGuardados[topoGuardaCaracteres] = caracterAtual;
            topoGuardaCaracteres++;
        }
        else
        {
            char inverso[SIZE_NOME];
            inverterPalavra(caracteresGuardados, inverso);
            strcat(senhaInvertida, inverso);

            if (caracterAtual == '_')
                strcat(senhaInvertida, "_");
            else
                strcat(senhaInvertida, "#");

            topoGuardaCaracteres = 0;
            memset(caracteresGuardados, 0, sizeof caracteresGuardados);
        }
    }

    if (topoGuardaCaracteres != 0)
    {
        char inverso[SIZE_NOME];
        inverterPalavra(caracteresGuardados, inverso);
        strcat(senhaInvertida, inverso);
    }

    int senhaTamanho = tamanho(senha) / 3;
    for (int i = 0; senhaInvertida[i] != '\0'; i++)
    {
        if (senhaInvertida[i] == '_' || senhaInvertida[i] == '#')
            continue;
        int asc = senhaInvertida[i];
        asc += senhaTamanho;
        senhaInvertida[i] = asc;
    }

    strcpy(senha, senhaInvertida);
}

void decodifica(char senha[])
{
    int topoGuardaCaracteres = 0;
    char caracterAtual;
    char caracteresGuardados[10], senhaOriginal[SIZE_SENHA];
    memset(senhaOriginal, 0, sizeof senhaOriginal);
    memset(caracteresGuardados, 0, sizeof caracteresGuardados);
    for (int i = 0; senha[i] != '\0'; i++)
    {
        caracterAtual = senha[i];
        if (caracterAtual != '_' && caracterAtual != '#')
        {
            caracteresGuardados[topoGuardaCaracteres] = caracterAtual;
            topoGuardaCaracteres++;
        }
        else
        {
            char inverso[SIZE_NOME];
            inverterPalavra(caracteresGuardados, inverso);
            strcat(senhaOriginal, inverso);

            if (caracterAtual == '_')
                strcat(senhaOriginal, "_");
            else
                strcat(senhaOriginal, "#");

            topoGuardaCaracteres = 0;
            memset(caracteresGuardados, 0, sizeof caracteresGuardados);
        }
    }

    if (topoGuardaCaracteres != 0)
    {
        char inverso[SIZE_NOME];
        inverterPalavra(caracteresGuardados, inverso);
        strcat(senhaOriginal, inverso);
    }

    int senhaTamanho = tamanho(senha) / 3;
    for (int i = 0; senhaOriginal[i] != '\0'; i++)
    {
        if (senhaOriginal[i] == '_' || senhaOriginal[i] == '#')
            continue;
        int asc = senhaOriginal[i];
        asc -= senhaTamanho;
        senhaOriginal[i] = asc;
    }

    strcpy(senha, senhaOriginal);
}

int main()
{
    int opcao = 0;
    int numeroMaquinas = 0;
    char maquinas[SIZE_MAQUINAS][SIZE_NOME];
    char senhas[SIZE_MAQUINAS][SIZE_SENHA];

    bool estaCodificado = false;

    do
    {
        system("cls");        
        cout << "Digite a opção correspondente: " << endl;
        cout << "*********************************************" << endl;
        cout << "**| 1 - Cadastrar nova máquina" << endl;
        cout << "**| 2 - Codificar senha" << endl;
        cout << "**| 3 - Decodificar senha" << endl;
        cout << "**| 4 - Inverter máquinas" << endl;
        cout << "**| 5 - Sair do programa" << endl;
        cout << "*********************************************" << endl;
        cout << ">> ";
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 1:
        {
            cout << endl;
            cout << "Cadastrando nova máquina:" << endl;
            cout << "Digite o nome: ";
            cin.getline(maquinas[numeroMaquinas], SIZE_NOME);
            cout << "Digite a senha (original): ";
            cin.getline(senhas[numeroMaquinas], SIZE_SENHA);

            cout << "\nCadastro da máquina: '" << maquinas[numeroMaquinas] << "' feito com sucesso." << endl;
            system("pause");

            if (estaCodificado)
                codifica(senhas[numeroMaquinas]);

            numeroMaquinas++;
            break;
        }
        case 2:
        {
            if (!estaCodificado)
            {
                cout << endl;
                cout << "Codificando senhas de todas as máquinas:" << endl;
                cout << endl;

                cout << "NOME: \t SENHA (codificada):" << endl;
                for (int i = 0; i < numeroMaquinas; i++)
                {
                    char senha[SIZE_SENHA];
                    memset(senha, 0, sizeof senha);
                    strcpy(senha, senhas[i]);
                    codifica(senha);
                    strcpy(senhas[i], senha);
                    cout << maquinas[i] << " \t " << senhas[i] << endl;
                }

                estaCodificado = true;
            }
            else
            {
                cout << "As senhas já estão codificadas." << endl;
            }

            system("pause");
            break;
        }
        case 3:
        {
            if (estaCodificado)
            {
                cout << endl;
                cout << "Decodificando senhas de todas as máquinas:" << endl;
                cout << endl;

                cout << "NOME: \t SENHA (decodificada/original):" << endl;
                for (int i = 0; i < numeroMaquinas; i++)
                {
                    char senha[SIZE_SENHA];
                    memset(senha, 0, sizeof senha);
                    strcpy(senha, senhas[i]);
                    decodifica(senha);
                    strcpy(senhas[i], senha);
                    cout << maquinas[i] << " \t " << senhas[i] << endl;
                }

                estaCodificado = false;
            }
            else
            {
                cout << "As senhas ainda não estão codificadas." << endl;
            }

            system("pause");
            break;
        }
        case 4:
        {
            char maquinasInversas[SIZE_MAQUINAS][SIZE_NOME];
            cout << "Antes:" << endl;
            for (int i = 0; i < numeroMaquinas; i++)
            {
                cout << maquinas[i] << " \t " << senhas[i] << endl;
            }

            cout << endl
                 << "Invertendo nome das máquinas:" << endl;
            inverterMaquinas(maquinas, numeroMaquinas);
            cout << "NOME: \t SENHA:" << endl;
            for (int i = 0; i < numeroMaquinas; i++)
            {
                cout << maquinas[i] << " \t " << senhas[i] << endl;
            }

            system("pause");
            break;
        }
        case 5:
            cout << "Encerrando programa." << endl;
            break;

        default:
            cout << "Opção inválida." << endl;
            break;
        }

    } while (opcao != 5);
}