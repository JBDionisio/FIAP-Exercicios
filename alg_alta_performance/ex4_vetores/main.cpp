#include <iostream>
using namespace std;

#define NUMERO_ALUNOS 6

int main()
{
  setlocale(LC_ALL, "");
  float p1[NUMERO_ALUNOS];
  float p2[NUMERO_ALUNOS];
  float medias[NUMERO_ALUNOS];

  for(int i=0; i<NUMERO_ALUNOS; i++) 
  {
    cout << "Digite a nota da prova P1 do aluno " << i+1 << ": ";
    cin >> p1[i];

    cout << "Digite a nota da prova P2 do aluno " << i+1 << ": ";
    cin >> p2[i];

    medias[i] = 0.3*p1[i]+0.7*p2[i];

    cout << "\n";
  }

  for(int i=0; i<NUMERO_ALUNOS; i++)
  {
    cout << "A média do aluno " << i+1 << " é: " << medias[i];
    cout << "\n";
  }

  return 0;
}