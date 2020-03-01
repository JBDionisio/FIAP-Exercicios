#include <iostream>
#define N 10
using namespace std;

int main()
{
    int i, saldo_negativo=0;
    float saldos[N];
    for(i=0; i<N; i++)
    {
        cout << "Digite o saldo da sua conta bancaria: ";
        cin >> saldos[i];
    }

    cout << "\n";

    for(i=0; i<N; i++)
    {
        if(saldos[i] > 0)
        {
            cout << "SALDO POSITIVO: " << saldos[i] << "\n";
        }
        else if(saldos[i] < 0)
        {
            saldo_negativo++;
        }

    }
    cout << "Numero de saldos negativos: " << saldo_negativo << "\n";

    return 0;
}
