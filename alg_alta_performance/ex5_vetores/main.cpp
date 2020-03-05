#include <iostream>
using namespace std;

#define N 2 //40 no max

//usar para limpar a tela
  //for(int i=0; i<100; i++) {
  //  cout << "\n";
  //}

int main()
{
  setlocale(LC_ALL, "");
  int codAlunos[N];
  float nota1[N];
  float nota2[N];

  for(int i=0; i<N; i++)
  {
    cout << "\nDigite o codigo do aluno " << i+1 << ": ";
    cin >> codAlunos[i];

    cout << "\n";
    cout << "Digite a nota 1: ";
    cin >> nota1[i];
    cout << "Digite a nota 2: ";
    cin >> nota2[i];
  }

  while(1) {
    int opcao = 0;
    for(int i=0; i<100; i++) {
      cout << "\n";
    }

    cout << "MENU - Escolha sua opção: \n";
    cout << "[1] - Mostrar codigo de todos os alunos\n";
    cout << "[2] - Mostrar nota de prova\n";
    cout << "[3] - Calcular média de um aluno\n";
    cout << "[4] - Calcular média todos os alunos\n";
    cout << "---> ";
    cin >> opcao;

    cout << "\n";
    int codDigitado = 0;
    switch (opcao)
    {
      case 1:
        for(int j=0; j<N; j++)
        {
          cout << "Aluno " << j+1 << ": " << codAlunos[j] << "\n";
        }
        break;
      
      case 2:
        for(int j=0; j<N; j++)
        {
          cout << codAlunos[j];
          // if(codAlunos[i] == codDigitado)
          // {
          //   float media = (nota1[i] + nota2[i]) / 2.0;
          //   cout << "A media deste aluno é: " << media;
          // }
        }
        break;

      default:
        break;
    }

    int exit = 1;
    cout << "\nDigite 0 para voltar ao menu.\n";
    while(exit > 0) {
      cin >> exit;
    }

  }  

}