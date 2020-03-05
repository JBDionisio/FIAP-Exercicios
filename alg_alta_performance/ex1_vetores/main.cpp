#include <iostream>
using namespace std;

#define N 5 //30 na verdade

int main()
{
  setlocale(LC_ALL, "");
  int vetOriginal[N];
  int vetGerado[N];

  cout << "Digite " << N << " valores inteiros: " << "\n";
  for(int i=0; i<N; i++) 
  {
    cin >> vetOriginal[i];

    if(vetOriginal[i] == 0)
    {
      vetGerado[i] = 1;
    }
    else {
      vetGerado[i] = vetOriginal[i];
    }
  }

  cout << "\n" << "Vetor original: " << "\n";
  for(int i=0; i<N; i++)
  {
    cout << vetOriginal[i] << "\n";
  }

  cout << "\n" << "Vetor gerado: " << "\n";
  for(int i=0; i<N; i++)
  {
    cout << vetGerado[i] << "\n";
  }

  return 0;
}