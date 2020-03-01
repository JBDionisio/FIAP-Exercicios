#include <iostream>
#define N 10

using namespace std;

int main()
{
    int vet[N];
    int i;
    for(i=0; i<N; i++)
    {
        cout << "Digite um valor inteiro para posicao " << i << ": ";
        cin >> vet[i];
    }

    for(i=0; i<N; i++)
    {
        vet[i] += 2;
    }

    for(i=5; i<N; i++)
    {
        cout << "\n";
        cout << "vet[" << i << "] = " << vet[i] << "\n";
    }

    return 0;
}
