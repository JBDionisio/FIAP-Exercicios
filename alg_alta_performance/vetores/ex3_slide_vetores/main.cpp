#include <iostream>
#define N 10
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    int i;
    int valores[N];
    for(i=0; i<N; i++)
    {
        cout << "Digite um valor inteiro: ";
        cin >> valores[i];
    }

    int maior_elemento = 0;
    int posicao_maior_elemento = 0;
    for(i=0; i<N; i++)
    {
        if(valores[i] > maior_elemento) {
            maior_elemento = valores[i];
            posicao_maior_elemento = i;
        }
    }

    cout << "Maior valor: " << maior_elemento << "\n";
    cout << "Sua posição no vetor é: " << posicao_maior_elemento << "\n";

    return 0;
}
