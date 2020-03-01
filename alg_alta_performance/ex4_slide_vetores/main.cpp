#include <iostream>
#define N 5
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int i;
    int rm[N];
    float nota1[N], nota2[N], medias[N];
    int aprovados[N];

    for(i=0; i<N; i++)
    {
        cout << "Digite o RM do aluno " << i << ": ";
        cin >> rm[i];

        cout << "Digite a nota da prova 1 do RM=" << rm[i] << " : ";
        cin >> nota1[i];

        cout << "Digite a nota da prova 2 do RM=" << rm[i] << " : ";
        cin >> nota2[i];

        medias[i] = (nota1[i] + nota2[i]) / 2;

        aprovados[i] = 0;
        if(medias[i] > 6.0)
            aprovados[i] = rm[i];
    }

    cout << "\n";
    for(i=0; i<N; i++)
    {
        if(aprovados[i] != 0) {
            cout << "APROVADO: " << aprovados[i] << "\n";
        }
    }

    return 0;
}
