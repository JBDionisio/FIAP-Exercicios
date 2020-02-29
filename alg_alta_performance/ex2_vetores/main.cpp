#include <iostream>
using namespace std;
#define N 5

int main()
{
  int vetor1[N];
  int vetor2[N];
  int vetorDerivado[N];

  for(int i=0; i<N; i++)
  {
    cout << "Digite o valor " << i+1 << " do primeiro vetor: ";
    cin >> vetor1[i];
    cout << "Digite o valor " << i+1 << " do segundo vetor: ";
    cin >> vetor2[i];


    if(vetor1[i] >= vetor2[i])
    {
      vetorDerivado[i] = vetor1[i];
    }
    else
    {
      vetorDerivado[i] = vetor2[i];
    }
    
    cout << "\n";
  }

  for(int i=0; i<N; i++)
  {
    cout << "\n";
    cout << "Maior valor: " << vetorDerivado[i];
  }

  return 0;
}