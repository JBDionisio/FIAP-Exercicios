#include <iostream>
#include <locale>
using namespace std;

#define N 3
#define NC 10

struct cadastro
{
    char nome[NC];
    float nota;
};

typedef struct cadastro TipoCad;

int main()
{
    TipoCad alunos[N];
    TipoCad maiorAluno;
    float maior = 0.0;
    int i;

    for(i=0; i<N; i++)
    {
        cout << "Digite nome do aluno " << i << ": ";
        cin.getline(alunos[i].nome, NC);
        cout << "Digite nota do aluno: ";
        cin >> alunos[i].nota;
        cin.ignore();
    }

    for(i=0; i<N; i++)
    {
        if(alunos[i].nota > maior)
        {
            maior = alunos[i].nota;
            maiorAluno = alunos[i];
        }
    }

    cout << "\n\nInformações do aluno com maior nota: " << endl;
    cout << "************************************************" << endl;
    cout << "** Nome: " << maiorAluno.nome << endl;
    cout << "** Nota: " << maiorAluno.nota << endl;
    cout << "************************************************" << endl;

    return 0;
}
