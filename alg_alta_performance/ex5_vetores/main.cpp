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

  int exit = 0;
  while(exit >= 0) {
    exit = 1;
    int opcao = 0;
    int cod;
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
    switch (opcao)
    {
      case 1:
        for(int j=0; j<N; j++)
        {
          cout << "Aluno " << j+1 << ": " << codAlunos[j] << "\n";
        }
        break;
      
      case 2:
        cout << "Digite o codigo do aluno: ";
        cin >> cod;
        for(int j=0; j<N; j++)
        {          
          if(codAlunos[j] == cod)
          {
            int iProva;
            cout << "Qual a prova deseja ver a nota [1/2]: ";
            cin >> iProva;

            if(iProva == 1)
              cout << "A nota é: " << nota1[j];
            else if(iProva == 2)
              cout << "A nota é: " << nota2[j];
            else
              cout << "Opção invalida";
          }
        }
        break;

      case 3:        
        cout << "Digite o codigo do aluno: ";
        cin >> cod;
        for(int j=0; j<N; j++)
        {          
          if(codAlunos[j] == cod)
          {
            float media = (nota1[j] + nota2[j]) / 2.0;
            cout << "A media deste aluno é: " << media;
          }
        }
        break;

      case 4:
        for(int j=0; j<N; j++)
        {          
          float media = (nota1[j] + nota2[j]) / 2.0;
          cout << "A media do aluno " << codAlunos[j] << " é: " << media << "\n";
        }
        break;

      default:
        break;
    }
    
    cout << "\n\n";
    cout << "\nDigite 0 para voltar ao menu\n";
    cout << "Digite -1 para encerrar programa\n";
    cout << "---> ";
    while(exit > 0) {
      cin >> exit;
    }

  }  

}